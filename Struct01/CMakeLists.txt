cmake_minimum_required(VERSION 3.28)
project(Struct01 C)

set(CMAKE_C_STANDARD 11)

add_executable(Struct01 main.c
        aluno.c
        aluno.h)
