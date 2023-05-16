
# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project(H2-2 VERSION 1.0 LANGUAGES CXX)

# define the cpp standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra -pedantic -O0)

#add_library(H2-2_lib STATIC src/)

#target_include_directories(H2-2_lib PUBLIC include)

# Create executable
add_executable(H2-2_exec src/main.cpp)

target_include_directories(H2-2_exec PRIVATE include)

#target_link_libraries(H2-2_exec PRIVATE H2-2_lib)



# enable the testing
enable_testing()

# check if we have gtest
find_package(GTest REQUIRED)

# include the gtest CMake stuff
include(GoogleTest)

#add_executable(H2-2_tests test/)
# link the gtest libraries

#target_link_libraries(H2-2_tests PRIVATE GTest::GTest GTest::Main)
# link the library we want to test

#target_link_libraries(H2-2_tests PRIVATE H2-2_lib)
# add the include directories

#target_include_directories(H2-2_tests PUBLIC include)
# discover and add tests to the test list

#gtest_discover_tests(tdd_tests)
