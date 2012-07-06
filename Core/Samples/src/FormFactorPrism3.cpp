#include "FormFactorPrism3.h"
#include "StochasticDiracDelta.h"

#include "MathFunctions.h"

FormFactorPrism3::FormFactorPrism3(double height, double half_side)
{
    mp_height = new StochasticDiracDelta<double>(height);
    mp_half_side = new StochasticDiracDelta<double>(half_side);
    m_root3 = std::sqrt(3.0);
}

FormFactorPrism3::FormFactorPrism3(StochasticParameter<double>* p_height,
        StochasticParameter<double>* p_half_side)
: mp_height(p_height)
, mp_half_side(p_half_side)
{
    m_root3 = std::sqrt(3.0);
}

FormFactorPrism3::~FormFactorPrism3()
{
    delete mp_height;
    delete mp_half_side;
}

FormFactorPrism3* FormFactorPrism3::clone() const
{
    return new FormFactorPrism3(mp_height->clone(), mp_half_side->clone());
}

complex_t FormFactorPrism3::evaluate_for_complex_qz(kvector_t q, complex_t qz) const
{
    double R = mp_half_side->getCurrent();
    double H = mp_height->getCurrent();

    complex_t qzH_half = qz*H/2.0;
    complex_t z_part = H*MathFunctions::Sinc(qzH_half)*std::exp(complex_t(0.0, 1.0)*qzH_half);

    complex_t xy_part = complex_t(0.0, 0.0);
    if (q.x()==0.0 && q.y()==0.0) {
        xy_part = m_root3*R*R;
    }
    else {
        double r3qyR = m_root3*q.y()*R;
        complex_t expminiqyRdivr3 = std::exp(-complex_t(0.0, 1.0)*q.y()*R/m_root3);
        if (q.x()*q.x()-3*q.y()*q.y()==0.0) {
            xy_part = complex_t(0.0, 1.0)*m_root3*expminiqyRdivr3*
                    (std::sin(r3qyR)-r3qyR*std::exp(complex_t(0.0, 1.0)*r3qyR))/q.x()/q.x();
        }
        else {
            double qxR = q.x()*R;
            xy_part = std::exp(complex_t(0.0, 1.0)*r3qyR)-std::cos(qxR)-complex_t(0.0, 1.0)*r3qyR*
                    MathFunctions::Sinc(qxR);
            xy_part *= 2*m_root3*expminiqyRdivr3/(q.x()*q.x()-3*q.y()*q.y());
        }
    }

    return xy_part*z_part;
}