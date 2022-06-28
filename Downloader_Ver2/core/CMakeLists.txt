cmake_minimum_required(VERSION 3.14)

project(downloader_new LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core5Compat)
find_package(Qt6 REQUIRED COMPONENTS Concurrent)
aux_source_directory(. DIR_SRCS)
add_executable(downloader_new
  ${DIR_SRCS}
)
target_link_libraries(downloader_new Qt6::Core5Compat)
target_link_libraries(downloader_new Qt6::Widgets)
target_link_libraries(downloader_new Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(downloader_new Qt${QT_VERSION_MAJOR}::Network)
target_link_libraries(downloader_new Qt6::Concurrent)
