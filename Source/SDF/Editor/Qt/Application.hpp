#ifndef SDF_EDITOR_QT_APPLICATION_HPP
#define SDF_EDITOR_QT_APPLICATION_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution
// terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Application.hpp
// PURPOSE: Defines the Application class.

#include <fruit/fruit.h>

namespace SDF::Editor::Qt {
    // CLASS:   Application
    // PURPOSE: Provides the application implementation for the Qt widget system. This class is (for reasons of
    //          necessity) a singleton global state object, so don't put too much in here.
    class Application {
       public:
        static Application *getInstance();

        int exec(int a_argc, char **a_argv);

       private:
        static Application *psm_instance;
    };
}  // namespace SDF::Editor::Qt

#endif  // SDF_EDITOR_QT_APPLICATION_HPP