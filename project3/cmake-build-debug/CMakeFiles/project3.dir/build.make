# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /root/VE280/project3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/VE280/project3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project3.dir/flags.make

CMakeFiles/project3.dir/card.cpp.o: CMakeFiles/project3.dir/flags.make
CMakeFiles/project3.dir/card.cpp.o: ../card.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/VE280/project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project3.dir/card.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project3.dir/card.cpp.o -c /root/VE280/project3/card.cpp

CMakeFiles/project3.dir/card.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project3.dir/card.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/VE280/project3/card.cpp > CMakeFiles/project3.dir/card.cpp.i

CMakeFiles/project3.dir/card.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project3.dir/card.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/VE280/project3/card.cpp -o CMakeFiles/project3.dir/card.cpp.s

CMakeFiles/project3.dir/deck.cpp.o: CMakeFiles/project3.dir/flags.make
CMakeFiles/project3.dir/deck.cpp.o: ../deck.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/VE280/project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project3.dir/deck.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project3.dir/deck.cpp.o -c /root/VE280/project3/deck.cpp

CMakeFiles/project3.dir/deck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project3.dir/deck.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/VE280/project3/deck.cpp > CMakeFiles/project3.dir/deck.cpp.i

CMakeFiles/project3.dir/deck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project3.dir/deck.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/VE280/project3/deck.cpp -o CMakeFiles/project3.dir/deck.cpp.s

CMakeFiles/project3.dir/rand.cpp.o: CMakeFiles/project3.dir/flags.make
CMakeFiles/project3.dir/rand.cpp.o: ../rand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/VE280/project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project3.dir/rand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project3.dir/rand.cpp.o -c /root/VE280/project3/rand.cpp

CMakeFiles/project3.dir/rand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project3.dir/rand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/VE280/project3/rand.cpp > CMakeFiles/project3.dir/rand.cpp.i

CMakeFiles/project3.dir/rand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project3.dir/rand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/VE280/project3/rand.cpp -o CMakeFiles/project3.dir/rand.cpp.s

CMakeFiles/project3.dir/main.cpp.o: CMakeFiles/project3.dir/flags.make
CMakeFiles/project3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/VE280/project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project3.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project3.dir/main.cpp.o -c /root/VE280/project3/main.cpp

CMakeFiles/project3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/VE280/project3/main.cpp > CMakeFiles/project3.dir/main.cpp.i

CMakeFiles/project3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/VE280/project3/main.cpp -o CMakeFiles/project3.dir/main.cpp.s

CMakeFiles/project3.dir/hand.cpp.o: CMakeFiles/project3.dir/flags.make
CMakeFiles/project3.dir/hand.cpp.o: ../hand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/VE280/project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/project3.dir/hand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project3.dir/hand.cpp.o -c /root/VE280/project3/hand.cpp

CMakeFiles/project3.dir/hand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project3.dir/hand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/VE280/project3/hand.cpp > CMakeFiles/project3.dir/hand.cpp.i

CMakeFiles/project3.dir/hand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project3.dir/hand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/VE280/project3/hand.cpp -o CMakeFiles/project3.dir/hand.cpp.s

CMakeFiles/project3.dir/player.cpp.o: CMakeFiles/project3.dir/flags.make
CMakeFiles/project3.dir/player.cpp.o: ../player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/VE280/project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/project3.dir/player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project3.dir/player.cpp.o -c /root/VE280/project3/player.cpp

CMakeFiles/project3.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project3.dir/player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/VE280/project3/player.cpp > CMakeFiles/project3.dir/player.cpp.i

CMakeFiles/project3.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project3.dir/player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/VE280/project3/player.cpp -o CMakeFiles/project3.dir/player.cpp.s

# Object files for target project3
project3_OBJECTS = \
"CMakeFiles/project3.dir/card.cpp.o" \
"CMakeFiles/project3.dir/deck.cpp.o" \
"CMakeFiles/project3.dir/rand.cpp.o" \
"CMakeFiles/project3.dir/main.cpp.o" \
"CMakeFiles/project3.dir/hand.cpp.o" \
"CMakeFiles/project3.dir/player.cpp.o"

# External object files for target project3
project3_EXTERNAL_OBJECTS =

project3: CMakeFiles/project3.dir/card.cpp.o
project3: CMakeFiles/project3.dir/deck.cpp.o
project3: CMakeFiles/project3.dir/rand.cpp.o
project3: CMakeFiles/project3.dir/main.cpp.o
project3: CMakeFiles/project3.dir/hand.cpp.o
project3: CMakeFiles/project3.dir/player.cpp.o
project3: CMakeFiles/project3.dir/build.make
project3: CMakeFiles/project3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/VE280/project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable project3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project3.dir/build: project3

.PHONY : CMakeFiles/project3.dir/build

CMakeFiles/project3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project3.dir/clean

CMakeFiles/project3.dir/depend:
	cd /root/VE280/project3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/VE280/project3 /root/VE280/project3 /root/VE280/project3/cmake-build-debug /root/VE280/project3/cmake-build-debug /root/VE280/project3/cmake-build-debug/CMakeFiles/project3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project3.dir/depend
