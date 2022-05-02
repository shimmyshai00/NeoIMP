# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

set(SRCS
    AImage.cpp
    AImage.hpp
)

target_sources(NeoIMP PUBLIC ${SRCS})

add_subdirectory(Math)
add_subdirectory(Metrics)
add_subdirectory(Image)
add_subdirectory(Color)