# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "F:\Program Files (x86)\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\Program Files (x86)\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\c\linux\test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\c\linux\test\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/swoole_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/swoole_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/swoole_test.dir/flags.make

CMakeFiles/swoole_test.dir/demo22.cpp.obj: CMakeFiles/swoole_test.dir/flags.make
CMakeFiles/swoole_test.dir/demo22.cpp.obj: ../demo22.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\c\linux\test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/swoole_test.dir/demo22.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\swoole_test.dir\demo22.cpp.obj -c E:\c\linux\test\demo22.cpp

CMakeFiles/swoole_test.dir/demo22.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/swoole_test.dir/demo22.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\c\linux\test\demo22.cpp > CMakeFiles\swoole_test.dir\demo22.cpp.i

CMakeFiles/swoole_test.dir/demo22.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/swoole_test.dir/demo22.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\c\linux\test\demo22.cpp -o CMakeFiles\swoole_test.dir\demo22.cpp.s

# Object files for target swoole_test
swoole_test_OBJECTS = \
"CMakeFiles/swoole_test.dir/demo22.cpp.obj"

# External object files for target swoole_test
swoole_test_EXTERNAL_OBJECTS =

swoole_test.exe: CMakeFiles/swoole_test.dir/demo22.cpp.obj
swoole_test.exe: CMakeFiles/swoole_test.dir/build.make
swoole_test.exe: CMakeFiles/swoole_test.dir/linklibs.rsp
swoole_test.exe: CMakeFiles/swoole_test.dir/objects1.rsp
swoole_test.exe: CMakeFiles/swoole_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\c\linux\test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable swoole_test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\swoole_test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/swoole_test.dir/build: swoole_test.exe

.PHONY : CMakeFiles/swoole_test.dir/build

CMakeFiles/swoole_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\swoole_test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/swoole_test.dir/clean

CMakeFiles/swoole_test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\c\linux\test E:\c\linux\test E:\c\linux\test\cmake-build-debug E:\c\linux\test\cmake-build-debug E:\c\linux\test\cmake-build-debug\CMakeFiles\swoole_test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/swoole_test.dir/depend

