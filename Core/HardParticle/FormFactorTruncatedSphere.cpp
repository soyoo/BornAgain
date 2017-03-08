// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/HardParticle/FormFactorTruncatedSphere.cpp
//! @brief     Implements class FormFactorTruncatedSphere.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FormFactorTruncatedSphere.h"
#include "BornAgainNamespace.h"
#include "Exceptions.h"
#include "RealLimits.h"
#include "MathFunctions.h"
#include "MathConstants.h"
#include "RealParameter.h"
#include "Rotations.h"
#include "TruncatedEllipsoid.h"
#include <limits>

FormFactorTruncatedSphere::FormFactorTruncatedSphere(double radius, double height, double dh)
    : m_radius(radius)
    , m_height(height)
    , m_dh(dh)
{
    setName(BornAgain::FFTruncatedSphereType);
    check_initialization();
    registerParameter(BornAgain::Radius, &m_radius).setUnit("nm").setNonnegative();
    registerParameter(BornAgain::Height, &m_height).setUnit("nm").setNonnegative();
    registerParameter(BornAgain::DeltaHeight, &m_dh).setUnit("nm").setNonnegative();
    mP_integrator = make_integrator_complex(this, &FormFactorTruncatedSphere::Integrand);
    onChange();
}

bool FormFactorTruncatedSphere::check_initialization() const
{
    bool result(true);
    if(m_height > 2.*m_radius || m_dh > m_height) {
        std::ostringstream ostr;
        ostr << "::FormFactorTruncatedSphere() -> Error in class initialization ";
        ostr << "with parameters 'radius':" << m_radius << " 'height':" << m_height
             << " 'delta_height':" << m_dh << "\n\n";
        ostr << "Check for height <= 2.*radius AND delta_height < height failed.";
        throw Exceptions::ClassInitializationException(ostr.str());
    }
    return result;
}

//! Integrand for complex formfactor.
complex_t FormFactorTruncatedSphere::Integrand(double Z) const
{
    double Rz = std::sqrt(m_radius*m_radius-Z*Z );
    complex_t qx = m_q.x();
    complex_t qy = m_q.y();
    complex_t q_p = std::sqrt(qx*qx + qy*qy); // NOT the modulus!
    return Rz*Rz*MathFunctions::Bessel_J1c(q_p*Rz) * exp_I(m_q.z()*Z);
}

//! Complex formfactor.
complex_t FormFactorTruncatedSphere::evaluate_for_q(cvector_t q) const
{
    m_q = q;
    if ( std::abs(q.mag()) < std::numeric_limits<double>::epsilon()) {
        double HdivR = m_height/m_radius;
        return M_PI/3.*m_radius*m_radius*m_radius
                *(3.*HdivR -1. - (HdivR - 1.)*(HdivR - 1.)*(HdivR - 1.));
    }
    // else
    complex_t integral = mP_integrator->integrate(m_radius-m_height, m_radius - m_dh);
    return M_TWOPI * integral * exp_I(q.z()*(m_height-m_radius));
}

IFormFactor* FormFactorTruncatedSphere::sliceFormFactor(ZLimits limits, const IRotation& rot,
                                                        kvector_t translation) const
{
    if (!IsZRotation(rot))
        throw std::runtime_error("FormFactorTruncatedSphere::sliceFormFactor error: "
                                 "rotation is not along z-axis.");
    double height = m_height - m_dh;
    double dz_bottom = limits.zmin() - translation.z();
    double dz_top = translation.z() + height - limits.zmax();
    switch (limits.type()) {
    case ZLimits::FINITE:
    {
        if (dz_bottom < 0 && dz_top < 0)
            throw std::runtime_error("FormFactorTruncatedSphere::sliceFormFactor error: "
                                     "interface outside shape.");
        if (dz_bottom > m_height)
            throw std::runtime_error("FormFactorTruncatedSphere::sliceFormFactor error: "
                                     "interface outside shape.");
        if (dz_top > m_height)
            throw std::runtime_error("FormFactorTruncatedSphere::sliceFormFactor error: "
                                     "interface outside shape.");
        if (dz_bottom + dz_top > m_height)
            throw std::runtime_error("FormFactorTruncatedSphere::sliceFormFactor error: "
                                     "limits zmax < zmin.");
        kvector_t position(translation);
        if (dz_bottom < 0)
            dz_bottom = 0;
        else
            position.setZ(limits.zmin());
        if (dz_top < 0)
            dz_top = 0;
        FormFactorTruncatedSphere slicedff(m_radius, height - dz_bottom, dz_top + m_dh);
        return CreateTransformedFormFactor(slicedff, rot, position);
    }
    case ZLimits::INFINITE:
    {
        throw std::runtime_error("FormFactorTruncatedSphere::sliceFormFactor error: "
                                 "shape didn't need to be sliced.");
    }
    case ZLimits::POS_INFINITE:
    {
        if (dz_bottom < 0.0 || dz_bottom > height)
            throw std::runtime_error("FormFactorTruncatedSphere::sliceFormFactor error: "
                                     "shape didn't need to be sliced.");
        FormFactorTruncatedSphere slicedff(m_radius, height - dz_bottom, m_dh);
        kvector_t position(translation.x(), translation.y(), limits.zmin());
        return CreateTransformedFormFactor(slicedff, rot, position);
    }
    case ZLimits::NEG_INFINITE:
    {
        if (dz_top < 0.0 || dz_top > height)
            throw std::runtime_error("FormFactorTruncatedSphere::sliceFormFactor error: "
                                     "shape didn't need to be sliced.");
        FormFactorTruncatedSphere slicedff(m_radius, height, dz_top + m_dh);
        return CreateTransformedFormFactor(slicedff, rot, translation);
    }
    }
    return nullptr;
}

void FormFactorTruncatedSphere::onChange()
{
    mP_shape.reset(new TruncatedEllipsoid(m_radius, m_radius, m_radius, m_height, m_dh));
}
