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
#include "InterferenceFunction2DLattice.pypp.h"

namespace bp = boost::python;

struct InterferenceFunction2DLattice_wrapper : InterferenceFunction2DLattice, bp::wrapper< InterferenceFunction2DLattice > {

    InterferenceFunction2DLattice_wrapper(double length_1, double length_2, double angle, double xi=0.0 )
    : InterferenceFunction2DLattice( length_1, length_2, angle, xi )
      , bp::wrapper< InterferenceFunction2DLattice >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::InterferenceFunction2DLattice * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->InterferenceFunction2DLattice::clone(  );
        }
    }
    
    ::InterferenceFunction2DLattice * default_clone(  ) const  {
        return InterferenceFunction2DLattice::clone( );
    }

    virtual double evaluate( ::kvector_t const & q ) const  {
        if( bp::override func_evaluate = this->get_override( "evaluate" ) )
            return func_evaluate( boost::ref(q) );
        else{
            return this->InterferenceFunction2DLattice::evaluate( boost::ref(q) );
        }
    }
    
    double default_evaluate( ::kvector_t const & q ) const  {
        return InterferenceFunction2DLattice::evaluate( boost::ref(q) );
    }

    virtual double getParticleDensity(  ) const  {
        if( bp::override func_getParticleDensity = this->get_override( "getParticleDensity" ) )
            return func_getParticleDensity(  );
        else{
            return this->InterferenceFunction2DLattice::getParticleDensity(  );
        }
    }
    
    double default_getParticleDensity(  ) const  {
        return InterferenceFunction2DLattice::getParticleDensity( );
    }

    virtual ::ISample * cloneInvertB(  ) const  {
        if( bp::override func_cloneInvertB = this->get_override( "cloneInvertB" ) )
            return func_cloneInvertB(  );
        else{
            return this->ISample::cloneInvertB(  );
        }
    }
    
    ::ISample * default_cloneInvertB(  ) const  {
        return ISample::cloneInvertB( );
    }

    virtual bool containsMagneticMaterial(  ) const  {
        if( bp::override func_containsMagneticMaterial = this->get_override( "containsMagneticMaterial" ) )
            return func_containsMagneticMaterial(  );
        else{
            return this->ISample::containsMagneticMaterial(  );
        }
    }
    
    bool default_containsMagneticMaterial(  ) const  {
        return ISample::containsMagneticMaterial( );
    }

    virtual ::std::vector< const ISample* > getChildren(  ) const  {
        if( bp::override func_getChildren = this->get_override( "getChildren" ) )
            return func_getChildren(  );
        else{
            return this->ISample::getChildren(  );
        }
    }
    
    ::std::vector< const ISample* > default_getChildren(  ) const  {
        return ISample::getChildren( );
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

    virtual void printSampleTree(  ) {
        if( bp::override func_printSampleTree = this->get_override( "printSampleTree" ) )
            func_printSampleTree(  );
        else{
            this->ISample::printSampleTree(  );
        }
    }
    
    void default_printSampleTree(  ) {
        ISample::printSampleTree( );
    }

    virtual ::std::size_t size(  ) const  {
        if( bp::override func_size = this->get_override( "size" ) )
            return func_size(  );
        else{
            return this->ISample::size(  );
        }
    }
    
    ::std::size_t default_size(  ) const  {
        return ISample::size( );
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

void register_InterferenceFunction2DLattice_class(){

    { //::InterferenceFunction2DLattice
        typedef bp::class_< InterferenceFunction2DLattice_wrapper, bp::bases< IInterferenceFunction >, std::auto_ptr< InterferenceFunction2DLattice_wrapper >, boost::noncopyable > InterferenceFunction2DLattice_exposer_t;
        InterferenceFunction2DLattice_exposer_t InterferenceFunction2DLattice_exposer = InterferenceFunction2DLattice_exposer_t( "InterferenceFunction2DLattice", "Interference function of 2D lattic.", bp::init< double, double, double, bp::optional< double > >(( bp::arg("length_1"), bp::arg("length_2"), bp::arg("angle"), bp::arg("xi")=0.0 ), "contructor.\n\n:Parameters:\n  - 'length_1' - Lattice length 1\n  - 'length_2' - Lattice length 2\n  - 'angle' - angle between lattice vectors\n  - 'xi' - rotation of lattice with respect to x-axis\n") );
        bp::scope InterferenceFunction2DLattice_scope( InterferenceFunction2DLattice_exposer );
        { //::InterferenceFunction2DLattice::clone
        
            typedef ::InterferenceFunction2DLattice * ( ::InterferenceFunction2DLattice::*clone_function_type)(  ) const;
            typedef ::InterferenceFunction2DLattice * ( InterferenceFunction2DLattice_wrapper::*default_clone_function_type)(  ) const;
            
            InterferenceFunction2DLattice_exposer.def( 
                "clone"
                , clone_function_type(&::InterferenceFunction2DLattice::clone)
                , default_clone_function_type(&InterferenceFunction2DLattice_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::InterferenceFunction2DLattice::createHexagonal
        
            typedef ::InterferenceFunction2DLattice * ( *createHexagonal_function_type )( double,double );
            
            InterferenceFunction2DLattice_exposer.def( 
                "createHexagonal"
                , createHexagonal_function_type( &::InterferenceFunction2DLattice::createHexagonal )
                , ( bp::arg("lattice_length"), bp::arg("xi")=0.0 )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::InterferenceFunction2DLattice::createSquare
        
            typedef ::InterferenceFunction2DLattice * ( *createSquare_function_type )( double,double );
            
            InterferenceFunction2DLattice_exposer.def( 
                "createSquare"
                , createSquare_function_type( &::InterferenceFunction2DLattice::createSquare )
                , ( bp::arg("lattice_length"), bp::arg("xi")=0.0 )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::InterferenceFunction2DLattice::evaluate
        
            typedef double ( ::InterferenceFunction2DLattice::*evaluate_function_type)( ::kvector_t const & ) const;
            typedef double ( InterferenceFunction2DLattice_wrapper::*default_evaluate_function_type)( ::kvector_t const & ) const;
            
            InterferenceFunction2DLattice_exposer.def( 
                "evaluate"
                , evaluate_function_type(&::InterferenceFunction2DLattice::evaluate)
                , default_evaluate_function_type(&InterferenceFunction2DLattice_wrapper::default_evaluate)
                , ( bp::arg("q") ) );
        
        }
        { //::InterferenceFunction2DLattice::getDecayFunction
        
            typedef ::IFTDecayFunction2D const * ( ::InterferenceFunction2DLattice::*getDecayFunction_function_type)(  ) const;
            
            InterferenceFunction2DLattice_exposer.def( 
                "getDecayFunction"
                , getDecayFunction_function_type( &::InterferenceFunction2DLattice::getDecayFunction )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::InterferenceFunction2DLattice::getLatticeParameters
        
            typedef ::Lattice2DParameters ( ::InterferenceFunction2DLattice::*getLatticeParameters_function_type)(  ) const;
            
            InterferenceFunction2DLattice_exposer.def( 
                "getLatticeParameters"
                , getLatticeParameters_function_type( &::InterferenceFunction2DLattice::getLatticeParameters ) );
        
        }
        { //::InterferenceFunction2DLattice::getParticleDensity
        
            typedef double ( ::InterferenceFunction2DLattice::*getParticleDensity_function_type)(  ) const;
            typedef double ( InterferenceFunction2DLattice_wrapper::*default_getParticleDensity_function_type)(  ) const;
            
            InterferenceFunction2DLattice_exposer.def( 
                "getParticleDensity"
                , getParticleDensity_function_type(&::InterferenceFunction2DLattice::getParticleDensity)
                , default_getParticleDensity_function_type(&InterferenceFunction2DLattice_wrapper::default_getParticleDensity) );
        
        }
        { //::InterferenceFunction2DLattice::setDecayFunction
        
            typedef void ( ::InterferenceFunction2DLattice::*setDecayFunction_function_type)( ::IFTDecayFunction2D const & ) ;
            
            InterferenceFunction2DLattice_exposer.def( 
                "setDecayFunction"
                , setDecayFunction_function_type( &::InterferenceFunction2DLattice::setDecayFunction )
                , ( bp::arg("pdf") ) );
        
        }
        { //::ISample::cloneInvertB
        
            typedef ::ISample * ( ::ISample::*cloneInvertB_function_type)(  ) const;
            typedef ::ISample * ( InterferenceFunction2DLattice_wrapper::*default_cloneInvertB_function_type)(  ) const;
            
            InterferenceFunction2DLattice_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::ISample::cloneInvertB)
                , default_cloneInvertB_function_type(&InterferenceFunction2DLattice_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type)(  ) const;
            typedef bool ( InterferenceFunction2DLattice_wrapper::*default_containsMagneticMaterial_function_type)(  ) const;
            
            InterferenceFunction2DLattice_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&InterferenceFunction2DLattice_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::ISample::getChildren
        
            typedef ::std::vector< const ISample* > ( ::ISample::*getChildren_function_type)(  ) const;
            typedef ::std::vector< const ISample* > ( InterferenceFunction2DLattice_wrapper::*default_getChildren_function_type)(  ) const;
            
            InterferenceFunction2DLattice_exposer.def( 
                "getChildren"
                , getChildren_function_type(&::ISample::getChildren)
                , default_getChildren_function_type(&InterferenceFunction2DLattice_wrapper::default_getChildren) );
        
        }
        { //::IInterferenceFunction::getKappa
        
            typedef double ( ::IInterferenceFunction::*getKappa_function_type)(  ) const;
            typedef double ( InterferenceFunction2DLattice_wrapper::*default_getKappa_function_type)(  ) const;
            
            InterferenceFunction2DLattice_exposer.def( 
                "getKappa"
                , getKappa_function_type(&::IInterferenceFunction::getKappa)
                , default_getKappa_function_type(&InterferenceFunction2DLattice_wrapper::default_getKappa) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type)(  ) ;
            typedef void ( InterferenceFunction2DLattice_wrapper::*default_printSampleTree_function_type)(  ) ;
            
            InterferenceFunction2DLattice_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&InterferenceFunction2DLattice_wrapper::default_printSampleTree) );
        
        }
        { //::ISample::size
        
            typedef ::std::size_t ( ::ISample::*size_function_type)(  ) const;
            typedef ::std::size_t ( InterferenceFunction2DLattice_wrapper::*default_size_function_type)(  ) const;
            
            InterferenceFunction2DLattice_exposer.def( 
                "size"
                , size_function_type(&::ISample::size)
                , default_size_function_type(&InterferenceFunction2DLattice_wrapper::default_size) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( InterferenceFunction2DLattice_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            InterferenceFunction2DLattice_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&InterferenceFunction2DLattice_wrapper::default_transferToCPP) );
        
        }
        InterferenceFunction2DLattice_exposer.staticmethod( "createHexagonal" );
        InterferenceFunction2DLattice_exposer.staticmethod( "createSquare" );
    }

}
