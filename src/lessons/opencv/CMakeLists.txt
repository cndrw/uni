

cmake_minimum_required(VERSION 3.20)

project(opencv_project VERSION 1.0 LANGUAGES CXX)

# define the c standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add some compile options
add_compile_options(-Wall -Wextra -pedantic -O0)

#openCV
# search for module opencv
find_package( OpenCV REQUIRED )
# continue only if opencv is found
if(OpenCV_FOUND)
    # add executable for opencv hello world
    add_executable(opencv_test opencv.cpp)
    # include and link all opencv stuff
    target_compile_definitions(opencv_test PRIVATE OUTPATH="${CMAKE_CURRENT_BINARY_DIR}")
    target_compile_definitions(opencv_test PRIVATE IMPATH="${CMAKE_CURRENT_BINARY_DIR}")
    target_include_directories(opencv_test PUBLIC ${OpenCV_INCLUDE_DIRS} )
    target_link_libraries( opencv_test ${OpenCV_LIBRARIES})
endif()