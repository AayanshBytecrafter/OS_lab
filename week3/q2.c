// write a  c program to wait for specific child

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
    pid_t pid1, pid2;
    pid1 = fork();
    if(pid1 < 0)
    {
        printf("Fork Failed");
        return -1;
    }
    else if(pid1 == 0)
    {
        printf("Child1 pid is %d\n", getpid());
        printf("Child1 sleeping for 3 sec\n");
        sleep(3);
        printf("Child 1 is done\n");
        _exit(0);
    }

    pid2 = fork();
    if(pid2 < 0)
    {
        printf("fork failed !");
        return -1;
    }
    else if(pid2 == 0)
    {
        printf("Child 2 pid is %d\n", getpid());
        printf("Child 2 is sleeping for 4 sec\n");
        sleep(4);
        printf("Child 2 is done\n");
        _exit(0);
    }

    printf("Parent is waiting for child 1 with pid as %d\n", pid1);
    waitpid(pid1, NULL, 0);

    printf("Waiting for child 1 is done\n");

    printf("Waiting for child 2 with pid as %d\n", pid2);
    waitpid(pid2, NULL, 0);
    printf("Waiting for child 2 is done");
    return 0;
}