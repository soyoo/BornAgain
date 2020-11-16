// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Sample/Interference/SSCApproximationStrategy.cpp
//! @brief     Implements class SSCApproximationStrategy.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "Sample/Interference/SSCApproximationStrategy.h"
#include "Base/Pixel/SimulationElement.h"
#include "Base/Types/Exceptions.h"
#include "Sample/Aggregate/IInterferenceFunction.h"
#include "Sample/Aggregate/InterferenceFunctionRadialParaCrystal.h"
#include "Sample/Fresnel/FormFactorCoherentSum.h"

complex_t SSCApproximationStrategy::getCharacteristicSizeCoupling(
    double qp, const std::vector<FormFactorCoherentSum>& ff_wrappers) const
{
    complex_t result{};
    for (auto& ffw : ff_wrappers) {
        double radial_extension = ffw.radialExtension();
        result +=
            ffw.relativeAbundance() * calculatePositionOffsetPhase(2.0 * qp, radial_extension);
    }
    return result;
}

complex_t
SSCApproximationStrategy::getCharacteristicDistribution(double qp,
                                                        const IInterferenceFunction* p_iff) const
{
    const InterferenceFunctionRadialParaCrystal* p_iff_radial =
        dynamic_cast<const InterferenceFunctionRadialParaCrystal*>(p_iff);
    if (!p_iff_radial)
        throw Exceptions::ClassInitializationException("Wrong interference function for SSCA");
    return p_iff_radial->FTPDF(qp);
}

complex_t SSCApproximationStrategy::calculatePositionOffsetPhase(double qp,
                                                                 double radial_extension) const
{
    return exp_I(m_kappa * qp * (radial_extension - m_mean_radius));
}

SSCApproximationStrategy::SSCApproximationStrategy(
    const std::vector<FormFactorCoherentSum>& weighted_formfactors,
    const IInterferenceFunction* p_iff, SimulationOptions sim_params, bool polarized, double kappa)
    : IInterferenceFunctionStrategy(weighted_formfactors, p_iff, sim_params, polarized)
    , m_kappa(kappa)
{
    m_mean_radius = 0.0;
    for (auto& ffw : m_weighted_formfactors)
        m_mean_radius += ffw.relativeAbundance() * ffw.radialExtension();
}

//! Returns the total scattering intensity for given kf and
//! for one particle layout (implied by the given particle form factors).
//! This is the scalar version
double SSCApproximationStrategy::scalarCalculation(const SimulationElement& sim_element) const
{
    double qp = sim_element.getMeanQ().magxy();
    double diffuse_intensity = 0.0;
    complex_t ff_orig = 0., ff_conj = 0.; // original and conjugated mean formfactor
    for (auto& ffw : m_weighted_formfactors) {
        complex_t ff = ffw.evaluate(sim_element);
        double fraction = ffw.relativeAbundance();
        diffuse_intensity += fraction * std::norm(ff);
        double radial_extension = ffw.radialExtension();
        complex_t prefac =
            ffw.relativeAbundance() * calculatePositionOffsetPhase(qp, radial_extension);
        ff_orig += prefac * ff;
        ff_conj += prefac * std::conj(ff);
    }
    complex_t mean_ff_norm = ff_orig * ff_conj;
    complex_t p2kappa = getCharacteristicSizeCoupling(qp, m_weighted_formfactors);
    complex_t omega = getCharacteristicDistribution(qp, m_iff.get());
    double iff = 2.0 * (mean_ff_norm * omega / (1.0 - p2kappa * omega)).real();
    double dw_factor = m_iff->DWfactor(sim_element.getMeanQ());
    return diffuse_intensity + dw_factor * iff;
}

//! This is the polarized version
double SSCApproximationStrategy::polarizedCalculation(const SimulationElement& sim_element) const
{
    double qp = sim_element.getMeanQ().magxy();
    Eigen::Matrix2cd diffuse_matrix = Eigen::Matrix2cd::Zero();
    const auto& polarization_handler = sim_element.polarizationHandler();
    Eigen::Matrix2cd ff_orig = Eigen::Matrix2cd::Zero();
    Eigen::Matrix2cd ff_conj = Eigen::Matrix2cd::Zero();
    for (auto& ffw : m_weighted_formfactors) {
        Eigen::Matrix2cd ff = ffw.evaluatePol(sim_element);
        double fraction = ffw.relativeAbundance();
        diffuse_matrix += fraction * (ff * polarization_handler.getPolarization() * ff.adjoint());
        double radial_extension = ffw.radialExtension();
        complex_t prefac =
            ffw.relativeAbundance() * calculatePositionOffsetPhase(qp, radial_extension);
        ff_orig += prefac * ff;
        ff_conj += prefac * ff.adjoint();
    }
    complex_t p2kappa = getCharacteristicSizeCoupling(qp, m_weighted_formfactors);
    complex_t omega = getCharacteristicDistribution(qp, m_iff.get());
    Eigen::Matrix2cd interference_matrix = (2.0 * omega / (1.0 - p2kappa * omega))
                                           * polarization_handler.getAnalyzerOperator() * ff_orig
                                           * polarization_handler.getPolarization() * ff_conj;
    Eigen::Matrix2cd diffuse_matrix2 = polarization_handler.getAnalyzerOperator() * diffuse_matrix;
    double interference_trace = std::abs(interference_matrix.trace());
    double diffuse_trace = std::abs(diffuse_matrix2.trace());
    double dw_factor = m_iff->DWfactor(sim_element.getMeanQ());
    return diffuse_trace + dw_factor * interference_trace;
}
