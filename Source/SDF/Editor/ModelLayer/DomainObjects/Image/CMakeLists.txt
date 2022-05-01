# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

set(SRCS
    Defs.hpp
    ImageComposite.hpp
    ImageComposite.tpp
    ABackgroundLayer.hpp
    ABackgroundLayer.tpp
)

target_sources(NeoIMP PUBLIC ${SRCS})

add_subdirectory(Components)
add_subdirectory(Gil)