# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

set(SRCS
    MainWindow.cpp
    MainWindow.hpp
    NewDocumentDialog.cpp
    NewDocumentDialog.hpp
)

target_sources(NeoIMP PUBLIC ${SRCS})

add_subdirectory(CustomWidgets)
add_subdirectory(Resources)