#
# Find the libLTE includes and library
#
# This module defines
# LIBLTE_INCLUDE_DIR, where to find lte.h, etc.
# LIBLTE_LIBRARIES, the libraries to link against to use liblte.so.
# LIBLTE_FOUND, If false, do not try to use libLTE.

INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_LIBLTE "liblte")

FIND_PATH(LIBLTE_INCLUDE_DIRS
    NAMES lte.h
    HINTS ${PC_LIBLTE_INCLUDE_DIR}
    PATHS
    /usr/local/include
    /usr/include
)

FIND_LIBRARY(LIBLTE_LIBRARIES
    NAMES lte
    HINTS ${PC_LIBLTE_LIBDIR}
    PATHS
    ${LIBLTE_INCLUDE_DIRS}/../lib
    /usr/local/lib
    /usr/lib
)

LIST(APPEND LIBLTE_LIBRARIES ${CMAKE_DL_LIBS})
SET(LIBLTE_LIBRARY_DIRS ${PC_LIBLTE_LIBDIR})

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LIBLTE DEFAULT_MSG
  LIBLTE_LIBRARIES LIBLTE_INCLUDE_DIRS)
MARK_AS_ADVANCED(LIBLTE_LIBRARIES LIBLTE_INCLUDE_DIRS)
