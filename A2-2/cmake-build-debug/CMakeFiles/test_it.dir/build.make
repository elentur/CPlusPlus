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
CMAKE_SOURCE_DIR = /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test_it.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_it.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_it.dir/flags.make

CMakeFiles/test_it.dir/main.cpp.o: CMakeFiles/test_it.dir/flags.make
CMakeFiles/test_it.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_it.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_it.dir/main.cpp.o -c /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/main.cpp

CMakeFiles/test_it.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_it.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/main.cpp > CMakeFiles/test_it.dir/main.cpp.i

CMakeFiles/test_it.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_it.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/main.cpp -o CMakeFiles/test_it.dir/main.cpp.s

CMakeFiles/test_it.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/test_it.dir/main.cpp.o.requires

CMakeFiles/test_it.dir/main.cpp.o.provides: CMakeFiles/test_it.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_it.dir/build.make CMakeFiles/test_it.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/test_it.dir/main.cpp.o.provides

CMakeFiles/test_it.dir/main.cpp.o.provides.build: CMakeFiles/test_it.dir/main.cpp.o


CMakeFiles/test_it.dir/payload.cpp.o: CMakeFiles/test_it.dir/flags.make
CMakeFiles/test_it.dir/payload.cpp.o: ../payload.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_it.dir/payload.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_it.dir/payload.cpp.o -c /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/payload.cpp

CMakeFiles/test_it.dir/payload.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_it.dir/payload.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/payload.cpp > CMakeFiles/test_it.dir/payload.cpp.i

CMakeFiles/test_it.dir/payload.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_it.dir/payload.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/payload.cpp -o CMakeFiles/test_it.dir/payload.cpp.s

CMakeFiles/test_it.dir/payload.cpp.o.requires:

.PHONY : CMakeFiles/test_it.dir/payload.cpp.o.requires

CMakeFiles/test_it.dir/payload.cpp.o.provides: CMakeFiles/test_it.dir/payload.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_it.dir/build.make CMakeFiles/test_it.dir/payload.cpp.o.provides.build
.PHONY : CMakeFiles/test_it.dir/payload.cpp.o.provides

CMakeFiles/test_it.dir/payload.cpp.o.provides.build: CMakeFiles/test_it.dir/payload.cpp.o


CMakeFiles/test_it.dir/test21.cpp.o: CMakeFiles/test_it.dir/flags.make
CMakeFiles/test_it.dir/test21.cpp.o: ../test21.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_it.dir/test21.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_it.dir/test21.cpp.o -c /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/test21.cpp

CMakeFiles/test_it.dir/test21.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_it.dir/test21.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/test21.cpp > CMakeFiles/test_it.dir/test21.cpp.i

CMakeFiles/test_it.dir/test21.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_it.dir/test21.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/test21.cpp -o CMakeFiles/test_it.dir/test21.cpp.s

CMakeFiles/test_it.dir/test21.cpp.o.requires:

.PHONY : CMakeFiles/test_it.dir/test21.cpp.o.requires

CMakeFiles/test_it.dir/test21.cpp.o.provides: CMakeFiles/test_it.dir/test21.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_it.dir/build.make CMakeFiles/test_it.dir/test21.cpp.o.provides.build
.PHONY : CMakeFiles/test_it.dir/test21.cpp.o.provides

CMakeFiles/test_it.dir/test21.cpp.o.provides.build: CMakeFiles/test_it.dir/test21.cpp.o


# Object files for target test_it
test_it_OBJECTS = \
"CMakeFiles/test_it.dir/main.cpp.o" \
"CMakeFiles/test_it.dir/payload.cpp.o" \
"CMakeFiles/test_it.dir/test21.cpp.o"

# External object files for target test_it
test_it_EXTERNAL_OBJECTS =

test_it: CMakeFiles/test_it.dir/main.cpp.o
test_it: CMakeFiles/test_it.dir/payload.cpp.o
test_it: CMakeFiles/test_it.dir/test21.cpp.o
test_it: CMakeFiles/test_it.dir/build.make
test_it: CMakeFiles/test_it.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test_it"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_it.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_it.dir/build: test_it

.PHONY : CMakeFiles/test_it.dir/build

CMakeFiles/test_it.dir/requires: CMakeFiles/test_it.dir/main.cpp.o.requires
CMakeFiles/test_it.dir/requires: CMakeFiles/test_it.dir/payload.cpp.o.requires
CMakeFiles/test_it.dir/requires: CMakeFiles/test_it.dir/test21.cpp.o.requires

.PHONY : CMakeFiles/test_it.dir/requires

CMakeFiles/test_it.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_it.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_it.dir/clean

CMakeFiles/test_it.dir/depend:
	cd /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2 /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2 /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/cmake-build-debug /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/cmake-build-debug /home/roberto/Documents/beuth/WS16/CPlusPlus/A2-2/cmake-build-debug/CMakeFiles/test_it.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_it.dir/depend

