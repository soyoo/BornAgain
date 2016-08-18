// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/FormFactor/IFormFactorDecorator.h
//! @brief     Defines pure virtual interface class IFormFactorDecorator.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef IFORMFACTORDECORATOR_H
#define IFORMFACTORDECORATOR_H

#include "IFormFactor.h"

//! Encapsulates another formfactor and adds extra functionality
//! (a scalar factor, a Debye-Waller factor, ...).
//! @ingroup formfactors_internal

class BA_CORE_API_ IFormFactorDecorator : public IFormFactor
{
public:
    IFormFactorDecorator(const IFormFactor& form_factor) : mp_form_factor(form_factor.clone()) {}
    virtual ~IFormFactorDecorator() { delete mp_form_factor; }
    virtual IFormFactorDecorator* clone() const = 0;
    virtual void accept(ISampleVisitor* visitor) const = 0;

    virtual void setAmbientMaterial(const IMaterial &material) {
        if (mp_form_factor)
            mp_form_factor->setAmbientMaterial(material);  }

    virtual double getVolume() const {
        return mp_form_factor ? mp_form_factor->getVolume() : 0; }

    virtual double getRadialExtension() const {
        return mp_form_factor ? mp_form_factor->getRadialExtension() : 0; }

protected:
    IFormFactor* mp_form_factor;
};

#endif // IFORMFACTORDECORATOR_H
