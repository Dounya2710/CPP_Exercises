# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/local/lib/python3.9/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python3.9/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft

# Include any dependencies generated for this target.
include 3-hrsoft/CMakeFiles/hrsoft-tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include 3-hrsoft/CMakeFiles/hrsoft-tests.dir/compiler_depend.make

# Include the progress variables for this target.
include 3-hrsoft/CMakeFiles/hrsoft-tests.dir/progress.make

# Include the compile flags for this target's objects.
include 3-hrsoft/CMakeFiles/hrsoft-tests.dir/flags.make

3-hrsoft/CMakeFiles/hrsoft-tests.dir/HRSoftTests.cpp.o: 3-hrsoft/CMakeFiles/hrsoft-tests.dir/flags.make
3-hrsoft/CMakeFiles/hrsoft-tests.dir/HRSoftTests.cpp.o: HRSoftTests.cpp
3-hrsoft/CMakeFiles/hrsoft-tests.dir/HRSoftTests.cpp.o: 3-hrsoft/CMakeFiles/hrsoft-tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 3-hrsoft/CMakeFiles/hrsoft-tests.dir/HRSoftTests.cpp.o"
	cd /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft/3-hrsoft && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 3-hrsoft/CMakeFiles/hrsoft-tests.dir/HRSoftTests.cpp.o -MF CMakeFiles/hrsoft-tests.dir/HRSoftTests.cpp.o.d -o CMakeFiles/hrsoft-tests.dir/HRSoftTests.cpp.o -c /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft/HRSoftTests.cpp

3-hrsoft/CMakeFiles/hrsoft-tests.dir/HRSoftTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hrsoft-tests.dir/HRSoftTests.cpp.i"
	cd /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft/3-hrsoft && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft/HRSoftTests.cpp > CMakeFiles/hrsoft-tests.dir/HRSoftTests.cpp.i

3-hrsoft/CMakeFiles/hrsoft-tests.dir/HRSoftTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hrsoft-tests.dir/HRSoftTests.cpp.s"
	cd /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft/3-hrsoft && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft/HRSoftTests.cpp -o CMakeFiles/hrsoft-tests.dir/HRSoftTests.cpp.s

# Object files for target hrsoft-tests
hrsoft__tests_OBJECTS = \
"CMakeFiles/hrsoft-tests.dir/HRSoftTests.cpp.o"

# External object files for target hrsoft-tests
hrsoft__tests_EXTERNAL_OBJECTS =

3-hrsoft/hrsoft-tests: 3-hrsoft/CMakeFiles/hrsoft-tests.dir/HRSoftTests.cpp.o
3-hrsoft/hrsoft-tests: 3-hrsoft/CMakeFiles/hrsoft-tests.dir/build.make
3-hrsoft/hrsoft-tests: 3-hrsoft/CMakeFiles/hrsoft-tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hrsoft-tests"
	cd /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft/3-hrsoft && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hrsoft-tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
3-hrsoft/CMakeFiles/hrsoft-tests.dir/build: 3-hrsoft/hrsoft-tests
.PHONY : 3-hrsoft/CMakeFiles/hrsoft-tests.dir/build

3-hrsoft/CMakeFiles/hrsoft-tests.dir/clean:
	cd /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft/3-hrsoft && $(CMAKE_COMMAND) -P CMakeFiles/hrsoft-tests.dir/cmake_clean.cmake
.PHONY : 3-hrsoft/CMakeFiles/hrsoft-tests.dir/clean

3-hrsoft/CMakeFiles/hrsoft-tests.dir/depend:
	cd /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3 /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft/3-hrsoft /home/2inf1/dounya.hamma/Documents/CPP_Exercises/tp3/3-hrsoft/3-hrsoft/CMakeFiles/hrsoft-tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 3-hrsoft/CMakeFiles/hrsoft-tests.dir/depend

