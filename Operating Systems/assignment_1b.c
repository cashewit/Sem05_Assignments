/*
Implement the fork() system call and print the parent and child ID in C.
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main() {
    int pid = fork();

    printf("Process Id: %d\n", pid);
}