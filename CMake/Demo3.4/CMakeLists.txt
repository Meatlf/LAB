# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo3.4)

include_directories(inc)

# 查找目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

add_subdirectory(src)

# 指定生成目标
add_executable(Demo ${DIR_SRCS})
find_library(MathFunctions_Libraries libMathFunctions.a /home/ttz/Documents/LAB/CMake/Demo3.4/src/function/math/build)

IF(NOT  MathFunctions_Libraries)
    message(FATAL_ERROR "lib MathFunctions not found")
ELSE(MathFunctions_Libraries)
    message(STATUS "Congratulations, lib MathFunctions  found")
ENDIF(NOT MathFunctions_Libraries)

target_link_libraries(Demo Functions ${MathFunctions_Libraries})

