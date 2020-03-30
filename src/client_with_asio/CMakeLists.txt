set(project_name client_with_asio)

if(UNIX AND (NOT APPLE))
    #Set rpath
    set(CMAKE_INSTALL_RPATH ".")
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
endif(UNIX AND (NOT APPLE))

file(GLOB_RECURSE SRC_LIST *.h *.hpp *.cpp *.cc *.c)
add_executable(${project_name} ${SRC_LIST})

if(WIN32)
    target_link_libraries(${project_name} 
        debug kcp_client_d.lib
        optimized kcp_client.lib)
else(UNIX)
    target_link_libraries(${project_name} 
        debug "${BIN_OUTPUT_DIR}/kcp_client_d.a"
        optimized "${BIN_OUTPUT_DIR}/kcp_client.a"

        ${Boost_LIBRARIES} kcp pthread dl)
endif()

set_target_properties(${project_name} PROPERTIES OUTPUT_NAME_DEBUG "${project_name}_d")
set_target_properties(${project_name} PROPERTIES
    FOLDER "src"
	ARCHIVE_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR})