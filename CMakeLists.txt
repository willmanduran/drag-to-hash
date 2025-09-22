# ===== Packaging (CPack) =====
set(CPACK_PACKAGE_NAME "dragtohash")
set(CPACK_PACKAGE_VENDOR "Willman Durán")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Drag-and-drop file hasher")
set(CPACK_PACKAGE_CONTACT "contact@willmanstoolbox.com")
set(CPACK_PACKAGE_VERSION "0.1.0")

# Produce both .deb and .tar.gz
set(CPACK_GENERATOR "DEB;TGZ")

# Filename for the TGZ; DEB name is controlled by CPACK_DEBIAN_FILE_NAME
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-linux-x86_64")

# Debian-specific
set(CPACK_DEBIAN_FILE_NAME "DEB-DEFAULT")       # standard deb naming
set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Willman Durán <contact@willmanstoolbox.com>")

# Let dpkg-shlibdeps compute Depends from linked libs
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

# (Optional) force/append additional deps if you really want to pin them:
# set(CPACK_DEBIAN_PACKAGE_DEPENDS "libqt6widgets6, libqt6dbus6, libxkbcommon0")

include(CPack)
