CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(LIBMXML_SRC mxml-attr.c mxml-entity.c mxml-file.c mxml-get.c mxml-node.c mxml-private.c mxml-set.c mxml-string.c)
ADD_LIBRARY(mxml SHARED ${LIBMXML_SRC})
ADD_LIBRARY(mxml_static STATIC ${LIBMXML_SRC})
SET_TARGET_PROPERTIES(mxml_static PROPERTIES VERSION 1 SOVERSION 1 OUTPUT_NAME "mxml")
# INSTALL(TARGETS hello hello_static LIBRARY DESTINATION lib
#	ARCHIVE DESTINATION lib)
# INSTALL(FILES hello.h DESTINATION include/hello)
