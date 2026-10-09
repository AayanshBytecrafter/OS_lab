// Create three children with sleep durations of 2, 4 and 6 seconds. Parent should use
// wait() to determine the order in which children terminate.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    pid_t pid1, pid2, pid3;

    pid1 = fork();
    if(pid1 == 0)
    {
        printf("Child 1 pid -> %d\n", getpid());
        sleep(2);
        printf("Child 1 is done\n");
        _exit(0);
    }

    pid2 = fork();
    if(pid2 == 0)
    {
        printf("Child 2 pid -> %d\n", getpid());
        sleep(4);
        printf("Child 2 is done\n");
        _exit(0);
    }
    
    pid3 = fork();
    if(pid3 == 0)
    {
        printf("Child 3 pid -> %d\n", getpid());
        sleep(6);
        printf("Child 3 is done\n");
        _exit(0);
    }
    printf("Parent process waiting\n");
    wait(NULL);
    printf("Parent process waiting\n");
    wait(NULL);
    printf("Parent process waiting\n");
    wait(NULL);
    return 0;
}