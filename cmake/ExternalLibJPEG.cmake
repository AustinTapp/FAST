# Download and set up LibJPEG library

include(cmake/Externals.cmake)

if(WIN32)
ExternalProject_Add(libjpeg
        PREFIX ${FAST_EXTERNAL_BUILD_DIR}/libjpeg
        URL "https://github.com/CristiFati/Prebuilt-Binaries/raw/master/LibJPEG/v9d/LibJPEG-9d-Win-pc064.zip"
        UPDATE_COMMAND ""
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ${CMAKE_COMMAND} -E copy ${FAST_EXTERNAL_BUILD_DIR}/libjpeg/src/libjpeg/ ${FAST_EXTERNAL_INSTALL_DIR}/bin/libjpeg.dll
)
endif()