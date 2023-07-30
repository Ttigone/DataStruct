cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

add_library(LinkList_header INTERFACE)
set(LINKLIST_HPP ${CMAKE_CURRENT_SOURCE_DIR}/LinkList.hpp)
target_include_directories(LinkList_header INTERFACE "$<BUILD_INTERFACE:${LINKLIST_HPP}>") 

