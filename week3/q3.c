// Create two child processes. Parent should execute two wait() calls 
// and print the PID of each child as it terminates.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    pid_t pid1, pid2;
    pid1 = fork();
    if(pid1 < 0)
    {
        printf("Fork Failed");
        return -1;
    }
    else if(pid1 == 0)
    {
        printf("Child 1 pid is %d\n", getpid());
        sleep(3);
        printf("Child 1 is done");
        _exit(0);
    }

    pid2 = fork();
    if(pid2 < 0)
    {
        printf("Fork Failed");
        return -1;
    }
    else if(pid2 == 0)
    {
        printf("Child 2 pid is %d\n", getpid());
        sleep(3);
        printf("Child 2 is done");
        _exit(0);
    }

    printf("Parent waiting for child1");
    int term1 = wait(NULL);
    printf("Pid for wait of child 1 is %d\n", term1);

    printf("parent waiting for child 2");
    int term2 = wait(NULL);
    printf("Pid for wait of child 2 is %d\n", term2);

    return 0;
}