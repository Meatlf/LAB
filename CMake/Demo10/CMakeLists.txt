# This is the minimum cmake version supporting the modern cmake OpenMP module below
# modern cmake requires 3.0 anyway and android cmake requires 3.6
cmake_minimum_required(VERSION 3.1.3)

message("Hello World")
if(CMAKE_TOOLCHAIN_FILE)
message(CMAKE_TOOLCHAIN_FILE)
set(LIBRARY_OUTPUT_PATH_ROOT ${CMAKE_BINARY_DIR} CACHE ANDROID_PROGUARD_CONFIG_PATH "root for library")
get_filename_component(CMAKE_TOOLCHAIN_FILE_NAME ${CMAKE_TOOLCHAIN_FILE} NAME)
else()
message("Have not find CMAKE_TOOLCHAIN_FILE")
endif()
