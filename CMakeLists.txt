cmake_minimum_required(VERSION 3.20)
project(MyCppApp VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your executable
add_executable(MyCppApp src/main.cpp)