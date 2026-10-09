// C Program: Displaying the PID Returned by wait()
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        printf("Fork Failed");
        return -1;
    }
    else if(pid == 0)
    {
        printf("Child pid is %d\n", getpid());
        sleep(3);
        _exit(0);
    }
    else{
        printf("parent's child pid is %d\n", pid);
        int status;
        pid_t term_child = wait(&status);
        if(term_child > 0)
        {
            printf("The pid returned by wait is %d\n", term_child);
        }
        else printf("Wait() failed due to some error");
    }
    return 0;
}