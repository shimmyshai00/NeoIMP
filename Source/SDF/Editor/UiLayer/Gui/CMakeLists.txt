# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

set(SRCS
    EntryPoint.cpp
    EntryPoint.hpp
)

target_sources(NeoIMP PUBLIC ${SRCS})

add_subdirectory(Controller)
add_subdirectory(Qt)
