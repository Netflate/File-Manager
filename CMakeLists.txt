cmake_minimum_required(VERSION 3.16)
project(FileManager VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Quick QuickControls2 Qml REQUIRED)

set(SOURCES
        src/main.cpp
        src/ui/models/FileSystemModel.cpp
)

set(HEADERS
        src/ui/models/FileSystemModel.h
)

qt_add_resources(RESOURCES
        qml.qrc
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${RESOURCES})

# Add QML import path for development
set(QML_IMPORT_PATH ${CMAKE_SOURCE_DIR}/qml CACHE STRING "Qt Creator QML Module Path")

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt6::Core
        Qt6::Quick
        Qt6::QuickControls2
        Qt6::Qml
)