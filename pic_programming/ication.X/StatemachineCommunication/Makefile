
.PHONY: clean

SRC=main.c send_receive_messages.c send_receive_messages.h

#O binário executável (nome do programa)
PROG=example

################################

CC=gcc
CFLAGS=-Wall # - wall -> show all warnings

OBJ=$(SRC:.c=.o) 

$(PROG): $(OBJ) 
	gcc -o $@ $^
# for each c file generate an o file, 




run: example
	- ./example

clean:
	rm -f *.o
	rm -f example
	rm -rf doc/*
	rm -f *~


