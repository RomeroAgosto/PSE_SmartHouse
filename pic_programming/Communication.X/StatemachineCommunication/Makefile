
SRC=main.c create_normal_message.c send_receive_messages.c send_receive_messages.h create_normal_message.h
PROG=primo



$(PROG):
	gcc $(SRC) -o $(PROG)

doc: Doxyfile
	doxygen

Doxyfile: 
	doxygen -g

all: $(PROG) doc

clean:
	rm -rf primo html latex Doxyfile
