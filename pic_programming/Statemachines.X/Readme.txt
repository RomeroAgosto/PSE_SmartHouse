Instruction how to use the unit test and the state machines

ATTENTION: don't rearrange the files, since the dependencies are fixed. (Paths to the files)

Unit Test:

Running Unit Tests:
1. The files from the state machines and the unit test must be in 2 different folders (because of the Makefile -> change it if you want to rearrange)
2. Go first into the state machine folder and build the state machine ( the .o file is needed for the unit tests!)
3. Change the directory to UnitTest_Tester and build this project
4. Execute the test executable

Add New Tests:

1. Ensure that the unit tests in general are running
(2.Add a new Test Group)
3. Add a new Test case to the corresponding group
4. Build the tests executable again (you don't have to build the state machine again)
5. Run the executable

Using the Statemachines:

1. Include the whole Statemachines.X Project
2. Ensure, that all main.c files aren't part of the project
3. Include the statemachine.h file
4. Set UNITTEST to FALSE before using it in MPLAB
5. use the statemachines