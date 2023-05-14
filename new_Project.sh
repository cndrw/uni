#!/bin/bash

read -p "Geben Sie den Namen des neuen Ordners ein: " folder_name

# Überprüfen, ob der Ordner bereits vorhanden ist
if [ -d "src/$folder_name" ]; then
  echo "Der Ordner existiert bereits."
  exit 1
fi

# Neuen Ordner erstellen
mkdir "src/$folder_name"

# Unterordner erstellen
mkdir "src/$folder_name/src"
mkdir "src/$folder_name/include"
mkdir "src/$folder_name/test"

touch "src/$folder_name/src/main.cpp"



# CMakeLists.txt-Vorlagendatei erstellen
cat >"src/$folder_name/CMakeLists_template.txt" <<EOF

# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project($folder_name VERSION 1.0 LANGUAGES CXX)

# define the cpp standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra -pedantic -O0)

#add_library(${folder_name}_lib STATIC src/)

#target_include_directories(${folder_name}_lib PUBLIC include)

# Create executable
add_executable(${folder_name}_exec src/main.cpp)

target_include_directories(${folder_name}_exec PRIVATE include)

#target_link_libraries(${folder_name}_exec PRIVATE ${folder_name}_lib)



# enable the testing
enable_testing()

# check if we have gtest
find_package(GTest REQUIRED)

# include the gtest CMake stuff
include(GoogleTest)

#add_executable(${folder_name}_tests test/)
# link the gtest libraries

#target_link_libraries(${folder_name}_tests PRIVATE GTest::GTest GTest::Main)
# link the library we want to test

#target_link_libraries(${folder_name}_tests PRIVATE ${folder_name}_lib)
# add the include directories

#target_include_directories(${folder_name}_tests PUBLIC include)
# discover and add tests to the test list

#gtest_discover_tests(tdd_tests)
EOF

# CMakeLists.txt-Datei erstellen
cp "src/$folder_name/CMakeLists_template.txt" "src/$folder_name/CMakeLists.txt"

# Vorlagendatei löschen
rm "src/$folder_name/CMakeLists_template.txt"

echo "Der Ordner, die CMakeLists.txt-Datei und die Vorlagendatei wurden erfolgreich erstellt."
