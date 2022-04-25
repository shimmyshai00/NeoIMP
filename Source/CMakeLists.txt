# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

cmake_minimum_required(VERSION 3.16.3)
project(NeoIMP)

set(SRCS Main.cpp)

add_executable(NeoIMP ${SRCS})
target_link_libraries(NeoIMP Qt5::Widgets)

add_subdirectory(SDF)
