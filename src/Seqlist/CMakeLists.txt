cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

add_library(header INTERFACE)
target_include_directories(header INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>")
target_include_directories(header INTERFACE "$<BUILD_INTERFACE:SeqList.hpp>")

