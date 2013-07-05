cmake_minimum_required(VERSION 2.8)

project(WinDebloat CXX C)

# Find packages
find_package(Qt REQUIRED)

include(${QT_USE_FILE})

include_directories(${CMAKE_SOURCE_DIR})

# Add subprojects
add_subdirectory(libdebloat)
add_subdirectory(gui)

