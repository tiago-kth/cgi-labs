# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tiago/Documents/GitHub/cgi-labs/CgLab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tiago/Documents/GitHub/cgi-labs/CgLab2

# Include any dependencies generated for this target.
include CMakeFiles/SecondLab.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SecondLab.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SecondLab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SecondLab.dir/flags.make

CMakeFiles/SecondLab.dir/skeleton.cpp.o: CMakeFiles/SecondLab.dir/flags.make
CMakeFiles/SecondLab.dir/skeleton.cpp.o: skeleton.cpp
CMakeFiles/SecondLab.dir/skeleton.cpp.o: CMakeFiles/SecondLab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tiago/Documents/GitHub/cgi-labs/CgLab2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SecondLab.dir/skeleton.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SecondLab.dir/skeleton.cpp.o -MF CMakeFiles/SecondLab.dir/skeleton.cpp.o.d -o CMakeFiles/SecondLab.dir/skeleton.cpp.o -c /Users/tiago/Documents/GitHub/cgi-labs/CgLab2/skeleton.cpp

CMakeFiles/SecondLab.dir/skeleton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SecondLab.dir/skeleton.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tiago/Documents/GitHub/cgi-labs/CgLab2/skeleton.cpp > CMakeFiles/SecondLab.dir/skeleton.cpp.i

CMakeFiles/SecondLab.dir/skeleton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SecondLab.dir/skeleton.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tiago/Documents/GitHub/cgi-labs/CgLab2/skeleton.cpp -o CMakeFiles/SecondLab.dir/skeleton.cpp.s

# Object files for target SecondLab
SecondLab_OBJECTS = \
"CMakeFiles/SecondLab.dir/skeleton.cpp.o"

# External object files for target SecondLab
SecondLab_EXTERNAL_OBJECTS =

SecondLab: CMakeFiles/SecondLab.dir/skeleton.cpp.o
SecondLab: CMakeFiles/SecondLab.dir/build.make
SecondLab: /opt/homebrew/lib/libSDLmain.a
SecondLab: /opt/homebrew/lib/libSDL.dylib
SecondLab: CMakeFiles/SecondLab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tiago/Documents/GitHub/cgi-labs/CgLab2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SecondLab"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SecondLab.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SecondLab.dir/build: SecondLab
.PHONY : CMakeFiles/SecondLab.dir/build

CMakeFiles/SecondLab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SecondLab.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SecondLab.dir/clean

CMakeFiles/SecondLab.dir/depend:
	cd /Users/tiago/Documents/GitHub/cgi-labs/CgLab2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tiago/Documents/GitHub/cgi-labs/CgLab2 /Users/tiago/Documents/GitHub/cgi-labs/CgLab2 /Users/tiago/Documents/GitHub/cgi-labs/CgLab2 /Users/tiago/Documents/GitHub/cgi-labs/CgLab2 /Users/tiago/Documents/GitHub/cgi-labs/CgLab2/CMakeFiles/SecondLab.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SecondLab.dir/depend

