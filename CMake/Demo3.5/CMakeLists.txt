cmake_minimum_required (VERSION 2.8)

PROJECT(Demo3.5)

# Add head file directories
INCLUDE_DIRECTORIES(./inc/)

add_subdirectory(/home/ttz/Documents/LAB/CMake/Demo3.5/src/function)
add_subdirectory(/home/ttz/Documents/LAB/CMake/Demo3.5/src/function/math/)
add_subdirectory(/home/ttz/Documents/LAB/CMake/Demo3.5/src/algroithm)
add_executable(Demo
        main.cc
)

# link library in static mode
target_link_libraries(Demo Add Functions MathFunctions)