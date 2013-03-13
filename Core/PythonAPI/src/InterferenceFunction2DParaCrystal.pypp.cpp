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
#include "InterferenceFunction2DParaCrystal.pypp.h"

namespace bp = boost::python;

struct InterferenceFunction2DParaCrystal_wrapper : InterferenceFunction2DParaCrystal, bp::wrapper< InterferenceFunction2DParaCrystal > {

    InterferenceFunction2DParaCrystal_wrapper(double length_1, double length_2, double alpha_lattice, double xi=0.0, double corr_length=0.0 )
    : InterferenceFunction2DParaCrystal( length_1, length_2, alpha_lattice, xi, corr_length )
      , bp::wrapper< InterferenceFunction2DParaCrystal >(){
        // constructor
    
    }

    virtual ::InterferenceFunction2DParaCrystal * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->InterferenceFunction2DParaCrystal::clone(  );
        }
    }
    
    ::InterferenceFunction2DParaCrystal * default_clone(  ) const  {
        return InterferenceFunction2DParaCrystal::clone( );
    }

    virtual double evaluate( ::cvector_t const & q ) const  {
        if( bp::override func_evaluate = this->get_override( "evaluate" ) )
            return func_evaluate( boost::ref(q) );
        else{
            return this->InterferenceFunction2DParaCrystal::evaluate( boost::ref(q) );
        }
    }
    
    double default_evaluate( ::cvector_t const & q ) const  {
        return InterferenceFunction2DParaCrystal::evaluate( boost::ref(q) );
    }

    virtual bool areParametersChanged(  ) {
        if( bp::override func_areParametersChanged = this->get_override( "areParametersChanged" ) )
            return func_areParametersChanged(  );
        else{
            return this->IParameterized::areParametersChanged(  );
        }
    }
    
    bool default_areParametersChanged(  ) {
        return IParameterized::areParametersChanged( );
    }

    virtual ::ParameterPool * createParameterTree(  ) const  {
        if( bp::override func_createParameterTree = this->get_override( "createParameterTree" ) )
            return func_createParameterTree(  );
        else{
            return this->IParameterized::createParameterTree(  );
        }
    }
    
    ::ParameterPool * default_createParameterTree(  ) const  {
        return IParameterized::createParameterTree( );
    }

    virtual double getKappa(  ) const  {
        if( bp::override func_getKappa = this->get_override( "getKappa" ) )
            return func_getKappa(  );
        else{
            return this->IInterferenceFunction::getKappa(  );
        }
    }
    
    double default_getKappa(  ) const  {
        return IInterferenceFunction::getKappa( );
    }

    virtual void printParameters(  ) const  {
        if( bp::override func_printParameters = this->get_override( "printParameters" ) )
            func_printParameters(  );
        else{
            this->IParameterized::printParameters(  );
        }
    }
    
    void default_printParameters(  ) const  {
        IParameterized::printParameters( );
    }

    virtual void print_structure(  ) {
        if( bp::override func_print_structure = this->get_override( "print_structure" ) )
            func_print_structure(  );
        else{
            this->ISample::print_structure(  );
        }
    }
    
    void default_print_structure(  ) {
        ISample::print_structure( );
    }

    virtual void setParametersAreChanged(  ) {
        if( bp::override func_setParametersAreChanged = this->get_override( "setParametersAreChanged" ) )
            func_setParametersAreChanged(  );
        else{
            this->IParameterized::setParametersAreChanged(  );
        }
    }
    
    void default_setParametersAreChanged(  ) {
        IParameterized::setParametersAreChanged( );
    }

};

void register_InterferenceFunction2DParaCrystal_class(){

    bp::class_< InterferenceFunction2DParaCrystal_wrapper, bp::bases< IInterferenceFunction >, boost::noncopyable >( "InterferenceFunction2DParaCrystal", bp::init< double, double, double, bp::optional< double, double > >(( bp::arg("length_1"), bp::arg("length_2"), bp::arg("alpha_lattice"), bp::arg("xi")=0.0, bp::arg("corr_length")=0.0 )) )    
        .def( 
            "clone"
            , (::InterferenceFunction2DParaCrystal * ( ::InterferenceFunction2DParaCrystal::* )(  ) const)(&::InterferenceFunction2DParaCrystal::clone)
            , (::InterferenceFunction2DParaCrystal * ( InterferenceFunction2DParaCrystal_wrapper::* )(  ) const)(&InterferenceFunction2DParaCrystal_wrapper::default_clone)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "createHexagonal"
            , (::InterferenceFunction2DParaCrystal * (*)( double,double,double,double ))( &::InterferenceFunction2DParaCrystal::createHexagonal )
            , ( bp::arg("peak_distance"), bp::arg("corr_length")=0.0, bp::arg("domain_size_1")=0.0, bp::arg("domain_size_2")=0.0 )
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "createSquare"
            , (::InterferenceFunction2DParaCrystal * (*)( double,double,double,double ))( &::InterferenceFunction2DParaCrystal::createSquare )
            , ( bp::arg("peak_distance"), bp::arg("corr_length")=0.0, bp::arg("domain_size_1")=0.0, bp::arg("domain_size_2")=0.0 )
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "evaluate"
            , (double ( ::InterferenceFunction2DParaCrystal::* )( ::cvector_t const & ) const)(&::InterferenceFunction2DParaCrystal::evaluate)
            , (double ( InterferenceFunction2DParaCrystal_wrapper::* )( ::cvector_t const & ) const)(&InterferenceFunction2DParaCrystal_wrapper::default_evaluate)
            , ( bp::arg("q") ) )    
        .def( 
            "setDomainSizes"
            , (void ( ::InterferenceFunction2DParaCrystal::* )( double,double ) )( &::InterferenceFunction2DParaCrystal::setDomainSizes )
            , ( bp::arg("size_1"), bp::arg("size_2") ) )    
        .def( 
            "setIntegrationOverXi"
            , (void ( ::InterferenceFunction2DParaCrystal::* )( bool ) )( &::InterferenceFunction2DParaCrystal::setIntegrationOverXi )
            , ( bp::arg("integrate_xi") ) )    
        .def( 
            "setProbabilityDistributions"
            , (void ( ::InterferenceFunction2DParaCrystal::* )( ::IFTDistribution2D const &,::IFTDistribution2D const & ) )( &::InterferenceFunction2DParaCrystal::setProbabilityDistributions )
            , ( bp::arg("pdf_1"), bp::arg("pdf_2") ) )    
        .def( 
            "areParametersChanged"
            , (bool ( ::IParameterized::* )(  ) )(&::IParameterized::areParametersChanged)
            , (bool ( InterferenceFunction2DParaCrystal_wrapper::* )(  ) )(&InterferenceFunction2DParaCrystal_wrapper::default_areParametersChanged) )    
        .def( 
            "createParameterTree"
            , (::ParameterPool * ( ::IParameterized::* )(  ) const)(&::IParameterized::createParameterTree)
            , (::ParameterPool * ( InterferenceFunction2DParaCrystal_wrapper::* )(  ) const)(&InterferenceFunction2DParaCrystal_wrapper::default_createParameterTree)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "getKappa"
            , (double ( ::IInterferenceFunction::* )(  ) const)(&::IInterferenceFunction::getKappa)
            , (double ( InterferenceFunction2DParaCrystal_wrapper::* )(  ) const)(&InterferenceFunction2DParaCrystal_wrapper::default_getKappa) )    
        .def( 
            "printParameters"
            , (void ( ::IParameterized::* )(  ) const)(&::IParameterized::printParameters)
            , (void ( InterferenceFunction2DParaCrystal_wrapper::* )(  ) const)(&InterferenceFunction2DParaCrystal_wrapper::default_printParameters) )    
        .def( 
            "print_structure"
            , (void ( ::ISample::* )(  ) )(&::ISample::print_structure)
            , (void ( InterferenceFunction2DParaCrystal_wrapper::* )(  ) )(&InterferenceFunction2DParaCrystal_wrapper::default_print_structure) )    
        .def( 
            "setParametersAreChanged"
            , (void ( ::IParameterized::* )(  ) )(&::IParameterized::setParametersAreChanged)
            , (void ( InterferenceFunction2DParaCrystal_wrapper::* )(  ) )(&InterferenceFunction2DParaCrystal_wrapper::default_setParametersAreChanged) )    
        .staticmethod( "createHexagonal" )    
        .staticmethod( "createSquare" );

}
