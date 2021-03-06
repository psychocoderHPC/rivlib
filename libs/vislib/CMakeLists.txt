#
# Vislib
#
cmake_minimum_required(VERSION 2.8)

project(vislib)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

set(BUILDING_VISLIB_PROJECT 1)
#set(BUILD_TESTS 1)


# processor word size detection
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(BITS 64)
else(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(BITS 32)
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)


# compiler options
if(GCC_VERSION VERSION_LESS 4.7)
  add_definitions(-std=c++0x -Wall -pedantic -ansi -fPIC -DUNIX -D_GNU_SOURCE -D_LIN${BITS} )
else()
  add_definitions(-std=c++11 -Wall -pedantic -ansi -fPIC -DUNIX -D_GNU_SOURCE -D_LIN${BITS} )
endif()

find_package(UUID REQUIRED)

add_subdirectory(base)
add_subdirectory(math)
add_subdirectory(sys)
add_subdirectory(net)
add_subdirectory(graphics)

if (BUILD_TESTS)
    add_subdirectory(glutInclude)
    add_subdirectory(gl)
	add_subdirectory(test)
	add_subdirectory(glutTest)
endif ()

add_dependencies(vislibmath${BITS} vislibbase${BITS})
add_dependencies(vislibsys${BITS} vislibmath${BITS} vislibbase${BITS})
add_dependencies(vislibnet${BITS} vislibsys${BITS} vislibmath${BITS} vislibbase${BITS})
add_dependencies(vislibgraphics${BITS} vislibsys${BITS} vislibmath${BITS} vislibbase${BITS})
if (BUILD_TESTS)
    add_dependencies(vislibgl${BITS} glutInclude vislibgraphics${BITS} vislibsys${BITS} vislibmath${BITS} vislibbase${BITS})
	add_dependencies(vislibtest vislibnet${BITS} vislibgraphics${BITS} vislibsys${BITS} vislibmath${BITS} vislibbase${BITS})
	add_dependencies(vislibgluttest glutInclude vislibgl${BITS} vislibgraphics${BITS} vislibsys${BITS} vislibmath${BITS} vislibbase${BITS})
endif ()

