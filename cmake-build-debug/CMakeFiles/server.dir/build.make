# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/zfs-student-6/users/rojones/year2/IRC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/zfs-student-6/users/rojones/year2/IRC/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/server_src/server.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/server_src/server.c.o: ../server_src/server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/IRC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/server.dir/server_src/server.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/server_src/server.c.o   -c /nfs/zfs-student-6/users/rojones/year2/IRC/server_src/server.c

CMakeFiles/server.dir/server_src/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/server_src/server.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/IRC/server_src/server.c > CMakeFiles/server.dir/server_src/server.c.i

CMakeFiles/server.dir/server_src/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/server_src/server.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/IRC/server_src/server.c -o CMakeFiles/server.dir/server_src/server.c.s

CMakeFiles/server.dir/server_src/server.c.o.requires:

.PHONY : CMakeFiles/server.dir/server_src/server.c.o.requires

CMakeFiles/server.dir/server_src/server.c.o.provides: CMakeFiles/server.dir/server_src/server.c.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/server_src/server.c.o.provides.build
.PHONY : CMakeFiles/server.dir/server_src/server.c.o.provides

CMakeFiles/server.dir/server_src/server.c.o.provides.build: CMakeFiles/server.dir/server_src/server.c.o


CMakeFiles/server.dir/src/exwraper.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/exwraper.c.o: ../src/exwraper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/IRC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/server.dir/src/exwraper.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/exwraper.c.o   -c /nfs/zfs-student-6/users/rojones/year2/IRC/src/exwraper.c

CMakeFiles/server.dir/src/exwraper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/exwraper.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/IRC/src/exwraper.c > CMakeFiles/server.dir/src/exwraper.c.i

CMakeFiles/server.dir/src/exwraper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/exwraper.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/IRC/src/exwraper.c -o CMakeFiles/server.dir/src/exwraper.c.s

CMakeFiles/server.dir/src/exwraper.c.o.requires:

.PHONY : CMakeFiles/server.dir/src/exwraper.c.o.requires

CMakeFiles/server.dir/src/exwraper.c.o.provides: CMakeFiles/server.dir/src/exwraper.c.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/exwraper.c.o.provides.build
.PHONY : CMakeFiles/server.dir/src/exwraper.c.o.provides

CMakeFiles/server.dir/src/exwraper.c.o.provides.build: CMakeFiles/server.dir/src/exwraper.c.o


CMakeFiles/server.dir/server_src/setup.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/server_src/setup.c.o: ../server_src/setup.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/IRC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/server.dir/server_src/setup.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/server_src/setup.c.o   -c /nfs/zfs-student-6/users/rojones/year2/IRC/server_src/setup.c

CMakeFiles/server.dir/server_src/setup.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/server_src/setup.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/IRC/server_src/setup.c > CMakeFiles/server.dir/server_src/setup.c.i

CMakeFiles/server.dir/server_src/setup.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/server_src/setup.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/IRC/server_src/setup.c -o CMakeFiles/server.dir/server_src/setup.c.s

CMakeFiles/server.dir/server_src/setup.c.o.requires:

.PHONY : CMakeFiles/server.dir/server_src/setup.c.o.requires

CMakeFiles/server.dir/server_src/setup.c.o.provides: CMakeFiles/server.dir/server_src/setup.c.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/server_src/setup.c.o.provides.build
.PHONY : CMakeFiles/server.dir/server_src/setup.c.o.provides

CMakeFiles/server.dir/server_src/setup.c.o.provides.build: CMakeFiles/server.dir/server_src/setup.c.o


CMakeFiles/server.dir/server_src/receve.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/server_src/receve.c.o: ../server_src/receve.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/IRC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/server.dir/server_src/receve.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/server_src/receve.c.o   -c /nfs/zfs-student-6/users/rojones/year2/IRC/server_src/receve.c

CMakeFiles/server.dir/server_src/receve.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/server_src/receve.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/IRC/server_src/receve.c > CMakeFiles/server.dir/server_src/receve.c.i

CMakeFiles/server.dir/server_src/receve.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/server_src/receve.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/IRC/server_src/receve.c -o CMakeFiles/server.dir/server_src/receve.c.s

CMakeFiles/server.dir/server_src/receve.c.o.requires:

.PHONY : CMakeFiles/server.dir/server_src/receve.c.o.requires

CMakeFiles/server.dir/server_src/receve.c.o.provides: CMakeFiles/server.dir/server_src/receve.c.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/server_src/receve.c.o.provides.build
.PHONY : CMakeFiles/server.dir/server_src/receve.c.o.provides

CMakeFiles/server.dir/server_src/receve.c.o.provides.build: CMakeFiles/server.dir/server_src/receve.c.o


CMakeFiles/server.dir/server_src/client.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/server_src/client.c.o: ../server_src/client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/IRC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/server.dir/server_src/client.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/server_src/client.c.o   -c /nfs/zfs-student-6/users/rojones/year2/IRC/server_src/client.c

CMakeFiles/server.dir/server_src/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/server_src/client.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/IRC/server_src/client.c > CMakeFiles/server.dir/server_src/client.c.i

CMakeFiles/server.dir/server_src/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/server_src/client.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/IRC/server_src/client.c -o CMakeFiles/server.dir/server_src/client.c.s

CMakeFiles/server.dir/server_src/client.c.o.requires:

.PHONY : CMakeFiles/server.dir/server_src/client.c.o.requires

CMakeFiles/server.dir/server_src/client.c.o.provides: CMakeFiles/server.dir/server_src/client.c.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/server_src/client.c.o.provides.build
.PHONY : CMakeFiles/server.dir/server_src/client.c.o.provides

CMakeFiles/server.dir/server_src/client.c.o.provides.build: CMakeFiles/server.dir/server_src/client.c.o


CMakeFiles/server.dir/src/ipv.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/ipv.c.o: ../src/ipv.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/IRC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/server.dir/src/ipv.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/ipv.c.o   -c /nfs/zfs-student-6/users/rojones/year2/IRC/src/ipv.c

CMakeFiles/server.dir/src/ipv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/ipv.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/IRC/src/ipv.c > CMakeFiles/server.dir/src/ipv.c.i

CMakeFiles/server.dir/src/ipv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/ipv.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/IRC/src/ipv.c -o CMakeFiles/server.dir/src/ipv.c.s

CMakeFiles/server.dir/src/ipv.c.o.requires:

.PHONY : CMakeFiles/server.dir/src/ipv.c.o.requires

CMakeFiles/server.dir/src/ipv.c.o.provides: CMakeFiles/server.dir/src/ipv.c.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/ipv.c.o.provides.build
.PHONY : CMakeFiles/server.dir/src/ipv.c.o.provides

CMakeFiles/server.dir/src/ipv.c.o.provides.build: CMakeFiles/server.dir/src/ipv.c.o


# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/server_src/server.c.o" \
"CMakeFiles/server.dir/src/exwraper.c.o" \
"CMakeFiles/server.dir/server_src/setup.c.o" \
"CMakeFiles/server.dir/server_src/receve.c.o" \
"CMakeFiles/server.dir/server_src/client.c.o" \
"CMakeFiles/server.dir/src/ipv.c.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server: CMakeFiles/server.dir/server_src/server.c.o
server: CMakeFiles/server.dir/src/exwraper.c.o
server: CMakeFiles/server.dir/server_src/setup.c.o
server: CMakeFiles/server.dir/server_src/receve.c.o
server: CMakeFiles/server.dir/server_src/client.c.o
server: CMakeFiles/server.dir/src/ipv.c.o
server: CMakeFiles/server.dir/build.make
server: liblibft.a
server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/zfs-student-6/users/rojones/year2/IRC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server

.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/requires: CMakeFiles/server.dir/server_src/server.c.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/src/exwraper.c.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/server_src/setup.c.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/server_src/receve.c.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/server_src/client.c.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/src/ipv.c.o.requires

.PHONY : CMakeFiles/server.dir/requires

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /nfs/zfs-student-6/users/rojones/year2/IRC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/zfs-student-6/users/rojones/year2/IRC /nfs/zfs-student-6/users/rojones/year2/IRC /nfs/zfs-student-6/users/rojones/year2/IRC/cmake-build-debug /nfs/zfs-student-6/users/rojones/year2/IRC/cmake-build-debug /nfs/zfs-student-6/users/rojones/year2/IRC/cmake-build-debug/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

