// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/InstrumentWidgets/InstrumentComponentsWidget.cpp
//! @brief     Implements class InstrumentComponentsWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "InstrumentComponentsWidget.h"
#include "BeamEditorWidget.h"
#include "DetectorEditorWidget.h"
#include <QVBoxLayout>
#include <QDebug>


InstrumentComponentsWidget::InstrumentComponentsWidget(QWidget *parent)
    : QWidget(parent)
    , m_beamEditor(new BeamEditorWidget)
    , m_detectorEditor(new DetectorEditorWidget)
    , m_beamItem(0)
    , m_detectorItem(0)
{
//    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
//    mainLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    mainLayout->addWidget(m_beamEditor);
    mainLayout->addWidget(m_detectorEditor);
//    setStyleSheet("InstrumentComponentsWidget {background-color:black;}");
//    mainLayout->addStretch();
//    setLayout(mainLayout);
}


void InstrumentComponentsWidget::setBeamItem(BeamItem *beamItem)
{
    m_beamItem = beamItem;
    m_beamEditor->setBeamItem(beamItem);
}

void InstrumentComponentsWidget::setDetectorItem(DetectorItem *detectorItem)
{
    m_detectorItem = detectorItem;
    m_detectorEditor->setDetectorItem(detectorItem);

}
