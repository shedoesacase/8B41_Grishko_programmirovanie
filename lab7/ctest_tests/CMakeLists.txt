cmake_minimum_required(VERSION 3.14)
project(CTestTests)

enable_testing()

include_directories("../tasks")

set(TASK_SOURCES ../tasks/task2.cpp)

file(GLOB TEST_SOURCES "*.cpp")  # Исправленный путь

foreach(test_src ${TEST_SOURCES})
    get_filename_component(test_name ${test_src} NAME_WE)
    add_executable(${test_name} ${test_src} ${TASK_SOURCES})
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()