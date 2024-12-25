/**
 * !Creates a simple C program has a parent and a child process and both write their PID to the same file.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    FILE *file = fopen("pids.txt", "w");

    pid_t child;

    if ((child = fork()) < 0)
    {
        perror("cannot fork");
        exit(1);
    }

    if (child == 0) // Child process
    { 
        fprintf(file, "Child PID: %d\n", getpid());
    }
    
    else // Parent process
    { 
        fprintf(file, "Parent PID: %d\n", getpid());
        wait(NULL); // Wait for child
    }

    fclose(file);
    return 0;
}
