# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

add_subdirectory(CustomWidgets)

set(SRCS
    MainWindow.cpp
    MainWindow.hpp
    NewDocumentDialog.cpp
    NewDocumentDialog.hpp
)

target_sources(NeoIMP PUBLIC ${SRCS})

add_subdirectory(Resources)