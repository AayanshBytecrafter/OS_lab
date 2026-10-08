// Create three child processes. Each child must print 
// its PID, PPID, and child number.

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    for(int i = 1; i<= 3; i++)
    {
        pid_t pid = fork();
        if(pid < 0)
        {
            printf("Fork Failed");
            return -1;
        }
        else if(pid == 0)
        {
            printf("Child number is -> %d, Child PID is -> %d\n,  Child PPID is -> %d\n", i, getpid(), getppid());
            _exit(0); // to terminate immediately with status 0
        }
    }   

    for(int i = 0; i<3; i++)
    {
        wait(NULL);
    }

}