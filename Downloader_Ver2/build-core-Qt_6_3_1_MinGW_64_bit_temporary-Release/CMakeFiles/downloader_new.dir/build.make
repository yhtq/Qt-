# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = E:\Qt\Tools\CMake_64\bin\cmake.exe

# The command to remove a file.
RM = E:\Qt\Tools\CMake_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\qt\Qt-\Downloader_Ver2\core

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\qt\Qt-\Downloader_Ver2\build-core-Qt_6_3_1_MinGW_64_bit_temporary-Release

# Include any dependencies generated for this target.
include CMakeFiles/downloader_new.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/downloader_new.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/downloader_new.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/downloader_new.dir/flags.make

CMakeFiles/downloader_new.dir/downloader_new_autogen/mocs_compilation.cpp.obj: CMakeFiles/downloader_new.dir/flags.make
CMakeFiles/downloader_new.dir/downloader_new_autogen/mocs_compilation.cpp.obj: CMakeFiles/downloader_new.dir/includes_CXX.rsp
CMakeFiles/downloader_new.dir/downloader_new_autogen/mocs_compilation.cpp.obj: downloader_new_autogen/mocs_compilation.cpp
CMakeFiles/downloader_new.dir/downloader_new_autogen/mocs_compilation.cpp.obj: CMakeFiles/downloader_new.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\qt\Qt-\Downloader_Ver2\build-core-Qt_6_3_1_MinGW_64_bit_temporary-Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/downloader_new.dir/downloader_new_autogen/mocs_compilation.cpp.obj"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/downloader_new.dir/downloader_new_autogen/mocs_compilation.cpp.obj -MF CMakeFiles\downloader_new.dir\downloader_new_autogen\mocs_compilation.cpp.obj.d -o CMakeFiles\downloader_new.dir\downloader_new_autogen\mocs_compilation.cpp.obj -c D:\qt\Qt-\Downloader_Ver2\build-core-Qt_6_3_1_MinGW_64_bit_temporary-Release\downloader_new_autogen\mocs_compilation.cpp

CMakeFiles/downloader_new.dir/downloader_new_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/downloader_new.dir/downloader_new_autogen/mocs_compilation.cpp.i"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\qt\Qt-\Downloader_Ver2\build-core-Qt_6_3_1_MinGW_64_bit_temporary-Release\downloader_new_autogen\mocs_compilation.cpp > CMakeFiles\downloader_new.dir\downloader_new_autogen\mocs_compilation.cpp.i

CMakeFiles/downloader_new.dir/downloader_new_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/downloader_new.dir/downloader_new_autogen/mocs_compilation.cpp.s"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\qt\Qt-\Downloader_Ver2\build-core-Qt_6_3_1_MinGW_64_bit_temporary-Release\downloader_new_autogen\mocs_compilation.cpp -o CMakeFiles\downloader_new.dir\downloader_new_autogen\mocs_compilation.cpp.s

CMakeFiles/downloader_new.dir/downloader.cpp.obj: CMakeFiles/downloader_new.dir/flags.make
CMakeFiles/downloader_new.dir/downloader.cpp.obj: CMakeFiles/downloader_new.dir/includes_CXX.rsp
CMakeFiles/downloader_new.dir/downloader.cpp.obj: D:/qt/Qt-/Downloader_Ver2/core/downloader.cpp
CMakeFiles/downloader_new.dir/downloader.cpp.obj: CMakeFiles/downloader_new.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\qt\Qt-\Downloader_Ver2\build-core-Qt_6_3_1_MinGW_64_bit_temporary-Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/downloader_new.dir/downloader.cpp.obj"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/downloader_new.dir/downloader.cpp.obj -MF CMakeFiles\downloader_new.dir\downloader.cpp.obj.d -o CMakeFiles\downloader_new.dir\downloader.cpp.obj -c D:\qt\Qt-\Downloader_Ver2\core\downloader.cpp

CMakeFiles/downloader_new.dir/downloader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/downloader_new.dir/downloader.cpp.i"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\qt\Qt-\Downloader_Ver2\core\downloader.cpp > CMakeFiles\downloader_new.dir\downloader.cpp.i

CMakeFiles/downloader_new.dir/downloader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/downloader_new.dir/downloader.cpp.s"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\qt\Qt-\Downloader_Ver2\core\downloader.cpp -o CMakeFiles\downloader_new.dir\downloader.cpp.s

CMakeFiles/downloader_new.dir/get.cpp.obj: CMakeFiles/downloader_new.dir/flags.make
CMakeFiles/downloader_new.dir/get.cpp.obj: CMakeFiles/downloader_new.dir/includes_CXX.rsp
CMakeFiles/downloader_new.dir/get.cpp.obj: D:/qt/Qt-/Downloader_Ver2/core/get.cpp
CMakeFiles/downloader_new.dir/get.cpp.obj: CMakeFiles/downloader_new.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\qt\Qt-\Downloader_Ver2\build-core-Qt_6_3_1_MinGW_64_bit_temporary-Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/downloader_new.dir/get.cpp.obj"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/downloader_new.dir/get.cpp.obj -MF CMakeFiles\downloader_new.dir\get.cpp.obj.d -o CMakeFiles\downloader_new.dir\get.cpp.obj -c D:\qt\Qt-\Downloader_Ver2\core\get.cpp

CMakeFiles/downloader_new.dir/get.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/downloader_new.dir/get.cpp.i"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\qt\Qt-\Downloader_Ver2\core\get.cpp > CMakeFiles\downloader_new.dir\get.cpp.i

CMakeFiles/downloader_new.dir/get.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/downloader_new.dir/get.cpp.s"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\qt\Qt-\Downloader_Ver2\core\get.cpp -o CMakeFiles\downloader_new.dir\get.cpp.s

CMakeFiles/downloader_new.dir/main.cpp.obj: CMakeFiles/downloader_new.dir/flags.make
CMakeFiles/downloader_new.dir/main.cpp.obj: CMakeFiles/downloader_new.dir/includes_CXX.rsp
CMakeFiles/downloader_new.dir/main.cpp.obj: D:/qt/Qt-/Downloader_Ver2/core/main.cpp
CMakeFiles/downloader_new.dir/main.cpp.obj: CMakeFiles/downloader_new.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\qt\Qt-\Downloader_Ver2\build-core-Qt_6_3_1_MinGW_64_bit_temporary-Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/downloader_new.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/downloader_new.dir/main.cpp.obj -MF CMakeFiles\downloader_new.dir\main.cpp.obj.d -o CMakeFiles\downloader_new.dir\main.cpp.obj -c D:\qt\Qt-\Downloader_Ver2\core\main.cpp

CMakeFiles/downloader_new.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/downloader_new.dir/main.cpp.i"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\qt\Qt-\Downloader_Ver2\core\main.cpp > CMakeFiles\downloader_new.dir\main.cpp.i

CMakeFiles/downloader_new.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/downloader_new.dir/main.cpp.s"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\qt\Qt-\Downloader_Ver2\core\main.cpp -o CMakeFiles\downloader_new.dir\main.cpp.s

# Object files for target downloader_new
downloader_new_OBJECTS = \
"CMakeFiles/downloader_new.dir/downloader_new_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/downloader_new.dir/downloader.cpp.obj" \
"CMakeFiles/downloader_new.dir/get.cpp.obj" \
"CMakeFiles/downloader_new.dir/main.cpp.obj"

# External object files for target downloader_new
downloader_new_EXTERNAL_OBJECTS =

downloader_new.exe: CMakeFiles/downloader_new.dir/downloader_new_autogen/mocs_compilation.cpp.obj
downloader_new.exe: CMakeFiles/downloader_new.dir/downloader.cpp.obj
downloader_new.exe: CMakeFiles/downloader_new.dir/get.cpp.obj
downloader_new.exe: CMakeFiles/downloader_new.dir/main.cpp.obj
downloader_new.exe: CMakeFiles/downloader_new.dir/build.make
downloader_new.exe: E:/Qt/6.3.1/mingw_64/lib/libQt6Core5Compat.a
downloader_new.exe: E:/Qt/6.3.1/mingw_64/lib/libQt6Widgets.a
downloader_new.exe: E:/Qt/6.3.1/mingw_64/lib/libQt6Network.a
downloader_new.exe: E:/Qt/6.3.1/mingw_64/lib/libQt6Concurrent.a
downloader_new.exe: E:/Qt/6.3.1/mingw_64/lib/libQt6Gui.a
downloader_new.exe: E:/Qt/6.3.1/mingw_64/lib/libQt6Core.a
downloader_new.exe: CMakeFiles/downloader_new.dir/linklibs.rsp
downloader_new.exe: CMakeFiles/downloader_new.dir/objects1.rsp
downloader_new.exe: CMakeFiles/downloader_new.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\qt\Qt-\Downloader_Ver2\build-core-Qt_6_3_1_MinGW_64_bit_temporary-Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable downloader_new.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\downloader_new.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/downloader_new.dir/build: downloader_new.exe
.PHONY : CMakeFiles/downloader_new.dir/build

CMakeFiles/downloader_new.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\downloader_new.dir\cmake_clean.cmake
.PHONY : CMakeFiles/downloader_new.dir/clean

CMakeFiles/downloader_new.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\qt\Qt-\Downloader_Ver2\core D:\qt\Qt-\Downloader_Ver2\core D:\qt\Qt-\Downloader_Ver2\build-core-Qt_6_3_1_MinGW_64_bit_temporary-Release D:\qt\Qt-\Downloader_Ver2\build-core-Qt_6_3_1_MinGW_64_bit_temporary-Release D:\qt\Qt-\Downloader_Ver2\build-core-Qt_6_3_1_MinGW_64_bit_temporary-Release\CMakeFiles\downloader_new.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/downloader_new.dir/depend

