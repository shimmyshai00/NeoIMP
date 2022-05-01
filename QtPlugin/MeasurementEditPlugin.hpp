#ifndef MEASUREMENT_EDIT_PLUGIN_HPP
#define MEASUREMENT_EDIT_PLUGIN_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    MeasurementEditPlugin.hpp
// PURPOSE: The header for the Qt Designer plugin for the MeasurementEdit custom widget.

#include <QDesignerCustomWidgetInterface>
#include <QIcon>
#include <QString>
#include <QWidget>

class MeasurementEditPlugin : public QObject, public QDesignerCustomWidgetInterface {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.shiningdestiny.neoimp.CustomWidgets.MeasurementEditPlugin")
    Q_INTERFACES(QDesignerCustomWidgetInterface)

   public:
    explicit MeasurementEditPlugin(QObject *parent = nullptr);

    void initialize(QDesignerFormEditorInterface *core) override;
    bool isInitialized() const override;

    QString name() const override;
    QString includeFile() const override;
    QString group() const override;
    QIcon icon() const override;
    QString toolTip() const override;
    QString whatsThis() const override;
    bool isContainer() const override;
    QString domXml() const override;
    QWidget *createWidget(QWidget *parent) override;

   private:
    bool m_initialized = false;
};

#endif  // MEASUREMENT_EDIT_PLUGIN_HPP