

cmake_minimum_required(VERSION 3.20)

project(opencv_project VERSION 1.0 LANGUAGES CXX)

# define the c standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add some compile options
add_compile_options(-Wall)

#openCV
# search for module opencv
find_package( OpenCV REQUIRED )
# continue only if opencv is found
if(OpenCV_FOUND)
    include(FetchContent)

    # download CvPlot library and add it to the project
    FetchContent_Declare(cvplot
        GIT_REPOSITORY https://github.com/Profactor/cv-plot.git
        GIT_TAG origin/master) # or whatever tag you want
    FetchContent_GetProperties(cvplot)
    if(NOT cvplot_POPULATED)
        set(CVPLOT_USE_CONAN FALSE)
        FetchContent_Populate(cvplot)
    endif()

     # download rapidcsv library and add it to the project
    FetchContent_Declare(rapidcsv
        GIT_REPOSITORY https://github.com/d99kris/rapidcsv.git
        GIT_TAG origin/master) # or whatever tag you want
    FetchContent_MakeAvailable(rapidcsv)

    # add executable for cvplot hello world
    add_executable(cvplot_hello cvplot.cpp)
    target_include_directories(cvplot_hello PUBLIC ${OpenCV_INCLUDE_DIRS} ${cvplot_SOURCE_DIR}/CvPlot/inc)
    
    # add executable for csv reader 
    target_compile_definitions(cvplot_hello PRIVATE RESOURCEPATH="${CMAKE_CURRENT_LIST_DIR}/resources")
    target_link_libraries( cvplot_hello ${OpenCV_LIBRARIES} rapidcsv)

    
    target_compile_definitions(cvplot_hello PRIVATE OUTPATH="${CMAKE_CURRENT_BINARY_DIR}")
    target_compile_definitions( cvplot_hello PRIVATE IMPATH="${CMAKE_CURRENT_BINARY_DIR}")
    target_include_directories(cvplot_hello PUBLIC ${OpenCV_INCLUDE_DIRS} )
    target_link_libraries( cvplot_hello ${OpenCV_LIBRARIES})
endif()