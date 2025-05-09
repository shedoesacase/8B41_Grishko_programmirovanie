cmake_minimum_required(VERSION 3.14)
project(AssertTests)

include_directories("../tasks")
set(TASK_SOURCES 
    ../tasks/task1.cpp
)
add_executable(AssertTests 
    main.cpp          
    ${TASK_SOURCES}   
)
