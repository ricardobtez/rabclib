# CMakeList.txt : CMake project for InterfaceCreationTool, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.16)
set(CMAKE_C_STANDARD 11)
set(SOURCE_INCLUDE_DIRS
        ../include
        ./
        )

set(AUX_SOURCE
        LinkedList.c)

# Add source to this project's executable.
add_executable (rabclib main.c ${AUX_SOURCE})
target_include_directories(rabclib PUBLIC ${SOURCE_INCLUDE_DIRS})
target_link_libraries(rabclib PRIVATE project_warnings project_options)
