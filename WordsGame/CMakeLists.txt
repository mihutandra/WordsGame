cmake_minimum_required(VERSION 3.24)
project(WordsGame)

set(CMAKE_CXX_STANDARD 11)

add_executable(WordsGame main.cpp GraphUtils.cpp Graph.cpp Graph.h GraphUtils.h Utils.cpp Utils.h)
