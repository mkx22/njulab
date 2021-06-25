#include "x86.h"
#include "device.h"
//extern SegDesc gdt[NR_SEGMENTS];

int row = 0, col = 0;

void schedule();

void syscallHandle(struct TrapFrame *tf);

void timerHandle();

void GProtectFaultHandle(struct TrapFrame *tf);

void putchar(char c);

void irqHandle(struct TrapFrame *tf) {
    /*
     * 中断处理程序
     */

    /* Reassign segment register */
	asm volatile("mov %%ax, %%ds"::"a"(KSEL(SEG_KDATA)));
	asm volatile("mov %%ax, %%es"::"a"(KSEL(SEG_KDATA)));
	asm volatile("mov %%ax, %%ss"::"a"(KSEL(SEG_KDATA)));
	asm volatile("mov %%ax, %%gs"::"a"(KSEL(SEG_VIDEO)));

    switch (tf->irq) {
        case -1:
            break;
        case 0xd:
            GProtectFaultHandle(tf);
            break;
        case 0x20:
            timerHandle();
            break;
        case 0x80:
            syscallHandle(tf);
            break;
        default:
            assert(0);
    }

}

void sys_exit(struct TrapFrame *tf) {
	current->state = DEAD;
	schedule();
}

void sys_fork(struct TrapFrame *tf) {
	struct ProcessTable * p = pcb_free;
	struct ProcessTable * q = pcb_head;

    	if (pcb_head == NULL) 
        	pcb_head = p;
	else {
		for(; q->next; q = q->next);
		q->next = p;
	}

    	unsigned int pp = 0x200000 + (current-pcb) * PROC_MEMSZ;
    	unsigned int qq = 0x200000 + (p-pcb) * PROC_MEMSZ;
    	for (int i = 0; i < 0x100000; i++) {
    	    *((char*)qq+i) = *((char*)pp+i);
    	}

    	for (int i = 0; i < MAX_STACK_SIZE; i++) {
    	    p->stack[i] = current->stack[i];
    	}
  	p->state = RUNNABLE;
	p->tf.eax = 0;             
	tf->eax = p->pid;
	schedule();
}

void sys_sleep(struct TrapFrame *tf) {
    	current->state = BLOCKED;
    	current->sleepTime = tf->ebx;
    	schedule();
}

size_t fs_write(int fd, void *buf, size_t len) {
	assert(fd <= 2);
	int i = 0;
	//int p = 5*80;
	extern void putChar(char);
	for(i = 0; i < len; i++) {
		char c = ((char*)buf)[i];
		if(c == '\0')
			break;
		putChar(c);
		putchar(c);
	}
	return len;
}

void sys_write(struct TrapFrame *tf) {
    	tf->ecx += ((current - pcb) * PROC_MEMSZ);//res
	tf->eax = fs_write(tf->ebx, (void*)tf->ecx, tf->edx);
}

void sys_sem_init(struct TrapFrame *tf) {
    	int i = 0;
	for(;i<MAX_SEM_NUM;i++){
		if(!semaphore[i].value){
    		semaphore[i].value = tf->ecx;//value
			break;
		}
	}
	if(i==MAX_SEM_NUM)
    		tf->eax = -1;
	else
		tf->eax = 0;
}

//post
size_t V(sem_t s){
	semaphore[s].value++;
    	if (semaphore[s].value <= 0) {
		//int i = 0;		
		//for(; i < MAX_SEM_NUM-1; i++)
		//	semaphore[i].pid = semaphore[i+1].pid;
        	pcb[semaphore[s].pid].state = RUNNABLE;
        	current->state = RUNNABLE;
        	schedule();
		return 0;
    	}
	return -1;
}

void sys_sem_post(struct TrapFrame *tf) {//V
    	sem_t s = *(sem_t*)tf->ebx;
 	tf->eax = V(s);
}

//wait
size_t P(sem_t s){
	semaphore[s].value--;
	if (semaphore[s].value < 0) {
        	semaphore[s].pid = current-pcb;
        	pcb[current-pcb].state = BLOCKED;
        	current->state = BLOCKED;
        	schedule();
		return 0;	
	}
	return -1;
}

void sys_sem_wait(struct TrapFrame *tf) {//P
    	sem_t s = *(sem_t*)tf->ebx;
    	tf->eax = P(s);
}

void sys_sem_destroy(struct TrapFrame *tf) {
    	sem_t *sem = (sem_t*)tf->ebx;
	if(semaphore[(int)sem].value == 0)
		tf->eax = -1;
	else
		tf->eax = 0;
	semaphore[(int)sem].value = 0;
	//semaphore[(int)sem].next = NULL;  
}

void syscallHandle(struct TrapFrame *tf) {
    	/* 实现系统调用*/
    	switch (tf->eax) {
		case 4: sys_write(tf); break;
		case 1: sys_exit(tf); break;
		case 2: sys_fork(tf); break;
		case 100: sys_sleep(tf); break;
		case 5: sys_sem_init(tf); break;
		case 6: sys_sem_post(tf); break;
	    	case 7: sys_sem_wait(tf); break;
	    	case 8: sys_sem_destroy(tf); break;
        	default:break;    
	}
}

void timerHandle() {
    	struct ProcessTable *p = NULL;

	for(p = pcb_head; p; p = p->next) {
        	if (p->state == BLOCKED) {
            		p->sleepTime--;
            		if (p->sleepTime == 0) {
            			p->state = RUNNABLE;
				if(current-pcb < 0)
					schedule();
            		}
        	}
    	}

	if (current && current->timeCount == 1) {
    		current->state = RUNNABLE;
    	    	schedule();
    	}
}

void GProtectFaultHandle(struct TrapFrame *tf) {
    	assert(0);
    	return;
}

void putchar(char c){
	if(c == '\n'){
		row++;
		col = 0;
	}
	else {
		short *p = (short *)(0xB8000 + (row*80+col)*2);	
		*p = (0x0c<<8) + c;
		col++;
		if(col == 80) {
			row++;
			col = 0;
		}
	}
}


