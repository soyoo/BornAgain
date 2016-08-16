// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Fit/Parameters/FitParameter.h
//! @brief     Defines class FitParameter.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FITPARAMETER_H
#define FITPARAMETER_H

#include "Attributes.h"
#include "Limits.h"
#include <string>

//! @class FitParameter
//! @ingroup fitting_internal
//! @brief Parameter with value, error and limits for fitting routines.

class BA_CORE_API_ FitParameter : public Limits, public Attributes
{
 public:
    FitParameter();
    FitParameter(
        const std::string& name, double value, double step=0.0,
        const Limits& limits=Limits::limitless(), const Attributes& attr=Attributes::free(),
        double error=0.0);
    virtual ~FitParameter(){}

    std::string getName() const { return m_name; }

    //! Sets value of parameter
    virtual void setValue(double value) { m_value = value; }
    //! Returns value of parameter
    virtual double getValue() const { return m_value; }

    //! Sets parameter step for minimizer
    virtual void setStep(double value) { m_step = value; }
    //! Returns parameter step for minimizer
    virtual double getStep() const { return m_step; }

    //! Sets parameter error
    virtual void setError(double value) { m_error = value; }
    //! Returns parameter step for minimizer
    virtual double getError() const { return m_error; }

    //! Prints class
    friend std::ostream& operator<<(std::ostream& ostr, const FitParameter& m) {
        m.print(ostr); return ostr; }

 protected:
    //! Prints class
    void print(std::ostream& ostr) const;

    std::string m_name;
    double m_value;
    double m_step;
    double m_error;
};

#endif // FITPARAMETER_H
