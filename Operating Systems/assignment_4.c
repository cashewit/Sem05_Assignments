// Creating threads in fork calls.
// Shows that pthread variables created in fork calls have the same thread id.

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 
#include<sys/wait.h>
 
void *myThread1(void *vargp) 
{ 
   int *myid = (int *)vargp;
    printf("Thread 1 ID: %d\n", *myid); 
 
} 
 
void *myThread2(void *vargp) 
{ 
   int *myid = (int *)vargp;
    printf("Thread 2 ID: %d\n", *myid); 
 
} 
 
int main() 
{
    pthread_t thread_1;  
    pthread_t thread_2;

    printf("Start of Process\n");
    int pid = fork();

    pthread_create(&thread_1, NULL, myThread1, (void *)&thread_1);
    pthread_join(thread_1, NULL); 
 
    if(pid==0)
    {
        printf(" In child process \n");   
         
        printf("pid=%d ,parent=%d\n",getpid(),getppid());
        pthread_create(&thread_2, NULL, myThread2, (void *)&thread_2);
        pthread_join(thread_2, NULL); 
    }
    else{
        wait(NULL);
        printf(" In Parent process\n");
        printf("pid=%d ,parent=%d\n",getpid(),getppid());
     
        pthread_create(&thread_2, NULL, myThread2, (void *)&thread_2);
        pthread_join(thread_2, NULL); 	
 
   }
 
}
