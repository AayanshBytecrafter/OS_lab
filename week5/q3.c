// to find sum of array in child and check that sum is prime or not
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    int fd[2];
    int sum = 0;
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    pid_t pid;

    if(pipe(fd) == -1)
    {
        printf("Some error occured");
        return -1;
    }
    pid = fork();
    if(pid == 0)
    {
        for(int i = 0; i<n; i++)
        {
            sum += arr[i];
        }
        close(fd[0]);
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
        _exit(0);
    }
    else{
        wait(NULL);
        close(fd[1]);
        int received;
        read(fd[0], &received, sizeof(received));
        close(fd[0]);
        printf("The number received in parent is %d\n", received);
        int prime = 1;
        for(int i = 2; i< received; i++)
        {
            if(received % i == 0)
            {
                prime = 0;
                break;
            }
        }
        
        if(prime == 0)
        {
            printf("NO the number is not a prime number");
        }
        else {
            printf("Yes the number is prime");
        }
    }
    return 0;
}