cmake_minimum_required(VERSION 3.16)

project(gpsim VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
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
    "modules/*.h"
    "devices/*.h"
    "registers/*.h"
)

file(GLOB PROJECT_SOURCES
    "*.cc"
    "modules/*.cc"
    "devices/*.cc"
    "registers/*.cc"
) 

add_library( gpsim STATIC
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
)

target_include_directories( gpsim PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/modules
    ${CMAKE_CURRENT_SOURCE_DIR}/devices
    ${CMAKE_CURRENT_SOURCE_DIR}/registers
)

set_target_properties( gpsim PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER dev.naisys.net
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE FALSE
)

target_link_libraries( gpsim
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
    simavr
    simulator
)

install( TARGETS gpsim
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
