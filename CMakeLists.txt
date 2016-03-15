cmake_minimum_required(VERSION 2.8.4)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        LeetCodeUtils.cpp
        LeetCodeUtils.h
#        2TwoSum.cpp
#        3ThreeSumII.cpp
#        HappyNumber.cpp
#        MoveZeroes.cpp
        SimpleFunction.cpp)
add_executable(leetcode ${SOURCE_FILES})
