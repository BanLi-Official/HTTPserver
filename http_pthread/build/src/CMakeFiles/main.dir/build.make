# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build

# Include any dependencies generated for this target.
include src/CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/main.dir/flags.make

src/CMakeFiles/main.dir/main.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/main.c.o: /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/src/main.c
src/CMakeFiles/main.dir/main.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/main.dir/main.c.o"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/main.c.o -MF CMakeFiles/main.dir/main.c.o.d -o CMakeFiles/main.dir/main.c.o -c /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/src/main.c

src/CMakeFiles/main.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/main.c.i"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/src/main.c > CMakeFiles/main.dir/main.c.i

src/CMakeFiles/main.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/main.c.s"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/src/main.c -o CMakeFiles/main.dir/main.c.s

src/CMakeFiles/main.dir/server.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/server.c.o: /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/src/server.c
src/CMakeFiles/main.dir/server.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/main.dir/server.c.o"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/server.c.o -MF CMakeFiles/main.dir/server.c.o.d -o CMakeFiles/main.dir/server.c.o -c /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/src/server.c

src/CMakeFiles/main.dir/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/server.c.i"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/src/server.c > CMakeFiles/main.dir/server.c.i

src/CMakeFiles/main.dir/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/server.c.s"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/src/server.c -o CMakeFiles/main.dir/server.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.c.o" \
"CMakeFiles/main.dir/server.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/output/main: src/CMakeFiles/main.dir/main.c.o
/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/output/main: src/CMakeFiles/main.dir/server.c.o
/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/output/main: src/CMakeFiles/main.dir/build.make
/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/output/main: src/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/output/main"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/main.dir/build: /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/output/main
.PHONY : src/CMakeFiles/main.dir/build

src/CMakeFiles/main.dir/clean:
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build/src && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/main.dir/clean

src/CMakeFiles/main.dir/depend:
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/src /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build/src /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_pthread/build/src/CMakeFiles/main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/main.dir/depend

