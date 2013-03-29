// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
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
#include "FormFactorParallelepiped.h"
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
#include "OutputData.h"
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
#include "StochasticDoubleGate.h"
#include "Transform3D.h"
#include "Types.h"
#include "Units.h"
#include "FormFactorLorentz.pypp.h"

namespace bp = boost::python;

struct FormFactorLorentz_wrapper : FormFactorLorentz, bp::wrapper< FormFactorLorentz > {

    FormFactorLorentz_wrapper(double volume )
    : FormFactorLorentz( volume )
      , bp::wrapper< FormFactorLorentz >(){
        // constructor
    
    }

    FormFactorLorentz_wrapper(double height, double width )
    : FormFactorLorentz( height, width )
      , bp::wrapper< FormFactorLorentz >(){
        // constructor
    
    }

    virtual ::FormFactorLorentz * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->FormFactorLorentz::clone(  );
        }
    }
    
    ::FormFactorLorentz * default_clone(  ) const  {
        return FormFactorLorentz::clone( );
    }

    virtual ::complex_t evaluate_for_q( ::cvector_t const & q ) const  {
        if( bp::override func_evaluate_for_q = this->get_override( "evaluate_for_q" ) )
            return func_evaluate_for_q( boost::ref(q) );
        else{
            return this->FormFactorLorentz::evaluate_for_q( boost::ref(q) );
        }
    }
    
    ::complex_t default_evaluate_for_q( ::cvector_t const & q ) const  {
        return FormFactorLorentz::evaluate_for_q( boost::ref(q) );
    }

    virtual int getNumberOfStochasticParameters(  ) const  {
        if( bp::override func_getNumberOfStochasticParameters = this->get_override( "getNumberOfStochasticParameters" ) )
            return func_getNumberOfStochasticParameters(  );
        else{
            return this->FormFactorLorentz::getNumberOfStochasticParameters(  );
        }
    }
    
    int default_getNumberOfStochasticParameters(  ) const  {
        return FormFactorLorentz::getNumberOfStochasticParameters( );
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

    virtual void clearParameterPool(  ) {
        if( bp::override func_clearParameterPool = this->get_override( "clearParameterPool" ) )
            func_clearParameterPool(  );
        else{
            this->IParameterized::clearParameterPool(  );
        }
    }
    
    void default_clearParameterPool(  ) {
        IParameterized::clearParameterPool( );
    }

    virtual void createDistributedFormFactors( ::std::vector< IFormFactor* > & form_factors, ::std::vector< double > & probabilities, ::size_t nbr_samples ) const  {
        if( bp::override func_createDistributedFormFactors = this->get_override( "createDistributedFormFactors" ) )
            func_createDistributedFormFactors( boost::ref(form_factors), boost::ref(probabilities), nbr_samples );
        else{
            this->IFormFactor::createDistributedFormFactors( boost::ref(form_factors), boost::ref(probabilities), nbr_samples );
        }
    }
    
    void default_createDistributedFormFactors( ::std::vector< IFormFactor* > & form_factors, ::std::vector< double > & probabilities, ::size_t nbr_samples ) const  {
        IFormFactor::createDistributedFormFactors( boost::ref(form_factors), boost::ref(probabilities), nbr_samples );
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

    virtual ::complex_t evaluate( ::cvector_t const & k_i, ::Bin1DCVector const & k_f_bin, double alpha_i, double alpha_f ) const  {
        if( bp::override func_evaluate = this->get_override( "evaluate" ) )
            return func_evaluate( boost::ref(k_i), boost::ref(k_f_bin), alpha_i, alpha_f );
        else{
            return this->IFormFactorBorn::evaluate( boost::ref(k_i), boost::ref(k_f_bin), alpha_i, alpha_f );
        }
    }
    
    ::complex_t default_evaluate( ::cvector_t const & k_i, ::Bin1DCVector const & k_f_bin, double alpha_i, double alpha_f ) const  {
        return IFormFactorBorn::evaluate( boost::ref(k_i), boost::ref(k_f_bin), alpha_i, alpha_f );
    }

    virtual double getHeight(  ) const  {
        if( bp::override func_getHeight = this->get_override( "getHeight" ) )
            return func_getHeight(  );
        else{
            return this->IFormFactor::getHeight(  );
        }
    }
    
    double default_getHeight(  ) const  {
        return IFormFactor::getHeight( );
    }

    virtual double getRadius(  ) const  {
        if( bp::override func_getRadius = this->get_override( "getRadius" ) )
            return func_getRadius(  );
        else{
            return this->IFormFactor::getRadius(  );
        }
    }
    
    double default_getRadius(  ) const  {
        return IFormFactor::getRadius( );
    }

    virtual double getVolume(  ) const  {
        if( bp::override func_getVolume = this->get_override( "getVolume" ) )
            return func_getVolume(  );
        else{
            return this->IFormFactorBorn::getVolume(  );
        }
    }
    
    double default_getVolume(  ) const  {
        return IFormFactorBorn::getVolume( );
    }

    virtual bool isDistributedFormFactor(  ) const  {
        if( bp::override func_isDistributedFormFactor = this->get_override( "isDistributedFormFactor" ) )
            return func_isDistributedFormFactor(  );
        else{
            return this->IFormFactor::isDistributedFormFactor(  );
        }
    }
    
    bool default_isDistributedFormFactor(  ) const  {
        return IFormFactor::isDistributedFormFactor( );
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

    virtual void registerParameter( ::std::string const & name, double * parpointer ) {
        namespace bpl = boost::python;
        if( bpl::override func_registerParameter = this->get_override( "registerParameter" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_registerParameter.ptr(), name, parpointer );
        }
        else{
            IParameterized::registerParameter( name, parpointer );
        }
    }
    
    static void default_registerParameter( ::IParameterized & inst, ::std::string const & name, long unsigned int parpointer ){
        if( dynamic_cast< FormFactorLorentz_wrapper * >( boost::addressof( inst ) ) ){
            inst.::IParameterized::registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
        else{
            inst.registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
    }

    virtual void setAmbientRefractiveIndex( ::complex_t const & refractive_index ) {
        if( bp::override func_setAmbientRefractiveIndex = this->get_override( "setAmbientRefractiveIndex" ) )
            func_setAmbientRefractiveIndex( boost::ref(refractive_index) );
        else{
            this->IFormFactor::setAmbientRefractiveIndex( boost::ref(refractive_index) );
        }
    }
    
    void default_setAmbientRefractiveIndex( ::complex_t const & refractive_index ) {
        IFormFactor::setAmbientRefractiveIndex( boost::ref(refractive_index) );
    }

    virtual bool setParameterValue( ::std::string const & name, double value ) {
        if( bp::override func_setParameterValue = this->get_override( "setParameterValue" ) )
            return func_setParameterValue( name, value );
        else{
            return this->IParameterized::setParameterValue( name, value );
        }
    }
    
    bool default_setParameterValue( ::std::string const & name, double value ) {
        return IParameterized::setParameterValue( name, value );
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

void register_FormFactorLorentz_class(){

    bp::class_< FormFactorLorentz_wrapper, bp::bases< IFormFactorBorn >, boost::noncopyable >( "FormFactorLorentz", bp::init< double >(( bp::arg("volume") )) )    
        .def( bp::init< double, double >(( bp::arg("height"), bp::arg("width") )) )    
        .def( 
            "clone"
            , (::FormFactorLorentz * ( ::FormFactorLorentz::* )(  ) const)(&::FormFactorLorentz::clone)
            , (::FormFactorLorentz * ( FormFactorLorentz_wrapper::* )(  ) const)(&FormFactorLorentz_wrapper::default_clone)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "evaluate_for_q"
            , (::complex_t ( ::FormFactorLorentz::* )( ::cvector_t const & ) const)(&::FormFactorLorentz::evaluate_for_q)
            , (::complex_t ( FormFactorLorentz_wrapper::* )( ::cvector_t const & ) const)(&FormFactorLorentz_wrapper::default_evaluate_for_q)
            , ( bp::arg("q") ) )    
        .def( 
            "getNumberOfStochasticParameters"
            , (int ( ::FormFactorLorentz::* )(  ) const)(&::FormFactorLorentz::getNumberOfStochasticParameters)
            , (int ( FormFactorLorentz_wrapper::* )(  ) const)(&FormFactorLorentz_wrapper::default_getNumberOfStochasticParameters) )    
        .def( 
            "areParametersChanged"
            , (bool ( ::IParameterized::* )(  ) )(&::IParameterized::areParametersChanged)
            , (bool ( FormFactorLorentz_wrapper::* )(  ) )(&FormFactorLorentz_wrapper::default_areParametersChanged) )    
        .def( 
            "clearParameterPool"
            , (void ( ::IParameterized::* )(  ) )(&::IParameterized::clearParameterPool)
            , (void ( FormFactorLorentz_wrapper::* )(  ) )(&FormFactorLorentz_wrapper::default_clearParameterPool) )    
        .def( 
            "createDistributedFormFactors"
            , (void ( ::IFormFactor::* )( ::std::vector< IFormFactor* > &,::std::vector< double > &,::size_t ) const)(&::IFormFactor::createDistributedFormFactors)
            , (void ( FormFactorLorentz_wrapper::* )( ::std::vector< IFormFactor* > &,::std::vector< double > &,::size_t ) const)(&FormFactorLorentz_wrapper::default_createDistributedFormFactors)
            , ( bp::arg("form_factors"), bp::arg("probabilities"), bp::arg("nbr_samples") )
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "createParameterTree"
            , (::ParameterPool * ( ::IParameterized::* )(  ) const)(&::IParameterized::createParameterTree)
            , (::ParameterPool * ( FormFactorLorentz_wrapper::* )(  ) const)(&FormFactorLorentz_wrapper::default_createParameterTree)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "evaluate"
            , (::complex_t ( ::IFormFactorBorn::* )( ::cvector_t const &,::Bin1DCVector const &,double,double ) const)(&::IFormFactorBorn::evaluate)
            , (::complex_t ( FormFactorLorentz_wrapper::* )( ::cvector_t const &,::Bin1DCVector const &,double,double ) const)(&FormFactorLorentz_wrapper::default_evaluate)
            , ( bp::arg("k_i"), bp::arg("k_f_bin"), bp::arg("alpha_i"), bp::arg("alpha_f") ) )    
        .def( 
            "getHeight"
            , (double ( ::IFormFactor::* )(  ) const)(&::IFormFactor::getHeight)
            , (double ( FormFactorLorentz_wrapper::* )(  ) const)(&FormFactorLorentz_wrapper::default_getHeight) )    
        .def( 
            "getRadius"
            , (double ( ::IFormFactor::* )(  ) const)(&::IFormFactor::getRadius)
            , (double ( FormFactorLorentz_wrapper::* )(  ) const)(&FormFactorLorentz_wrapper::default_getRadius) )    
        .def( 
            "getVolume"
            , (double ( ::IFormFactorBorn::* )(  ) const)(&::IFormFactorBorn::getVolume)
            , (double ( FormFactorLorentz_wrapper::* )(  ) const)(&FormFactorLorentz_wrapper::default_getVolume) )    
        .def( 
            "isDistributedFormFactor"
            , (bool ( ::IFormFactor::* )(  ) const)(&::IFormFactor::isDistributedFormFactor)
            , (bool ( FormFactorLorentz_wrapper::* )(  ) const)(&FormFactorLorentz_wrapper::default_isDistributedFormFactor) )    
        .def( 
            "printParameters"
            , (void ( ::IParameterized::* )(  ) const)(&::IParameterized::printParameters)
            , (void ( FormFactorLorentz_wrapper::* )(  ) const)(&FormFactorLorentz_wrapper::default_printParameters) )    
        .def( 
            "print_structure"
            , (void ( ::ISample::* )(  ) )(&::ISample::print_structure)
            , (void ( FormFactorLorentz_wrapper::* )(  ) )(&FormFactorLorentz_wrapper::default_print_structure) )    
        .def( 
            "registerParameter"
            , (void (*)( ::IParameterized &,::std::string const &,long unsigned int ))( &FormFactorLorentz_wrapper::default_registerParameter )
            , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) )    
        .def( 
            "setAmbientRefractiveIndex"
            , (void ( ::IFormFactor::* )( ::complex_t const & ) )(&::IFormFactor::setAmbientRefractiveIndex)
            , (void ( FormFactorLorentz_wrapper::* )( ::complex_t const & ) )(&FormFactorLorentz_wrapper::default_setAmbientRefractiveIndex)
            , ( bp::arg("refractive_index") ) )    
        .def( 
            "setParameterValue"
            , (bool ( ::IParameterized::* )( ::std::string const &,double ) )(&::IParameterized::setParameterValue)
            , (bool ( FormFactorLorentz_wrapper::* )( ::std::string const &,double ) )(&FormFactorLorentz_wrapper::default_setParameterValue)
            , ( bp::arg("name"), bp::arg("value") ) )    
        .def( 
            "setParametersAreChanged"
            , (void ( ::IParameterized::* )(  ) )(&::IParameterized::setParametersAreChanged)
            , (void ( FormFactorLorentz_wrapper::* )(  ) )(&FormFactorLorentz_wrapper::default_setParametersAreChanged) );

}
