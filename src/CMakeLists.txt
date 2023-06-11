cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

add_executable(main main.cpp)

add_subdirectory(Seqlist)
target_link_libraries(main PUBLIC SeqList_header)
# install(FILES SeqList.hpp DESTINATION Seqlist/)
target_include_directories(main INTERFACE "$<TARGET_PROPERTY:SeqList_header,INTERFACE_INCLUDE_DIRECTORIES>") 


add_subdirectory(Linklist)
target_link_libraries(main PUBLIC LinkList_header)
install(FILES LinkList.hpp DESTINATION LinkList/)
target_include_directories(main INTERFACE "$<TARGET_PROPERTY:LinkList_header,INTERFACE_INCLUDE_DIRECTORIES>") 

add_subdirectory(Stack)
target_link_libraries(main PUBLIC Stack_header)
install(FILES Stack.hpp DESTINATION Stack/)
target_include_directories(main INTERFACE "$<TARGET_PROPERTY:Stack_header,INTERFACE_INCLUDE_DIRECTORIES>") 

add_subdirectory(Deque)
target_link_libraries(main PUBLIC Deque_header)
install(FILES Deque.hpp DESTINATION Deque/)
target_include_directories(main INTERFACE "$<TARGET_PROPERTY:Deque_header,INTERFACE_INCLUDE_DIRECTORIES>") 