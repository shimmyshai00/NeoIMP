# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

set(SRCS
    conversion_factors.hpp
    IConverter.hpp
    CustomConversionContext.cpp
    CustomConversionContext.hpp
    LengthConverter.cpp
    LengthConverter.hpp
    ResolutionConverter.cpp
    ResolutionConverter.hpp
)

target_sources(NeoIMP PUBLIC ${SRCS})