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
#include "EnumListModel.hpp"
#include "Resources/Forms/ui_NewDocumentDialog.h"

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    EnumListModel<AbstractModel::Defs::Color::ColorFormat, AbstractModel::Defs::Color::COLOR_FMT_MAX>
        g_colorFormatSubtypeNames = {{AbstractModel::Defs::Color::COLOR_FMT_RGB24_888, "8 bpc"},
                                     {AbstractModel::Defs::Color::COLOR_FMT_RGBA32_8888, "8 bpc"}};

    auto g_rgbColorFormatSubtypeNames =
        EnumListModel<AbstractModel::Defs::Color::ColorFormat, AbstractModel::Defs::Color::COLOR_FMT_MAX>(
            g_colorFormatSubtypeNames, [](AbstractModel::Defs::Color::ColorFormat b_item) {
                return std::find(AbstractModel::Defs::Color::g_colorFormatsForRgb.begin(),
                                 AbstractModel::Defs::Color::g_colorFormatsForRgb.end(),
                                 b_item) != AbstractModel::Defs::Color::g_colorFormatsForRgb.end();
            });

    auto g_rgbaColorFormatSubtypeNames =
        EnumListModel<AbstractModel::Defs::Color::ColorFormat, AbstractModel::Defs::Color::COLOR_FMT_MAX>(
            g_colorFormatSubtypeNames, [](AbstractModel::Defs::Color::ColorFormat b_item) {
                return std::find(AbstractModel::Defs::Color::g_colorFormatsForRgba.begin(),
                                 AbstractModel::Defs::Color::g_colorFormatsForRgba.end(),
                                 b_item) != AbstractModel::Defs::Color::g_colorFormatsForRgba.end();
            });
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    EnumListModel<AbstractModel::Defs::Image::BackgroundPreset, AbstractModel::Defs::Image::PRE_BACKGROUND_MAX>
        g_presetNames = {{AbstractModel::Defs::Image::PRE_BACKGROUND_WHITE, "White"},
                         {AbstractModel::Defs::Image::PRE_BACKGROUND_BLACK, "Black"},
                         {AbstractModel::Defs::Image::PRE_BACKGROUND_TRANSPARENT, "Transparent"},
                         {AbstractModel::Defs::Image::PRE_BACKGROUND_CUSTOM, "Custom"}};

    auto g_presetNamesNoTransp =
        EnumListModel<AbstractModel::Defs::Image::BackgroundPreset, AbstractModel::Defs::Image::PRE_BACKGROUND_MAX>(
            g_presetNames, [](AbstractModel::Defs::Image::BackgroundPreset b_item) {
                return b_item != AbstractModel::Defs::Image::PRE_BACKGROUND_TRANSPARENT;
            });
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    class NewDocumentDialogRgbState;
    class NewDocumentDialogRgbaState;

    // The root for the state machine states.
    class NewDocumentDialogRootState : public Common::Hsm::HsmRootState<NewDocumentDialog> {
       public:
        typedef NewDocumentDialogRgbState Default;

        void processInput(NewDocumentDialog *a_hsm, const HsmQtSignalEvent &a_input) const {
            const auto *a_inputArgs = dynamic_cast<const HsmQtSignalEventArgs<int> *>(&a_input);

            if (a_inputArgs != nullptr) {
                // these must match the proper order of items in the list box
                switch (std::get<0>(a_inputArgs->args)) {
                    case 0:  // RGB
                        hsmTran<NewDocumentDialogRootState, NewDocumentDialogRgbState>(a_hsm);
                        break;
                    case 1:  // RGBA
                        hsmTran<NewDocumentDialogRootState, NewDocumentDialogRgbaState>(a_hsm);
                        break;
                }
            }
        }
    };

    // The state tree for the new-document dialog comes about due to the fact that certain options are only available
    // upon the selection or deselection of certain color models. In particular, bit depth settings and available
    // transparency options can vary from one type of color model to the next. In fact, we only need one layer of
    // hierarchy here so, in effect, this is really just a simple FSM, but the HSM framework is generic and can
    // take care of it easily.
    class NewDocumentDialogRgbState : public Common::Hsm::HsmLeafState<NewDocumentDialogRootState> {
       public:
        void enter(NewDocumentDialog *a_hsm) {
            using namespace AbstractModel::Defs::Color;

            // The available bit depths for the new-document dialog are entered into the list box here.
            a_hsm->m_ui->bitDepthSelector->setModel(&g_rgbColorFormatSubtypeNames);
            a_hsm->m_ui->initialBackgroundSelector->setModel(&g_presetNamesNoTransp);
        }

        void exit(NewDocumentDialog *a_hsm) {
            a_hsm->m_ui->initialBackgroundSelector->clear();
            a_hsm->m_ui->bitDepthSelector->clear();
        }
    };

    class NewDocumentDialogRgbaState : public Common::Hsm::HsmLeafState<NewDocumentDialogRootState> {
       public:
        void enter(NewDocumentDialog *a_hsm) {
            using namespace AbstractModel::Defs::Color;

            // The available bit depths for the new-document dialog are entered into the list box here.
            a_hsm->m_ui->bitDepthSelector->setModel(&g_rgbaColorFormatSubtypeNames);
            a_hsm->m_ui->initialBackgroundSelector->setModel(&g_presetNames);
        }

        void exit(NewDocumentDialog *a_hsm) {
            a_hsm->m_ui->initialBackgroundSelector->clear();
            a_hsm->m_ui->bitDepthSelector->clear();
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
        using namespace UiLayer::AbstractModel::Defs::Color;
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

        // Add image prefabs
        std::size_t numPrefabs = m_services.get<IGetImagePrefab>()->getNumPrefabs();
        for (std::size_t i(0); i < numPrefabs; ++i) {
            QString prefabTitle = QString::fromStdString(m_services.get<IGetImagePrefab>()->getPrefabTitle(i));
            m_ui->presetSelector->addItem(prefabTitle);
        }

        // Add color models
        m_ui->colorModelSelector->addItem(QComboBox::tr("RGB"), (int)COLOR_MODEL_RGB);
        m_ui->colorModelSelector->addItem(QComboBox::tr("RGBA"), (int)COLOR_MODEL_RGBA);

        // Hook signals
        connectToHsm(m_ui->colorModelSelector, QOverload<int>::of(&QComboBox::activated));

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