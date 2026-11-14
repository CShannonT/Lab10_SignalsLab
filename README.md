# Lab10_SignalsLab
A set of 5 programs that test and demonstrate various POSIX signals in C, alongside custom handlers
and how to use them with these signals to create custom behavior.
<br>
**Programs**
> **sighander** - Demonstrates a signal handler that overwrites SIGINT, also
> known as the signal that handles CTRL + C in the terminal. Instead of interrupting
> execution, the signal is repurposed to print a message.
> <br>
> **sigalarm** - Shows off an alarm using the alarm() method, and how it can be used alongside
> a signal handler to send messages and signals at specific times.
> <br>
> **sigsegfault** - This program will intentionally cause a segmentation fault error and handle it
> with a custom handler, demonstrating that the error will still go through.
> <br>
> **sendsig** - Requires a command line argument, the PID of the process to recieve this signal.
> This program uses sigaction() to send a custom signal containing a randomly-generated integer
> in order to be recieved by the final program in this set.
> <br>
> **recvSig** - Prints the PID of this process for use with the sendsig program, and proceeds to wait
> for a signal to be recieved. When the signal from sendsig is recieved, it will print the random integer
> and continue to wait. This program must be stopped by sending it a SIGINT through some other method.