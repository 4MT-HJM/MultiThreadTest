PROJECT(MultiThreadTest)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "-std=c++14")
include_directories("googletest/googletest/include")
include_directories("googletest/googlemock/include")
include_directories("googletest/googletest")
include_directories("googletest/googlemock")
include_directories("inc")
add_library(gtestgmock googletest/googletest/src/gtest-all.cc googletest/googlemock/src/gmock-all.cc)


add_executable(MultiThreadTest test/MainTest.cpp src/MultiThread.cc test/MultiThreadTest.cc)
target_link_libraries(MultiThreadTest gtestgmock pthread)
