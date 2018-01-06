
.PHONY: clean


example: main.c send_receive_messages.o
	gcc -o $@ $^

run: example
	- ./example

clean:
	rm -f *.o
	rm -f example
	rm -rf doc/*
	rm -f *~
