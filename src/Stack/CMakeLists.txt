cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

add_library(Stack_header INTERFACE Hanoi.hpp)
set(STACK_HPP ${CMAKE_CURRENT_SOURCE_DIR}/Stack.hpp)
# target_include_directories(Stack_header INTERFACE "$<BUILD_INTERFACE:${STACK_HPP}>") 

