cmake_minimum_required(VERSION 3.10.2)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)

include("${PROJECT_SOURCE_DIR}/cmake/functions.cmake")
google_initialize_cartographer_project()
google_enable_testing()
add_executable(leetcode_temp
        algorithms/cpp/twoSum/twoSum_temp_test.cpp
        )
target_link_libraries(leetcode_temp ${GMOCK_LIBRARIES})

add_executable(leetcode
        algorithms/cpp/twoSum/twoSum_test.cpp
        )
target_link_libraries(leetcode ${GMOCK_LIBRARIES})


add_executable(leetcode_insert_sort
        algorithms/cpp/insertionSortList/insertionSortList_test.cpp)
target_link_libraries(leetcode_insert_sort ${GMOCK_LIBRARIES})
