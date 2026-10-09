#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid1, pid2, pid3;

    pid1 = fork();
    if (pid1 < 0) { printf("Fork Failed\n"); return -1; }
    else if (pid1 == 0)
    {
        printf("Child 1 pid -> %d\n", getpid());
        sleep(2);
        printf("Child 1 is done\n");
        _exit(0);
    }

    pid2 = fork();
    if (pid2 < 0) { printf("Fork Failed\n"); return -1; }
    else if (pid2 == 0)
    {
        printf("Child 2 pid -> %d\n", getpid());
        sleep(4);
        printf("Child 2 is done\n");
        _exit(0);
    }
    
    pid3 = fork();
    if (pid3 < 0) { printf("Fork Failed\n"); return -1; }
    else if (pid3 == 0)
    {
        printf("Child 3 pid -> %d\n", getpid());
        sleep(6);
        printf("Child 3 is done\n");
        _exit(0);
    }

    printf("Parent waiting for child 3 (PID: %d)...\n", pid3);
    waitpid(pid3, NULL, 0);
    printf("Finished waiting for child 3.\n\n");

    printf("Parent waiting for child 1 (PID: %d)...\n", pid1);
    waitpid(pid1, NULL, 0);
    printf("Finished waiting for child 1.\n\n");

    printf("Parent waiting for child 2 (PID: %d)...\n", pid2);
    waitpid(pid2, NULL, 0);
    printf("Finished waiting for child 2.\n");

    return 0;
}