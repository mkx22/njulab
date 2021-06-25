#ifndef __lib_h__
#define __lib_h__
typedef int sem_t;

void printf(const char *format, ...);
int fork();
int sleep(int time);
int exit();
int sem_init(sem_t *sem, unsigned int value);
int sem_post(sem_t *sem);
int sem_wait(sem_t *sem);
int sem_destroy(sem_t *sem);

#endif
