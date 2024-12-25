/**
 * !Create a simple C program that has a parent and a child process and parent signals the other process via pipe()
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 50

int main()
{
    int pd[2];
    char buffer[BUFFER_SIZE];
    pid_t child;

    if (pipe(pd) < 0)
    {
        perror("creating pipe");
        exit(1);
    } 
    if ((child = fork()) < 0)
    {
        perror("cannot fork");
        exit(1);
    }

    if (child == 0) // Child process
    {
        close(pd[1]); // Close write end
        read(pd[0], buffer, BUFFER_SIZE);
        printf("Child received: %s\n", buffer);
        close(pd[0]); // Close read end
    }
    else // Parent process
    {
        close(pd[0]); // Close read end
        sprintf(buffer, "Ηello from Parent with PID: %d!", getpid());
        write(pd[1], buffer, strlen(buffer) + 1);
        close(pd[1]); // Close write end
        wait(NULL);   // Wait for child to finish
    }

    return 0;
}
