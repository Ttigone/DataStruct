cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

add_library(LinkedList_header INTERFACE)
set(LINKEDLIST_HPP ${CMAKE_CURRENT_SOURCE_DIR})
# target_include_directories(LinkedList_header INTERFACE "$<BUILD_INTERFACE:${LINKEDLIST_HPP}>") 

# add_library(DoublyLinkedList_header INTERFACE)
# set(DOUBLYLINKEDLIST_HPP ${CMAKE_CURRENT_SOURCE_DIR}/DoublyLinkedList.hpp)
# target_include_directories(DoublyLinkedList_header INTERFACE "$<BUILD_INTERFACE:${DOUBLYLINKEDLIST_HPP}>")