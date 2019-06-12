cmake_minimum_required(VERSION 3.14)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

include("${PROJECT_SOURCE_DIR}/cmake/functions.cmake")
google_initialize_cartographer_project()
google_enable_testing()
add_executable(leetcode
        algorithms/cpp/twoSum/twoSum_test.cpp
        )
target_link_libraries(leetcode ${GMOCK_LIBRARIES})
