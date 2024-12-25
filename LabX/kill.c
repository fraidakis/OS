/**
 * !Create a simple C program that has a parent and a child process and parent signals the other process via pipe()
 * *(Modification of Lab's 4 example5.c)
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

// Signal handler for SIGUSR1 in child
void sigusr1_handler(int sig)
{
    printf("Child received SIGUSR1 (signal %d).\n", sig);
}

int main()
{
    pid_t child;

    child = fork();

    if (child == -1)
    { // Error
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child == 0) // Child process
    {
        if (signal(SIGUSR1, sigusr1_handler) == SIG_ERR) // Register signal handler for SIGUSR1
        {
            perror("signal");
            exit(EXIT_FAILURE);
        }

        else
            printf("Child process waiting for SIGUSR1...\n");

        pause();
    }

    else // Parent process
    {
        sleep(2); // Sleep for 2 seconds before sending SIGUSR1 to give child time to setup signal handler

        printf("Parent sending SIGUSR1 to child.\n");
        if (kill(child, SIGUSR1) == -1)
        {
            perror("kill");
            exit(EXIT_FAILURE);
        }

        wait(NULL); // Wait for the child process to terminate
    }

    return 0;
}
