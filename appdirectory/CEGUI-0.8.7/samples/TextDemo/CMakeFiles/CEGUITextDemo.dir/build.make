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
include samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/depend.make

# Include the progress variables for this target.
include samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/progress.make

# Include the compile flags for this target's objects.
include samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/flags.make

samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.o: samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/flags.make
samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.o: cegui-0.8.7/samples/TextDemo/Sample_Text.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.o"
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/TextDemo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.o -c /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/samples/TextDemo/Sample_Text.cpp

samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.i"
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/TextDemo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/samples/TextDemo/Sample_Text.cpp > CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.i

samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.s"
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/TextDemo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/samples/TextDemo/Sample_Text.cpp -o CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.s

samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.o.requires:
.PHONY : samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.o.requires

samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.o.provides: samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.o.requires
	$(MAKE) -f samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/build.make samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.o.provides.build
.PHONY : samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.o.provides

samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.o.provides.build: samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.o

# Object files for target CEGUITextDemo
CEGUITextDemo_OBJECTS = \
"CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.o"

# External object files for target CEGUITextDemo
CEGUITextDemo_EXTERNAL_OBJECTS =

lib/libCEGUITextDemo.so: samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.o
lib/libCEGUITextDemo.so: samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/build.make
lib/libCEGUITextDemo.so: lib/libCEGUIBase-0.so.2.4.2
lib/libCEGUITextDemo.so: /usr/lib/x86_64-linux-gnu/libfreetype.so
lib/libCEGUITextDemo.so: /usr/lib/x86_64-linux-gnu/libpcre.so
lib/libCEGUITextDemo.so: samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../lib/libCEGUITextDemo.so"
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/TextDemo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CEGUITextDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/build: lib/libCEGUITextDemo.so
.PHONY : samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/build

samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/requires: samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/Sample_Text.cpp.o.requires
.PHONY : samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/requires

samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/clean:
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/TextDemo && $(CMAKE_COMMAND) -P CMakeFiles/CEGUITextDemo.dir/cmake_clean.cmake
.PHONY : samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/clean

samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/depend:
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7 /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/samples/TextDemo /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7 /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/TextDemo /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : samples/TextDemo/CMakeFiles/CEGUITextDemo.dir/depend

