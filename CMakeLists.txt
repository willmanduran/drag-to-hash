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

# ===== Packaging (CPack) =====
set(CPACK_PACKAGE_NAME "dragtohash")
set(CPACK_PACKAGE_VENDOR "You")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Drag-to-Hash: drop files, hash, save")
set(CPACK_PACKAGE_CONTACT "you@example.com")

# Version – change as needed or set from git
set(CPACK_PACKAGE_VERSION "0.1.0")

# Where the installed files go inside the packages (uses your install() rules)
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-linux-x86_64")

# TGZ
set(CPACK_GENERATOR "DEB;TGZ")

# Debian metadata
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "You")
set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
# Runtime deps (keep minimal; adjust to your distro if needed)
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.31), libstdc++6 (>= 11), libqt6widgets6 (>= 6.2)")

include(CPack)
