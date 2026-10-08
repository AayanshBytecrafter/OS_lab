//Write a program in which the child prints numbers from 1 to 5 and 
// the parent waits for it using wait().

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
        printf("Child process printing ");
        for(int i = 1; i<=5; i++)
        {
            printf("%d", i);
        }
    }
    else{
        wait(NULL);
        printf("\nParent waited for child to finish");
    }
    return 0;
}