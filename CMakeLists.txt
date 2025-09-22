cmake_minimum_required(VERSION 3.21)
project(dragtohash LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Enable Qt's automatic code generation
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
  # Embed the .ico into the .exe so Explorer shows the app icon
  target_sources(dragtohash PRIVATE resources/resources.rc)
endif()


target_link_libraries(dragtohash
  Qt${QT_VERSION_MAJOR}::Widgets
)

# Install the binary
install(TARGETS dragtohash RUNTIME DESTINATION bin)

# Install Linux desktop entry and icon so launchers find them
# (Icon name is "dragtohash"; we install a 256px PNG. Add other sizes if you have them.)
install(FILES packaging/linux/dragtohash.desktop DESTINATION share/applications)

install(FILES resources/icon.png
        DESTINATION share/icons/hicolor/256x256/apps
        RENAME dragtohash.png)
