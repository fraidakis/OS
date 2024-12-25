/**
 * !Create a simple C program that forks 3 times and each fork() prints its PID
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    pid_t parent = getpid();

    fork(); // Executed 1 time
    fork(); // Executed 2 times (from parent and first fork)

    if (getpid() != parent)
        printf("Child Process: PID = %d\n", getpid());
    else
        wait(NULL); // Wait for all child processes to finish

    return 0;
}
