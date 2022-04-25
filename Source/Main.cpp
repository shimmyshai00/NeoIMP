// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Main.cpp
// PURPOSE: Implements the program main function.

#include "SDF/Editor/Qt/Application.hpp"

// FUNCTION: main
// PURPOSE:  Provides the program entry point.
// NOTES:    None.
int
main(int argc, char **argv) {
    return SDF::Editor::Qt::Application::getInstance()->exec(argc, argv);
}