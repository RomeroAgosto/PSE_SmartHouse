# Makefile for creating and running unit tests, using CppUTest
#
# The modules to be tested are located in $(PROG_LOCATION). 

# Adapt the following lines to your own environment:
# - Location of CppUTest 
#CPPUTEST_HOME = /trabalho/Aulas/PSE/Software/CppUTest/cpputest-3.6
CPPUTEST_HOME =/home/ppedreiras/Software/cpputest-3.8

# - Location of main program files
PROG_LOCATION_COMMUNICATION=../StatemachineCommunication


CXXFLAGS += -I$(CPPUTEST_HOME)/include-I$(PROG_LOCATION_COMMUNICATION)

# The following is required in Red Hat based systems (Fedora, CentOS) to
# solve "fatal error: bits/c++config.h: No such file or directory"
#
# CXXFLAGS in this example applies to Fedora 20 Heisenbug. Other 
# distros may place c++config.h in a different path. You will have to 
# adapt if necessary. 
CXXFLAGS += -I/usr/include/c++/4.8.3/i686-redhat-linux

# If you want to test memory leak, uncomment the following lines:
# CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
# CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h

CPPUTEST_LIBS = ${CPPUTEST_HOME}/cpputest_build/lib
CXX = g++

.PHONY: run clean

# The following rule creates the test executable file. 
# Do not forget to add the dependencies on your main program modules. 
# -lCppUTest should be the last source/object/library file to be 
# included in the command line.
# Notice that, in this example, implicit rules are sufficient to 
# compile conversion.c
tests: *.cpp $(PROG_LOCATION_COMMUNICATION)/send_receive_messages.o
	$(CXX) $(CXXFLAGS) -I$(PROG_LOCATION_COMMUNICATION) $^ -L$(CPPUTEST_LIBS) -lCppUTest -o tests

run: tests
	- ./tests

clean:
	rm -f tests
