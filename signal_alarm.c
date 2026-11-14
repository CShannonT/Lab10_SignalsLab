/**
 * Filename: signal_alarm.c
 * Description: Sets up a signal handler, and then schedules and
 * sends an alarm to this process. The alarm is sent after 5 seconds.
 * After the alarm is recieved, the program exits manually.
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

//Custom alarm method, exits on reciept.
void handle_signal(int number) {
    printf("Received the alarm.\n");
    exit(0);
}

int main() {
    //Assign signal handler.
    signal(SIGALRM, handle_signal);
    unsigned int alarmSet = alarm(5);
    if (alarmSet == -1) {
        //Ensure the alarm properly set.
        printf("Alarm didn't set.\n");
        exit(1);
    }
    //Wait for alarm.
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}

