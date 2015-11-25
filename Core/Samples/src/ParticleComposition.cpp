// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Samples/src/ParticleComposition.cpp
//! @brief     Implements class ParticleComposition.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "ParticleComposition.h"
#include "FormFactors.h"
#include "Materials.h"
#include "ParticleDistribution.h"
#include <boost/scoped_ptr.hpp>

ParticleComposition::ParticleComposition()
{
    setName("ParticleComposition");
    registerPosition();
}

ParticleComposition::ParticleComposition(const IParticle& particle)
{
    setName("ParticleComposition");
    registerPosition();
    addParticle( particle, kvector_t(0.0, 0.0, 0.0) );
}

ParticleComposition::ParticleComposition(const IParticle &particle, kvector_t position)
{
    setName("ParticleComposition");
    registerPosition();
    addParticle(particle, position);
}

ParticleComposition::ParticleComposition(const IParticle& particle,
        std::vector<kvector_t> positions)
{
    setName("ParticleComposition");
    registerPosition();
    addParticles(particle, positions);
}

ParticleComposition::~ParticleComposition()
{
    for (size_t index=0; index<m_particles.size(); ++index) {
        delete m_particles[index];
    }
}

ParticleComposition* ParticleComposition::clone() const
{
    ParticleComposition *p_new = new ParticleComposition();
    for (size_t index=0; index<m_particles.size(); ++index) {
        p_new->addParticle(*m_particles[index]);
    }
    p_new->setName(getName());
    p_new->setAmbientMaterial(*getAmbientMaterial());
    if (mP_rotation.get()) {
        p_new->setRotation(*mP_rotation);
    }
    p_new->setPosition(m_position);
    return p_new;
}

ParticleComposition* ParticleComposition::cloneInvertB() const
{
    ParticleComposition *p_new = new ParticleComposition();
    for (size_t index=0; index<m_particles.size(); ++index) {
        p_new->addParticlePointer(m_particles[index]->cloneInvertB());
    }
    p_new->setName(getName() + "_inv");

    if(getAmbientMaterial()) {
        p_new->setAmbientMaterial(*Materials::createInvertedMaterial(getAmbientMaterial()));
    }
    if (mP_rotation.get()) {
        p_new->setRotation(*mP_rotation);
    }
    p_new->setPosition(m_position);

    return p_new;
}

void ParticleComposition::addParticle(const IParticle &particle)
{
    checkParticleType(particle);
    IParticle *np = particle.clone();
    registerChild(np);
    m_particles.push_back(np);
}

void ParticleComposition::addParticle(const IParticle &particle, kvector_t position)
{
    checkParticleType(particle);
    IParticle *np = particle.clone();
    np->applyTranslation(position);
    registerChild(np);
    m_particles.push_back(np);
}

// Please note, that positions is not const reference here. This is intentionally to
// python lists to std::vector
void ParticleComposition::addParticles(const IParticle& particle,
        std::vector<kvector_t > positions)
{
    for (size_t i=0; i<positions.size(); ++i) {
        addParticle(particle, positions[i]);
    }
}

void ParticleComposition::setAmbientMaterial(const IMaterial& material)
{
    for (size_t index=0; index<m_particles.size(); ++index) {
        m_particles[index]->setAmbientMaterial(material);
    }
}

const IMaterial *ParticleComposition::getAmbientMaterial() const
{
    if (m_particles.size()==0) return 0;
    return m_particles[0]->getAmbientMaterial();
}

IFormFactor *
ParticleComposition::createTransformedFormFactor(complex_t wavevector_scattering_factor,
                                                 const IRotation *p_rotation,
                                                 kvector_t translation) const
{
    if (m_particles.size() == 0)
        return 0;
    boost::scoped_ptr<IRotation> P_total_rotation(createComposedRotation(p_rotation));
    kvector_t total_position = getComposedTranslation(p_rotation, translation);
    FormFactorWeighted *p_result = new FormFactorWeighted();
    for (size_t index = 0; index < m_particles.size(); ++index) {
        boost::scoped_ptr<IFormFactor> P_particle_ff(
            m_particles[index]->createTransformedFormFactor(
                wavevector_scattering_factor, P_total_rotation.get(), total_position));
        p_result->addFormFactor(*P_particle_ff);
    }
    return p_result;
}

void ParticleComposition::checkParticleType(const IParticle &p_particle)
{
    const ParticleDistribution *p_distr = dynamic_cast<const ParticleDistribution*>(&p_particle);
    if (p_distr) {
        throw Exceptions::ClassInitializationException("ParticleComposition::checkParticleType: "
                                                       "cannot add ParticleDistribution!");
    }
}

void ParticleComposition::addParticlePointer(IParticle* p_particle)
{
    registerChild(p_particle);
    m_particles.push_back(p_particle);
}
