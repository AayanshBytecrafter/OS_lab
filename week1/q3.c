// to demonstrate zombie process
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int pid = fork();
    if(pid == 0)
    {
        printf("Child process is exiting");
        return 0;
    }
    else{
        printf("parent is sleeping");
        sleep(30);
    }
    return 0;
}