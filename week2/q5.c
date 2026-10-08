// Write a program using fork(), exec(), and wait() to execute the date command.

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
        printf("Child executing");
        execlp("date", "date", NULL);
// execlp will not return if it does it means some error
        printf("Some error has occured");
        _exit(1);
    }
    else {
        printf("Parent is waiting for the child to finish\n");
        wait(NULL);
        printf("The child has done its execution");
    }
    return 0;
}