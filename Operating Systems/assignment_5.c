#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

int global = 0;

void* myThread(void* args) {
    int *id = (int *)args;
    static int stat = 0;
    int local = 0;

    printf("Thread ID: %d, Static: %d, Global: %d, Local: %d\n", *id, ++stat, ++global, ++local);
}

int main() {
    pthread_t thread1, thread2, thread3;

    pthread_create(&thread1, NULL, myThread, &thread1);
    pthread_create(&thread2, NULL, myThread, &thread2);
    pthread_create(&thread3, NULL, myThread, &thread3);

    pthread_exit(NULL);
    return 0;
}