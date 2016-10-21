cmake_minimum_required(VERSION 3.5.1)
project (MyCourceWork)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(MY_ROOT ${CMAKE_SOURCE_DIR})


#gtest
link_directories(${MY_ROOT}/external/gtest/build)
set(PROJECT_LINK_LIBS libgtest.a)
include_directories(${MY_ROOT}/external/gtest/include)

add_executable(main src/main.cpp)
target_link_libraries(main -pthread ${PROJECT_LINK_LIBS})



# //////

# set(FILES_TO_TEST Testable.cpp)
# set(UNIT_TESTS test/main.cpp)
# set(MAIN_FILE src/main.cpp)

# add_subdirectory(gtest) #Build all the gtest stuff
# include_directories(gtest/include)
# include_directories(.)
# add_library(codeToTest ${FILES_TO_TEST})

# add_executable(mainsrc ${MAIN_FILE})
# target_link_libraries(mainsrc pthread ${PROJECT_LINK_LIBS})

# add_executable(maintest ${UNIT_TESTS})
# target_link_libraries(main)
