set(project_name asio_kcp_server)

file(GLOB_RECURSE SRC_LIST *.h *.hpp *.cpp *.cc *.c)
list(APPEND SRC_LIST ../util/connect_packet.cpp)

add_library(${project_name} STATIC ${SRC_LIST})

target_link_libraries(${project_name} 
    kcp
    debug essential_d
    optimized essential)

set_target_properties(${project_name} PROPERTIES PREFIX "")
set_target_properties(${project_name} PROPERTIES
    FOLDER "src"
	ARCHIVE_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR})

