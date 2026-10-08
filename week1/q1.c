// to identify parent and child process
#include<unistd.h>
#include<stdio.h>

int main()
{
    int pid = fork();
    if(pid < 0)
    {
        printf("Fork Failed");
        return -1;
    }
    else if(pid == 0)
    {
        // child process
        printf("Child Process\n");
        printf("Child PID is %d\n", getpid());
        printf("Parent PID is %d\n", getppid());
    }
    else {
        printf("Parent Process\n");
        printf("Parent Pid is %d\n", getpid());
        printf("Child PID is %d\n", pid);
    }
    return 0;
}