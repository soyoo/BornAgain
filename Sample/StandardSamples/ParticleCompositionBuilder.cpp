// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Sample/StandardSamples/ParticleCompositionBuilder.cpp
//! @brief     Implements class ParticleCompositionBuilder.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "Sample/StandardSamples/ParticleCompositionBuilder.h"
#include "Base/Const/Units.h"
#include "Sample/Aggregate/InterferenceFunction2DLattice.h"
#include "Sample/Aggregate/ParticleLayout.h"
#include "Sample/HardParticle/FormFactorFullSphere.h"
#include "Sample/Multilayer/Layer.h"
#include "Sample/Multilayer/MultiLayer.h"
#include "Sample/Particle/Particle.h"
#include "Sample/Particle/ParticleComposition.h"
#include "Sample/StandardSamples/ReferenceMaterials.h"

// --- ParticleCompositionBuilder ---

MultiLayer* ParticleCompositionBuilder::buildSample() const
{
    Layer vacuum_layer(refMat::Vacuum);
    Layer substrate_layer(refMat::Substrate);

    double radius(10.0 * Units::nanometer);
    FormFactorFullSphere sphere_ff(radius);
    Particle sphere(refMat::Particle, sphere_ff);
    ParticleLayout particle_layout;

    std::vector<kvector_t> positions = {
        {}, {radius, radius / std::sqrt(3.0), std::sqrt(8.0 / 3.0) * radius}};

    ParticleComposition basis;

    basis.addParticles(sphere, positions);
    particle_layout.addParticle(basis);

    std::unique_ptr<InterferenceFunction2DLattice> P_interference{
        InterferenceFunction2DLattice::createHexagonal(radius * 2.0, 0)};
    FTDecayFunction2DCauchy pdf(10 * Units::nanometer, 10 * Units::nanometer, 0);
    P_interference->setDecayFunction(pdf);

    particle_layout.setInterferenceFunction(*P_interference);

    vacuum_layer.addLayout(particle_layout);

    MultiLayer* multi_layer = new MultiLayer();
    multi_layer->addLayer(vacuum_layer);
    multi_layer->addLayer(substrate_layer);
    return multi_layer;
}