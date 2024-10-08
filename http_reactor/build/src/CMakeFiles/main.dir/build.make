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
CMAKE_SOURCE_DIR = /mnt/hgfs/GitHub项目/HTTPserver/http_reactor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build

# Include any dependencies generated for this target.
include src/CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/main.dir/flags.make

src/CMakeFiles/main.dir/Buffer.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/Buffer.c.o: /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/Buffer.c
src/CMakeFiles/main.dir/Buffer.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/main.dir/Buffer.c.o"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/Buffer.c.o -MF CMakeFiles/main.dir/Buffer.c.o.d -o CMakeFiles/main.dir/Buffer.c.o -c /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/Buffer.c

src/CMakeFiles/main.dir/Buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/Buffer.c.i"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/Buffer.c > CMakeFiles/main.dir/Buffer.c.i

src/CMakeFiles/main.dir/Buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/Buffer.c.s"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/Buffer.c -o CMakeFiles/main.dir/Buffer.c.s

src/CMakeFiles/main.dir/Channel.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/Channel.c.o: /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/Channel.c
src/CMakeFiles/main.dir/Channel.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/main.dir/Channel.c.o"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/Channel.c.o -MF CMakeFiles/main.dir/Channel.c.o.d -o CMakeFiles/main.dir/Channel.c.o -c /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/Channel.c

src/CMakeFiles/main.dir/Channel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/Channel.c.i"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/Channel.c > CMakeFiles/main.dir/Channel.c.i

src/CMakeFiles/main.dir/Channel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/Channel.c.s"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/Channel.c -o CMakeFiles/main.dir/Channel.c.s

src/CMakeFiles/main.dir/ChannelMap.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/ChannelMap.c.o: /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/ChannelMap.c
src/CMakeFiles/main.dir/ChannelMap.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/main.dir/ChannelMap.c.o"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/ChannelMap.c.o -MF CMakeFiles/main.dir/ChannelMap.c.o.d -o CMakeFiles/main.dir/ChannelMap.c.o -c /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/ChannelMap.c

src/CMakeFiles/main.dir/ChannelMap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/ChannelMap.c.i"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/ChannelMap.c > CMakeFiles/main.dir/ChannelMap.c.i

src/CMakeFiles/main.dir/ChannelMap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/ChannelMap.c.s"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/ChannelMap.c -o CMakeFiles/main.dir/ChannelMap.c.s

src/CMakeFiles/main.dir/EpollDispatcher.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/EpollDispatcher.c.o: /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/EpollDispatcher.c
src/CMakeFiles/main.dir/EpollDispatcher.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/main.dir/EpollDispatcher.c.o"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/EpollDispatcher.c.o -MF CMakeFiles/main.dir/EpollDispatcher.c.o.d -o CMakeFiles/main.dir/EpollDispatcher.c.o -c /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/EpollDispatcher.c

src/CMakeFiles/main.dir/EpollDispatcher.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/EpollDispatcher.c.i"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/EpollDispatcher.c > CMakeFiles/main.dir/EpollDispatcher.c.i

src/CMakeFiles/main.dir/EpollDispatcher.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/EpollDispatcher.c.s"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/EpollDispatcher.c -o CMakeFiles/main.dir/EpollDispatcher.c.s

src/CMakeFiles/main.dir/EventLoop.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/EventLoop.c.o: /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/EventLoop.c
src/CMakeFiles/main.dir/EventLoop.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/main.dir/EventLoop.c.o"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/EventLoop.c.o -MF CMakeFiles/main.dir/EventLoop.c.o.d -o CMakeFiles/main.dir/EventLoop.c.o -c /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/EventLoop.c

src/CMakeFiles/main.dir/EventLoop.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/EventLoop.c.i"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/EventLoop.c > CMakeFiles/main.dir/EventLoop.c.i

src/CMakeFiles/main.dir/EventLoop.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/EventLoop.c.s"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/EventLoop.c -o CMakeFiles/main.dir/EventLoop.c.s

src/CMakeFiles/main.dir/HTTPRequest.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/HTTPRequest.c.o: /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/HTTPRequest.c
src/CMakeFiles/main.dir/HTTPRequest.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/CMakeFiles/main.dir/HTTPRequest.c.o"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/HTTPRequest.c.o -MF CMakeFiles/main.dir/HTTPRequest.c.o.d -o CMakeFiles/main.dir/HTTPRequest.c.o -c /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/HTTPRequest.c

src/CMakeFiles/main.dir/HTTPRequest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/HTTPRequest.c.i"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/HTTPRequest.c > CMakeFiles/main.dir/HTTPRequest.c.i

src/CMakeFiles/main.dir/HTTPRequest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/HTTPRequest.c.s"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/HTTPRequest.c -o CMakeFiles/main.dir/HTTPRequest.c.s

src/CMakeFiles/main.dir/HTTPResponse.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/HTTPResponse.c.o: /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/HTTPResponse.c
src/CMakeFiles/main.dir/HTTPResponse.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/CMakeFiles/main.dir/HTTPResponse.c.o"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/HTTPResponse.c.o -MF CMakeFiles/main.dir/HTTPResponse.c.o.d -o CMakeFiles/main.dir/HTTPResponse.c.o -c /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/HTTPResponse.c

src/CMakeFiles/main.dir/HTTPResponse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/HTTPResponse.c.i"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/HTTPResponse.c > CMakeFiles/main.dir/HTTPResponse.c.i

src/CMakeFiles/main.dir/HTTPResponse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/HTTPResponse.c.s"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/HTTPResponse.c -o CMakeFiles/main.dir/HTTPResponse.c.s

src/CMakeFiles/main.dir/PollDispatcher.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/PollDispatcher.c.o: /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/PollDispatcher.c
src/CMakeFiles/main.dir/PollDispatcher.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/CMakeFiles/main.dir/PollDispatcher.c.o"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/PollDispatcher.c.o -MF CMakeFiles/main.dir/PollDispatcher.c.o.d -o CMakeFiles/main.dir/PollDispatcher.c.o -c /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/PollDispatcher.c

src/CMakeFiles/main.dir/PollDispatcher.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/PollDispatcher.c.i"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/PollDispatcher.c > CMakeFiles/main.dir/PollDispatcher.c.i

src/CMakeFiles/main.dir/PollDispatcher.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/PollDispatcher.c.s"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/PollDispatcher.c -o CMakeFiles/main.dir/PollDispatcher.c.s

src/CMakeFiles/main.dir/SelectDispatcher.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/SelectDispatcher.c.o: /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/SelectDispatcher.c
src/CMakeFiles/main.dir/SelectDispatcher.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object src/CMakeFiles/main.dir/SelectDispatcher.c.o"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/SelectDispatcher.c.o -MF CMakeFiles/main.dir/SelectDispatcher.c.o.d -o CMakeFiles/main.dir/SelectDispatcher.c.o -c /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/SelectDispatcher.c

src/CMakeFiles/main.dir/SelectDispatcher.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/SelectDispatcher.c.i"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/SelectDispatcher.c > CMakeFiles/main.dir/SelectDispatcher.c.i

src/CMakeFiles/main.dir/SelectDispatcher.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/SelectDispatcher.c.s"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/SelectDispatcher.c -o CMakeFiles/main.dir/SelectDispatcher.c.s

src/CMakeFiles/main.dir/TcpConnection.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/TcpConnection.c.o: /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/TcpConnection.c
src/CMakeFiles/main.dir/TcpConnection.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object src/CMakeFiles/main.dir/TcpConnection.c.o"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/TcpConnection.c.o -MF CMakeFiles/main.dir/TcpConnection.c.o.d -o CMakeFiles/main.dir/TcpConnection.c.o -c /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/TcpConnection.c

src/CMakeFiles/main.dir/TcpConnection.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/TcpConnection.c.i"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/TcpConnection.c > CMakeFiles/main.dir/TcpConnection.c.i

src/CMakeFiles/main.dir/TcpConnection.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/TcpConnection.c.s"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/TcpConnection.c -o CMakeFiles/main.dir/TcpConnection.c.s

src/CMakeFiles/main.dir/TcpServer.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/TcpServer.c.o: /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/TcpServer.c
src/CMakeFiles/main.dir/TcpServer.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object src/CMakeFiles/main.dir/TcpServer.c.o"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/TcpServer.c.o -MF CMakeFiles/main.dir/TcpServer.c.o.d -o CMakeFiles/main.dir/TcpServer.c.o -c /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/TcpServer.c

src/CMakeFiles/main.dir/TcpServer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/TcpServer.c.i"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/TcpServer.c > CMakeFiles/main.dir/TcpServer.c.i

src/CMakeFiles/main.dir/TcpServer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/TcpServer.c.s"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/TcpServer.c -o CMakeFiles/main.dir/TcpServer.c.s

src/CMakeFiles/main.dir/ThreadPool.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/ThreadPool.c.o: /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/ThreadPool.c
src/CMakeFiles/main.dir/ThreadPool.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object src/CMakeFiles/main.dir/ThreadPool.c.o"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/ThreadPool.c.o -MF CMakeFiles/main.dir/ThreadPool.c.o.d -o CMakeFiles/main.dir/ThreadPool.c.o -c /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/ThreadPool.c

src/CMakeFiles/main.dir/ThreadPool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/ThreadPool.c.i"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/ThreadPool.c > CMakeFiles/main.dir/ThreadPool.c.i

src/CMakeFiles/main.dir/ThreadPool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/ThreadPool.c.s"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/ThreadPool.c -o CMakeFiles/main.dir/ThreadPool.c.s

src/CMakeFiles/main.dir/WorkerThread.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/WorkerThread.c.o: /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/WorkerThread.c
src/CMakeFiles/main.dir/WorkerThread.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object src/CMakeFiles/main.dir/WorkerThread.c.o"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/WorkerThread.c.o -MF CMakeFiles/main.dir/WorkerThread.c.o.d -o CMakeFiles/main.dir/WorkerThread.c.o -c /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/WorkerThread.c

src/CMakeFiles/main.dir/WorkerThread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/WorkerThread.c.i"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/WorkerThread.c > CMakeFiles/main.dir/WorkerThread.c.i

src/CMakeFiles/main.dir/WorkerThread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/WorkerThread.c.s"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/WorkerThread.c -o CMakeFiles/main.dir/WorkerThread.c.s

src/CMakeFiles/main.dir/main.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/main.c.o: /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/main.c
src/CMakeFiles/main.dir/main.c.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object src/CMakeFiles/main.dir/main.c.o"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/main.c.o -MF CMakeFiles/main.dir/main.c.o.d -o CMakeFiles/main.dir/main.c.o -c /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/main.c

src/CMakeFiles/main.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/main.c.i"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/main.c > CMakeFiles/main.dir/main.c.i

src/CMakeFiles/main.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/main.c.s"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src/main.c -o CMakeFiles/main.dir/main.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/Buffer.c.o" \
"CMakeFiles/main.dir/Channel.c.o" \
"CMakeFiles/main.dir/ChannelMap.c.o" \
"CMakeFiles/main.dir/EpollDispatcher.c.o" \
"CMakeFiles/main.dir/EventLoop.c.o" \
"CMakeFiles/main.dir/HTTPRequest.c.o" \
"CMakeFiles/main.dir/HTTPResponse.c.o" \
"CMakeFiles/main.dir/PollDispatcher.c.o" \
"CMakeFiles/main.dir/SelectDispatcher.c.o" \
"CMakeFiles/main.dir/TcpConnection.c.o" \
"CMakeFiles/main.dir/TcpServer.c.o" \
"CMakeFiles/main.dir/ThreadPool.c.o" \
"CMakeFiles/main.dir/WorkerThread.c.o" \
"CMakeFiles/main.dir/main.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/Buffer.c.o
/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/Channel.c.o
/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/ChannelMap.c.o
/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/EpollDispatcher.c.o
/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/EventLoop.c.o
/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/HTTPRequest.c.o
/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/HTTPResponse.c.o
/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/PollDispatcher.c.o
/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/SelectDispatcher.c.o
/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/TcpConnection.c.o
/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/TcpServer.c.o
/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/ThreadPool.c.o
/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/WorkerThread.c.o
/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/main.c.o
/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/build.make
/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main: src/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking C executable /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main"
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/main.dir/build: /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/output/main
.PHONY : src/CMakeFiles/main.dir/build

src/CMakeFiles/main.dir/clean:
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/main.dir/clean

src/CMakeFiles/main.dir/depend:
	cd /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/GitHub项目/HTTPserver/http_reactor /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/src /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src /mnt/hgfs/GitHub项目/HTTPserver/http_reactor/build/src/CMakeFiles/main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/main.dir/depend

