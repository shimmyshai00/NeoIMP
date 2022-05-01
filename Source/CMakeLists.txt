# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

cmake_minimum_required(VERSION 3.16.3)
project(NeoIMP)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets UiTools)

set(SRCS Main.cpp)

add_executable(NeoIMP ${SRCS})
target_link_libraries(NeoIMP fruit Qt5::Core Qt5::Widgets Qt5::UiTools)

add_subdirectory(SDF)
