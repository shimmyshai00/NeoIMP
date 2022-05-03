# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

set(SRCS
    EngineInfo.cpp
    EngineInfo.hpp
    ImagePrefabs.cpp
    ImagePrefabs.hpp
    CreateImage.cpp
    CreateImage.hpp
    UnitConversion.cpp
    UnitConversion.hpp
)

target_sources(NeoIMP PUBLIC ${SRCS})