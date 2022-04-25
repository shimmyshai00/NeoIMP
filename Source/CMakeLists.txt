# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

cmake_minimum_required(3.16.3)
project(NeoIMP)

add_subdirectory(SDF)

set(SRCS Main.cpp)

add_executable(neoimp ${SRCS})
