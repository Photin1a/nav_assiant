# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/build

# Include any dependencies generated for this target.
include CMakeFiles/test_sever.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_sever.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_sever.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_sever.dir/flags.make

CMakeFiles/test_sever.dir/test_sever_autogen/mocs_compilation.cpp.o: CMakeFiles/test_sever.dir/flags.make
CMakeFiles/test_sever.dir/test_sever_autogen/mocs_compilation.cpp.o: test_sever_autogen/mocs_compilation.cpp
CMakeFiles/test_sever.dir/test_sever_autogen/mocs_compilation.cpp.o: CMakeFiles/test_sever.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_sever.dir/test_sever_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_sever.dir/test_sever_autogen/mocs_compilation.cpp.o -MF CMakeFiles/test_sever.dir/test_sever_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/test_sever.dir/test_sever_autogen/mocs_compilation.cpp.o -c /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/build/test_sever_autogen/mocs_compilation.cpp

CMakeFiles/test_sever.dir/test_sever_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_sever.dir/test_sever_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/build/test_sever_autogen/mocs_compilation.cpp > CMakeFiles/test_sever.dir/test_sever_autogen/mocs_compilation.cpp.i

CMakeFiles/test_sever.dir/test_sever_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_sever.dir/test_sever_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/build/test_sever_autogen/mocs_compilation.cpp -o CMakeFiles/test_sever.dir/test_sever_autogen/mocs_compilation.cpp.s

CMakeFiles/test_sever.dir/src/tcp_connect.cpp.o: CMakeFiles/test_sever.dir/flags.make
CMakeFiles/test_sever.dir/src/tcp_connect.cpp.o: /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/src/tcp_connect.cpp
CMakeFiles/test_sever.dir/src/tcp_connect.cpp.o: CMakeFiles/test_sever.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_sever.dir/src/tcp_connect.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_sever.dir/src/tcp_connect.cpp.o -MF CMakeFiles/test_sever.dir/src/tcp_connect.cpp.o.d -o CMakeFiles/test_sever.dir/src/tcp_connect.cpp.o -c /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/src/tcp_connect.cpp

CMakeFiles/test_sever.dir/src/tcp_connect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_sever.dir/src/tcp_connect.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/src/tcp_connect.cpp > CMakeFiles/test_sever.dir/src/tcp_connect.cpp.i

CMakeFiles/test_sever.dir/src/tcp_connect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_sever.dir/src/tcp_connect.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/src/tcp_connect.cpp -o CMakeFiles/test_sever.dir/src/tcp_connect.cpp.s

CMakeFiles/test_sever.dir/src/tcp_sever_test.cpp.o: CMakeFiles/test_sever.dir/flags.make
CMakeFiles/test_sever.dir/src/tcp_sever_test.cpp.o: /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/src/tcp_sever_test.cpp
CMakeFiles/test_sever.dir/src/tcp_sever_test.cpp.o: CMakeFiles/test_sever.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_sever.dir/src/tcp_sever_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_sever.dir/src/tcp_sever_test.cpp.o -MF CMakeFiles/test_sever.dir/src/tcp_sever_test.cpp.o.d -o CMakeFiles/test_sever.dir/src/tcp_sever_test.cpp.o -c /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/src/tcp_sever_test.cpp

CMakeFiles/test_sever.dir/src/tcp_sever_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_sever.dir/src/tcp_sever_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/src/tcp_sever_test.cpp > CMakeFiles/test_sever.dir/src/tcp_sever_test.cpp.i

CMakeFiles/test_sever.dir/src/tcp_sever_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_sever.dir/src/tcp_sever_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/src/tcp_sever_test.cpp -o CMakeFiles/test_sever.dir/src/tcp_sever_test.cpp.s

# Object files for target test_sever
test_sever_OBJECTS = \
"CMakeFiles/test_sever.dir/test_sever_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/test_sever.dir/src/tcp_connect.cpp.o" \
"CMakeFiles/test_sever.dir/src/tcp_sever_test.cpp.o"

# External object files for target test_sever
test_sever_EXTERNAL_OBJECTS =

test_sever: CMakeFiles/test_sever.dir/test_sever_autogen/mocs_compilation.cpp.o
test_sever: CMakeFiles/test_sever.dir/src/tcp_connect.cpp.o
test_sever: CMakeFiles/test_sever.dir/src/tcp_sever_test.cpp.o
test_sever: CMakeFiles/test_sever.dir/build.make
test_sever: /opt/Qt/5.15.2/gcc_64/lib/libQt5Network.so.5.15.2
test_sever: /opt/Qt/5.15.2/gcc_64/lib/libQt5Core.so.5.15.2
test_sever: CMakeFiles/test_sever.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test_sever"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_sever.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_sever.dir/build: test_sever
.PHONY : CMakeFiles/test_sever.dir/build

CMakeFiles/test_sever.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_sever.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_sever.dir/clean

CMakeFiles/test_sever.dir/depend:
	cd /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/build /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/build /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/PID_Assiant/build/CMakeFiles/test_sever.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_sever.dir/depend

