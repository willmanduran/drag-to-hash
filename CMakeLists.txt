cmake_minimum_required(VERSION 3.21)
project(dragtohash LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(dragtohash
  src/main.cpp
  src/DropWidget.cpp
  src/DropWidget.h
  resources/resources.qrc
)

if(WIN32)
  target_sources(dragtohash PRIVATE resources/resources.rc)
endif()

target_link_libraries(dragtohash PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

install(TARGETS dragtohash RUNTIME DESTINATION bin)
install(FILES packaging/linux/dragtohash.desktop DESTINATION share/applications)
install(FILES resources/icon-256.png
        DESTINATION share/icons/hicolor/256x256/apps
        RENAME dragtohash.png)

set(CPACK_PACKAGE_NAME "dragtohash")
set(CPACK_PACKAGE_VENDOR "Willman Durán")
set(CPACK_PACKAGE_CONTACT "contact@willmanstoolbox.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Drag-and-drop file hasher")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")

set(CPACK_GENERATOR "DEB;TGZ")

set(CPACK_DEBIAN_FILE_NAME "DEB-DEFAULT")
set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Willman Durán <contact@willmanstoolbox.com>")

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)
