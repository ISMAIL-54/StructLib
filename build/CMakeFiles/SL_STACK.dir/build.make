# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/i5m4il/Projects/StructLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/i5m4il/Projects/StructLib/build

# Include any dependencies generated for this target.
include CMakeFiles/SL_STACK.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SL_STACK.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SL_STACK.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SL_STACK.dir/flags.make

# Object files for target SL_STACK
SL_STACK_OBJECTS =

# External object files for target SL_STACK
SL_STACK_EXTERNAL_OBJECTS =

libSL_STACK.a: CMakeFiles/SL_STACK.dir/build.make
libSL_STACK.a: CMakeFiles/SL_STACK.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/i5m4il/Projects/StructLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library libSL_STACK.a"
	$(CMAKE_COMMAND) -P CMakeFiles/SL_STACK.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SL_STACK.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SL_STACK.dir/build: libSL_STACK.a
.PHONY : CMakeFiles/SL_STACK.dir/build

CMakeFiles/SL_STACK.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SL_STACK.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SL_STACK.dir/clean

CMakeFiles/SL_STACK.dir/depend:
	cd /home/i5m4il/Projects/StructLib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/i5m4il/Projects/StructLib /home/i5m4il/Projects/StructLib /home/i5m4il/Projects/StructLib/build /home/i5m4il/Projects/StructLib/build /home/i5m4il/Projects/StructLib/build/CMakeFiles/SL_STACK.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SL_STACK.dir/depend

