// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    NewDocumentDialog.cpp
// PURPOSE: Implements the NewDocumentDialog class.

#include "NewDocumentDialog.hpp"

#include <QtUiTools>

#include "../../../../../Common/Hsm/Hsm.hpp"
#include "../../../../../Common/Hsm/HsmInnerState.hpp"
#include "../../../../../Common/Hsm/HsmLeafState.hpp"
#include "../../../../../Common/Hsm/HsmRootState.hpp"
#include "../../../AbstractModel/Defs/Color/ColorFormat.hpp"
#include "../../../AbstractModel/Defs/Image/Spec.hpp"
#include "../../../AbstractModel/Defs/Metrics/LengthUnit.hpp"
#include "../../../AbstractModel/Defs/Metrics/ResolutionUnit.hpp"
#include "CustomWidgets/Converters.hpp"
#include "CustomWidgets/MeasurementEdit.hpp"
#include "Resources/Forms/ui_NewDocumentDialog.h"

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    // The root for the state machine states.

    class NewDocumentDialogRootState : public Common::Hsm::HsmRootState<NewDocumentDialog> {
       public:
        typedef class NewDocumentDialogDefaultState Default;

        void enter(NewDocumentDialog *a_hsm) {
            printf("entered NewDocumentDialogRootState\n");
        }
    };

    class NewDocumentDialogDefaultState : public Common::Hsm::HsmLeafState<NewDocumentDialogRootState> {
       public:
       void enter(NewDocumentDialog *a_hsm) {
            printf("entered NewDocumentDialogDefaultState\n");
        }
    };

    /*
    using namespace UiLayer::AbstractModel::Defs::Color;

    // Descriptions for the different color formats.
    struct ColorSubFmtEntry {
        std::string subFmtDesc;
        ColorFormat colorFormat;
    };

    struct ColorFmtEntry {
        std::string colorModelDesc;
        std::vector<ColorSubFmtEntry> colorSubFormats;
    };

    static const std::vector<ColorFmtEntry> g_colorFormatDescriptions = {{"RGB", {{"8 bpc", COLOR_FMT_RGB24_888}}},
                                                                         {"RGBA", {{"8 bpc", COLOR_FMT_RGBA32_8888}}}};
                                                                         */
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    NewDocumentDialog::NewDocumentDialog(deps_t a_deps, QWidget *a_parent)
        : HsmManagedView(a_parent), m_services(a_deps), m_ui(new Ui::NewDocumentDialog) {
        // Set up the dialog in the root state.
        using namespace UiLayer::AbstractModel::Defs::Metrics;
        using namespace UiLayer::AbstractModel::Defs::Image;
        using namespace UiLayer::AbstractModel::Services;

        const float c_defaultResPpi = 72.0f;

        m_ui->setupUi(this);

        // Create a measurement unit conversion context.
        m_conversionContext =
            m_services.get<IUnitConversionContextManipulator>()->createUnitConversionContext(c_defaultResPpi);

        // Inject and setup the measurement edit widgets.
        m_ui->widthEdit->setConverter(std::make_unique<CustomWidgets::LengthConverter>(m_services));
        m_ui->heightEdit->setConverter(std::make_unique<CustomWidgets::LengthConverter>(m_services));
        m_ui->resolutionEdit->setConverter(std::make_unique<CustomWidgets::ResolutionConverter>(m_services));

        m_ui->widthEdit->setConversionContext(m_conversionContext);
        m_ui->heightEdit->setConversionContext(m_conversionContext);
        m_ui->resolutionEdit->setConversionContext(m_conversionContext);

        m_ui->widthEdit->setMin(1.0f, LENGTH_UNIT_PIXEL);
        m_ui->widthEdit->setMax(m_services.get<IGetImageLimits>()->getMaximumImageWidth(), LENGTH_UNIT_PIXEL);

        m_ui->heightEdit->setMin(1.0f, LENGTH_UNIT_PIXEL);
        m_ui->heightEdit->setMax(m_services.get<IGetImageLimits>()->getMaximumImageHeight(), LENGTH_UNIT_PIXEL);

        m_ui->resolutionEdit->setMin(1.0f, RESOLUTION_UNIT_PPI);
        m_ui->resolutionEdit->setMax(1000.0f, RESOLUTION_UNIT_PPI);

        // Set defaults
        m_ui->widthEdit->setUnit(LENGTH_UNIT_PIXEL);
        m_ui->widthEdit->setQuantity(1280.0f);

        m_ui->heightEdit->setUnit(LENGTH_UNIT_PIXEL);
        m_ui->heightEdit->setQuantity(720.0f);

        m_ui->resolutionEdit->setUnit(RESOLUTION_UNIT_PPI);
        m_ui->resolutionEdit->setQuantity(c_defaultResPpi);

        // Add prefabs
        std::size_t numPrefabs = m_services.get<IGetImagePrefab>()->getNumPrefabs();
        for (std::size_t i(0); i < numPrefabs; ++i) {
            QString prefabTitle = QString::fromStdString(m_services.get<IGetImagePrefab>()->getPrefabTitle(i));
            m_ui->presetSelector->addItem(prefabTitle);
        }

        /*
        // Hook signals
        connect(m_ndd->ui->resolutionEdit, &CustomWidgets::MeasurementEdit::quantityChanged,
                [&](float b_newQuantity) {
                    float resPpi = m_ndd->ui->resolutionEdit->quantityIn(RESOLUTION_UNIT_PPI);
                    m_ndd->services.get<IUnitConversionContextManipulator>()->setConversionResolution(
                        m_conversionContext, resPpi);
                });

        connect(m_ndd->ui->presetSelector, QOverload<int>::of(&QComboBox::currentIndexChanged),
                [&](int b_newIndex) {
                    Spec prefabSpec = m_ndd->services.get<IGetImagePrefab>()->getPrefabSpec(b_newIndex);

                    // Fill out the fields. Remember to set units first because the quantities take in the
                    // currently-set unit. Also, the resolution should be filled out before the lengths so that they
                    // will be property interpreted.
                    m_ndd->ui->resolutionEdit->setUnit(prefabSpec.resolutionUnit);
                    m_ndd->ui->resolutionEdit->setQuantity(prefabSpec.resolution);

                    m_ndd->ui->widthEdit->setUnit(prefabSpec.widthUnit);
                    m_ndd->ui->widthEdit->setQuantity(prefabSpec.width);

                    m_ndd->ui->heightEdit->setUnit(prefabSpec.heightUnit);
                    m_ndd->ui->heightEdit->setQuantity(prefabSpec.height);

                    // setColorFormatBoxes(prefabSpec.colorFormat);
                });
                */

        // Select first prefab
        m_ui->presetSelector->setCurrentIndex(0);

        beginHsm<NewDocumentDialogRootState>();
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View