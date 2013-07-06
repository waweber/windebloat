project(debloatgui)

# Collect sources
file(GLOB_RECURSE debloatgui_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE debloatgui_FORMS ${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui)
file(GLOB_RECURSE debloatgui_MOC ${CMAKE_CURRENT_SOURCE_DIR}/ui/*.h)

QT4_WRAP_UI(debloatgui_SOURCES ${debloatgui_FORMS})
QT4_WRAP_CPP(debloatgui_SOURCES ${debloatgui_MOC})

# include
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Create target
add_executable(windebloat ${debloatgui_SOURCES})

# Link
target_link_libraries(windebloat debloat ${QT_LIBRARIES})
