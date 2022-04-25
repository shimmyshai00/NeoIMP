# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

set(SRCS
    Listener/IListener.hpp
    Listener/ListenerList.hpp
    Listener/ListenerList.tpp
    Mvc/IController.hpp
    Mvc/IViewProducer.hpp
    Connection.cpp
    Connection.hpp
    IConnectable.cpp
    IConnectable.hpp
    IDisconnector.hpp
)

target_sources(NeoIMP PUBLIC ${SRCS})