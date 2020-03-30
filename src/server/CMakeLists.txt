set(project_name server)

if(UNIX AND (NOT APPLE))
    #Set rpath
    set(CMAKE_INSTALL_RPATH ".")
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
endif(UNIX AND (NOT APPLE))

file(GLOB_RECURSE SRC_LIST *.h *.hpp *.cpp *.cc *.c)
add_executable(${project_name} ${SRC_LIST})
add_dependencies(${project_name} asio_kcp_server)

if(WIN32)
    target_link_libraries(${project_name} 
        debug asio_kcp_server_d.lib
        optimized asio_kcp_server.lib)
else(UNIX)
    target_link_libraries(${project_name} 
        debug "${BIN_OUTPUT_DIR}/asio_kcp_server_d.a"
        debug "${BIN_OUTPUT_DIR}/essential_d.a"

        optimized "${BIN_OUTPUT_DIR}/asio_kcp_server.a"
        optimized "${BIN_OUTPUT_DIR}/essential.a"

        kcp
        pthread dl)
endif()

set_target_properties(${project_name} PROPERTIES OUTPUT_NAME_DEBUG "server_d")
set_target_properties(${project_name} PROPERTIES
    FOLDER "src"
	ARCHIVE_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR})
