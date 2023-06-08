cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

add_executable(main main.cpp)

add_subdirectory(Seqlist)
target_link_libraries(main PUBLIC header)
install(FILES SeqList.hpp DESTINATION Seqlist)

# include_directories("Seqlist")
# add_library(header OBJECT "Seqlist/SeqList.hpp")  
# target_link_libraries(main header)
# target_include_directories(main PRIVATE "Seqlist")
# include_directories(Seqlist)
# add_library(template Seqlist/SeqList.cpp)

# target_include_directories(template PUBLIC 
#                            "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Seqlist>"
#                            "$<INSTALL_INTERFACE:Seqlist>")

# target_link_libraries(main template)

# target_include_directories(main PRIVATE "$<TARGET_PROPERTY:template,INTERFACE_INCLUDE_DIRECTORIES>") 

# install(DIRECTORY Seqlist/ DESTINATION Seqlist)

# install(TARGETS template EXPORT templateTargets 
#         ARCHIVE DESTINATION lib 
#         LIBRARY DESTINATION lib
#         RUNTIME DESTINATION bin)
