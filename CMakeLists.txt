cmake_minimum_required(VERSION 3.5.1)
project (MyCourceWork)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(MY_ROOT ${CMAKE_SOURCE_DIR})

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

#gtest
link_directories(${MY_ROOT}/external/gtest/build)
set(PROJECT_LINK_LIBS libgtest.a)
include_directories(${MY_ROOT}/external/gtest/include)

#Debug for gdb
set(CMAKE_BUILD_TYPE Debug)

#Qt
find_package(Qt5Widgets)


# if(${CMAKE_BUILD_TYPE} Debug)
#     add_executable(main src/main.cpp)
# else()
add_executable(main
    src/main.cpp
    src/timeableClasses/source.cpp
    src/timeableClasses/bid.cpp
    src/buffer.cpp
    src/timeableClasses/device.cpp
    src/timeableClasses/controller.cpp
    src/timeableClasses/timeable.cpp
    src/layer.cpp
    src/utils/randomhelper.cpp
    src/timeableClasses/director.cpp
    src/controllers/devicescontroller.cpp
    src/controllers/sourcescontroller.cpp

#    test/buffer_test.cpp
#    test/randomHelper_test.cpp
#    test/source_test.cpp
#    test/source_controller_test.cpp
    test/device_controller_test.cpp
#    test/layer_test.cpp
)

#add_executable(
#)

# endif()

target_link_libraries(main -pthread ${PROJECT_LINK_LIBS} Qt5::Widgets Qt5::Core)
