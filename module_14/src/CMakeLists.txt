cmake_minimum_required(VERSION 4.0)

add_executable(C14start main.cpp
        ${MY_INCLUDE_DIR}/task1.h
        ${MY_INCLUDE_DIR}/task2.h
        ${MY_INCLUDE_DIR}/task3.h
        ${MY_INCLUDE_DIR}/task4.h
        ${MY_INCLUDE_DIR}/task5.h
        task1.cpp
        task2.cpp
        task3.cpp
        task4.cpp
        task5.cpp)

target_include_directories(C14start PUBLIC ${MY_INCLUDE_DIR})
