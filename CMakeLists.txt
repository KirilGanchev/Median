cmake_minimum_required (VERSION 2.6)

set (CMAKE_CXX_STANDARD 11)

project (Median)
add_executable(Median main.cpp)

include(CTest)

add_test (MedianTest1 Median "${PROJECT_SOURCE_DIR}/Tests/test1")
set_tests_properties (MedianTest1 PROPERTIES PASS_REGULAR_EXPRESSION "52")

add_test (MedianTest2 Median "${PROJECT_SOURCE_DIR}/Tests/test2")
set_tests_properties (MedianTest2 PROPERTIES PASS_REGULAR_EXPRESSION "72")

add_test (MedianTest3 Median "${PROJECT_SOURCE_DIR}/Tests/test3")
set_tests_properties (MedianTest3 PROPERTIES PASS_REGULAR_EXPRESSION "68")
