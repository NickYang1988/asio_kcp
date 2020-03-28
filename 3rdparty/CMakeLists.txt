message(STATUS "Add 3rdparty projects...")

set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Set dependencies as release mode" FORCE)

if(WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${BIN_OUTPUT_DIR}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${BIN_OUTPUT_DIR}")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${BIN_OUTPUT_DIR}")

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${BIN_OUTPUT_DIR}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${BIN_OUTPUT_DIR}")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${BIN_OUTPUT_DIR}")
endif()

#------------------------------------------------------------------------------
# kcp
#------------------------------------------------------------------------------
add_subdirectory(kcp)
set(THIRD_PARTY_TARGET kcp)

#------------------------------------------------------------------------------
# google test
#------------------------------------------------------------------------------
if(AK_BUILD_TESTS)
    add_subdirectory(googletest)
    # set output directory
    list(APPEND THIRD_PARTY_TARGET
        gtest
        gtest_main
        gmock
        gmock_main)
endif(AK_BUILD_TESTS)

foreach(target_index ${THIRD_PARTY_TARGET})
    set_target_properties(${target_index} PROPERTIES
            FOLDER "3rdparty"
            ARCHIVE_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
            RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
            LIBRARY_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR})
endforeach(target_index)