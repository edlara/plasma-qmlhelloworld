cmake_minimum_required(VERSION 3.0)

set(VERSION 0.1.0)

project(plasma-qmlhelloworld VERSION 0.1.0)
add_definitions(-DPROJECT_VERSION="\\\"${PROJECT_VERSION}\\\"")

find_package(ECM 1.3.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})
set(CMAKE_AUTOMOC ON)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)
include(ECMInstallIcons)
include(FeatureSummary)

find_package(Qt5 REQUIRED
    Core
    Gui
    Widgets
    Quick
    DBus
)

find_package(KF5 REQUIRED
    Plasma
    I18n
    CoreAddons # KFormat
    Notifications
    IconThemes # KIconLoader
    KDELibs4Support #Solid::Power
)

add_definitions(
    -DQT_USE_FAST_CONCATENATION
    -DQT_USE_FAST_OPERATOR_PLUS
    -DQT_STRICT_ITERATORS
    -DCMAKE_SOURCE_DIR="${CMAKE_SOURCE_DIR}"
)

if(CMAKE_COMPILER_IS_GNUCXX)
  # more aggressive warnings and C++11 support
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
endif()

#
# Packing stuff
#
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Plasmoid Template")
set(CPACK_PACKAGE_VENDOR "Eduardo Lara")
set(CPACK_PACKAGE_DESCRIPTION_FILE ${CMAKE_CURRENT_SOURCE_DIR}/README.md)
set(CPACK_GENERATOR TBZ2)
set(CPACK_SOURCE_PACKAGE_FILE_NAME "plasmoid-qmlhelloworld-${VERSION}"
    CACHE INTERNAL "tarball basename")
set(CPACK_SOURCE_GENERATOR TBZ2)

# The following components are regex's to match anywhere (unless anchored)
# in absolute path + filename to find files or directories to be excluded
# from source tarball.
set(CPACK_SOURCE_IGNORE_FILES
   "\\\\.gitignore$" 
    "~$"
    "^${PROJECT_SOURCE_DIR}/build/"
    "^${PROJECT_SOURCE_DIR}/src/plasma/metadata.desktop"
    ".*~$"
    "\\\\..*\\\\.swp$"
    "\\\\.orig$"
    "\\\\.rej$"
    "\\\\.bak$"
)
include(CPack)

add_subdirectory(src)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)

