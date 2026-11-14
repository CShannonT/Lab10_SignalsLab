/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: C. Shannon Terry
 * 
 * Brief summary of modifications: Added a signal handler for SIGSEGV to test
 * behavior when manually handling the error.
 */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

//Custom handler.
void handle_signal(int number) {
    printf("Segmentation fault occurred, returning to operation.\n");
}

int main (int argc, char* argv[]) {
    //Assign handler.
    signal(SIGSEGV, handle_signal);
    
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}