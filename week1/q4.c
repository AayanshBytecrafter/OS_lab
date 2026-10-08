// to demonstrate Orphan process
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    int pid = fork();
    if(pid == 0)
    {
        printf("\nChild pid is %d, and parent pid is %d", getpid(), getppid());
        sleep(3);
        printf("\nChild pid is %d, and parent pid is %d", getpid(), getppid());
        
    }
    else{
        
        printf("parent Exiting .....\n");
        return 0;
    }
    return 0;
}