#include "x86.h"
#include "device.h"

SegDesc gdt[NR_SEGMENTS];
TSS tss;

#define SECTSIZE 512

void waitDisk(void) {
	while((inByte(0x1F7) & 0xC0) != 0x40);
}

void readSect(void *dst, int offset) {
	int i;
	waitDisk();

	outByte(0x1F2, 1);
	outByte(0x1F3, offset);
	outByte(0x1F4, offset >> 8);
	outByte(0x1F5, offset >> 16);
	outByte(0x1F6, (offset >> 24) | 0xE0);
	outByte(0x1F7, 0x20);

	waitDisk();
	for (i = 0; i < SECTSIZE / 4; i ++) {
		((int *)dst)[i] = inLong(0x1F0);
	}
}

void initSeg() {
	gdt[SEG_KCODE] = SEG(STA_X | STA_R, 0,       0xffffffff, DPL_KERN);
	gdt[SEG_KDATA] = SEG(STA_W,         0,       0xffffffff, DPL_KERN);
	gdt[SEG_UCODE] = SEG(STA_X | STA_R, 0,       0xffffffff, DPL_USER);
	gdt[SEG_KSTAK] = SEG(STA_W,         0,       0xffffffff, DPL_KERN);
	gdt[SEG_UDATA] = SEG(STA_W,         0,       0xffffffff, DPL_USER);
	gdt[SEG_TSS] = SEG16(STS_T32A,   &tss,    sizeof(TSS)-1, DPL_KERN);
	gdt[SEG_TSS].s = 0;
	gdt[SEG_VIDEO] = SEG(STA_W,  0x0b8000,       0xffffffff, DPL_KERN);
	setGdt(gdt, sizeof(gdt));

//	tss.esp0 = 0x200000;   
	tss.ss0  = KSEL(SEG_KDATA);
	tss.esp0 = (uint32_t)&pcb[0].state;//&pcb[0].stack[MAX_STACK_SIZE];

	asm volatile("ltr %%ax":: "a" (KSEL(SEG_TSS)));

	/*设置正确的段寄存器*/
	asm volatile("mov %%ax, %%ds"::"a"(KSEL(SEG_KDATA)));
	asm volatile("mov %%ax, %%es"::"a"(KSEL(SEG_KDATA)));
	asm volatile("mov %%ax, %%ss"::"a"(KSEL(SEG_KDATA)));
	asm volatile("mov %%ax, %%gs"::"a"(KSEL(SEG_VIDEO)));

	lLdt(0);

}

void enterUserSpace(uint32_t entry) {
	/*
	 * Before enter user space
	 * you should set the right segment registers here
	 * and use 'iret' to jump to ring3
	 */
	asm volatile("pushl %0"::"r"(USEL(SEG_UDATA)));	//ss
	asm volatile("pushl %0"::"r"(128<<20));		//esp
	asm volatile("pushfl");				//eflags
	asm volatile("pushl %0"::"r"(USEL(SEG_UCODE)));	//cs
	asm volatile("pushl %0"::"r"(entry));		//eip
	asm volatile("iret");

}

void loadUMain(void) {

	char *buf = (char*)0x8000;
	struct ELFHeader *elf = (void*)buf;;
	struct ProgramHeader *ph, *eph;
	
	for (int i = 0; i < 100; i ++) {
		readSect((void*)(buf + i*SECTSIZE), i + 201);
	}
	//readSect(buf, 201);
	ph = (void*)buf + elf->phoff;
	eph = ph + elf->phnum;
	for(;ph < eph; ph++) {
		if (ph->type == 1) {
			unsigned int p = ph->off;
			unsigned int q = ph->vaddr; 
			for(int j=0; j<ph->filesz;j++) {
				*(char*)(q+j) = *(char*)(buf+p+j);
			}
			for(int k=0; k<ph->memsz-ph->filesz;k++) {
				*(char*)(q+ph->filesz+k) = 0;
			}			
		}
		ph++;
	}
    	struct ProcessTable *p = pcb_free, *q = pcb_head;

    	pcb_free = pcb_free->next;
    	p->next = NULL;
    	p->sleepTime = 0;
    	p->timeCount = 10;
    	p->pid = p-current;
    	p->state = RUNNABLE;
    
    	if (pcb_head == NULL) {
        	pcb_head = p;
    	} 
    	else {
		for(; q->next; q = q->next);
		q->next = p;
    	}
    	current = p;//child

    	asm volatile("movl %0, %%eax" ::"r"(USEL(SEG_UDATA)));
    	asm volatile("movw %ax, %ds");

    	p->tf.ss = USEL(SEG_UDATA);
    	p->tf.esp = 0x220000;
    	p->tf.cs = USEL(SEG_UCODE);
    	p->tf.eip = elf->entry;
    	asm volatile("movl %0, %%esp" ::"r"(&p->tf.eip));
    	asm volatile("iret");
    	enterUserSpace(elf->entry);
}
