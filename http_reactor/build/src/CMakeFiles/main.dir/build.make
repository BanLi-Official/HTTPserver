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
CMAKE_SOURCE_DIR = /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build

# Include any dependencies generated for this target.
include src/CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/main.dir/flags.make

src/CMakeFiles/main.dir/Channel.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/Channel.c.o: /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/Channel.c
src/CMakeFiles/main.dir/Channel.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/main.dir/Channel.c.o"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/Channel.c.o -MF CMakeFiles/main.dir/Channel.c.o.d -o CMakeFiles/main.dir/Channel.c.o -c /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/Channel.c

src/CMakeFiles/main.dir/Channel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/Channel.c.i"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/Channel.c > CMakeFiles/main.dir/Channel.c.i

src/CMakeFiles/main.dir/Channel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/Channel.c.s"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/Channel.c -o CMakeFiles/main.dir/Channel.c.s

src/CMakeFiles/main.dir/ChannelMap.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/ChannelMap.c.o: /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/ChannelMap.c
src/CMakeFiles/main.dir/ChannelMap.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/main.dir/ChannelMap.c.o"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/ChannelMap.c.o -MF CMakeFiles/main.dir/ChannelMap.c.o.d -o CMakeFiles/main.dir/ChannelMap.c.o -c /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/ChannelMap.c

src/CMakeFiles/main.dir/ChannelMap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/ChannelMap.c.i"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/ChannelMap.c > CMakeFiles/main.dir/ChannelMap.c.i

src/CMakeFiles/main.dir/ChannelMap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/ChannelMap.c.s"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/ChannelMap.c -o CMakeFiles/main.dir/ChannelMap.c.s

src/CMakeFiles/main.dir/EpollDispatcher.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/EpollDispatcher.c.o: /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/EpollDispatcher.c
src/CMakeFiles/main.dir/EpollDispatcher.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/main.dir/EpollDispatcher.c.o"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/EpollDispatcher.c.o -MF CMakeFiles/main.dir/EpollDispatcher.c.o.d -o CMakeFiles/main.dir/EpollDispatcher.c.o -c /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/EpollDispatcher.c

src/CMakeFiles/main.dir/EpollDispatcher.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/EpollDispatcher.c.i"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/EpollDispatcher.c > CMakeFiles/main.dir/EpollDispatcher.c.i

src/CMakeFiles/main.dir/EpollDispatcher.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/EpollDispatcher.c.s"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/EpollDispatcher.c -o CMakeFiles/main.dir/EpollDispatcher.c.s

src/CMakeFiles/main.dir/EventLoop.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/EventLoop.c.o: /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/EventLoop.c
src/CMakeFiles/main.dir/EventLoop.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/main.dir/EventLoop.c.o"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/EventLoop.c.o -MF CMakeFiles/main.dir/EventLoop.c.o.d -o CMakeFiles/main.dir/EventLoop.c.o -c /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/EventLoop.c

src/CMakeFiles/main.dir/EventLoop.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/EventLoop.c.i"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/EventLoop.c > CMakeFiles/main.dir/EventLoop.c.i

src/CMakeFiles/main.dir/EventLoop.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/EventLoop.c.s"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/EventLoop.c -o CMakeFiles/main.dir/EventLoop.c.s

src/CMakeFiles/main.dir/main.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/main.c.o: /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/main.c
src/CMakeFiles/main.dir/main.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/main.dir/main.c.o"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/main.c.o -MF CMakeFiles/main.dir/main.c.o.d -o CMakeFiles/main.dir/main.c.o -c /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/main.c

src/CMakeFiles/main.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/main.c.i"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/main.c > CMakeFiles/main.dir/main.c.i

src/CMakeFiles/main.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/main.c.s"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src/main.c -o CMakeFiles/main.dir/main.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/Channel.c.o" \
"CMakeFiles/main.dir/ChannelMap.c.o" \
"CMakeFiles/main.dir/EpollDispatcher.c.o" \
"CMakeFiles/main.dir/EventLoop.c.o" \
"CMakeFiles/main.dir/main.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/output/main: src/CMakeFiles/main.dir/Channel.c.o
/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/output/main: src/CMakeFiles/main.dir/ChannelMap.c.o
/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/output/main: src/CMakeFiles/main.dir/EpollDispatcher.c.o
/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/output/main: src/CMakeFiles/main.dir/EventLoop.c.o
/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/output/main: src/CMakeFiles/main.dir/main.c.o
/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/output/main: src/CMakeFiles/main.dir/build.make
/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/output/main: src/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/output/main"
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/main.dir/build: /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/output/main
.PHONY : src/CMakeFiles/main.dir/build

src/CMakeFiles/main.dir/clean:
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/main.dir/clean

src/CMakeFiles/main.dir/depend:
	cd /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/src /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src /mnt/hgfs/VMshared/code/c++/HTTPReactor/http_reactor/build/src/CMakeFiles/main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/main.dir/depend

