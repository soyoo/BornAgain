// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "BasicVector3D.h"
#include "Bin.h"
#include "Crystal.h"
#include "DiffuseParticleInfo.h"
#include "FTDistributions.h"
#include "FormFactorBox.h"
#include "FormFactorCrystal.h"
#include "FormFactorCylinder.h"
#include "FormFactorDecoratorDebyeWaller.h"
#include "FormFactorFullSphere.h"
#include "FormFactorGauss.h"
#include "FormFactorLorentz.h"
#include "FormFactorPrism3.h"
#include "FormFactorPyramid.h"
#include "FormFactorSphereGaussianRadius.h"
#include "HomogeneousMaterial.h"
#include "ICloneable.h"
#include "IClusteredParticles.h"
#include "ICompositeSample.h"
#include "IDecoration.h"
#include "IFormFactor.h"
#include "IFormFactorBorn.h"
#include "IFormFactorDecorator.h"
#include "IInterferenceFunction.h"
#include "IMaterial.h"
#include "IParameterized.h"
#include "ISample.h"
#include "ISampleBuilder.h"
#include "ISelectionRule.h"
#include "ISingleton.h"
#include "Instrument.h"
#include "InterferenceFunction1DParaCrystal.h"
#include "InterferenceFunction2DLattice.h"
#include "InterferenceFunction2DParaCrystal.h"
#include "InterferenceFunctionNone.h"
#include "Lattice.h"
#include "Lattice2DIFParameters.h"
#include "LatticeBasis.h"
#include "Layer.h"
#include "LayerDecorator.h"
#include "LayerRoughness.h"
#include "Lattice2DIFParameters.h"
#include "MaterialManager.h"
#include "MesoCrystal.h"
#include "MultiLayer.h"
#include "OpticalFresnel.h"
#include "ParameterPool.h"
#include "Particle.h"
#include "ParticleBuilder.h"
#include "ParticleCoreShell.h"
#include "ParticleDecoration.h"
#include "ParticleInfo.h"
#include "PositionParticleInfo.h"
#include "PythonOutputData.h"
#include "PythonPlusplusHelper.h"
#include "RealParameterWrapper.h"
#include "Simulation.h"
#include "SimulationParameters.h"
#include "IStochasticParameter.h"
#include "StochasticGaussian.h"
#include "StochasticSampledParameter.h"
#include "Transform3D.h"
#include "Types.h"
#include "Units.h"
#include "RealParameterWrapper.pypp.h"

namespace bp = boost::python;

void register_RealParameterWrapper_class(){

    { //::RealParameterWrapper
        typedef bp::class_< RealParameterWrapper > RealParameterWrapper_exposer_t;
        RealParameterWrapper_exposer_t RealParameterWrapper_exposer = RealParameterWrapper_exposer_t( "RealParameterWrapper", bp::no_init );
        bp::scope RealParameterWrapper_scope( RealParameterWrapper_exposer );
        RealParameterWrapper_exposer.def( bp::init< RealParameterWrapper const & >(( bp::arg("other") )) );
        { //::RealParameterWrapper::getValue
        
            typedef double ( ::RealParameterWrapper::*getValue_function_type )(  ) const;
            
            RealParameterWrapper_exposer.def( 
                "getValue"
                , getValue_function_type( &::RealParameterWrapper::getValue ) );
        
        }
        { //::RealParameterWrapper::isNull
        
            typedef bool ( ::RealParameterWrapper::*isNull_function_type )(  ) const;
            
            RealParameterWrapper_exposer.def( 
                "isNull"
                , isNull_function_type( &::RealParameterWrapper::isNull ) );
        
        }
        { //::RealParameterWrapper::operator=
        
            typedef ::RealParameterWrapper & ( ::RealParameterWrapper::*assign_function_type )( ::RealParameterWrapper const & ) ;
            
            RealParameterWrapper_exposer.def( 
                "assign"
                , assign_function_type( &::RealParameterWrapper::operator= )
                , ( bp::arg("other") )
                , bp::return_self< >() );
        
        }
        { //::RealParameterWrapper::setValue
        
            typedef void ( ::RealParameterWrapper::*setValue_function_type )( double ) ;
            
            RealParameterWrapper_exposer.def( 
                "setValue"
                , setValue_function_type( &::RealParameterWrapper::setValue )
                , ( bp::arg("value") ) );
        
        }
        RealParameterWrapper_exposer.def( bp::self_ns::str( bp::self ) );
    }

}
