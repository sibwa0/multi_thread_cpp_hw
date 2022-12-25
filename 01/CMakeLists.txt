cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

project(project_hw1)

add_subdirectory(tests/tmp_func)

add_subdirectory(lib)

message("RAII_ACTION_LIB_INCLUDE_DIRS = ${RAII_ACTION_LIB_INCLUDE_DIRS}")
message("RAII_ACTION_LIB_LIBRARIES = ${RAII_ACTION_LIB_LIBRARIES}")

add_subdirectory(exe)

add_subdirectory(tests/unit)
