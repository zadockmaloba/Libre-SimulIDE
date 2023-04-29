cmake_minimum_required(VERSION 3.16)

project(simavr VERSION 0.0.1 LANGUAGES C)
set(CMAKE_C_COMPILER gcc)

file(GLOB PROJECT_HEADERS
    "*.h"
    "cores/*.h"
    "cores/*.hpp"
    "cores/avr/*.h"
    "cores/avr/*.hpp"
    "sim/*.h"
    "sim/*.hpp"
    "sim/avr/*.h"
    "sim/avr/*.hpp"
)

file(GLOB PROJECT_SOURCES
    "*.cc"
    "*.cpp"
    "*.c"
    "cores/*.c"
    "cores/*.cpp"
    "cores/avr/*.c"
    "cores/avr/*.cpp"
    "sim/*.c"
    "sim/*.cpp"
    "sim/avr/*.c"
    "sim/avr/*.cpp"
) 

add_library( simavr STATIC
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
)

target_include_directories( simavr PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/cores
    ${CMAKE_CURRENT_SOURCE_DIR}/cores/avr
    ${CMAKE_CURRENT_SOURCE_DIR}/sim
    ${CMAKE_CURRENT_SOURCE_DIR}/sim/avr
)
if(APPLE)
    target_include_directories( simavr PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/cores
        ${CMAKE_CURRENT_SOURCE_DIR}/cores/avr
        ${CMAKE_CURRENT_SOURCE_DIR}/sim
        ${CMAKE_CURRENT_SOURCE_DIR}/sim/avr
        /usr/local/Cellar/libelf/0.8.13_1/include
        /usr/local/Cellar/libelf/0.8.13_1/include/libelf
    )
    target_link_libraries( simavr
        /usr/local/Cellar/libelf/0.8.13_1/lib/libelf.a
    )
endif()

set_target_properties( simavr PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER dev.naisys.net
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE FALSE
)

install( TARGETS simavr
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
