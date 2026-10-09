// basic implementation of pipe()

#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int fd[2];
    pid_t pid;
    char message[] = "Hello from child";
    char buffer[100];

    if(pipe(fd) == -1)
    {
        printf("error");
        return -1;
    }
    pid = fork();
    if(pid < 0)
    {
        printf("Error");
        return -1;
    }
    else if(pid == 0){
        close(fd[0]);
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    }
    else{
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Parent received %s\n", buffer);
        close(fd[0]);
    }
    return 0;
}