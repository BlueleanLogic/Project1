# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7

# Include any dependencies generated for this target.
include samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/depend.make

# Include the progress variables for this target.
include samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/progress.make

# Include the compile flags for this target's objects.
include samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/flags.make

samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.o: samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/flags.make
samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.o: cegui-0.8.7/samples/EffectsDemo/EffectsDemo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.o"
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/EffectsDemo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.o -c /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/samples/EffectsDemo/EffectsDemo.cpp

samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.i"
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/EffectsDemo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/samples/EffectsDemo/EffectsDemo.cpp > CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.i

samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.s"
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/EffectsDemo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/samples/EffectsDemo/EffectsDemo.cpp -o CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.s

samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.o.requires:
.PHONY : samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.o.requires

samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.o.provides: samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.o.requires
	$(MAKE) -f samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/build.make samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.o.provides.build
.PHONY : samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.o.provides

samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.o.provides.build: samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.o

# Object files for target CEGUIEffectsDemo
CEGUIEffectsDemo_OBJECTS = \
"CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.o"

# External object files for target CEGUIEffectsDemo
CEGUIEffectsDemo_EXTERNAL_OBJECTS =

lib/libCEGUIEffectsDemo.so: samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.o
lib/libCEGUIEffectsDemo.so: samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/build.make
lib/libCEGUIEffectsDemo.so: lib/libCEGUIBase-0.so.2.4.2
lib/libCEGUIEffectsDemo.so: /usr/lib/x86_64-linux-gnu/libfreetype.so
lib/libCEGUIEffectsDemo.so: /usr/lib/x86_64-linux-gnu/libpcre.so
lib/libCEGUIEffectsDemo.so: samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../lib/libCEGUIEffectsDemo.so"
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/EffectsDemo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CEGUIEffectsDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/build: lib/libCEGUIEffectsDemo.so
.PHONY : samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/build

samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/requires: samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/EffectsDemo.cpp.o.requires
.PHONY : samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/requires

samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/clean:
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/EffectsDemo && $(CMAKE_COMMAND) -P CMakeFiles/CEGUIEffectsDemo.dir/cmake_clean.cmake
.PHONY : samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/clean

samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/depend:
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7 /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/samples/EffectsDemo /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7 /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/EffectsDemo /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : samples/EffectsDemo/CMakeFiles/CEGUIEffectsDemo.dir/depend
