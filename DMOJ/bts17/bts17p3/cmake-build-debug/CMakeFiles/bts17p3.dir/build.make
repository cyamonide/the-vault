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
CMAKE_COMMAND = /home/sliu/Downloads/clion-2017.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/sliu/Downloads/clion-2017.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sliu/GitHub/the-vault/DMOJ/bts17/bts17p3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sliu/GitHub/the-vault/DMOJ/bts17/bts17p3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bts17p3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bts17p3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bts17p3.dir/flags.make

CMakeFiles/bts17p3.dir/main.cpp.o: CMakeFiles/bts17p3.dir/flags.make
CMakeFiles/bts17p3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sliu/GitHub/the-vault/DMOJ/bts17/bts17p3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bts17p3.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bts17p3.dir/main.cpp.o -c /home/sliu/GitHub/the-vault/DMOJ/bts17/bts17p3/main.cpp

CMakeFiles/bts17p3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bts17p3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sliu/GitHub/the-vault/DMOJ/bts17/bts17p3/main.cpp > CMakeFiles/bts17p3.dir/main.cpp.i

CMakeFiles/bts17p3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bts17p3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sliu/GitHub/the-vault/DMOJ/bts17/bts17p3/main.cpp -o CMakeFiles/bts17p3.dir/main.cpp.s

CMakeFiles/bts17p3.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/bts17p3.dir/main.cpp.o.requires

CMakeFiles/bts17p3.dir/main.cpp.o.provides: CMakeFiles/bts17p3.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/bts17p3.dir/build.make CMakeFiles/bts17p3.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/bts17p3.dir/main.cpp.o.provides

CMakeFiles/bts17p3.dir/main.cpp.o.provides.build: CMakeFiles/bts17p3.dir/main.cpp.o


# Object files for target bts17p3
bts17p3_OBJECTS = \
"CMakeFiles/bts17p3.dir/main.cpp.o"

# External object files for target bts17p3
bts17p3_EXTERNAL_OBJECTS =

bts17p3: CMakeFiles/bts17p3.dir/main.cpp.o
bts17p3: CMakeFiles/bts17p3.dir/build.make
bts17p3: CMakeFiles/bts17p3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sliu/GitHub/the-vault/DMOJ/bts17/bts17p3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bts17p3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bts17p3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bts17p3.dir/build: bts17p3

.PHONY : CMakeFiles/bts17p3.dir/build

CMakeFiles/bts17p3.dir/requires: CMakeFiles/bts17p3.dir/main.cpp.o.requires

.PHONY : CMakeFiles/bts17p3.dir/requires

CMakeFiles/bts17p3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bts17p3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bts17p3.dir/clean

CMakeFiles/bts17p3.dir/depend:
	cd /home/sliu/GitHub/the-vault/DMOJ/bts17/bts17p3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sliu/GitHub/the-vault/DMOJ/bts17/bts17p3 /home/sliu/GitHub/the-vault/DMOJ/bts17/bts17p3 /home/sliu/GitHub/the-vault/DMOJ/bts17/bts17p3/cmake-build-debug /home/sliu/GitHub/the-vault/DMOJ/bts17/bts17p3/cmake-build-debug /home/sliu/GitHub/the-vault/DMOJ/bts17/bts17p3/cmake-build-debug/CMakeFiles/bts17p3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bts17p3.dir/depend

