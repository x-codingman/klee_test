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
CMAKE_SOURCE_DIR = /home/klee/klee_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/klee/klee_test/build_test

# Include any dependencies generated for this target.
include runtime/Runtest/CMakeFiles/kleeRuntest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include runtime/Runtest/CMakeFiles/kleeRuntest.dir/compiler_depend.make

# Include the progress variables for this target.
include runtime/Runtest/CMakeFiles/kleeRuntest.dir/progress.make

# Include the compile flags for this target's objects.
include runtime/Runtest/CMakeFiles/kleeRuntest.dir/flags.make

runtime/Runtest/CMakeFiles/kleeRuntest.dir/intrinsics.c.o: runtime/Runtest/CMakeFiles/kleeRuntest.dir/flags.make
runtime/Runtest/CMakeFiles/kleeRuntest.dir/intrinsics.c.o: /home/klee/klee_test/runtime/Runtest/intrinsics.c
runtime/Runtest/CMakeFiles/kleeRuntest.dir/intrinsics.c.o: runtime/Runtest/CMakeFiles/kleeRuntest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/klee/klee_test/build_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object runtime/Runtest/CMakeFiles/kleeRuntest.dir/intrinsics.c.o"
	cd /home/klee/klee_test/build_test/runtime/Runtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT runtime/Runtest/CMakeFiles/kleeRuntest.dir/intrinsics.c.o -MF CMakeFiles/kleeRuntest.dir/intrinsics.c.o.d -o CMakeFiles/kleeRuntest.dir/intrinsics.c.o -c /home/klee/klee_test/runtime/Runtest/intrinsics.c

runtime/Runtest/CMakeFiles/kleeRuntest.dir/intrinsics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kleeRuntest.dir/intrinsics.c.i"
	cd /home/klee/klee_test/build_test/runtime/Runtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/klee/klee_test/runtime/Runtest/intrinsics.c > CMakeFiles/kleeRuntest.dir/intrinsics.c.i

runtime/Runtest/CMakeFiles/kleeRuntest.dir/intrinsics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kleeRuntest.dir/intrinsics.c.s"
	cd /home/klee/klee_test/build_test/runtime/Runtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/klee/klee_test/runtime/Runtest/intrinsics.c -o CMakeFiles/kleeRuntest.dir/intrinsics.c.s

runtime/Runtest/CMakeFiles/kleeRuntest.dir/__/__/lib/Basic/KTest.cpp.o: runtime/Runtest/CMakeFiles/kleeRuntest.dir/flags.make
runtime/Runtest/CMakeFiles/kleeRuntest.dir/__/__/lib/Basic/KTest.cpp.o: /home/klee/klee_test/lib/Basic/KTest.cpp
runtime/Runtest/CMakeFiles/kleeRuntest.dir/__/__/lib/Basic/KTest.cpp.o: runtime/Runtest/CMakeFiles/kleeRuntest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/klee/klee_test/build_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object runtime/Runtest/CMakeFiles/kleeRuntest.dir/__/__/lib/Basic/KTest.cpp.o"
	cd /home/klee/klee_test/build_test/runtime/Runtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT runtime/Runtest/CMakeFiles/kleeRuntest.dir/__/__/lib/Basic/KTest.cpp.o -MF CMakeFiles/kleeRuntest.dir/__/__/lib/Basic/KTest.cpp.o.d -o CMakeFiles/kleeRuntest.dir/__/__/lib/Basic/KTest.cpp.o -c /home/klee/klee_test/lib/Basic/KTest.cpp

runtime/Runtest/CMakeFiles/kleeRuntest.dir/__/__/lib/Basic/KTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kleeRuntest.dir/__/__/lib/Basic/KTest.cpp.i"
	cd /home/klee/klee_test/build_test/runtime/Runtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/klee/klee_test/lib/Basic/KTest.cpp > CMakeFiles/kleeRuntest.dir/__/__/lib/Basic/KTest.cpp.i

runtime/Runtest/CMakeFiles/kleeRuntest.dir/__/__/lib/Basic/KTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kleeRuntest.dir/__/__/lib/Basic/KTest.cpp.s"
	cd /home/klee/klee_test/build_test/runtime/Runtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/klee/klee_test/lib/Basic/KTest.cpp -o CMakeFiles/kleeRuntest.dir/__/__/lib/Basic/KTest.cpp.s

# Object files for target kleeRuntest
kleeRuntest_OBJECTS = \
"CMakeFiles/kleeRuntest.dir/intrinsics.c.o" \
"CMakeFiles/kleeRuntest.dir/__/__/lib/Basic/KTest.cpp.o"

# External object files for target kleeRuntest
kleeRuntest_EXTERNAL_OBJECTS =

lib/libkleeRuntest.so.1.0: runtime/Runtest/CMakeFiles/kleeRuntest.dir/intrinsics.c.o
lib/libkleeRuntest.so.1.0: runtime/Runtest/CMakeFiles/kleeRuntest.dir/__/__/lib/Basic/KTest.cpp.o
lib/libkleeRuntest.so.1.0: runtime/Runtest/CMakeFiles/kleeRuntest.dir/build.make
lib/libkleeRuntest.so.1.0: runtime/Runtest/CMakeFiles/kleeRuntest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/klee/klee_test/build_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../../lib/libkleeRuntest.so"
	cd /home/klee/klee_test/build_test/runtime/Runtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kleeRuntest.dir/link.txt --verbose=$(VERBOSE)
	cd /home/klee/klee_test/build_test/runtime/Runtest && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/libkleeRuntest.so.1.0 ../../lib/libkleeRuntest.so.1.0 ../../lib/libkleeRuntest.so

lib/libkleeRuntest.so: lib/libkleeRuntest.so.1.0
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libkleeRuntest.so

# Rule to build all files generated by this target.
runtime/Runtest/CMakeFiles/kleeRuntest.dir/build: lib/libkleeRuntest.so
.PHONY : runtime/Runtest/CMakeFiles/kleeRuntest.dir/build

runtime/Runtest/CMakeFiles/kleeRuntest.dir/clean:
	cd /home/klee/klee_test/build_test/runtime/Runtest && $(CMAKE_COMMAND) -P CMakeFiles/kleeRuntest.dir/cmake_clean.cmake
.PHONY : runtime/Runtest/CMakeFiles/kleeRuntest.dir/clean

runtime/Runtest/CMakeFiles/kleeRuntest.dir/depend:
	cd /home/klee/klee_test/build_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/klee/klee_test /home/klee/klee_test/runtime/Runtest /home/klee/klee_test/build_test /home/klee/klee_test/build_test/runtime/Runtest /home/klee/klee_test/build_test/runtime/Runtest/CMakeFiles/kleeRuntest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : runtime/Runtest/CMakeFiles/kleeRuntest.dir/depend

