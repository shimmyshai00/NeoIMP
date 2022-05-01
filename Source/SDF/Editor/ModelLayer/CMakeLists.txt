# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

set(SRCS
    getComponent.cpp
    getComponent.hpp
)

target_sources(NeoIMP PUBLIC ${SRCS})

add_subdirectory(DomainObjects)
add_subdirectory(Services)