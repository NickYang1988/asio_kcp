set(project_name server)

if(UNIX AND (NOT APPLE))
    #Set rpath
    set(CMAKE_INSTALL_RPATH ".")
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
endif(UNIX AND (NOT APPLE))

file(GLOB_RECURSE SRC_LIST *.h *.hpp *.cpp *.cc *.c)
add_executable(${project_name} ${SRC_LIST})

if(WIN32)
    target_link_libraries(${project_name})
else(UNIX)
    target_link_libraries(${project_name} pthread dl)
endif()

set_target_properties(${project_name} PROPERTIES OUTPUT_NAME_DEBUG "server_d")
set_target_properties(${project_name} PROPERTIES
    FOLDER "src"
	ARCHIVE_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR})
