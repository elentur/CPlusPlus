# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/roberto/CLion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/roberto/CLion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/roberto/Documents/WS16/CPlusPlus/A3-3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/roberto/Documents/WS16/CPlusPlus/A3-3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/A3-3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/A3-3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A3-3.dir/flags.make

CMakeFiles/A3-3.dir/main.cpp.o: CMakeFiles/A3-3.dir/flags.make
CMakeFiles/A3-3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/roberto/Documents/WS16/CPlusPlus/A3-3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/A3-3.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/A3-3.dir/main.cpp.o -c /home/roberto/Documents/WS16/CPlusPlus/A3-3/main.cpp

CMakeFiles/A3-3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A3-3.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/roberto/Documents/WS16/CPlusPlus/A3-3/main.cpp > CMakeFiles/A3-3.dir/main.cpp.i

CMakeFiles/A3-3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A3-3.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/roberto/Documents/WS16/CPlusPlus/A3-3/main.cpp -o CMakeFiles/A3-3.dir/main.cpp.s

CMakeFiles/A3-3.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/A3-3.dir/main.cpp.o.requires

CMakeFiles/A3-3.dir/main.cpp.o.provides: CMakeFiles/A3-3.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/A3-3.dir/build.make CMakeFiles/A3-3.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/A3-3.dir/main.cpp.o.provides

CMakeFiles/A3-3.dir/main.cpp.o.provides.build: CMakeFiles/A3-3.dir/main.cpp.o


# Object files for target A3-3
A3__3_OBJECTS = \
"CMakeFiles/A3-3.dir/main.cpp.o"

# External object files for target A3-3
A3__3_EXTERNAL_OBJECTS =

A3-3: CMakeFiles/A3-3.dir/main.cpp.o
A3-3: CMakeFiles/A3-3.dir/build.make
A3-3: CMakeFiles/A3-3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/roberto/Documents/WS16/CPlusPlus/A3-3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable A3-3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/A3-3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A3-3.dir/build: A3-3

.PHONY : CMakeFiles/A3-3.dir/build

CMakeFiles/A3-3.dir/requires: CMakeFiles/A3-3.dir/main.cpp.o.requires

.PHONY : CMakeFiles/A3-3.dir/requires

CMakeFiles/A3-3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/A3-3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/A3-3.dir/clean

CMakeFiles/A3-3.dir/depend:
	cd /home/roberto/Documents/WS16/CPlusPlus/A3-3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/roberto/Documents/WS16/CPlusPlus/A3-3 /home/roberto/Documents/WS16/CPlusPlus/A3-3 /home/roberto/Documents/WS16/CPlusPlus/A3-3/cmake-build-debug /home/roberto/Documents/WS16/CPlusPlus/A3-3/cmake-build-debug /home/roberto/Documents/WS16/CPlusPlus/A3-3/cmake-build-debug/CMakeFiles/A3-3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/A3-3.dir/depend

