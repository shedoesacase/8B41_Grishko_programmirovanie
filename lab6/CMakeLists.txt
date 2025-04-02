cmake_minimum_required(VERSION 3.10.0)
project(matrix VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCE_FILE
    main.cpp
    matrix.cpp
    square_matrix.cpp
    )

add_executable(matrix ${SOURCE_FILE})


