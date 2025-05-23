cmake_minimum_required(VERSION 3.10.0)
project(lab8 VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenCV REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(lab8t1 task1.cpp task1code.cpp)
add_executable(lab8t2 task2.cpp task2table.cpp)
add_executable(lab8t3 task3.cpp)


target_include_directories(lab8t3 PRIVATE 
    ${OpenCV_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIR}
)


target_link_libraries(lab8t3 PRIVATE 
    ${OpenCV_LIBS}
    ${OPENSSL_CRYPTO_LIBRARY}
)