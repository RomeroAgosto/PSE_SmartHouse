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
CMAKE_SOURCE_DIR = /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Schedules_X.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Schedules_X.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Schedules_X.dir/flags.make

CMakeFiles/Schedules_X.dir/main.c.o: CMakeFiles/Schedules_X.dir/flags.make
CMakeFiles/Schedules_X.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Schedules_X.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Schedules_X.dir/main.c.o   -c /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/main.c

CMakeFiles/Schedules_X.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Schedules_X.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/main.c > CMakeFiles/Schedules_X.dir/main.c.i

CMakeFiles/Schedules_X.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Schedules_X.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/main.c -o CMakeFiles/Schedules_X.dir/main.c.s

CMakeFiles/Schedules_X.dir/main.c.o.requires:

.PHONY : CMakeFiles/Schedules_X.dir/main.c.o.requires

CMakeFiles/Schedules_X.dir/main.c.o.provides: CMakeFiles/Schedules_X.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Schedules_X.dir/build.make CMakeFiles/Schedules_X.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Schedules_X.dir/main.c.o.provides

CMakeFiles/Schedules_X.dir/main.c.o.provides.build: CMakeFiles/Schedules_X.dir/main.c.o


CMakeFiles/Schedules_X.dir/schedules.c.o: CMakeFiles/Schedules_X.dir/flags.make
CMakeFiles/Schedules_X.dir/schedules.c.o: ../schedules.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Schedules_X.dir/schedules.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Schedules_X.dir/schedules.c.o   -c /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/schedules.c

CMakeFiles/Schedules_X.dir/schedules.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Schedules_X.dir/schedules.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/schedules.c > CMakeFiles/Schedules_X.dir/schedules.c.i

CMakeFiles/Schedules_X.dir/schedules.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Schedules_X.dir/schedules.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/schedules.c -o CMakeFiles/Schedules_X.dir/schedules.c.s

CMakeFiles/Schedules_X.dir/schedules.c.o.requires:

.PHONY : CMakeFiles/Schedules_X.dir/schedules.c.o.requires

CMakeFiles/Schedules_X.dir/schedules.c.o.provides: CMakeFiles/Schedules_X.dir/schedules.c.o.requires
	$(MAKE) -f CMakeFiles/Schedules_X.dir/build.make CMakeFiles/Schedules_X.dir/schedules.c.o.provides.build
.PHONY : CMakeFiles/Schedules_X.dir/schedules.c.o.provides

CMakeFiles/Schedules_X.dir/schedules.c.o.provides.build: CMakeFiles/Schedules_X.dir/schedules.c.o


CMakeFiles/Schedules_X.dir/desiredValues.c.o: CMakeFiles/Schedules_X.dir/flags.make
CMakeFiles/Schedules_X.dir/desiredValues.c.o: ../desiredValues.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Schedules_X.dir/desiredValues.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Schedules_X.dir/desiredValues.c.o   -c /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/desiredValues.c

CMakeFiles/Schedules_X.dir/desiredValues.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Schedules_X.dir/desiredValues.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/desiredValues.c > CMakeFiles/Schedules_X.dir/desiredValues.c.i

CMakeFiles/Schedules_X.dir/desiredValues.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Schedules_X.dir/desiredValues.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/desiredValues.c -o CMakeFiles/Schedules_X.dir/desiredValues.c.s

CMakeFiles/Schedules_X.dir/desiredValues.c.o.requires:

.PHONY : CMakeFiles/Schedules_X.dir/desiredValues.c.o.requires

CMakeFiles/Schedules_X.dir/desiredValues.c.o.provides: CMakeFiles/Schedules_X.dir/desiredValues.c.o.requires
	$(MAKE) -f CMakeFiles/Schedules_X.dir/build.make CMakeFiles/Schedules_X.dir/desiredValues.c.o.provides.build
.PHONY : CMakeFiles/Schedules_X.dir/desiredValues.c.o.provides

CMakeFiles/Schedules_X.dir/desiredValues.c.o.provides.build: CMakeFiles/Schedules_X.dir/desiredValues.c.o


CMakeFiles/Schedules_X.dir/send_receive_messages.c.o: CMakeFiles/Schedules_X.dir/flags.make
CMakeFiles/Schedules_X.dir/send_receive_messages.c.o: ../send_receive_messages.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Schedules_X.dir/send_receive_messages.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Schedules_X.dir/send_receive_messages.c.o   -c /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/send_receive_messages.c

CMakeFiles/Schedules_X.dir/send_receive_messages.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Schedules_X.dir/send_receive_messages.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/send_receive_messages.c > CMakeFiles/Schedules_X.dir/send_receive_messages.c.i

CMakeFiles/Schedules_X.dir/send_receive_messages.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Schedules_X.dir/send_receive_messages.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/send_receive_messages.c -o CMakeFiles/Schedules_X.dir/send_receive_messages.c.s

CMakeFiles/Schedules_X.dir/send_receive_messages.c.o.requires:

.PHONY : CMakeFiles/Schedules_X.dir/send_receive_messages.c.o.requires

CMakeFiles/Schedules_X.dir/send_receive_messages.c.o.provides: CMakeFiles/Schedules_X.dir/send_receive_messages.c.o.requires
	$(MAKE) -f CMakeFiles/Schedules_X.dir/build.make CMakeFiles/Schedules_X.dir/send_receive_messages.c.o.provides.build
.PHONY : CMakeFiles/Schedules_X.dir/send_receive_messages.c.o.provides

CMakeFiles/Schedules_X.dir/send_receive_messages.c.o.provides.build: CMakeFiles/Schedules_X.dir/send_receive_messages.c.o


CMakeFiles/Schedules_X.dir/create_normal_message.c.o: CMakeFiles/Schedules_X.dir/flags.make
CMakeFiles/Schedules_X.dir/create_normal_message.c.o: ../create_normal_message.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Schedules_X.dir/create_normal_message.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Schedules_X.dir/create_normal_message.c.o   -c /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/create_normal_message.c

CMakeFiles/Schedules_X.dir/create_normal_message.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Schedules_X.dir/create_normal_message.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/create_normal_message.c > CMakeFiles/Schedules_X.dir/create_normal_message.c.i

CMakeFiles/Schedules_X.dir/create_normal_message.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Schedules_X.dir/create_normal_message.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/create_normal_message.c -o CMakeFiles/Schedules_X.dir/create_normal_message.c.s

CMakeFiles/Schedules_X.dir/create_normal_message.c.o.requires:

.PHONY : CMakeFiles/Schedules_X.dir/create_normal_message.c.o.requires

CMakeFiles/Schedules_X.dir/create_normal_message.c.o.provides: CMakeFiles/Schedules_X.dir/create_normal_message.c.o.requires
	$(MAKE) -f CMakeFiles/Schedules_X.dir/build.make CMakeFiles/Schedules_X.dir/create_normal_message.c.o.provides.build
.PHONY : CMakeFiles/Schedules_X.dir/create_normal_message.c.o.provides

CMakeFiles/Schedules_X.dir/create_normal_message.c.o.provides.build: CMakeFiles/Schedules_X.dir/create_normal_message.c.o


# Object files for target Schedules_X
Schedules_X_OBJECTS = \
"CMakeFiles/Schedules_X.dir/main.c.o" \
"CMakeFiles/Schedules_X.dir/schedules.c.o" \
"CMakeFiles/Schedules_X.dir/desiredValues.c.o" \
"CMakeFiles/Schedules_X.dir/send_receive_messages.c.o" \
"CMakeFiles/Schedules_X.dir/create_normal_message.c.o"

# External object files for target Schedules_X
Schedules_X_EXTERNAL_OBJECTS =

Schedules_X: CMakeFiles/Schedules_X.dir/main.c.o
Schedules_X: CMakeFiles/Schedules_X.dir/schedules.c.o
Schedules_X: CMakeFiles/Schedules_X.dir/desiredValues.c.o
Schedules_X: CMakeFiles/Schedules_X.dir/send_receive_messages.c.o
Schedules_X: CMakeFiles/Schedules_X.dir/create_normal_message.c.o
Schedules_X: CMakeFiles/Schedules_X.dir/build.make
Schedules_X: CMakeFiles/Schedules_X.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable Schedules_X"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Schedules_X.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Schedules_X.dir/build: Schedules_X

.PHONY : CMakeFiles/Schedules_X.dir/build

CMakeFiles/Schedules_X.dir/requires: CMakeFiles/Schedules_X.dir/main.c.o.requires
CMakeFiles/Schedules_X.dir/requires: CMakeFiles/Schedules_X.dir/schedules.c.o.requires
CMakeFiles/Schedules_X.dir/requires: CMakeFiles/Schedules_X.dir/desiredValues.c.o.requires
CMakeFiles/Schedules_X.dir/requires: CMakeFiles/Schedules_X.dir/send_receive_messages.c.o.requires
CMakeFiles/Schedules_X.dir/requires: CMakeFiles/Schedules_X.dir/create_normal_message.c.o.requires

.PHONY : CMakeFiles/Schedules_X.dir/requires

CMakeFiles/Schedules_X.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Schedules_X.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Schedules_X.dir/clean

CMakeFiles/Schedules_X.dir/depend:
	cd /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/cmake-build-debug /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/cmake-build-debug /home/sascha/Embedded_Systems/Home_Automation/pse_42594_17-18_g1/pic_programming/Schedules.X/cmake-build-debug/CMakeFiles/Schedules_X.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Schedules_X.dir/depend

