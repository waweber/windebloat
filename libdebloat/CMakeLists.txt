project(libdebloat)

# Collect sources
file(GLOB_RECURSE libdebloat_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Create target
add_library(debloat STATIC ${libdebloat_SOURCES})