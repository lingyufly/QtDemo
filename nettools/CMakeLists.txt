cmake_minimum_required(VERSION 3.1.0)

project(nettools)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

include_directories(include)
qt5_add_resources(QRC_FILES resource/nettools.qrc)
set(SRCS
	include/scanip.h  
	source/main.cpp
	source/scanip.cpp 
	${QRC_FILES})
	
set(LIBS ${LIBS} Qt5::Widgets Qt5::Network)

add_executable(nettools ${SRCS})
target_link_libraries(nettools ${LIBS})

