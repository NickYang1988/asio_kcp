set(project_name kcp_client)

file(GLOB_RECURSE SRC_LIST *.h *.hpp *.cpp *.cc *.c)

add_library(${project_name} STATIC ${SRC_LIST})

set_target_properties(${project_name} PROPERTIES PREFIX "")
set_target_properties(${project_name} PROPERTIES
    FOLDER "src"
	ARCHIVE_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR})

target_link_libraries(${project_name})