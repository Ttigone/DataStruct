cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# 啥都不加

 add_library(SeqList_header INTERFACE)
 set(SEQLIST_HPP ${CMAKE_CURRENT_SOURCE_DIR}/SeqList.hpp)
# target_include_directories(SeqList_header INTERFACE "$<BUILD_INTERFACE:${SEQLIST_HPP}>") 