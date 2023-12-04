cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

add_library(Deque_header INTERFACE)
set(DEQUE_HPP ${CMAKE_CURRENT_SOURCE_DIR}/Deque.hpp)
# target_include_directories(Deque_header INTERFACE "$<BUILD_INTERFACE:${DEQUE_HPP}>") 