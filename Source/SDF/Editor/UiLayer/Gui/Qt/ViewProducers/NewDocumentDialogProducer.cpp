// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    NewDocumentDialogProducer.cpp
// PURPOSE: Implements the NewDocumentDialogProducer class.

#include "NewDocumentDialogProducer.hpp"

#include "../View/NewDocumentDialog.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers {
    NewDocumentDialogProducer::NewDocumentDialogProducer(deps_t a_deps, QWidget *a_parent)
        : m_services(a_deps), m_parent(a_parent) {}

    void NewDocumentDialogProducer::requestView() {
        View::NewDocumentDialog *ndd = new View::NewDocumentDialog(m_services, m_parent);
        ndd->setAttribute(::Qt::WA_DeleteOnClose);
        ndd->show();
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers