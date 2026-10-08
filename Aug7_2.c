// to print febonacci upto n numbers in child and check if that number
// is armstrong or not?
#include<unistd.h>
#include<sys/wait.h>
#include<math.h>
#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    pid_t pid = fork();

    if(pid < 0)
    {
        printf("Fork Failed!");
        return -1;
    }
    else if(pid == 0)
    {
        // child process
        int a = 0, b = 1;
        for(int i = 0; i<n; i++)
        {
            printf("%d", a);
            int c = a + b;
            a = b;
            b = c;
        }
        
    }
    else{
        int nd = 0; // number of digits
        int check = n;
        while(check != 0)
        {
            nd++;
            check /= 10;
        }
        check = n;
        int dig = 0;
        int ans = 0;
        while(check != 0)
        {
            dig = check % 10;
            ans = ans + pow(dig, nd);
            check = check / 10;
        }
        if(ans == n){
            printf("The given number is an armstrong number\n");
        }
        else printf("Number is not a armstrong number");
    }
    return 0;
}
