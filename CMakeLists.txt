cmake_minimum_required(VERSION 3.9)
project(DataStructure)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataStructure main.cpp RBTree/RBTree.h RBTree/RBTree.cpp RBTree/RBTreeUtil.h main.cpp)