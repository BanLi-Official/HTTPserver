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
CMAKE_SOURCE_DIR = /mnt/hgfs/Github/HTTPserver/http_reactor_CPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build

# Include any dependencies generated for this target.
include src/CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/main.dir/flags.make

src/CMakeFiles/main.dir/Buffer.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/Buffer.cpp.o: /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/Buffer.cpp
src/CMakeFiles/main.dir/Buffer.cpp.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/main.dir/Buffer.cpp.o"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/main.dir/Buffer.cpp.o -MF CMakeFiles/main.dir/Buffer.cpp.o.d -o CMakeFiles/main.dir/Buffer.cpp.o -c /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/Buffer.cpp

src/CMakeFiles/main.dir/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/Buffer.cpp.i"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/Buffer.cpp > CMakeFiles/main.dir/Buffer.cpp.i

src/CMakeFiles/main.dir/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/Buffer.cpp.s"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/Buffer.cpp -o CMakeFiles/main.dir/Buffer.cpp.s

src/CMakeFiles/main.dir/Channel.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/Channel.cpp.o: /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/Channel.cpp
src/CMakeFiles/main.dir/Channel.cpp.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/main.dir/Channel.cpp.o"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/main.dir/Channel.cpp.o -MF CMakeFiles/main.dir/Channel.cpp.o.d -o CMakeFiles/main.dir/Channel.cpp.o -c /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/Channel.cpp

src/CMakeFiles/main.dir/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/Channel.cpp.i"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/Channel.cpp > CMakeFiles/main.dir/Channel.cpp.i

src/CMakeFiles/main.dir/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/Channel.cpp.s"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/Channel.cpp -o CMakeFiles/main.dir/Channel.cpp.s

src/CMakeFiles/main.dir/Dispatcher.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/Dispatcher.cpp.o: /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/Dispatcher.cpp
src/CMakeFiles/main.dir/Dispatcher.cpp.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/main.dir/Dispatcher.cpp.o"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/main.dir/Dispatcher.cpp.o -MF CMakeFiles/main.dir/Dispatcher.cpp.o.d -o CMakeFiles/main.dir/Dispatcher.cpp.o -c /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/Dispatcher.cpp

src/CMakeFiles/main.dir/Dispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/Dispatcher.cpp.i"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/Dispatcher.cpp > CMakeFiles/main.dir/Dispatcher.cpp.i

src/CMakeFiles/main.dir/Dispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/Dispatcher.cpp.s"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/Dispatcher.cpp -o CMakeFiles/main.dir/Dispatcher.cpp.s

src/CMakeFiles/main.dir/EpollDispatcher.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/EpollDispatcher.cpp.o: /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/EpollDispatcher.cpp
src/CMakeFiles/main.dir/EpollDispatcher.cpp.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/main.dir/EpollDispatcher.cpp.o"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/main.dir/EpollDispatcher.cpp.o -MF CMakeFiles/main.dir/EpollDispatcher.cpp.o.d -o CMakeFiles/main.dir/EpollDispatcher.cpp.o -c /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/EpollDispatcher.cpp

src/CMakeFiles/main.dir/EpollDispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/EpollDispatcher.cpp.i"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/EpollDispatcher.cpp > CMakeFiles/main.dir/EpollDispatcher.cpp.i

src/CMakeFiles/main.dir/EpollDispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/EpollDispatcher.cpp.s"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/EpollDispatcher.cpp -o CMakeFiles/main.dir/EpollDispatcher.cpp.s

src/CMakeFiles/main.dir/EventLoop.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/EventLoop.cpp.o: /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/EventLoop.cpp
src/CMakeFiles/main.dir/EventLoop.cpp.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/main.dir/EventLoop.cpp.o"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/main.dir/EventLoop.cpp.o -MF CMakeFiles/main.dir/EventLoop.cpp.o.d -o CMakeFiles/main.dir/EventLoop.cpp.o -c /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/EventLoop.cpp

src/CMakeFiles/main.dir/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/EventLoop.cpp.i"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/EventLoop.cpp > CMakeFiles/main.dir/EventLoop.cpp.i

src/CMakeFiles/main.dir/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/EventLoop.cpp.s"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/EventLoop.cpp -o CMakeFiles/main.dir/EventLoop.cpp.s

src/CMakeFiles/main.dir/HTTPRequest.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/HTTPRequest.cpp.o: /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/HTTPRequest.cpp
src/CMakeFiles/main.dir/HTTPRequest.cpp.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/main.dir/HTTPRequest.cpp.o"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/main.dir/HTTPRequest.cpp.o -MF CMakeFiles/main.dir/HTTPRequest.cpp.o.d -o CMakeFiles/main.dir/HTTPRequest.cpp.o -c /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/HTTPRequest.cpp

src/CMakeFiles/main.dir/HTTPRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/HTTPRequest.cpp.i"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/HTTPRequest.cpp > CMakeFiles/main.dir/HTTPRequest.cpp.i

src/CMakeFiles/main.dir/HTTPRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/HTTPRequest.cpp.s"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/HTTPRequest.cpp -o CMakeFiles/main.dir/HTTPRequest.cpp.s

src/CMakeFiles/main.dir/HTTPResponse.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/HTTPResponse.cpp.o: /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/HTTPResponse.cpp
src/CMakeFiles/main.dir/HTTPResponse.cpp.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/main.dir/HTTPResponse.cpp.o"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/main.dir/HTTPResponse.cpp.o -MF CMakeFiles/main.dir/HTTPResponse.cpp.o.d -o CMakeFiles/main.dir/HTTPResponse.cpp.o -c /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/HTTPResponse.cpp

src/CMakeFiles/main.dir/HTTPResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/HTTPResponse.cpp.i"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/HTTPResponse.cpp > CMakeFiles/main.dir/HTTPResponse.cpp.i

src/CMakeFiles/main.dir/HTTPResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/HTTPResponse.cpp.s"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/HTTPResponse.cpp -o CMakeFiles/main.dir/HTTPResponse.cpp.s

src/CMakeFiles/main.dir/PollDispatcher.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/PollDispatcher.cpp.o: /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/PollDispatcher.cpp
src/CMakeFiles/main.dir/PollDispatcher.cpp.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/main.dir/PollDispatcher.cpp.o"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/main.dir/PollDispatcher.cpp.o -MF CMakeFiles/main.dir/PollDispatcher.cpp.o.d -o CMakeFiles/main.dir/PollDispatcher.cpp.o -c /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/PollDispatcher.cpp

src/CMakeFiles/main.dir/PollDispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/PollDispatcher.cpp.i"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/PollDispatcher.cpp > CMakeFiles/main.dir/PollDispatcher.cpp.i

src/CMakeFiles/main.dir/PollDispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/PollDispatcher.cpp.s"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/PollDispatcher.cpp -o CMakeFiles/main.dir/PollDispatcher.cpp.s

src/CMakeFiles/main.dir/SelectDispatcher.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/SelectDispatcher.cpp.o: /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/SelectDispatcher.cpp
src/CMakeFiles/main.dir/SelectDispatcher.cpp.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/main.dir/SelectDispatcher.cpp.o"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/main.dir/SelectDispatcher.cpp.o -MF CMakeFiles/main.dir/SelectDispatcher.cpp.o.d -o CMakeFiles/main.dir/SelectDispatcher.cpp.o -c /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/SelectDispatcher.cpp

src/CMakeFiles/main.dir/SelectDispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/SelectDispatcher.cpp.i"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/SelectDispatcher.cpp > CMakeFiles/main.dir/SelectDispatcher.cpp.i

src/CMakeFiles/main.dir/SelectDispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/SelectDispatcher.cpp.s"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/SelectDispatcher.cpp -o CMakeFiles/main.dir/SelectDispatcher.cpp.s

src/CMakeFiles/main.dir/TcpConnection.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/TcpConnection.cpp.o: /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/TcpConnection.cpp
src/CMakeFiles/main.dir/TcpConnection.cpp.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/main.dir/TcpConnection.cpp.o"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/main.dir/TcpConnection.cpp.o -MF CMakeFiles/main.dir/TcpConnection.cpp.o.d -o CMakeFiles/main.dir/TcpConnection.cpp.o -c /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/TcpConnection.cpp

src/CMakeFiles/main.dir/TcpConnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/TcpConnection.cpp.i"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/TcpConnection.cpp > CMakeFiles/main.dir/TcpConnection.cpp.i

src/CMakeFiles/main.dir/TcpConnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/TcpConnection.cpp.s"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/TcpConnection.cpp -o CMakeFiles/main.dir/TcpConnection.cpp.s

src/CMakeFiles/main.dir/TcpServer.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/TcpServer.cpp.o: /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/TcpServer.cpp
src/CMakeFiles/main.dir/TcpServer.cpp.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/main.dir/TcpServer.cpp.o"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/main.dir/TcpServer.cpp.o -MF CMakeFiles/main.dir/TcpServer.cpp.o.d -o CMakeFiles/main.dir/TcpServer.cpp.o -c /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/TcpServer.cpp

src/CMakeFiles/main.dir/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/TcpServer.cpp.i"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/TcpServer.cpp > CMakeFiles/main.dir/TcpServer.cpp.i

src/CMakeFiles/main.dir/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/TcpServer.cpp.s"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/TcpServer.cpp -o CMakeFiles/main.dir/TcpServer.cpp.s

src/CMakeFiles/main.dir/ThreadPool.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/ThreadPool.cpp.o: /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/ThreadPool.cpp
src/CMakeFiles/main.dir/ThreadPool.cpp.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/CMakeFiles/main.dir/ThreadPool.cpp.o"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/main.dir/ThreadPool.cpp.o -MF CMakeFiles/main.dir/ThreadPool.cpp.o.d -o CMakeFiles/main.dir/ThreadPool.cpp.o -c /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/ThreadPool.cpp

src/CMakeFiles/main.dir/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/ThreadPool.cpp.i"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/ThreadPool.cpp > CMakeFiles/main.dir/ThreadPool.cpp.i

src/CMakeFiles/main.dir/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/ThreadPool.cpp.s"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/ThreadPool.cpp -o CMakeFiles/main.dir/ThreadPool.cpp.s

src/CMakeFiles/main.dir/WorkerThread.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/WorkerThread.cpp.o: /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/WorkerThread.cpp
src/CMakeFiles/main.dir/WorkerThread.cpp.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/CMakeFiles/main.dir/WorkerThread.cpp.o"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/main.dir/WorkerThread.cpp.o -MF CMakeFiles/main.dir/WorkerThread.cpp.o.d -o CMakeFiles/main.dir/WorkerThread.cpp.o -c /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/WorkerThread.cpp

src/CMakeFiles/main.dir/WorkerThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/WorkerThread.cpp.i"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/WorkerThread.cpp > CMakeFiles/main.dir/WorkerThread.cpp.i

src/CMakeFiles/main.dir/WorkerThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/WorkerThread.cpp.s"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/WorkerThread.cpp -o CMakeFiles/main.dir/WorkerThread.cpp.s

src/CMakeFiles/main.dir/main.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/main.cpp.o: /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/main.cpp
src/CMakeFiles/main.dir/main.cpp.o: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object src/CMakeFiles/main.dir/main.cpp.o"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/main.cpp

src/CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/main.cpp > CMakeFiles/main.dir/main.cpp.i

src/CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src/main.cpp -o CMakeFiles/main.dir/main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/Buffer.cpp.o" \
"CMakeFiles/main.dir/Channel.cpp.o" \
"CMakeFiles/main.dir/Dispatcher.cpp.o" \
"CMakeFiles/main.dir/EpollDispatcher.cpp.o" \
"CMakeFiles/main.dir/EventLoop.cpp.o" \
"CMakeFiles/main.dir/HTTPRequest.cpp.o" \
"CMakeFiles/main.dir/HTTPResponse.cpp.o" \
"CMakeFiles/main.dir/PollDispatcher.cpp.o" \
"CMakeFiles/main.dir/SelectDispatcher.cpp.o" \
"CMakeFiles/main.dir/TcpConnection.cpp.o" \
"CMakeFiles/main.dir/TcpServer.cpp.o" \
"CMakeFiles/main.dir/ThreadPool.cpp.o" \
"CMakeFiles/main.dir/WorkerThread.cpp.o" \
"CMakeFiles/main.dir/main.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/Buffer.cpp.o
/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/Channel.cpp.o
/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/Dispatcher.cpp.o
/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/EpollDispatcher.cpp.o
/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/EventLoop.cpp.o
/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/HTTPRequest.cpp.o
/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/HTTPResponse.cpp.o
/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/PollDispatcher.cpp.o
/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/SelectDispatcher.cpp.o
/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/TcpConnection.cpp.o
/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/TcpServer.cpp.o
/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/ThreadPool.cpp.o
/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/WorkerThread.cpp.o
/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/main.cpp.o
/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/build.make
/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main: src/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main"
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/main.dir/build: /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/output/main
.PHONY : src/CMakeFiles/main.dir/build

src/CMakeFiles/main.dir/clean:
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/main.dir/clean

src/CMakeFiles/main.dir/depend:
	cd /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/Github/HTTPserver/http_reactor_CPP /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/src /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src /mnt/hgfs/Github/HTTPserver/http_reactor_CPP/build/src/CMakeFiles/main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/main.dir/depend

