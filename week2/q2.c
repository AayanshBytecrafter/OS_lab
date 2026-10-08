//Modify the single-fork() program to print the value returned by fork() in both
// processes.

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main() {
    pid_t pid;
    
    pid = fork();

  
    if (pid < 0) {
        printf("Fork Failed!\n");
        return -1;
    }
    else if (pid == 0) {

        printf("CHILD fork() returned: %d\n", pid);
        printf("CHILD Process ID (PID) is: %d\n", getpid());
        printf("CHILD Parent's PID is: %d\n\n", getppid());
    }
    else {
    
        printf("PARENT fork() returned: %d\n", pid);
        printf("PARENT My Process ID (PID) is: %d\n", getpid());
        printf("PARENT The Child's PID is: %d\n\n", pid);
        
        // Parent waits for the child to finish
        wait(NULL);
    }

    return 0;
}