cmake_minimum_required(VERSION 3.5)
project(password_storage_app LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)

add_executable(password_storage_app
    main.cpp
    database.cpp
    encryption.cpp
    login.cpp
    mainwindow.cpp
)

target_link_libraries(password_storage_app PRIVATE Qt6::Widgets Qt6::Sql)
