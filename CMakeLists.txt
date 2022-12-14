cmake_minimum_required(VERSION 3.20)
project(LAB_2_Supermarket_Modeling)

set(CMAKE_CXX_STANDARD 14)

add_executable(LAB_2_Supermarket_Modeling main.cpp Product.cpp Product.h Shelve.cpp Shelve.h Freezer.cpp Freezer.h
        Refrigerator.cpp Refrigerator.h FileReader.cpp FileReader.h Supermarket.cpp Supermarket.h)
