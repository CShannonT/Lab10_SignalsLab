CFLAGS=-c -g -Wall -Werror
CC=gcc

all: sighandler sigsegfault sigalarm sendsig recvsig

sighandler: signal_handler.o
	$(CC) -o sighandler signal_handler.o

sigsegfault: signal_segfault.o
	$(CC) -o sigsegfault signal_segfault.o

sigalarm: signal_alarm.o
	$(CC) -o sigalarm signal_alarm.o

sendsig: send_signal.o
	$(CC) -o sendsig send_signal.o

recvsig: recv_signal.o
	$(CC) -o recvsig recv_signal.o

clean:
	rm -f *.o sighandler sigsegfault sendsig recvsig

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

