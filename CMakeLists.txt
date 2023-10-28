cmake_minimum_required(VERSION 3.15)
project(DLL-Injector)

set(CMAKE_CXX_STANDARD 20)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
file(GLOB_RECURSE SOURCES "mem/*.cpp" "naive/*.cpp" "mmap/*.cpp")

find_library(LIBRARY_NAME
    NAME "GH Injector - x64.lib"
    PATHS ${CMAKE_SOURCE_DIR}/lib)

if(LIBRARY_NAME)
    message(STATUS "Found GH Injector - x64.lib")
else()
    message(FATAL_ERROR "Could not find GH Injector - x64.lib")
endif()

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBRARY_NAME})