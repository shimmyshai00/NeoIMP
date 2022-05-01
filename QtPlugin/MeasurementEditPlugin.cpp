// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    MeasurementEditPlugin.hpp
// PURPOSE: Adapt the MeasurementEdit custom widget to Qt Designer.


#include "MeasurementEditPlugin.hpp"

#include "../Source/SDF/Editor/UiLayer/Gui/Qt/View/CustomWidgets/MeasurementEdit.hpp"

#include <QtPlugin>

MeasurementEditPlugin::MeasurementEditPlugin(QObject *parent)
  : QObject(parent),
    m_initialized(false)
{
}

void
MeasurementEditPlugin::initialize(QDesignerFormEditorInterface *core) {
  if(m_initialized) {
    return;
  }

  m_initialized = true;
}

bool
MeasurementEditPlugin::isInitialized() const {
  return m_initialized;
}

QString
MeasurementEditPlugin::name() const {
  return QStringLiteral("SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets::MeasurementEdit");
}

QString
MeasurementEditPlugin::includeFile() const {
  return QStringLiteral("Source/SDF/Editor/UiLayer/Gui/Qt/View/CustomWidgets/MeasurementEdit.hpp");
}

QString
MeasurementEditPlugin::group() const {
  return tr("Input Widgets");
}

QIcon
MeasurementEditPlugin::icon() const {
  return QIcon("");
}

QString
MeasurementEditPlugin::toolTip() const {
  return tr("A widget for entering dimensionful measurements");
}

QString
MeasurementEditPlugin::whatsThis() const {
  return tr("Provides a way to enter measurements with a user-available selection of units, such as millimeters and "
            "inches. Note that, in order for it to work, however, it must be supplied in-program with suitable model "
            "service dependencies that hold the logic for the unit conversions."
           );
}

bool
MeasurementEditPlugin::isContainer() const {
  return false;
}

QString
MeasurementEditPlugin::domXml() const {
  /*
  return "<ui language=\"c++\" displayname=\"UnitQuantityEdit\">\n"
         "  <widget class=\"widgets::UnitQuantityEdit\" name="\unitquantityedit\">\n"
         "  <customwidgets>\n"
         "    <customwidget>\n"
         "      <class>widgets::UnitQuantityEdit</class>\n"
         "      <propertyspecifications>\n"
         "        <stringpropertyspecification name="
         */

/*
  return "<ui language=\"c++\" displayname=\"UnitQuantityEdit\">\n"
         "  <widget class=\"widgets::UnitQuantityEdit\" name=\"unitquantityedit\"/>\n"
         "  <customwidgets>\n"
         "    <customwidget>\n"
         "      <class>widgets::UnitQuantityEdit</class>\n"
         "    </customwidget>\n"
         "  </customwidgets>\n"
         "</ui>\n";
         */

  return QDesignerCustomWidgetInterface::domXml();
}

QWidget *
MeasurementEditPlugin::createWidget(QWidget *parent) {
  using SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets::MeasurementEdit;

  return new MeasurementEdit(parent);
}