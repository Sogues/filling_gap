# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("filling_gap")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -Wno-unused-variable -pthread")

# 包含子项目。
add_subdirectory ("gap_pthread")
add_subdirectory ("gap_container")
add_subdirectory ("gap_test")
add_subdirectory ("gap_leetcode")
add_subdirectory ("gap_algorithem")
