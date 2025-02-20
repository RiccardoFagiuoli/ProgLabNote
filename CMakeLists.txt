cmake_minimum_required(VERSION 3.30)
project(ProgLabNote)

set(CMAKE_CXX_STANDARD 26)

add_executable(ProgLabNote main.cpp
        Collezioni.cpp
        Collezioni.h
        Note.cpp
        Note.h
        Observer.h
)
