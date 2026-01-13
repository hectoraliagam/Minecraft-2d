cmake_minimum_required(VERSION 3.20)

project(minecraft2d LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SFML_STATIC_LIBRARIES ON)

find_package(SFML 3 CONFIG REQUIRED COMPONENTS Graphics)

add_executable(app main.cpp)

target_link_libraries(app PRIVATE SFML::Graphics)
