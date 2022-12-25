cmake_minimum_required(VERSION 3.15)
project(raii_action_lib)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0")

file(GLOB SOURCES *.cpp)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${PROJECT_NAME} STATIC ${SOURCES})

set(RAII_ACTION_LIB_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(RAII_ACTION_LIB_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)

message("SOURCES = ${SOURCES}")
