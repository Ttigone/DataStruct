cmake_minimum_required(VERSION 3.11 FATAL_ERROR)


add_library(String_header INTERFACE kmp.hpp)
set(STRING_HPP ${CMAKE_CURRENT_SOURCE_DIR}./String.hpp)
# target_include_directories(String_header INTERFACE "$<BUILD_INTERFACE:${STRING_HPP}>") 

