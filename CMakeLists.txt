cmake_minimum_required(VERSION 3.21)
project(dragtohash LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(dragtohash
  src/main.cpp
  src/DropWidget.cpp
  src/DropWidget.h
)

target_link_libraries(dragtohash
  Qt${QT_VERSION_MAJOR}::Widgets
)
