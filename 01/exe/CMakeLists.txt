project(main_app)


set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0 -fconcepts")

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC ${RAII_ACTION_LIB_LIBRARIES} ${UTILS_LIB_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${RAII_ACTION_LIB_INCLUDE_DIRS} ${UTILS_LIB_INCLUDE_DIRS})

message("RAII_ACTION_LIB_LIBRARIES = ${RAII_ACTION_LIB_LIBRARIES}")
