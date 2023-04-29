cmake_minimum_required(VERSION 3.16)

project(gui VERSION 0.0.1 LANGUAGES CXX)

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

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")

file(GLOB PROJECT_HEADERS
    "*.h"
    "circuitwidget/*.h"
    "circuitwidget/components/*.h"
    "circuitwidget/components/active/*.h"
    "circuitwidget/components/logic/*.h"
    "circuitwidget/components/mcu/*.h"
    "circuitwidget/components/meters/*.h"
    "circuitwidget/components/other/*.h"
    "circuitwidget/components/outputs/*.h"
    "circuitwidget/components/passive/*.h"
    "circuitwidget/components/sources/*.h"
    "circuitwidget/components/switches/*.h"
    "componentselector/*.h"
    "editorwidget/*.h"
    "editorwidget/findreplacedialog/*.h"
    "filebrowser/*.h"
    "oscopewidget/*.h"
    "plotterwidget/*.h"
    "QPropertyEditor/*.h"
    "terminalwidget/*.h"
)

file(GLOB PROJECT_SOURCES
    "*.cc"
    "*.cpp"
    "circuitwidget/*.cpp"
    "circuitwidget/components/*.cpp"
    "circuitwidget/components/active/*.cpp"
    "circuitwidget/components/logic/*.cpp"
    "circuitwidget/components/mcu/*.cpp"
    "circuitwidget/components/meters/*.cpp"
    "circuitwidget/components/other/*.cpp"
    "circuitwidget/components/outputs/*.cpp"
    "circuitwidget/components/passive/*.cpp"
    "circuitwidget/components/sources/*.cpp"
    "circuitwidget/components/switches/*.cpp"
    "componentselector/*.cpp"
    "editorwidget/*.cpp"
    "editorwidget/findreplacedialog/*.cpp"
    "filebrowser/*.cpp"
    "oscopewidget/*.cpp"
    "plotterwidget/*.cpp"
    "QPropertyEditor/*.cpp"
    "terminalwidget/*.cpp"
) 

add_library( gui STATIC
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
)

target_include_directories( gui PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/circuitwidget
    ${CMAKE_CURRENT_SOURCE_DIR}/circuitwidget/components
    ${CMAKE_CURRENT_SOURCE_DIR}/circuitwidget/components/active
    ${CMAKE_CURRENT_SOURCE_DIR}/circuitwidget/components/logic
    ${CMAKE_CURRENT_SOURCE_DIR}/circuitwidget/components/mcu
    ${CMAKE_CURRENT_SOURCE_DIR}/circuitwidget/components/meters
    ${CMAKE_CURRENT_SOURCE_DIR}/circuitwidget/components/other
    ${CMAKE_CURRENT_SOURCE_DIR}/circuitwidget/components/outputs
    ${CMAKE_CURRENT_SOURCE_DIR}/circuitwidget/components/passive
    ${CMAKE_CURRENT_SOURCE_DIR}/circuitwidget/components/sources
    ${CMAKE_CURRENT_SOURCE_DIR}/circuitwidget/components/switches
    ${CMAKE_CURRENT_SOURCE_DIR}/componentselector
    ${CMAKE_CURRENT_SOURCE_DIR}/editorwidget
    ${CMAKE_CURRENT_SOURCE_DIR}/editorwidget/findreplacedialog
    ${CMAKE_CURRENT_SOURCE_DIR}/filebrowser
    ${CMAKE_CURRENT_SOURCE_DIR}/oscopewidget
    ${CMAKE_CURRENT_SOURCE_DIR}/plotterwidget
    ${CMAKE_CURRENT_SOURCE_DIR}/QPropertyEditor
    ${CMAKE_CURRENT_SOURCE_DIR}/terminalwidget
)

set_target_properties( gui PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER dev.naisys.net
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE FALSE
)

target_link_libraries( gui
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
    gpsim
    simavr
    simulator
)

install( TARGETS gui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
