// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/InstrumentWidgets/GISASInstrumentEditor.cpp
//! @brief     Implements class GISASInstrumentEditor
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "GISASInstrumentEditor.h"
#include "BackgroundItems.h"
#include "BeamEditorWidget.h"
#include "ComponentEditor.h"
#include "ColumnResizer.h"
#include "DetectorEditorWidget.h"
#include "DetectorItems.h"
#include "InstrumentItems.h"
#include "GroupItem.h"
#include <QVBoxLayout>

namespace
{
const QString background_title("Background");
}

GISASInstrumentEditor::GISASInstrumentEditor(QWidget* parent)
    : SessionItemWidget(parent)
    , m_columnResizer(new ColumnResizer(this))
    , m_beamEditor(new BeamEditorWidget)
    , m_detectorEditor(new DetectorEditorWidget(m_columnResizer))
    , m_backgroundEditor(new ComponentEditor(ComponentEditor::PlainWidget, background_title))
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(m_beamEditor);
    mainLayout->addWidget(m_detectorEditor);
    mainLayout->addWidget(m_backgroundEditor);
    mainLayout->addStretch();

    m_columnResizer->addWidgetsFromGridLayout(m_beamEditor->gridLayout(), 0);
    m_columnResizer->addWidgetsFromGridLayout(m_beamEditor->gridLayout(), 1);
    m_columnResizer->addWidgetsFromGridLayout(m_beamEditor->gridLayout(), 2);

    connect(m_detectorEditor, &DetectorEditorWidget::extendedDetectorEditorRequest,
            this, &GISASInstrumentEditor::extendedDetectorEditorRequest);

    setStyleSheet("InstrumentComponentsWidget {background-color:transparent;}");
}

void GISASInstrumentEditor::subscribeToItem()
{
    m_beamEditor->setBeamItem(instrumentItem()->beamItem());
    m_detectorEditor->setItem(instrumentItem());
    m_backgroundEditor->setItem(instrumentItem()->backgroundGroup());
}

void GISASInstrumentEditor::unsubscribeFromItem()
{
    m_backgroundEditor->clearEditor();
    m_beamEditor->setBeamItem(nullptr);
    m_detectorEditor->setItem(nullptr);
}

GISASInstrumentItem* GISASInstrumentEditor::instrumentItem()
{
    auto result = dynamic_cast<GISASInstrumentItem*>(currentItem());
    Q_ASSERT(result);
    return result;
}
