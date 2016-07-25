// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Parametrization/ParameterPattern.h
//! @brief     Declares class ParameterPattern
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef PARAMETERPATTERN_H
#define PARAMETERPATTERN_H

#include <string>

//! @class ParameterPattern
//! @ingroup tools_internal
//! @brief Helper class for constructing parameter patterns.

class BA_CORE_API_ ParameterPattern
{
public:
    ParameterPattern() {}
    ParameterPattern(std::string root_object) : m_pattern ( "/" + root_object ) {}

    ParameterPattern& beginsWith(std::string start_type);
    ParameterPattern& add(std::string object_type);

    std::string toStdString() const { return m_pattern; }
private:
    std::string m_pattern;
};

#endif // PARAMETERPATTERN_H
