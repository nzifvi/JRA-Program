cmake_minimum_required(VERSION 3.31)
project(JRAProgram)

set(CMAKE_CXX_STANDARD 20)

add_executable(JRAProgram main.cpp
        Headers/MapItem.cpp
        Headers/MapItem.h
        Headers/ChainingHashMap.cpp
        Headers/ChainingHashMap.h
        Headers/DynamicArray.cpp
        Headers/DynamicArray.h
        Headers/Node.cpp
        Headers/Node.h
        Headers/Lexer.cpp
        Headers/Lexer.h
        Headers/Parser.cpp
        Headers/Parser.h
        Headers/Graph.cpp
        Headers/Graph.h
        Headers/ComputationalGraph.cpp
        Headers/ComputationalGraph.h
)
