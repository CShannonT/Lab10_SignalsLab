/**
 * Filename: send_signal.c
 * Description: Sends a random integer for recv_signal to
 * recieve and print properly.
 * Author: C. Shannon Terry
 * Section: 131
 * Assignment: Lab 10 - Signals
 * Date: 11/11/2026
 */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

#define MAXIDLENGTH 10 //Far larger than any PID I've seen. 
//It'll fit any integer process easily.

int main(int argc, char* argv[]) {
    if (argc > 1) {
        srand(time(NULL)); //Get a random seed using the time.
        int randomInt = rand();
        char *pidString = malloc(sizeof(char)*MAXIDLENGTH);
        strncpy(pidString, argv[1], MAXIDLENGTH);
        pid_t pid = atoi(pidString);
        if (pid == 0) {
            /*Error check. Technically PID 0 can exist but its definitely
            not the process here, and also happens to be the atoi fail code.*/
            perror("ATOI of command line argument failed. Please enter a real pid.\n");
            free(pidString);
            exit(EXIT_FAILURE);
        }
        
        printf("The value being sent is %d.\n", randomInt);
        union sigval dataToSend; //Need to initalize the union to send the data through.
        dataToSend.sival_int = randomInt;
        /*The middle arg helps send the data at low priority. Best signal type
        I could find that wasn't error related without defining my own. This 
        works just fine.*/
        int didsigqueueWork = sigqueue(pid, SIGRTMIN, dataToSend);
        if (didsigqueueWork == -1) {
            //Ensure signal sends and free memory to prevent leaks.
            perror("Sigqueue failed to properly run.");
            free(pidString);
            exit(EXIT_FAILURE);
        }
        //Free the string from earlier.
        free(pidString);
        printf("Sender is done sending data.\n");
    } else {
        perror("Must specifiy the pid of the recieving program as a command line argument.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

