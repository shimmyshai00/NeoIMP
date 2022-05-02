# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

set(SRCS
    IUidGenerator.hpp
    SimpleUidGenerator.cpp
    SimpleUidGenerator.hpp
    getComponent.cpp
    getComponent.hpp
)

target_sources(NeoIMP PUBLIC ${SRCS})
