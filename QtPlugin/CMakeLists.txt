# (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.

cmake_minimum_required(VERSION 3.16.3)
project(NeoIMP LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5UiPlugin REQUIRED)

add_library(MeasurementEditPlugin SHARED
  ../Source/SDF/Editor/UiLayer/Gui/Qt/View/CustomWidgets/MeasurementEdit.hpp
  ../Source/SDF/Editor/UiLayer/Gui/Qt/View/CustomWidgets/MeasurementEdit.cpp
  MeasurementEditPlugin.cpp
)

target_link_libraries(MeasurementEditPlugin PRIVATE Qt5::Widgets Qt5::UiPlugin)