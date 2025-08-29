cmake_minimum_required(VERSION 4.0)

add_executable(C13start main.cpp
        ${MY_INCLUDE_DIR}/task1.h
        ${MY_INCLUDE_DIR}/task2.h
        ${MY_INCLUDE_DIR}/task3.h
        task1.cpp
        task2.cpp
        task3.cpp)

target_include_directories(C13start PUBLIC ${MY_INCLUDE_DIR})