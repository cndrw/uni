# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project(test_ex VERSION 1.0 LANGUAGES CXX)

# define the c standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add some compile options
add_compile_options(-Wall -Wextra -pedantic -O0)

add_library(tdd_student_struct STATIC src/student.c)

target_include_directories(tdd_student_struct PUBLIC include)

# add an executabel and assign files to it
add_executable(main_ex src/main.c)

target_include_directories(main_ex PRIVATE include)

target_link_libraries(main_ex PRIVATE tdd_student_struct)

# enable the testing
enable_testing()
# check if we have gtest
find_package(GTest REQUIRED)
# include the gtest CMake stuff
include(GoogleTest)
# create a test executable
add_executable(tdd_tests test/test_functions.cpp)
# link the gtest libraries
target_link_libraries(tdd_tests PRIVATE GTest::GTest GTest::Main)
# link the library we want to test
target_link_libraries(tdd_tests PRIVATE tdd_student_struct)
# add the include directories
target_include_directories(tdd_tests PUBLIC include)
# discover and add tests to the test list
gtest_discover_tests(tdd_tests)