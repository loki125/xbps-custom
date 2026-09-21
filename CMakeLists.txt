cmake_minimum_required(VERSION 3.10)
project(xbps-custom)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(xbps-custom
    src/main.cpp
    src/cli.cpp
)

target_include_directories(xbps-custom PRIVATE include)
