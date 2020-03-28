cmake_minimum_required(VERSION 3.0)

#---------------------------------------------------------------------------------------
# Set default build type to release
#---------------------------------------------------------------------------------------
if(UNIX)
    if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
    endif()
endif()

#---------------------------------------------------------------------------------------
# Set CMAKE_MACOSX_RPATH
#---------------------------------------------------------------------------------------
if(APPLE)
    set(CMAKE_MACOSX_RPATH 1)
endif()

#---------------------------------------------------------------------------------------
# Compiler config
#---------------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#---------------------------------------------------------------------------------------
# 3rd cmake modules
#---------------------------------------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

#---------------------------------------------------------------------------------------
# Get version number.
#---------------------------------------------------------------------------------------
include(cmake/utils.cmake)
ak_extract_version()

#---------------------------------------------------------------------------------------
# Building tests and examples
#---------------------------------------------------------------------------------------
option(AK_BUILD_TESTS "Enable build tests" OFF)

#---------------------------------------------------------------------------------------
# asio_kcp project
#---------------------------------------------------------------------------------------
project(asio_kcp VERSION ${AK_VERSION} LANGUAGES CXX)
message(STATUS "Build asio_kcp: v${AK_VERSION}")

set(ROOT_DIR ${PROJECT_SOURCE_DIR})

find_package(Boost 1.72.0 REQUIRED)

set(BIN_OUTPUT_DIR ${ROOT_DIR}/build/bin)
#---------------------------------------------------------------------------------------
# Dependencies
set(SELF_BUILD_TYPE ${CMAKE_BUILD_TYPE})
add_subdirectory(3rdparty)
set(CMAKE_BUILD_TYPE ${SELF_BUILD_TYPE})
#---------------------------------------------------------------------------------------

if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest -D_CRT_SECURE_NO_WARNINGS -D_SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${BIN_OUTPUT_DIR}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${BIN_OUTPUT_DIR}")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${BIN_OUTPUT_DIR}")

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${BIN_OUTPUT_DIR}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${BIN_OUTPUT_DIR}")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${BIN_OUTPUT_DIR}")
else(UNIX)
    SET(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g -ggdb -Wall -Wextra -D_DEBUG -fPIC")
    SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -Wextra -DNDEBUG -fPIC")
    
    if (CMAKE_COMPILER_IS_GNUCXX AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 7.0)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
        set(CMAKE_CXX_STANDARD 11)
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
        set(CMAKE_CXX_STANDARD 17)
    endif()
    add_definitions(-Wno-unused-parameter -Wno-unused-variable -Wno-unused-function)

    if(XCODE)
        # set the output dir for xcode
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${BIN_OUTPUT_DIR}")
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${BIN_OUTPUT_DIR}")
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${BIN_OUTPUT_DIR}")

        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${BIN_OUTPUT_DIR}")
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${BIN_OUTPUT_DIR}")
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${BIN_OUTPUT_DIR}")
    endif(XCODE)
    
endif()

#---------------------------------------------------------------------------------------
# log
#---------------------------------------------------------------------------------------
message(STATUS "Current system is [${CMAKE_SYSTEM}]")
message(STATUS "ROOT_DIR=${ROOT_DIR}")
#message(STATUS "DEP_LIB_DIR=${DEP_LIB_DIR}")
message(STATUS "BIN_OUTPUT_DIR=${BIN_OUTPUT_DIR}")
message(STATUS "CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")

message(STATUS "Start building...")

#---------------------------------------------------------------------------------------
# Self defined postfix
#---------------------------------------------------------------------------------------
set(CMAKE_DEBUG_POSTFIX "_d" CACHE STRING "Set debug library postfix")
message(STATUS "Start to build all source...")

#---------------------------------------------------------------------------------------
# add include dirs and link dirs
#---------------------------------------------------------------------------------------
include_directories(
    ${ROOT_DIR}/3rdparty
    ${ROOT_DIR}/3rdparty/googletest/googletest/include
    ${ROOT_DIR}/3rdparty/googletest/googlemock/include
    ${Boost_INCLUDE_DIRS}
    ${ROOT_DIR}/src
    ${ROOT_DIR}/src/essential
    ${ROOT_DIR}/src/util
)

link_directories(${BIN_OUTPUT_DIR})

#---------------------------------------------------------------------------------------
# Building asio_kcp source.
#---------------------------------------------------------------------------------------
add_subdirectory(src/essential)
add_subdirectory(src/client_lib)
add_subdirectory(src/client_with_asio)
add_subdirectory(src/server_lib)
add_subdirectory(src/server)

#---------------------------------------------------------------------------------------
# Building tests
#---------------------------------------------------------------------------------------
if(AK_BUILD_TESTS)
    message(STATUS "Buiding tests ...")
    enable_testing()
    add_subdirectory(unittest/asio_kcp_client_unittest)
    add_subdirectory(unittest/asio_kcp_unittest)
endif(AK_BUILD_TESTS)