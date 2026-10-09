// use fork and take input from user and print it on console

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd[2];
    char buffer[100];
    pid_t pid;

    if(pipe(fd) == -1)
    {
        printf("Some error");
        return -1;
    }
    pid = fork();
    if(pid < 0)
    {
        printf("Some error");
        return -1;
    }
    else if(pid == 0)
    {
        close(fd[0]);

        char message[100];
        printf("Enter message in child for parent");
        fgets(message, sizeof(message), stdin);

        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    }
    else{
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf(" Parent received %s", buffer);
        close(fd[0]);
    }
    return 0;
}