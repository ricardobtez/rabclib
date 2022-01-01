cmake_minimum_required(VERSION 3.16)

# Create the testing project
project(fiverrTest C)
set(CMAKE_C_STANDARD 11)

set (AUX_TEST_FILES
        test_simple.c)

set(SOURCE_AUX_FILES
        ../src/LinkedList.c)

set(AUX_TEST_INCLUDES
        ./inc)


add_executable(rabclibTest test_main.c ${SOURCE_AUX_FILES} ${AUX_TEST_FILES})

target_include_directories(rabclibTest
        PUBLIC
        ${SOURCE_INCLUDE_DIRS}
        ${AUX_TEST_INCLUDES}
        ${GTEST_SOURCE_DIR}/include
        ${GTEST_SOURCE_DIR})

target_link_libraries(rabclibTest
        PRIVATE
        gtest
        gtest_main
        project_warnings
        project_options)
