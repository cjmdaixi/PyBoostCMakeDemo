cmake_minimum_required(VERSION 3.14)
project(PyTunnel VERSION 1.0.0)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from gitlab")
    file(DOWNLOAD "http://git.shining3d.io/Sn3D_Standards/conan-cmake/raw/master/share/conan.cmake"
        "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(REQUIRES Boost/1.70.0@shining3d/stable
    BASIC_SETUP CMAKE_TARGETS
    BUILD_TYPE None
    BUILD never)

set(Boost_USE_STATIC_LIBS ON)
set(BOOST_ROOT ${CONAN_BOOST_ROOT})

find_package(Python3 COMPONENTS Development REQUIRED)
find_package(Boost COMPONENTS python REQUIRED)

add_library(pytunnel SHARED pytunnel.cpp)
set_target_properties(pytunnel PROPERTIES SUFFIX ".pyd")
target_link_libraries(pytunnel Python3::Python Boost::python)