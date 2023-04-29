cmake_minimum_required(VERSION 3.16)

project(Libre-SimulIDE VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -std=c++17 -stdlib=libc++")

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

add_subdirectory(src/gpsim)
add_subdirectory(src/gui)
add_subdirectory(src/simavr)
add_subdirectory(src/simulator)

set( PROJECT_HEADERS
	src/appiface.h
	src/mainwindow.h
	src/simuapi_apppath.h
	src/utils.h
)

set( PROJECT_SOURCES
	src/main.cpp
	src/mainwindow.cpp
	src/simuapi_apppath.cpp
	src/application.qrc
) 

qt_add_executable( Libre-SimulIDE
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
)

target_include_directories( Libre-SimulIDE PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties( Libre-SimulIDE PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER dev.naisys.net
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE FALSE # If you want to enable std::cout in Windows :^)
)

target_link_libraries( Libre-SimulIDE
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
    simulator
)

install( TARGETS Libre-SimulIDE
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
