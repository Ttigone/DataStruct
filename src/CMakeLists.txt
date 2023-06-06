cmake_minimum_required(VERSION 3.25 FATAL_ERROR)


add_subdirectory(Seqlist)


add_executable(main main.cpp)

target_link_libraries(main
    PRIVATE
        Seqlist
)
