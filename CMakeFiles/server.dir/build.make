# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ec2-user/socket

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ec2-user/socket

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/test/Server.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/test/Server.cpp.o: test/Server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ec2-user/socket/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/server.dir/test/Server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/server.dir/test/Server.cpp.o -c /home/ec2-user/socket/test/Server.cpp

CMakeFiles/server.dir/test/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/test/Server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ec2-user/socket/test/Server.cpp > CMakeFiles/server.dir/test/Server.cpp.i

CMakeFiles/server.dir/test/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/test/Server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ec2-user/socket/test/Server.cpp -o CMakeFiles/server.dir/test/Server.cpp.s

CMakeFiles/server.dir/test/Server.cpp.o.requires:
.PHONY : CMakeFiles/server.dir/test/Server.cpp.o.requires

CMakeFiles/server.dir/test/Server.cpp.o.provides: CMakeFiles/server.dir/test/Server.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/test/Server.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/test/Server.cpp.o.provides

CMakeFiles/server.dir/test/Server.cpp.o.provides.build: CMakeFiles/server.dir/test/Server.cpp.o
.PHONY : CMakeFiles/server.dir/test/Server.cpp.o.provides.build

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/test/Server.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server: CMakeFiles/server.dir/test/Server.cpp.o
server: lib/libmylib.a
server: CMakeFiles/server.dir/build.make
server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server
.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/requires: CMakeFiles/server.dir/test/Server.cpp.o.requires
.PHONY : CMakeFiles/server.dir/requires

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /home/ec2-user/socket && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ec2-user/socket /home/ec2-user/socket /home/ec2-user/socket /home/ec2-user/socket /home/ec2-user/socket/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

