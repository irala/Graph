# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nuria/Graph

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nuria/Graph/build

# Include any dependencies generated for this target.
include CMakeFiles/prot.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prot.dir/flags.make

CMakeFiles/prot.dir/source/main.cpp.o: CMakeFiles/prot.dir/flags.make
CMakeFiles/prot.dir/source/main.cpp.o: ../source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nuria/Graph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prot.dir/source/main.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prot.dir/source/main.cpp.o -c /home/nuria/Graph/source/main.cpp

CMakeFiles/prot.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prot.dir/source/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nuria/Graph/source/main.cpp > CMakeFiles/prot.dir/source/main.cpp.i

CMakeFiles/prot.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prot.dir/source/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nuria/Graph/source/main.cpp -o CMakeFiles/prot.dir/source/main.cpp.s

CMakeFiles/prot.dir/source/graph.cpp.o: CMakeFiles/prot.dir/flags.make
CMakeFiles/prot.dir/source/graph.cpp.o: ../source/graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nuria/Graph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/prot.dir/source/graph.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prot.dir/source/graph.cpp.o -c /home/nuria/Graph/source/graph.cpp

CMakeFiles/prot.dir/source/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prot.dir/source/graph.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nuria/Graph/source/graph.cpp > CMakeFiles/prot.dir/source/graph.cpp.i

CMakeFiles/prot.dir/source/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prot.dir/source/graph.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nuria/Graph/source/graph.cpp -o CMakeFiles/prot.dir/source/graph.cpp.s

# Object files for target prot
prot_OBJECTS = \
"CMakeFiles/prot.dir/source/main.cpp.o" \
"CMakeFiles/prot.dir/source/graph.cpp.o"

# External object files for target prot
prot_EXTERNAL_OBJECTS =

prot: CMakeFiles/prot.dir/source/main.cpp.o
prot: CMakeFiles/prot.dir/source/graph.cpp.o
prot: CMakeFiles/prot.dir/build.make
prot: CMakeFiles/prot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nuria/Graph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable prot"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prot.dir/build: prot

.PHONY : CMakeFiles/prot.dir/build

CMakeFiles/prot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prot.dir/clean

CMakeFiles/prot.dir/depend:
	cd /home/nuria/Graph/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nuria/Graph /home/nuria/Graph /home/nuria/Graph/build /home/nuria/Graph/build /home/nuria/Graph/build/CMakeFiles/prot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prot.dir/depend

