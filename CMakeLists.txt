# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

cmake_minimum_required(VERSION 3.16.3)
project(NeoIMP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(Source)
