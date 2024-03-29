# 设置cmake 最低版本
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# ds 为工程名
project(ds
    VERSION         0.0.1
    DESCRIPTION     "cmake project of Data-Struct"
    HOMEPAGE_URL    "https://github.com/Ttigone/DataStruct"
    LANGUAGES       CXX
)

list(APPEND CMAKE_MESSAGE_CONTEXT       "VSCODE-STRUCTDATA")
list(APPEND CMAKE_MODULE_PATH           "${CMAKE_CURRENT_SOURCE_DIR}/vscode-structdata")

set(CMAKE_EXPORT_COMPILE_COMMANDS       ON)
set(TEST_TOP_SOURCE_DIR          ${CMAKE_CURRENT_SOURCE_DIR})
set(TEST_TOP_BINARY_DIR          ${CMAKE_CURRENT_BINARY_DIR})

 if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR AND NOT CMAKE_BUILD_TYPE)
     set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
     set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
 endif()

 if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
     message(FATAL_ERROR
     "\n"
     "In-source builds are not allowed.\n"
     "Instead, provide a path to build tree like so:\n"
     "cmake -S . -B <destination>\n"
     "\n"
     "To remove files you accidentally created execute:\n"
     "please delete CMakeFiles and CMakeCache.txt\n"
     )
 endif()

 set(CMAKE_CXX_STANDARD              20 )
 set(CMAKE_CXX_STANDARD_REQUIRED     ON )
 set(CMAKE_CXX_EXTENSIONS            OFF)
 set(CMAKE_CXX_VISIBILITY_PRESET     hidden)
 set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)
 set(CMAKE_INSTALL_RPATH             $ORIGIN $ORIGIN/../lib)
 set(CMAKE_INSTALL_PREFIX            "/usr/local")

 if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
     include(CheckIPOSupported)
     check_ipo_supported(RESULT ipo_supported)
     if(ipo_supported)
         message(STATUS "enable INTERPROCEDURAL OPTIMIZATION" )
         set(CMAKE_INTERPROCEDURAL_OPTIMIZATION True)
     endif()
 endif()

 if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
     message(STATUS "Configuring on/for Linux")
 elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
     message(STATUS "Configuring on/for macOS")
 elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
     message(STATUS "Configuring on/for Windows")
 else()
     message(STATUS "Configuring on/for ${CMAKE_SYSTEM_NAME}")
 endif()

include(GNUInstallDirs)
include(GenerateExportHeader)

add_subdirectory(src) #  这行代码搜索 src 文件夹，执行




 if(IS_BIG_ENDIAN)
     message(STATUS "Configuring on/for BIG_ENDIAN")
 else()
     message(STATUS "Configuring on/for LITTLE_ENDIAN")
 endif()


#  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/test_build_info.h
#      DESTINATION
#          ${CMAKE_INSTALL_INCLUDEDIR}
#  )





