cmake_minimum_required(VERSION 4.1)
project(Poo_P1)

set(CMAKE_CXX_STANDARD 20)


include_directories(include)

add_executable(Poo_P1
        src/main.cpp
        include/credit.h
        src/credit.cpp
        include/Client.h
        src/Client.cpp
        include/Banca.h
        src/Banca.cpp)
