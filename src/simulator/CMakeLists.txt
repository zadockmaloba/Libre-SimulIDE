cmake_minimum_required(VERSION 3.16)

project(simulator VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")

set(USED_QT_APIS
        Core
        Gui
        Multimedia
        Widgets
        SerialPort
        Concurrent
        Qml
        Xml
        Svg
        Core5Compat
)

find_package(Qt6 6.2
        COMPONENTS
        ${USED_QT_APIS}
        REQUIRED
)

file(GLOB PROJECT_HEADERS
    "*.h"
    "*.hpp"
    "elements/*.h"
    "elements/active/*.h"
    "elements/logic/*.h"
    "elements/outputs/*.h"
    "elements/passive/*.h"
    "elements/processors/*.h"
)

file(GLOB PROJECT_SOURCES
    "*.cc"
    "*.cpp"
    "*.c"
    "elements/*.cpp"
    "elements/active/*.cpp"
    "elements/logic/*.cpp"
    "elements/outputs/*.cpp"
    "elements/passive/*.cpp"
    "elements/processors/*.cpp"
) 

add_library( simulator STATIC
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
)

target_include_directories( simulator PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/elements
    ${CMAKE_CURRENT_SOURCE_DIR}/elements/active
    ${CMAKE_CURRENT_SOURCE_DIR}/elements/logic
    ${CMAKE_CURRENT_SOURCE_DIR}/elements/outputs
    ${CMAKE_CURRENT_SOURCE_DIR}/elements/passive
    ${CMAKE_CURRENT_SOURCE_DIR}/elements/processors
)

set_target_properties( simulator PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER dev.naisys.net
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE FALSE
)

target_link_libraries( simulator
    PRIVATE Qt6::Core
    PRIVATE Qt6::Gui
    PRIVATE Qt6::Multimedia
    PRIVATE Qt6::Widgets
    PRIVATE Qt6::SerialPort
    PRIVATE Qt6::Concurrent
    PRIVATE Qt6::Qml
    PRIVATE Qt6::Xml
    PRIVATE Qt6::Svg
    PRIVATE Qt6::Core5Compat
    gui
    gpsim
    simavr
)

install( TARGETS simulator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
