cmake_minimum_required (VERSION 2.8)

# PROJECT(projectname [CXX] [C] [Java] project (Demo1)
PROJECT(HELLO)

ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(src bin)
INSTALL(FILES COPYRIGHT README.md DESTINATION share/doc/cmake/Demo1)

# output project source dir
# MESSAGE(${PROJECT_SOURCE_DIR})
# MESSAGE(${PROJECT_BINARY_DIR})

