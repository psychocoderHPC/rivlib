#
# RIV Root CMakeLists
#
cmake_minimum_required(VERSION 2.8)

project(riv)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

set(BUILDING_RIV_PROJECT 1)
#set(BUILD_TESTS 1)

#set(CMAKE_VERBOSE_MAKEFILE ON)

# some manual external dependancies
find_package(TheLib++ REQUIRED)
find_package(Vislib REQUIRED)

# processor word size detection
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(BITS 64)
else(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(BITS 32)
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)


# actual projects
add_subdirectory(rivlib)
if (BUILD_TESTS)
    add_subdirectory(tests)
endif()
