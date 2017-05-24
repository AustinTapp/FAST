# Setup all dependencies for FAST, both internal (have to be installed on the system)
# and external (downloaded and built automatically)

## OpenCL
find_package(OpenCL REQUIRED)
list(APPEND FAST_SYSTEM_LIBRARIES ${OpenCL_LIBRARIES})
#list(APPEND FAST_INCLUDE_DIRS "${OpenCL_INCLUDE_DIRS}")
#message("-- OpenCL include dir: ${OpenCL_INCLUDE_DIRS}")
message("-- OpenCL library: ${OpenCL_LIBRARIES}")

## OpenGL
find_package(OpenGL REQUIRED)
#list(APPEND FAST_SYSTEM_LIBRARIES ${OPENGL_LIBRARIES})
#list(APPEND FAST_INCLUDE_DIRS ${OPENGL_INCLUDE_DIR})
# If OS is Linux, also need X
#if(CMAKE_SYSTEM_NAME STREQUAL Linux)
#    find_package(X11 REQUIRED)
#    list(APPEND FAST_INCLUDE_DIRS ${X11_INCLUDE_DIR})
#    list(APPEND FAST_SYSTEM_LIBRARIES ${X11_LIBRARIES})
#endif()

## Qt
if(FAST_MODULE_Visualization)
    include(cmake/ExternalQt5.cmake)
    set(Qt5Core_DIR ${PROJECT_SOURCE_DIR}/cmake/Qt5Core)
    set(Qt5Gui_DIR ${PROJECT_SOURCE_DIR}/cmake/Qt5Gui)
    set(Qt5Widgets_DIR ${PROJECT_SOURCE_DIR}/cmake/Qt5Widgets)
    set(Qt5OpenGL_DIR ${PROJECT_SOURCE_DIR}/cmake/Qt5OpenGL)
    find_package(Qt5Widgets REQUIRED PATHS ${PROJECT_SOURCE_DIR}/cmake/)
    find_package(Qt5OpenGL REQUIRED PATHS ${PROJECT_SOURCE_DIR}/cmake/)
    #set(CMAKE_AUTOMOC ON)
    if(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
        add_definitions("-fPIC") # Get rid of Qt error with position independent code
    endif()
    #include(cmake/Qt5CoreMacros.cmake) # Need this for the qt5_use_modules macro
    #include(${PROJECT_BINARY_DIR}/lib/cmake/Qt5Gui/Qt5GuiConfig.cmake)
    #include(${PROJECT_BINARY_DIR}/lib/cmake/Qt5Widgets/Qt5WidgetsConfig.cmake)
    qt5_wrap_cpp(HEADERS_MOC ${QT_HEADERS})
    #list(APPEND LIBRARIES ${QT_LIBRARIES})
    #list(APPEND FAST_INCLUDE_DIRS "${Qt5Widgets_INCLUDE_DIRS}")
    #list(APPEND FAST_INCLUDE_DIRS "${Qt5OpenGL_INCLUDE_DIRS}")
    add_definitions("-DFAST_MODULE_VISUALIZATION")
endif()

## External depedencies
include(cmake/ExternalEigen.cmake)
include(cmake/ExternalZlib.cmake)

# Optional modules
include(cmake/ModuleVTK.cmake)
include(cmake/ModuleITK.cmake)
include(cmake/ModuleOpenIGTLink.cmake)
include(cmake/ModuleNeuralNetwork.cmake)
include(cmake/ModuleKinect.cmake)

# Make sure FAST can find external includes and libaries
link_directories(${FAST_EXTERNAL_INSTALL_DIR}/lib/)
list(APPEND FAST_INCLUDE_DIRS ${FAST_EXTERNAL_INSTALL_DIR}/include)
