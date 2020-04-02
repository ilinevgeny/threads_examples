cmake_minimum_required(VERSION 3.10)
project(Threads)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads)

add_executable(test_std_thread main.cpp)

set_target_properties(test_std_thread PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON)
target_link_libraries(test_std_thread ${CMAKE_THREAD_LIB_INIT})


set(Boost_INCLUDE_DIR "g:/app/boost_1_69/include/boost-1_69")
set(Boost_LIBRARY_DIR g:/app/boost_1_69/lib)
#find_package(Boost COMPONENTS thread REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(test_boos_thread main_boost.cpp)
