// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Application.cpp
// PURPOSE: Implements the Application class.

#include "Application.hpp"

#include <QApplication>

namespace SDF::Editor::Qt {
    Application *Application::psm_instance = nullptr;
}  // namespace SDF::Editor::Qt

namespace SDF::Editor::Qt {
    Application *Application::getInstance() {
        if (psm_instance != nullptr) {
            psm_instance = new Application();
        }

        return psm_instance;
    }

    int Application::exec(int a_argc, char **a_argv) {
        QApplication myQApp(a_argc, a_argv);

        return myQApp.exec();
    }
}  // namespace SDF::Editor::Qt
