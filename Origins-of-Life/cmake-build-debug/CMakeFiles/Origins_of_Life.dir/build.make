# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ollie/Downloads/Origins-of-Life

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ollie/Downloads/Origins-of-Life/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Origins_of_Life.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Origins_of_Life.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Origins_of_Life.dir/flags.make

CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.o: CMakeFiles/Origins_of_Life.dir/flags.make
CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.o: ../tests/small/smallTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ollie/Downloads/Origins-of-Life/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.o -c /Users/ollie/Downloads/Origins-of-Life/tests/small/smallTests.cpp

CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ollie/Downloads/Origins-of-Life/tests/small/smallTests.cpp > CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.i

CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ollie/Downloads/Origins-of-Life/tests/small/smallTests.cpp -o CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.s

CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.o.requires:

.PHONY : CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.o.requires

CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.o.provides: CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.o.requires
	$(MAKE) -f CMakeFiles/Origins_of_Life.dir/build.make CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.o.provides.build
.PHONY : CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.o.provides

CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.o.provides.build: CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.o


# Object files for target Origins_of_Life
Origins_of_Life_OBJECTS = \
"CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.o"

# External object files for target Origins_of_Life
Origins_of_Life_EXTERNAL_OBJECTS =

../bin/Origins_of_Life: CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.o
../bin/Origins_of_Life: CMakeFiles/Origins_of_Life.dir/build.make
../bin/Origins_of_Life: CMakeFiles/Origins_of_Life.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ollie/Downloads/Origins-of-Life/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/Origins_of_Life"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Origins_of_Life.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Origins_of_Life.dir/build: ../bin/Origins_of_Life

.PHONY : CMakeFiles/Origins_of_Life.dir/build

CMakeFiles/Origins_of_Life.dir/requires: CMakeFiles/Origins_of_Life.dir/tests/small/smallTests.cpp.o.requires

.PHONY : CMakeFiles/Origins_of_Life.dir/requires

CMakeFiles/Origins_of_Life.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Origins_of_Life.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Origins_of_Life.dir/clean

CMakeFiles/Origins_of_Life.dir/depend:
	cd /Users/ollie/Downloads/Origins-of-Life/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ollie/Downloads/Origins-of-Life /Users/ollie/Downloads/Origins-of-Life /Users/ollie/Downloads/Origins-of-Life/cmake-build-debug /Users/ollie/Downloads/Origins-of-Life/cmake-build-debug /Users/ollie/Downloads/Origins-of-Life/cmake-build-debug/CMakeFiles/Origins_of_Life.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Origins_of_Life.dir/depend
