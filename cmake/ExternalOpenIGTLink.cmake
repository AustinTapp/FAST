# Download and set up zlib

include(cmake/Externals.cmake)

ExternalProject_Add(OpenIGTLink
        PREFIX ${FAST_EXTERNAL_BUILD_DIR}/OpenIGTLink
        BINARY_DIR ${FAST_EXTERNAL_BUILD_DIR}/OpenIGTLink
        GIT_REPOSITORY "https://github.com/openigtlink/OpenIGTLink.git"
        GIT_TAG "5a501817c2da52e81db4db3eca6dd5111f94fed9"
        CMAKE_ARGS
            -DBUILD_SHARED_LIBS=ON
            -DBUILD_TESTING=OFF
            -DBUILD_EXAMPLES=OFF
            -DLIBRARY_OUTPUT_PATH=${FAST_EXTERNAL_INSTALL_DIR}/lib/
	    -DOpenIGTLink_INSTALL_LIB_DIR=${FAST_EXTERNAL_INSTALL_DIR}/lib/
        CMAKE_CACHE_ARGS
            -DCMAKE_BUILD_TYPE:STRING=Release
            -DCMAKE_VERBOSE_MAKEFILE:BOOL=OFF
            -DCMAKE_INSTALL_MESSAGE:BOOL=LAZY
            -DCMAKE_INSTALL_PREFIX:STRING=${FAST_EXTERNAL_INSTALL_DIR}
)

if(WIN32)
set(OpenIGTLink_LIBRARY ${FAST_EXTERNAL_INSTALL_DIR}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}OpenIGTLink.lib)
else()
set(OpenIGTLink_LIBRARY ${FAST_EXTERNAL_INSTALL_DIR}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}OpenIGTLink${CMAKE_SHARED_LIBRARY_SUFFIX})
endif()
list(APPEND LIBRARIES ${OpenIGTLink_LIBRARY})
list(APPEND FAST_EXTERNAL_DEPENDENCIES OpenIGTLink)