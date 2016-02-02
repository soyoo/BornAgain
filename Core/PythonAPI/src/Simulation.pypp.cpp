// This file has been generated by Py++.

// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Automatically generated boost::python code for BornAgain Python bindings
//! @brief     Automatically generated boost::python code for BornAgain Python bindings
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Juelich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonCoreList.h"
#include "Simulation.pypp.h"

namespace bp = boost::python;

struct Simulation_wrapper : Simulation, bp::wrapper< Simulation > {

    Simulation_wrapper( )
    : Simulation( )
      , bp::wrapper< Simulation >(){
        // null constructor
    m_pyobj = 0;
    }

    virtual ::Simulation * clone(  ) const {
        bp::override func_clone = this->get_override( "clone" );
        return func_clone(  );
    }

    virtual double getBeamIntensity(  ) const {
        bp::override func_getBeamIntensity = this->get_override( "getBeamIntensity" );
        return func_getBeamIntensity(  );
    }

    virtual ::OutputData< double > * getDetectorIntensity( ::IDetector2D::EAxesUnits units_type=::IDetector2D::DEFAULT ) const {
        bp::override func_getDetectorIntensity = this->get_override( "getDetectorIntensity" );
        return func_getDetectorIntensity( units_type );
    }

    virtual int getNumberOfSimulationElements(  ) const {
        bp::override func_getNumberOfSimulationElements = this->get_override( "getNumberOfSimulationElements" );
        return func_getNumberOfSimulationElements(  );
    }

    virtual double getWavelength(  ) const  {
        if( bp::override func_getWavelength = this->get_override( "getWavelength" ) )
            return func_getWavelength(  );
        else{
            return this->Simulation::getWavelength(  );
        }
    }
    
    double default_getWavelength(  ) const  {
        return Simulation::getWavelength( );
    }

    virtual void initSimulationElementVector(  ){
        bp::override func_initSimulationElementVector = this->get_override( "initSimulationElementVector" );
        func_initSimulationElementVector(  );
    }

    virtual void prepareSimulation(  ) {
        if( bp::override func_prepareSimulation = this->get_override( "prepareSimulation" ) )
            func_prepareSimulation(  );
        else{
            this->Simulation::prepareSimulation(  );
        }
    }
    
    void default_prepareSimulation(  ) {
        Simulation::prepareSimulation( );
    }

    virtual void transferResultsToIntensityMap(  ){
        bp::override func_transferResultsToIntensityMap = this->get_override( "transferResultsToIntensityMap" );
        func_transferResultsToIntensityMap(  );
    }

    virtual void transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        if( bp::override func_transferToCPP = this->get_override( "transferToCPP" ) )
            func_transferToCPP(  );
        else{
            this->ICloneable::transferToCPP(  );
        }
    }
    
    void default_transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        ICloneable::transferToCPP( );
    }

    PyObject* m_pyobj;

};

void register_Simulation_class(){

    { //::Simulation
        typedef bp::class_< Simulation_wrapper, bp::bases< ICloneable, IParameterized >, std::auto_ptr< Simulation_wrapper >, boost::noncopyable > Simulation_exposer_t;
        Simulation_exposer_t Simulation_exposer = Simulation_exposer_t( "Simulation", "Main class to run the simulation.", bp::init< >() );
        bp::scope Simulation_scope( Simulation_exposer );
        { //::Simulation::addParameterDistribution
        
            typedef void ( ::Simulation::*addParameterDistribution_function_type)( ::std::string const &,::IDistribution1D const &,::std::size_t,double,::AttLimits const & ) ;
            
            Simulation_exposer.def( 
                "addParameterDistribution"
                , addParameterDistribution_function_type( &::Simulation::addParameterDistribution )
                , ( bp::arg("param_name"), bp::arg("distribution"), bp::arg("nbr_samples"), bp::arg("sigma_factor")=0.0, bp::arg("limits")=::AttLimits( ) ) );
        
        }
        { //::Simulation::addParameterDistribution
        
            typedef void ( ::Simulation::*addParameterDistribution_function_type)( ::ParameterDistribution const & ) ;
            
            Simulation_exposer.def( 
                "addParameterDistribution"
                , addParameterDistribution_function_type( &::Simulation::addParameterDistribution )
                , ( bp::arg("par_distr") )
                , "add a sampled parameter distribution." );
        
        }
        { //::Simulation::clone
        
            typedef ::Simulation * ( ::Simulation::*clone_function_type)(  ) const;
            
            Simulation_exposer.def( 
                "clone"
                , bp::pure_virtual( clone_function_type(&::Simulation::clone) )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::Simulation::getBeamIntensity
        
            typedef double ( Simulation_wrapper::*getBeamIntensity_function_type)(  ) const;
            
            Simulation_exposer.def( 
                "getBeamIntensity"
                , getBeamIntensity_function_type( &Simulation_wrapper::getBeamIntensity )
                , "Returns the intensity of the beam." );
        
        }
        { //::Simulation::getDetectorIntensity
        
            typedef ::OutputData<double> * ( ::Simulation::*getDetectorIntensity_function_type)( ::IDetector2D::EAxesUnits ) const;
            
            Simulation_exposer.def( 
                "getDetectorIntensity"
                , bp::pure_virtual( getDetectorIntensity_function_type(&::Simulation::getDetectorIntensity) )
                , ( bp::arg("units_type")=::IDetector2D::DEFAULT )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "Clone simulated intensity map." );
        
        }
        { //::Simulation::getDistributionHandler
        
            typedef ::DistributionHandler const & ( ::Simulation::*getDistributionHandler_function_type)(  ) const;
            
            Simulation_exposer.def( 
                "getDistributionHandler"
                , getDistributionHandler_function_type( &::Simulation::getDistributionHandler )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "add a sampled parameter distribution." );
        
        }
        { //::Simulation::getNumberOfSimulationElements
        
            typedef int ( ::Simulation::*getNumberOfSimulationElements_function_type)(  ) const;
            
            Simulation_exposer.def( 
                "getNumberOfSimulationElements"
                , bp::pure_virtual( getNumberOfSimulationElements_function_type(&::Simulation::getNumberOfSimulationElements) )
                , "Gets the number of elements this simulation needs to calculate." );
        
        }
        { //::Simulation::getSample
        
            typedef ::ISample * ( ::Simulation::*getSample_function_type)(  ) const;
            
            Simulation_exposer.def( 
                "getSample"
                , getSample_function_type( &::Simulation::getSample )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "Returns the sample." );
        
        }
        { //::Simulation::getSampleBuilder
        
            typedef ::SampleBuilder_t ( ::Simulation::*getSampleBuilder_function_type)(  ) const;
            
            Simulation_exposer.def( 
                "getSampleBuilder"
                , getSampleBuilder_function_type( &::Simulation::getSampleBuilder )
                , "return sample builder." );
        
        }
        { //::Simulation::getSimulationParameters
        
            typedef ::SimulationParameters ( ::Simulation::*getSimulationParameters_function_type)(  ) const;
            
            Simulation_exposer.def( 
                "getSimulationParameters"
                , getSimulationParameters_function_type( &::Simulation::getSimulationParameters )
                , "Returns simulation parameters." );
        
        }
        { //::Simulation::getWavelength
        
            typedef double ( ::Simulation::*getWavelength_function_type)(  ) const;
            typedef double ( Simulation_wrapper::*default_getWavelength_function_type)(  ) const;
            
            Simulation_exposer.def( 
                "getWavelength"
                , getWavelength_function_type(&::Simulation::getWavelength)
                , default_getWavelength_function_type(&Simulation_wrapper::default_getWavelength) );
        
        }
        { //::Simulation::initSimulationElementVector
        
            typedef void ( Simulation_wrapper::*initSimulationElementVector_function_type)(  ) ;
            
            Simulation_exposer.def( 
                "initSimulationElementVector"
                , initSimulationElementVector_function_type( &Simulation_wrapper::initSimulationElementVector )
                , "Initializes the vector of Simulation elements." );
        
        }
        { //::Simulation::prepareSimulation
        
            typedef void ( ::Simulation::*prepareSimulation_function_type)(  ) ;
            typedef void ( Simulation_wrapper::*default_prepareSimulation_function_type)(  ) ;
            
            Simulation_exposer.def( 
                "prepareSimulation"
                , prepareSimulation_function_type(&::Simulation::prepareSimulation)
                , default_prepareSimulation_function_type(&Simulation_wrapper::default_prepareSimulation) );
        
        }
        { //::Simulation::runOMPISimulation
        
            typedef void ( ::Simulation::*runOMPISimulation_function_type)(  ) ;
            
            Simulation_exposer.def( 
                "runOMPISimulation"
                , runOMPISimulation_function_type( &::Simulation::runOMPISimulation )
                , "Run an OpenMPI simulation." );
        
        }
        { //::Simulation::runSimulation
        
            typedef void ( ::Simulation::*runSimulation_function_type)(  ) ;
            
            Simulation_exposer.def( 
                "runSimulation"
                , runSimulation_function_type( &::Simulation::runSimulation )
                , "Run a simulation, possibly averaged over parameter distributions." );
        
        }
        { //::Simulation::setSample
        
            typedef void ( ::Simulation::*setSample_function_type)( ::ISample const & ) ;
            
            Simulation_exposer.def( 
                "setSample"
                , setSample_function_type( &::Simulation::setSample )
                , ( bp::arg("sample") )
                , "Sets the sample to be tested." );
        
        }
        { //::Simulation::setSampleBuilder
        
            typedef void ( ::Simulation::*setSampleBuilder_function_type)( ::SampleBuilder_t ) ;
            
            Simulation_exposer.def( 
                "setSampleBuilder"
                , setSampleBuilder_function_type( &::Simulation::setSampleBuilder )
                , ( bp::arg("sample_builder") )
                , "Sets the sample builder." );
        
        }
        { //::Simulation::setSimulationParameters
        
            typedef void ( ::Simulation::*setSimulationParameters_function_type)( ::SimulationParameters const & ) ;
            
            Simulation_exposer.def( 
                "setSimulationParameters"
                , setSimulationParameters_function_type( &::Simulation::setSimulationParameters )
                , ( bp::arg("sim_params") )
                , "Sets simulation parameters." );
        
        }
        { //::Simulation::setThreadInfo
        
            typedef void ( ::Simulation::*setThreadInfo_function_type)( ::ThreadInfo const & ) ;
            
            Simulation_exposer.def( 
                "setThreadInfo"
                , setThreadInfo_function_type( &::Simulation::setThreadInfo )
                , ( bp::arg("thread_info") )
                , "Sets the batch and thread information to be used." );
        
        }
        { //::Simulation::transferResultsToIntensityMap
        
            typedef void ( Simulation_wrapper::*transferResultsToIntensityMap_function_type)(  ) ;
            
            Simulation_exposer.def( 
                "transferResultsToIntensityMap"
                , transferResultsToIntensityMap_function_type( &Simulation_wrapper::transferResultsToIntensityMap )
                , "Creates the appropriate data structure (e.g. 2D intensity map) from the calculated SimulationElement objects " );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( Simulation_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            Simulation_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&Simulation_wrapper::default_transferToCPP) );
        
        }
    }

}
