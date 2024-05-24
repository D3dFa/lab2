cmake_minimum_required(VERSION 3.22)
project(lab2)

add_executable(craft
    src/craft.cpp
)

add_executable(lab2
    src/main.cpp
    src/Human.cpp
    src/Student.cpp

)
 
target_include_directories(lab2 PRIVATE include)
