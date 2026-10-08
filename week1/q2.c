    #include<stdio.h>
    #include<unistd.h>
    #include<sys/wait.h>
    #include<stdlib.h>

    int main()
    {
        int pid = fork();
        if(pid < 0)
        {
            printf("Fork Failed");
            return -1;
        }
        else if(pid == 0)
        {
            printf("Child exited with status 7\n");
            exit(7);
        }
        else{
            int status;
            wait(&status);
            printf("Parent Process\n");
            printf("Exit status of child was %d\n", WEXITSTATUS(status));
        }
        return 0;
    }