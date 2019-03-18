#CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
AUX_SOURCE_DIRECTORY(. DIR_LIB_SRCS)
find_library(Functions libmathfunctions.a ./)
ADD_LIBRARY(Functions ${DIR_LIB_SRCS})