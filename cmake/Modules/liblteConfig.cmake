INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_LIBLTE liblte)

FIND_PATH(
    LIBLTE_INCLUDE_DIRS
    NAMES liblte/api.h
    HINTS $ENV{LIBLTE_DIR}/include
        ${PC_LIBLTE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    LIBLTE_LIBRARIES
    NAMES gnuradio-liblte
    HINTS $ENV{LIBLTE_DIR}/lib
        ${PC_LIBLTE_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LIBLTE DEFAULT_MSG LIBLTE_LIBRARIES LIBLTE_INCLUDE_DIRS)
MARK_AS_ADVANCED(LIBLTE_LIBRARIES LIBLTE_INCLUDE_DIRS)

