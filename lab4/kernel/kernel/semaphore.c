#include "device.h"
#include "x86.h"

void init_sem() {
    for (int i = 0; i < MAX_SEM_NUM; i++) {
        semaphore[i].value = 0;
    }
}

