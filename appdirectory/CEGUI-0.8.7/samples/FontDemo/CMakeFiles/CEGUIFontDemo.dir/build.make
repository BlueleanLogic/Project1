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
include samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/depend.make

# Include the progress variables for this target.
include samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/progress.make

# Include the compile flags for this target's objects.
include samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/flags.make

samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.o: samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/flags.make
samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.o: cegui-0.8.7/samples/FontDemo/Sample_FontDemo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.o"
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/FontDemo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.o -c /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/samples/FontDemo/Sample_FontDemo.cpp

samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.i"
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/FontDemo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/samples/FontDemo/Sample_FontDemo.cpp > CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.i

samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.s"
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/FontDemo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/samples/FontDemo/Sample_FontDemo.cpp -o CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.s

samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.o.requires:
.PHONY : samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.o.requires

samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.o.provides: samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.o.requires
	$(MAKE) -f samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/build.make samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.o.provides.build
.PHONY : samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.o.provides

samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.o.provides.build: samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.o

# Object files for target CEGUIFontDemo
CEGUIFontDemo_OBJECTS = \
"CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.o"

# External object files for target CEGUIFontDemo
CEGUIFontDemo_EXTERNAL_OBJECTS =

lib/libCEGUIFontDemo.so: samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.o
lib/libCEGUIFontDemo.so: samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/build.make
lib/libCEGUIFontDemo.so: lib/libCEGUIBase-0.so.2.4.2
lib/libCEGUIFontDemo.so: /usr/lib/x86_64-linux-gnu/libfreetype.so
lib/libCEGUIFontDemo.so: /usr/lib/x86_64-linux-gnu/libpcre.so
lib/libCEGUIFontDemo.so: samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../lib/libCEGUIFontDemo.so"
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/FontDemo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CEGUIFontDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/build: lib/libCEGUIFontDemo.so
.PHONY : samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/build

samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/requires: samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/Sample_FontDemo.cpp.o.requires
.PHONY : samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/requires

samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/clean:
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/FontDemo && $(CMAKE_COMMAND) -P CMakeFiles/CEGUIFontDemo.dir/cmake_clean.cmake
.PHONY : samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/clean

samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/depend:
	cd /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7 /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/samples/FontDemo /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7 /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/FontDemo /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : samples/FontDemo/CMakeFiles/CEGUIFontDemo.dir/depend

