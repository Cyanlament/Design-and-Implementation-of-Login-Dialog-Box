cmake_minimum_required(VERSION 3.16)
project(LoginDialog)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt6_standard_project_setup()

set(SOURCES
    main.cpp
    logindialog.cpp
    registerdialog.cpp
)

set(HEADERS
    logindialog.h
    registerdialog.h
)

qt6_add_executable(LoginDialog ${SOURCES} ${HEADERS})

target_link_libraries(LoginDialog Qt6::Core Qt6::Widgets)

# Enable automoc
set_target_properties(LoginDialog PROPERTIES
    AUTOMOC ON
)