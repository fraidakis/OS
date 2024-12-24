#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void custom_sigint_handler(int sig) {
    int static sigint_count=0;
    sigint_count++;

    printf("Caught signal %d (SIGINT)!\n", sig);

    if (sigint_count >= 2) {
        printf("Restoring default SIGINT behavior...\n");
        signal(SIGINT, SIG_DFL); // Restore default behavior
    }
}

int main() {
    // Register the custom signal handler for SIGINT
    signal(SIGINT, custom_sigint_handler);

    printf("Press Ctrl+C to send SIGINT...\n");
    while (1) {
        // Infinite loop to keep the program running
    }
    return 0;
}
