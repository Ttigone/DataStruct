cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

add_library(Tree_header INTERFACE)
set(BINARY_TREE_HPP ${CMAKE_CURRENT_SOURCE_DIR}/Binary_Tree.hpp)
target_include_directories(Tree_header INTERFACE "$<BUILD_INTERFACE:${BINARY_TREE_HPP}>") 