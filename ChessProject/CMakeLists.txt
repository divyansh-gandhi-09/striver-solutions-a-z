cmake_minimum_required(VERSION 3.16)

project(Grandmaster)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(Grandmaster
    src/main.cpp
    src/chessboard.cpp
)

target_include_directories(Grandmaster PRIVATE include)
target_link_libraries(Grandmaster PRIVATE Qt6::Widgets)
