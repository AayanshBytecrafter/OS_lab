//process calcualte factoial of a number in the parent process.
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int n;
    scanf("%d", &n);
    pid_t pid = fork();
    if(pid < 0)
    {
        printf("Fork Failed");
        return -1;
    }
    else if(pid == 0)
    {
        int prime = 1;
        for(int i= 2; i<n; i++)
        {
            if(n % i == 0){
                prime = 0;
                break;
            }
        }
        if(prime == 0)
        {
            printf("Not a prime number");
        }
        else printf("Yes its a prime number");
        
    }
    else{
        wait(NULL); // wait for child process to finish
        int fact = 1;
        for(int i=  1; i<=n; i++)
        {
            fact *= i;
        }
        printf("Factorial of number is %d\n", fact);

    }
    return 0;
}