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
CMAKE_COMMAND = /home/emiren/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/emiren/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/emiren/Progs/cpp/opengl-proj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emiren/Progs/cpp/opengl-proj/build

# Utility rule file for uninstall.

# Include any custom commands dependencies for this target.
include include/glfw/CMakeFiles/uninstall.dir/compiler_depend.make

# Include the progress variables for this target.
include include/glfw/CMakeFiles/uninstall.dir/progress.make

include/glfw/CMakeFiles/uninstall:
	cd /home/emiren/Progs/cpp/opengl-proj/build/include/glfw && /home/emiren/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -P /home/emiren/Progs/cpp/opengl-proj/build/include/glfw/cmake_uninstall.cmake

uninstall: include/glfw/CMakeFiles/uninstall
uninstall: include/glfw/CMakeFiles/uninstall.dir/build.make
.PHONY : uninstall

# Rule to build all files generated by this target.
include/glfw/CMakeFiles/uninstall.dir/build: uninstall
.PHONY : include/glfw/CMakeFiles/uninstall.dir/build

include/glfw/CMakeFiles/uninstall.dir/clean:
	cd /home/emiren/Progs/cpp/opengl-proj/build/include/glfw && $(CMAKE_COMMAND) -P CMakeFiles/uninstall.dir/cmake_clean.cmake
.PHONY : include/glfw/CMakeFiles/uninstall.dir/clean

include/glfw/CMakeFiles/uninstall.dir/depend:
	cd /home/emiren/Progs/cpp/opengl-proj/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emiren/Progs/cpp/opengl-proj /home/emiren/Progs/cpp/opengl-proj/include/glfw /home/emiren/Progs/cpp/opengl-proj/build /home/emiren/Progs/cpp/opengl-proj/build/include/glfw /home/emiren/Progs/cpp/opengl-proj/build/include/glfw/CMakeFiles/uninstall.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/glfw/CMakeFiles/uninstall.dir/depend
