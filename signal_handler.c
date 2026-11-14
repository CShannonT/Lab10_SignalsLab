/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: C. Shannon Terry
 * Date: 11/12/2026
 * 
 * Brief summary of modifications: Changed the handle_signal method
 * to not exit the program, and added an int argument to make sure 
 * the code compiles.
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal(int number) {
    printf("Received a signal.\n");
}

int main() {
    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}