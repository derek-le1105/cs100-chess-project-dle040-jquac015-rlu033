# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\cmake-build-debug

# Include any dependencies generated for this target.
include googletest/googletest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include googletest/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include googletest/googletest/CMakeFiles/gtest.dir/flags.make

googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: googletest/googletest/CMakeFiles/gtest.dir/flags.make
googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: googletest/googletest/CMakeFiles/gtest.dir/includes_CXX.rsp
googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: ../googletest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj"
	cd /d C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\cmake-build-debug\googletest\googletest && C:\Users\justq\OneDrive\Documents\SFML\i686-7.3.0-release-posix-dwarf-rt_v5-rev0\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gtest.dir\src\gtest-all.cc.obj -c C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\googletest\googletest\src\gtest-all.cc

googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /d C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\cmake-build-debug\googletest\googletest && C:\Users\justq\OneDrive\Documents\SFML\i686-7.3.0-release-posix-dwarf-rt_v5-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\googletest\googletest\src\gtest-all.cc > CMakeFiles\gtest.dir\src\gtest-all.cc.i

googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /d C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\cmake-build-debug\googletest\googletest && C:\Users\justq\OneDrive\Documents\SFML\i686-7.3.0-release-posix-dwarf-rt_v5-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\googletest\googletest\src\gtest-all.cc -o CMakeFiles\gtest.dir\src\gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.obj"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtestd.a: googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj
lib/libgtestd.a: googletest/googletest/CMakeFiles/gtest.dir/build.make
lib/libgtestd.a: googletest/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\..\lib\libgtestd.a"
	cd /d C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\cmake-build-debug\googletest\googletest && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean_target.cmake
	cd /d C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\cmake-build-debug\googletest\googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest/googletest/CMakeFiles/gtest.dir/build: lib/libgtestd.a

.PHONY : googletest/googletest/CMakeFiles/gtest.dir/build

googletest/googletest/CMakeFiles/gtest.dir/clean:
	cd /d C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\cmake-build-debug\googletest\googletest && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean.cmake
.PHONY : googletest/googletest/CMakeFiles/gtest.dir/clean

googletest/googletest/CMakeFiles/gtest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033 C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\googletest\googletest C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\cmake-build-debug C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\cmake-build-debug\googletest\googletest C:\Users\justq\CLionProjects\final-project-dle040-jquac015-rlu033\cmake-build-debug\googletest\googletest\CMakeFiles\gtest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : googletest/googletest/CMakeFiles/gtest.dir/depend
