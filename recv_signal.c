/**
 * Filename: recv_signal.c
 * Description: Recieves a signal from the send_signal and
 * prints the sival_int.
 * Author: C. Shannon Terry
 * Section: 131
 * Assignment: Lab 10 - Signals
 * Date: 11/11/2026
 */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void handler(int sig, siginfo_t *info, void *context) {
    (void)context; //We won't be using context here, so we'll nullify it.
    printf("Signal %d recieved by reciever\n", sig); //Debug.
    int printint = info->si_value.sival_int; 
    //Get the sent integer from the si_value of info.
    printf("The recieved integer was %d\n", printint);
}

void onExitHandling(void) {
    exit(0);
}

int main(void) {
    //Set up exit code to help with a strange memory leak.
    int exitCode = atexit(onExitHandling);
    if (exitCode != 0) {
        perror("Exit behavior failed to initialize.\n");
        exit(EXIT_FAILURE);
    }
    struct sigaction signalact;
    signalact.sa_sigaction = handler; //Assign handler method (VOID POINTER!)
    //Ensures signals are nulled.
    int didSigEmptySet = sigemptyset(&signalact.sa_mask);
    if (didSigEmptySet == -1) {
        //Ensure that everything intializes properly.
        perror("Signal empty set did not set.\n");
        exit(EXIT_FAILURE);
    }
    signalact.sa_flags = SA_SIGINFO; //Enables three arg handler.
    //Set the handler for this obsucre signal. Its nice to keep the other
    //important signals available.
    if (sigaction(SIGRTMIN, &signalact, NULL) == -1) { 
        perror("Sigaction failed to properly set.\n");
        exit(EXIT_FAILURE);
    }
    pid_t pid = getpid();
    printf("PID of this reciever: %d\n", pid);
    //Enter loop to wait for signal.
    while (1) {
        //printf("Waiting.\n"); //Debug only.
    }
    return 0;
}