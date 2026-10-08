// Write a program in which the parent prints even numbers from 
// 1 to 20 and the child prints odd numbers

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
        printf("\nChoild Process\n");
        for(int i =0; i<=20; i++)
        {
            if(i % 2 != 0)
            {
                printf("%d", i);
            }
        }
    }
    else{
        wait(NULL);
        printf("\nParent Process\n");
        for(int i = 0; i<= 20; i++)
        {
            if(i % 2 == 0)
            {
                printf("%d", i);
            }
        }
    }
    return 0;
}