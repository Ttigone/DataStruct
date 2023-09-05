cmake_minimum_required(VERSION 3.24 FATAL_ERROR)  

# 生成可执行文件
add_executable(main main.cpp)

add_subdirectory(Seqlist)
target_link_libraries(main PUBLIC SeqList_header)
# install(FILES SeqList.hpp DESTINATION Seqlist/)
target_include_directories(main INTERFACE "$<TARGET_PROPERTY:SeqList_header,INTERFACE_INCLUDE_DIRECTORIES>") 


add_subdirectory(Linkedlist)
target_link_libraries(main PUBLIC LinkedList_header)
install(FILES LinkedList.hpp DESTINATION LinkedList/)
target_include_directories(main INTERFACE "$<TARGET_PROPERTY:LinkedList_header,INTERFACE_INCLUDE_DIRECTORIES>") 

# install(FILES DoublyLinkedList.hpp DESTINATION LinkedList/)
# target_include_directories(main INTERFACE "$<TARGET_PROPERTY:DoublyLinkedList_header,INTERFACE_INCLUDE_DIRECTORIES>") 

add_subdirectory(Stack)
target_link_libraries(main PUBLIC Stack_header)
install(FILES Stack.hpp DESTINATION Stack/)
target_include_directories(main INTERFACE "$<TARGET_PROPERTY:Stack_header,INTERFACE_INCLUDE_DIRECTORIES>") 

add_subdirectory(Deque)
target_link_libraries(main PUBLIC Deque_header)
install(FILES Deque.hpp DESTINATION Deque/)
target_include_directories(main INTERFACE "$<TARGET_PROPERTY:Deque_header,INTERFACE_INCLUDE_DIRECTORIES>") 

add_subdirectory(String)
target_link_libraries(main PUBLIC String_header)
install(FILES String.hpp DESTINATION String/)
target_include_directories(main INTERFACE "$<TARGET_PROPERTY:String_header,INTERFACE_INCLUDE_DIRECTORIES>") 

add_subdirectory(Tree)
target_link_libraries(main PUBLIC Tree_header)
install(FILES Binary_Tree.hpp DESTINATION Tree/)
target_include_directories(main INTERFACE "$<TARGET_PROPERTY:Tree_header,INTERFACE_INCLUDE_DIRECTORIES>") 