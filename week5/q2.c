// use fork and pipe to send the number from parent to child
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    int fd[2];
    int num = 34;
    pid_t pid;

    if(pipe(fd) == -1)
    {
        perror("Error");
        return -1;
    }
    pid = fork();
    if(pid == 0)
    {
        int received = 0;
        close(fd[1]);
        read(fd[0], &received, sizeof(received));
        printf("Child received %d\n", received);
        close(fd[0]);
    }
    else{
        close(fd[0]);
        write(fd[1], &num, sizeof(num));
        printf("Parent sent %d\n", num);
        close(fd[1]);
    }
}