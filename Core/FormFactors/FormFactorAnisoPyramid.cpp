// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FormFactors/FormFactorAnisoPyramid.cpp
//! @brief     Implements class FormFactorAnisoPyramid.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015-16
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FormFactorAnisoPyramid.h"
#include "BornAgainNamespace.h"
#include "MathFunctions.h"

const FormFactorPolyhedron::Topology FormFactorAnisoPyramid::topology = {
    { { 3, 2, 1, 0 }, false },
    { { 0, 1, 5, 4 }, false },
    { { 1, 2, 6, 5 }, false },
    { { 2, 3, 7, 6 }, false },
    { { 3, 0, 4, 7 }, false },
    { { 4, 5, 6, 7 }, false }
};

//! @brief Pyramid constructor
//! @param base_edge of one side of Pyramid's square base
//! @param height of Pyramid
//! @param angle in radians between base and facet

FormFactorAnisoPyramid::FormFactorAnisoPyramid(
    double length, double width, double height, double alpha)
    : FormFactorPolyhedron()
    , m_length(length)
    , m_width(width)
    , m_height(height)
    , m_alpha(alpha)
{
    setName(BornAgain::FFAnisoPyramidType);
    registerParameter(BornAgain::Length, &m_length, AttLimits::n_positive());
    registerParameter(BornAgain::Width, &m_width, AttLimits::n_positive());
    registerParameter(BornAgain::Height, &m_height, AttLimits::n_positive());
    registerParameter(BornAgain::Alpha, &m_alpha, AttLimits::n_positive());
    onChange();
}

void FormFactorAnisoPyramid::onChange()
{
    double cot_alpha = MathFunctions::cot(m_alpha);
    if( !std::isfinite(cot_alpha) || cot_alpha<0 )
        throw Exceptions::OutOfBoundsException("pyramid angle alpha out of bounds");
    if(cot_alpha*m_height > m_length || cot_alpha*m_height > m_width) {
        std::ostringstream ostr;
        ostr << "FormFactorAnisoPyramid() -> Error in class initialization with parameters";
        ostr << " length:" << m_length;
        ostr << " width:" << m_width;
        ostr << " height:" << m_height;
        ostr << " alpha[rad]:" << m_alpha << "\n\n";
        ostr << "Check for 'height <= (length,width)*tan(alpha)' failed.";
        throw Exceptions::ClassInitializationException(ostr.str());
    }

    double D = m_length/2;
    double d = m_length/2 - m_height*cot_alpha;
    double W = m_width/2;
    double w = m_width/2 - m_height*cot_alpha;

    setPolyhedron( topology, 0, false, {
        // base:
        { -D, -W, 0. },
        {  D, -W, 0. },
        {  D,  W, 0. },
        { -D,  W, 0. },
        // top:
        { -d, -w, m_height },
        {  d, -w, m_height },
        {  d,  w, m_height },
        { -d,  w, m_height } } );
}

FormFactorAnisoPyramid* FormFactorAnisoPyramid::clone() const
{
    return new FormFactorAnisoPyramid(m_length, m_width, m_height, m_alpha);
}

void FormFactorAnisoPyramid::accept(ISampleVisitor *visitor) const
{
    visitor->visit(this);
}
