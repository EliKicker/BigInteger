# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\Documents\GitHub\BigInteger

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Documents\GitHub\BigInteger\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BigInteger.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/BigInteger.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BigInteger.dir/flags.make

CMakeFiles/BigInteger.dir/main.cpp.obj: CMakeFiles/BigInteger.dir/flags.make
CMakeFiles/BigInteger.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\GitHub\BigInteger\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BigInteger.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BigInteger.dir\main.cpp.obj -c C:\Users\User\Documents\GitHub\BigInteger\main.cpp

CMakeFiles/BigInteger.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigInteger.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Documents\GitHub\BigInteger\main.cpp > CMakeFiles\BigInteger.dir\main.cpp.i

CMakeFiles/BigInteger.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigInteger.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Documents\GitHub\BigInteger\main.cpp -o CMakeFiles\BigInteger.dir\main.cpp.s

CMakeFiles/BigInteger.dir/BigInteger.cpp.obj: CMakeFiles/BigInteger.dir/flags.make
CMakeFiles/BigInteger.dir/BigInteger.cpp.obj: ../BigInteger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\GitHub\BigInteger\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BigInteger.dir/BigInteger.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BigInteger.dir\BigInteger.cpp.obj -c C:\Users\User\Documents\GitHub\BigInteger\BigInteger.cpp

CMakeFiles/BigInteger.dir/BigInteger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigInteger.dir/BigInteger.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Documents\GitHub\BigInteger\BigInteger.cpp > CMakeFiles\BigInteger.dir\BigInteger.cpp.i

CMakeFiles/BigInteger.dir/BigInteger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigInteger.dir/BigInteger.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Documents\GitHub\BigInteger\BigInteger.cpp -o CMakeFiles\BigInteger.dir\BigInteger.cpp.s

# Object files for target BigInteger
BigInteger_OBJECTS = \
"CMakeFiles/BigInteger.dir/main.cpp.obj" \
"CMakeFiles/BigInteger.dir/BigInteger.cpp.obj"

# External object files for target BigInteger
BigInteger_EXTERNAL_OBJECTS =

BigInteger.exe: CMakeFiles/BigInteger.dir/main.cpp.obj
BigInteger.exe: CMakeFiles/BigInteger.dir/BigInteger.cpp.obj
BigInteger.exe: CMakeFiles/BigInteger.dir/build.make
BigInteger.exe: CMakeFiles/BigInteger.dir/linklibs.rsp
BigInteger.exe: CMakeFiles/BigInteger.dir/objects1.rsp
BigInteger.exe: CMakeFiles/BigInteger.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Documents\GitHub\BigInteger\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable BigInteger.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BigInteger.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BigInteger.dir/build: BigInteger.exe
.PHONY : CMakeFiles/BigInteger.dir/build

CMakeFiles/BigInteger.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BigInteger.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BigInteger.dir/clean

CMakeFiles/BigInteger.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Documents\GitHub\BigInteger C:\Users\User\Documents\GitHub\BigInteger C:\Users\User\Documents\GitHub\BigInteger\cmake-build-debug C:\Users\User\Documents\GitHub\BigInteger\cmake-build-debug C:\Users\User\Documents\GitHub\BigInteger\cmake-build-debug\CMakeFiles\BigInteger.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BigInteger.dir/depend

