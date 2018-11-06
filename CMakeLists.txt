cmake_minimum_required(VERSION 3.12)
project(pruebas22)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(pruebas22 ${SOURCE_FILES})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/home/gaburolo/Documentos/SFML-2.4.2-linux-gcc-64-bit/SFML-2.4.2/share/SFML/cmake/Modules")
find_package(SFML REQUIRED graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(pruebas22 ${SFML_LIBRARIES})
endif(SFML_FOUND)