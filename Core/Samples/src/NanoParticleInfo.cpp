#include "NanoParticleInfo.h"



//NanoParticleInfo::NanoParticleInfo()
//: mp_particle(0)
//, m_depth(0)
//, m_abundance(0)
//, m_transform(0)
//{
//}


NanoParticleInfo::NanoParticleInfo(NanoParticle* p_particle, double depth, double abundance)
: mp_particle(p_particle)
, m_transform(0)
, m_depth(depth)
, m_abundance(abundance)
{
}


NanoParticleInfo::NanoParticleInfo(NanoParticle* p_particle, Geometry::Transform3D *transform, double depth, double abundance)
: mp_particle(p_particle)
, m_transform(transform)
, m_depth(depth)
, m_abundance(abundance)
{
}


NanoParticleInfo::NanoParticleInfo(const NanoParticleInfo& source)
: mp_particle(source.mp_particle->clone())
, m_transform(0)
, m_depth(source.m_depth)
, m_abundance(source.m_abundance)
{
    std::cout << "XXX" << source.m_transform << std::endl;
    if(source.m_transform) {
        m_transform = new Geometry::Transform3D(*source.m_transform);
        std::cout << "YYY" << m_transform << std::endl;
    }
}


NanoParticleInfo::~NanoParticleInfo()
{
    delete mp_particle;
    delete m_transform;
}


/* ************************************************************************* */
// clone method
/* ************************************************************************* */
NanoParticleInfo *NanoParticleInfo::clone() const
{
    Geometry::Transform3D *transform(0);
    if(m_transform) transform = new Geometry::Transform3D(*m_transform);
    return new NanoParticleInfo(mp_particle->clone(), transform, m_depth, m_abundance);
}


//NanoParticleInfo& NanoParticleInfo::operator=(const NanoParticleInfo& right)
//{
//    if (this!=&right) {
//        delete mp_particle;
//        mp_particle = right.mp_particle->clone();
//        m_depth = right.m_depth;
//        m_abundance = right.m_abundance;
//        delete m_transform;
//        m_transform = 0;
//        if(right.m_transform) m_transform = new Geometry::Transform3D(*right.m_transform);
//    }
//    return *this;
//}



