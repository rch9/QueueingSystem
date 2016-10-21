cmake_minimum_required(VERSION 3.5.1)
project (MyCourceWork)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(MY_ROOT ${CMAKE_SOURCE_DIR})

#gtest
set(PROJECT_LINK_LIBS libgtest.a)
link_directories(MY_ROOT/external/gtest/build)
include_directories(MY_ROOT/external/gtest/include)

add_executable(main src/main.cpp)
target_link_libraries(main ${PROJECT_LINK_LIBS})
