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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/work/project/FHdb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/work/project/FHdb/build

# Include any dependencies generated for this target.
include log/CMakeFiles/LOG.dir/depend.make

# Include the progress variables for this target.
include log/CMakeFiles/LOG.dir/progress.make

# Include the compile flags for this target's objects.
include log/CMakeFiles/LOG.dir/flags.make

log/CMakeFiles/LOG.dir/AsyncLogging.cc.o: log/CMakeFiles/LOG.dir/flags.make
log/CMakeFiles/LOG.dir/AsyncLogging.cc.o: ../log/AsyncLogging.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/work/project/FHdb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object log/CMakeFiles/LOG.dir/AsyncLogging.cc.o"
	cd /root/work/project/FHdb/build/log && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LOG.dir/AsyncLogging.cc.o -c /root/work/project/FHdb/log/AsyncLogging.cc

log/CMakeFiles/LOG.dir/AsyncLogging.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LOG.dir/AsyncLogging.cc.i"
	cd /root/work/project/FHdb/build/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/work/project/FHdb/log/AsyncLogging.cc > CMakeFiles/LOG.dir/AsyncLogging.cc.i

log/CMakeFiles/LOG.dir/AsyncLogging.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LOG.dir/AsyncLogging.cc.s"
	cd /root/work/project/FHdb/build/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/work/project/FHdb/log/AsyncLogging.cc -o CMakeFiles/LOG.dir/AsyncLogging.cc.s

log/CMakeFiles/LOG.dir/AsyncLogging.cc.o.requires:

.PHONY : log/CMakeFiles/LOG.dir/AsyncLogging.cc.o.requires

log/CMakeFiles/LOG.dir/AsyncLogging.cc.o.provides: log/CMakeFiles/LOG.dir/AsyncLogging.cc.o.requires
	$(MAKE) -f log/CMakeFiles/LOG.dir/build.make log/CMakeFiles/LOG.dir/AsyncLogging.cc.o.provides.build
.PHONY : log/CMakeFiles/LOG.dir/AsyncLogging.cc.o.provides

log/CMakeFiles/LOG.dir/AsyncLogging.cc.o.provides.build: log/CMakeFiles/LOG.dir/AsyncLogging.cc.o


log/CMakeFiles/LOG.dir/FileUtil.cc.o: log/CMakeFiles/LOG.dir/flags.make
log/CMakeFiles/LOG.dir/FileUtil.cc.o: ../log/FileUtil.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/work/project/FHdb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object log/CMakeFiles/LOG.dir/FileUtil.cc.o"
	cd /root/work/project/FHdb/build/log && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LOG.dir/FileUtil.cc.o -c /root/work/project/FHdb/log/FileUtil.cc

log/CMakeFiles/LOG.dir/FileUtil.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LOG.dir/FileUtil.cc.i"
	cd /root/work/project/FHdb/build/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/work/project/FHdb/log/FileUtil.cc > CMakeFiles/LOG.dir/FileUtil.cc.i

log/CMakeFiles/LOG.dir/FileUtil.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LOG.dir/FileUtil.cc.s"
	cd /root/work/project/FHdb/build/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/work/project/FHdb/log/FileUtil.cc -o CMakeFiles/LOG.dir/FileUtil.cc.s

log/CMakeFiles/LOG.dir/FileUtil.cc.o.requires:

.PHONY : log/CMakeFiles/LOG.dir/FileUtil.cc.o.requires

log/CMakeFiles/LOG.dir/FileUtil.cc.o.provides: log/CMakeFiles/LOG.dir/FileUtil.cc.o.requires
	$(MAKE) -f log/CMakeFiles/LOG.dir/build.make log/CMakeFiles/LOG.dir/FileUtil.cc.o.provides.build
.PHONY : log/CMakeFiles/LOG.dir/FileUtil.cc.o.provides

log/CMakeFiles/LOG.dir/FileUtil.cc.o.provides.build: log/CMakeFiles/LOG.dir/FileUtil.cc.o


log/CMakeFiles/LOG.dir/LogFile.cc.o: log/CMakeFiles/LOG.dir/flags.make
log/CMakeFiles/LOG.dir/LogFile.cc.o: ../log/LogFile.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/work/project/FHdb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object log/CMakeFiles/LOG.dir/LogFile.cc.o"
	cd /root/work/project/FHdb/build/log && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LOG.dir/LogFile.cc.o -c /root/work/project/FHdb/log/LogFile.cc

log/CMakeFiles/LOG.dir/LogFile.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LOG.dir/LogFile.cc.i"
	cd /root/work/project/FHdb/build/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/work/project/FHdb/log/LogFile.cc > CMakeFiles/LOG.dir/LogFile.cc.i

log/CMakeFiles/LOG.dir/LogFile.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LOG.dir/LogFile.cc.s"
	cd /root/work/project/FHdb/build/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/work/project/FHdb/log/LogFile.cc -o CMakeFiles/LOG.dir/LogFile.cc.s

log/CMakeFiles/LOG.dir/LogFile.cc.o.requires:

.PHONY : log/CMakeFiles/LOG.dir/LogFile.cc.o.requires

log/CMakeFiles/LOG.dir/LogFile.cc.o.provides: log/CMakeFiles/LOG.dir/LogFile.cc.o.requires
	$(MAKE) -f log/CMakeFiles/LOG.dir/build.make log/CMakeFiles/LOG.dir/LogFile.cc.o.provides.build
.PHONY : log/CMakeFiles/LOG.dir/LogFile.cc.o.provides

log/CMakeFiles/LOG.dir/LogFile.cc.o.provides.build: log/CMakeFiles/LOG.dir/LogFile.cc.o


log/CMakeFiles/LOG.dir/LogStream.cc.o: log/CMakeFiles/LOG.dir/flags.make
log/CMakeFiles/LOG.dir/LogStream.cc.o: ../log/LogStream.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/work/project/FHdb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object log/CMakeFiles/LOG.dir/LogStream.cc.o"
	cd /root/work/project/FHdb/build/log && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LOG.dir/LogStream.cc.o -c /root/work/project/FHdb/log/LogStream.cc

log/CMakeFiles/LOG.dir/LogStream.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LOG.dir/LogStream.cc.i"
	cd /root/work/project/FHdb/build/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/work/project/FHdb/log/LogStream.cc > CMakeFiles/LOG.dir/LogStream.cc.i

log/CMakeFiles/LOG.dir/LogStream.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LOG.dir/LogStream.cc.s"
	cd /root/work/project/FHdb/build/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/work/project/FHdb/log/LogStream.cc -o CMakeFiles/LOG.dir/LogStream.cc.s

log/CMakeFiles/LOG.dir/LogStream.cc.o.requires:

.PHONY : log/CMakeFiles/LOG.dir/LogStream.cc.o.requires

log/CMakeFiles/LOG.dir/LogStream.cc.o.provides: log/CMakeFiles/LOG.dir/LogStream.cc.o.requires
	$(MAKE) -f log/CMakeFiles/LOG.dir/build.make log/CMakeFiles/LOG.dir/LogStream.cc.o.provides.build
.PHONY : log/CMakeFiles/LOG.dir/LogStream.cc.o.provides

log/CMakeFiles/LOG.dir/LogStream.cc.o.provides.build: log/CMakeFiles/LOG.dir/LogStream.cc.o


log/CMakeFiles/LOG.dir/Logging.cc.o: log/CMakeFiles/LOG.dir/flags.make
log/CMakeFiles/LOG.dir/Logging.cc.o: ../log/Logging.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/work/project/FHdb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object log/CMakeFiles/LOG.dir/Logging.cc.o"
	cd /root/work/project/FHdb/build/log && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LOG.dir/Logging.cc.o -c /root/work/project/FHdb/log/Logging.cc

log/CMakeFiles/LOG.dir/Logging.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LOG.dir/Logging.cc.i"
	cd /root/work/project/FHdb/build/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/work/project/FHdb/log/Logging.cc > CMakeFiles/LOG.dir/Logging.cc.i

log/CMakeFiles/LOG.dir/Logging.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LOG.dir/Logging.cc.s"
	cd /root/work/project/FHdb/build/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/work/project/FHdb/log/Logging.cc -o CMakeFiles/LOG.dir/Logging.cc.s

log/CMakeFiles/LOG.dir/Logging.cc.o.requires:

.PHONY : log/CMakeFiles/LOG.dir/Logging.cc.o.requires

log/CMakeFiles/LOG.dir/Logging.cc.o.provides: log/CMakeFiles/LOG.dir/Logging.cc.o.requires
	$(MAKE) -f log/CMakeFiles/LOG.dir/build.make log/CMakeFiles/LOG.dir/Logging.cc.o.provides.build
.PHONY : log/CMakeFiles/LOG.dir/Logging.cc.o.provides

log/CMakeFiles/LOG.dir/Logging.cc.o.provides.build: log/CMakeFiles/LOG.dir/Logging.cc.o


# Object files for target LOG
LOG_OBJECTS = \
"CMakeFiles/LOG.dir/AsyncLogging.cc.o" \
"CMakeFiles/LOG.dir/FileUtil.cc.o" \
"CMakeFiles/LOG.dir/LogFile.cc.o" \
"CMakeFiles/LOG.dir/LogStream.cc.o" \
"CMakeFiles/LOG.dir/Logging.cc.o"

# External object files for target LOG
LOG_EXTERNAL_OBJECTS =

log/libLOG.a: log/CMakeFiles/LOG.dir/AsyncLogging.cc.o
log/libLOG.a: log/CMakeFiles/LOG.dir/FileUtil.cc.o
log/libLOG.a: log/CMakeFiles/LOG.dir/LogFile.cc.o
log/libLOG.a: log/CMakeFiles/LOG.dir/LogStream.cc.o
log/libLOG.a: log/CMakeFiles/LOG.dir/Logging.cc.o
log/libLOG.a: log/CMakeFiles/LOG.dir/build.make
log/libLOG.a: log/CMakeFiles/LOG.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/work/project/FHdb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libLOG.a"
	cd /root/work/project/FHdb/build/log && $(CMAKE_COMMAND) -P CMakeFiles/LOG.dir/cmake_clean_target.cmake
	cd /root/work/project/FHdb/build/log && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LOG.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
log/CMakeFiles/LOG.dir/build: log/libLOG.a

.PHONY : log/CMakeFiles/LOG.dir/build

log/CMakeFiles/LOG.dir/requires: log/CMakeFiles/LOG.dir/AsyncLogging.cc.o.requires
log/CMakeFiles/LOG.dir/requires: log/CMakeFiles/LOG.dir/FileUtil.cc.o.requires
log/CMakeFiles/LOG.dir/requires: log/CMakeFiles/LOG.dir/LogFile.cc.o.requires
log/CMakeFiles/LOG.dir/requires: log/CMakeFiles/LOG.dir/LogStream.cc.o.requires
log/CMakeFiles/LOG.dir/requires: log/CMakeFiles/LOG.dir/Logging.cc.o.requires

.PHONY : log/CMakeFiles/LOG.dir/requires

log/CMakeFiles/LOG.dir/clean:
	cd /root/work/project/FHdb/build/log && $(CMAKE_COMMAND) -P CMakeFiles/LOG.dir/cmake_clean.cmake
.PHONY : log/CMakeFiles/LOG.dir/clean

log/CMakeFiles/LOG.dir/depend:
	cd /root/work/project/FHdb/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/work/project/FHdb /root/work/project/FHdb/log /root/work/project/FHdb/build /root/work/project/FHdb/build/log /root/work/project/FHdb/build/log/CMakeFiles/LOG.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : log/CMakeFiles/LOG.dir/depend

