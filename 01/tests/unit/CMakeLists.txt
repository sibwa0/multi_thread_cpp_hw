cmake_minimum_required(VERSION 3.0.0)
project(test_raii_action)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

file(GLOB SOURCES *.cpp)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${RAII_ACTION_LIB_INCLUDE_DIRS} ${UTILS_LIB_INCLUDE_DIRS} ${GOOGLETEST_PATH})
target_link_libraries(${PROJECT_NAME} ${RAII_ACTION_LIB_LIBRARIES} ${UTILS_LIB_LIBRARIES} GTest::gtest GTest::gtest_main)



message(STATUS "SOURCES = ${SOURCES}")
