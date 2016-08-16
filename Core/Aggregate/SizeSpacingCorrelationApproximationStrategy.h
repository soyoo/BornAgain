// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Aggregate/SizeSpacingCorrelationApproximationStrategy.h
//! @brief     Defines class SizeSpacingCorrelationApproximationStrategy.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef SIZESPACINGCORRELATIONAPPROXIMATIONSTRATEGY_H
#define SIZESPACINGCORRELATIONAPPROXIMATIONSTRATEGY_H

#include "IInterferenceFunctionStrategy.h"

class SimulationElement;

//! Strategy which implements size spacing correlation approximation.
//! @ingroup algorithms_internal

class SizeSpacingCorrelationApproximationStrategy : public IInterferenceFunctionStrategy
{
public:
    SizeSpacingCorrelationApproximationStrategy(SimulationOptions sim_params, double kappa);
    virtual ~SizeSpacingCorrelationApproximationStrategy() {}

    virtual void init(const SafePointerVector<FormFactorInfo>& form_factor_infos,
                      const IInterferenceFunction& iff);

protected:
    //! Evaluates the intensity for given list of evaluated form factors
    virtual double evaluateForList(const SimulationElement& sim_element,
                                   const std::vector<complex_t>& ff_list) const;

    //! Evaluates the intensity for given list of evaluated form factors
    //! in the presence of polarization of beam and detector
    double evaluateForMatrixList(const SimulationElement& sim_element,
                                 const matrixFFVector_t& ff_list) const;

private:
    complex_t getMeanCharacteristicFF(const kvector_t q,
                                      const std::vector<complex_t>& ff_list) const;
    Eigen::Matrix2cd getMeanCharacteristicMatrixFF(const kvector_t q,
                                                   const matrixFFVector_t& ff_list) const;
    complex_t getMeanConjCharacteristicFF(const kvector_t q,
                                          const std::vector<complex_t>& ff_list) const;
    Eigen::Matrix2cd getMeanConjCharacteristicMatrixFF(const kvector_t q,
                                                       const matrixFFVector_t& ff_list) const;
    complex_t getCharacteristicDistribution(double qp) const;
    complex_t getCharacteristicSizeCoupling(double qp, double kappa) const;
    complex_t calculatePositionOffsetPhase(double qp, double kappa, size_t index) const;
    double getqp(const kvector_t q) const;
    void initMeanRadius();
    double m_mean_radius;
    double m_kappa;
};

#endif // SIZESPACINGCORRELATIONAPPROXIMATIONSTRATEGY_H
