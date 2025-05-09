cmake_minimum_required(VERSION 3.14)
project(GTestTests)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

include_directories("../tasks")

set(TASK_SOURCES
    ../tasks/task3.cpp
    ../tasks/task4.cpp
    ../tasks/task6.cpp
    ../tasks/task7.cpp
)

add_executable(GTestTests 
    tests.cpp
    ${TASK_SOURCES}
)

target_include_directories(GTestTests PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(GTestTests PRIVATE gtest gtest_main)