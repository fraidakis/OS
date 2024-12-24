/**
 * Modification of Lab4's signal handling example to catch SIGINT signal (example3.c).
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGINT
void sigint_handler() {
    printf("\nSIGINT signal caught!\n");
    exit(0); //Gracefully terminate
}

int main() {
    // Register the SIGINT handler
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    printf("Press Ctrl+C to trigger SIGINT.\n");

    // Infinite loop to keep the program running
    while (1) {
        printf("Running... Press Ctrl+C to exit.\n");
        sleep(2);
    }

    return 0;
}
