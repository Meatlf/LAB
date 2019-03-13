SET(LIBMXML_SRC mxml-attr.c mxml-entity.c mxml-file.c mxml-get.c mxml-index.c mxml-node.c mxml-private.c mxml-search.c mxml-set.c mxml-string.c) 

ADD_LIBRARY(mxml SHARED ${LIBMXML_SRC})
ADD_LIBRARY(mxml_static STATIC ${LIBMXML_SRC})

## SET_TARGET_PROPERTIES(
## SET_TARGET_PROPERTIES(mxml PROPERTIES CLEAN_DIRECT_OUTPUT 1)
## SET_TARGET_PROPERTIES(mxml_static PROPERTIES OUTPUT_NAME "mxml")
