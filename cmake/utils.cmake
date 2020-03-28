# Get asio_kcp (aka. AK) version from VERSION and put it in AK_VERSION
function(ak_extract_version)
	file(READ "${CMAKE_CURRENT_LIST_DIR}/VERSION" file_contents)
	string(REGEX MATCH "AK_VER_MAJOR ([0-9]+)" _  "${file_contents}")
	if(NOT CMAKE_MATCH_COUNT EQUAL 1)
        message(FATAL_ERROR "Could not extract major version number from ARK/VERSION")
	endif()
	set(ver_major ${CMAKE_MATCH_1})

	string(REGEX MATCH "AK_VER_MINOR ([0-9]+)" _  "${file_contents}")
	if(NOT CMAKE_MATCH_COUNT EQUAL 1)
        message(FATAL_ERROR "Could not extract minor version number from ARK/VERSION")
	endif()

	set(ver_minor ${CMAKE_MATCH_1})
	string(REGEX MATCH "AK_VER_PATCH ([0-9]+)" _  "${file_contents}")
	if(NOT CMAKE_MATCH_COUNT EQUAL 1)
        message(FATAL_ERROR "Could not extract patch version number from ARK/VERSION")
	endif()
	set(ver_patch ${CMAKE_MATCH_1})

	set(AK_VERSION "${ver_major}.${ver_minor}.${ver_patch}" PARENT_SCOPE)
endfunction()