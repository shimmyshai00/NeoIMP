# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

set(SRCS
    IUiEntryPoint.hpp
)

target_sources(NeoIMP PUBLIC ${SRCS})

# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

set(SRCS
    IUiEntryPoint.hpp
    getComponent.cpp
    getComponent.hpp
)

target_sources(NeoIMP PUBLIC ${SRCS})

add_subdirectory(Gui)
