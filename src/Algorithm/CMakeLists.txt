cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

add_library(Algorithm_header INTERFACE bag.hpp)
set(Algorithm_HPP ${CMAKE_CURRENT_SOURCE_DIR}/bag.hpp)
# target_include_directories(Stack_header INTERFACE "$<BUILD_INTERFACE:${STACK_HPP}>") 

