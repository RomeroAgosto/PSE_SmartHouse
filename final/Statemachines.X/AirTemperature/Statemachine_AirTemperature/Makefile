
.PHONY: clean


example: main.c statemachine_airtemp_control.o
	gcc -o $@ $^

run: example
	- ./example

clean:
	rm -f *.o
	rm -f example
	rm -rf doc/*
	rm -f *~
