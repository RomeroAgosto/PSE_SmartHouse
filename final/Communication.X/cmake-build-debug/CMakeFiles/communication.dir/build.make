# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/sascha/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/sascha/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/communication.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/communication.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/communication.dir/flags.make

CMakeFiles/communication.dir/StatemachineCommunication/main.c.o: CMakeFiles/communication.dir/flags.make
CMakeFiles/communication.dir/StatemachineCommunication/main.c.o: ../StatemachineCommunication/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/communication.dir/StatemachineCommunication/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/communication.dir/StatemachineCommunication/main.c.o   -c /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X/StatemachineCommunication/main.c

CMakeFiles/communication.dir/StatemachineCommunication/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/communication.dir/StatemachineCommunication/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X/StatemachineCommunication/main.c > CMakeFiles/communication.dir/StatemachineCommunication/main.c.i

CMakeFiles/communication.dir/StatemachineCommunication/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/communication.dir/StatemachineCommunication/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X/StatemachineCommunication/main.c -o CMakeFiles/communication.dir/StatemachineCommunication/main.c.s

CMakeFiles/communication.dir/StatemachineCommunication/main.c.o.requires:

.PHONY : CMakeFiles/communication.dir/StatemachineCommunication/main.c.o.requires

CMakeFiles/communication.dir/StatemachineCommunication/main.c.o.provides: CMakeFiles/communication.dir/StatemachineCommunication/main.c.o.requires
	$(MAKE) -f CMakeFiles/communication.dir/build.make CMakeFiles/communication.dir/StatemachineCommunication/main.c.o.provides.build
.PHONY : CMakeFiles/communication.dir/StatemachineCommunication/main.c.o.provides

CMakeFiles/communication.dir/StatemachineCommunication/main.c.o.provides.build: CMakeFiles/communication.dir/StatemachineCommunication/main.c.o


CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.o: CMakeFiles/communication.dir/flags.make
CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.o: ../StatemachineCommunication/send_receive_messages.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.o   -c /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X/StatemachineCommunication/send_receive_messages.c

CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X/StatemachineCommunication/send_receive_messages.c > CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.i

CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X/StatemachineCommunication/send_receive_messages.c -o CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.s

CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.o.requires:

.PHONY : CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.o.requires

CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.o.provides: CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.o.requires
	$(MAKE) -f CMakeFiles/communication.dir/build.make CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.o.provides.build
.PHONY : CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.o.provides

CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.o.provides.build: CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.o


# Object files for target communication
communication_OBJECTS = \
"CMakeFiles/communication.dir/StatemachineCommunication/main.c.o" \
"CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.o"

# External object files for target communication
communication_EXTERNAL_OBJECTS =

communication: CMakeFiles/communication.dir/StatemachineCommunication/main.c.o
communication: CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.o
communication: CMakeFiles/communication.dir/build.make
communication: CMakeFiles/communication.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable communication"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/communication.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/communication.dir/build: communication

.PHONY : CMakeFiles/communication.dir/build

CMakeFiles/communication.dir/requires: CMakeFiles/communication.dir/StatemachineCommunication/main.c.o.requires
CMakeFiles/communication.dir/requires: CMakeFiles/communication.dir/StatemachineCommunication/send_receive_messages.c.o.requires

.PHONY : CMakeFiles/communication.dir/requires

CMakeFiles/communication.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/communication.dir/cmake_clean.cmake
.PHONY : CMakeFiles/communication.dir/clean

CMakeFiles/communication.dir/depend:
	cd /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X/cmake-build-debug /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X/cmake-build-debug /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/final/Communication.X/cmake-build-debug/CMakeFiles/communication.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/communication.dir/depend

