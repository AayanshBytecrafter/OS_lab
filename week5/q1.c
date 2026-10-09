// write a c program to create a txt file in parent process and read in child process
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    pid_t pid = fork();
    if(pid == 0)
    {
        fp = fopen("input.txt", "r");
        char ch;
        while((ch = fgetc(fp)) != EOF)
        {
            printf("%c", ch);
        }
        fclose(fp);
    }
    else{
        fp = fopen("input.txt", "w");
        fprintf(fp, "Name : Aayansh Chaudhary\n");
        fprintf(fp, "Class : IOS\n");
        fprintf(fp, "ROll no : 2025012\n");
        fclose(fp);
    }
    return 0;
}