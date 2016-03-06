cmake_minimum_required(VERSION 3.2.1)

project(Jaipur)

if (NOT DEFINED JAIPUR_SOURCE_DIR)
    set(JAIPUR_SOURCE_DIR ${CMAKE_SOURCE_DIR})
endif ()

add_subdirectory(vendor)
add_subdirectory(source)