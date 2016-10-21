cmake_minimum_required(VERSION 3.5.1)
project (MyCourceWork)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(MY_ROOT ${CMAKE_SOURCE_DIR})


#gtest
link_directories(${MY_ROOT}/external/gtest/build)
set(PROJECT_LINK_LIBS libgtest.a)
include_directories(${MY_ROOT}/external/gtest/include)



# if(${CMAKE_BUILD_TYPE} Debug)
#     add_executable(main src/main.cpp)
# else()
add_executable(main
    src/main.cpp
    test/main.cpp
)
# endif()

target_link_libraries(main -pthread ${PROJECT_LINK_LIBS})
