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
#include "IsGISAXSDetector.pypp.h"

namespace bp = boost::python;

struct IsGISAXSDetector_wrapper : IsGISAXSDetector, bp::wrapper< IsGISAXSDetector > {

    IsGISAXSDetector_wrapper( )
    : IsGISAXSDetector( )
      , bp::wrapper< IsGISAXSDetector >(){
        // null constructor
    m_pyobj = 0;
    }

    IsGISAXSDetector_wrapper(::std::size_t n_phi, double phi_min, double phi_max, ::std::size_t n_alpha, double alpha_min, double alpha_max )
    : IsGISAXSDetector( n_phi, phi_min, phi_max, n_alpha, alpha_min, alpha_max )
      , bp::wrapper< IsGISAXSDetector >(){
        // constructor
    m_pyobj = 0;
    }

    IsGISAXSDetector_wrapper(::IsGISAXSDetector const & other )
    : IsGISAXSDetector( boost::ref(other) )
      , bp::wrapper< IsGISAXSDetector >(){
        // copy constructor
    m_pyobj = 0;
    }

    virtual ::IsGISAXSDetector * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->IsGISAXSDetector::clone(  );
        }
    }
    
    ::IsGISAXSDetector * default_clone(  ) const  {
        return IsGISAXSDetector::clone( );
    }

    virtual ::OutputData< double > * createDetectorMap( ::Beam const & beam, ::IDetector2D::EAxesUnits units_type ) const  {
        if( bp::override func_createDetectorMap = this->get_override( "createDetectorMap" ) )
            return func_createDetectorMap( boost::ref(beam), units_type );
        else{
            return this->SphericalDetector::createDetectorMap( boost::ref(beam), units_type );
        }
    }
    
    ::OutputData< double > * default_createDetectorMap( ::Beam const & beam, ::IDetector2D::EAxesUnits units_type ) const  {
        return SphericalDetector::createDetectorMap( boost::ref(beam), units_type );
    }

    virtual ::IDetector2D::EAxesUnits getDefaultAxesUnits(  ) const  {
        if( bp::override func_getDefaultAxesUnits = this->get_override( "getDefaultAxesUnits" ) )
            return func_getDefaultAxesUnits(  );
        else{
            return this->SphericalDetector::getDefaultAxesUnits(  );
        }
    }
    
    ::IDetector2D::EAxesUnits default_getDefaultAxesUnits(  ) const  {
        return SphericalDetector::getDefaultAxesUnits( );
    }

    virtual ::std::vector< IDetector2D::EAxesUnits > getValidAxesUnits(  ) const  {
        if( bp::override func_getValidAxesUnits = this->get_override( "getValidAxesUnits" ) )
            return func_getValidAxesUnits(  );
        else{
            return this->SphericalDetector::getValidAxesUnits(  );
        }
    }
    
    ::std::vector< IDetector2D::EAxesUnits > default_getValidAxesUnits(  ) const  {
        return SphericalDetector::getValidAxesUnits( );
    }

    virtual void init( ::Beam const & beam ) {
        if( bp::override func_init = this->get_override( "init" ) )
            func_init( boost::ref(beam) );
        else{
            this->IDetector2D::init( boost::ref(beam) );
        }
    }
    
    void default_init( ::Beam const & beam ) {
        IDetector2D::init( boost::ref(beam) );
    }

    PyObject* m_pyobj;

};

void register_IsGISAXSDetector_class(){

    { //::IsGISAXSDetector
        typedef bp::class_< IsGISAXSDetector_wrapper, bp::bases< SphericalDetector >, std::auto_ptr< IsGISAXSDetector_wrapper > > IsGISAXSDetector_exposer_t;
        IsGISAXSDetector_exposer_t IsGISAXSDetector_exposer = IsGISAXSDetector_exposer_t( "IsGISAXSDetector", "A spherical detector used for validation with IsGISAXS results.", bp::init< >() );
        bp::scope IsGISAXSDetector_scope( IsGISAXSDetector_exposer );
        IsGISAXSDetector_exposer.def( bp::init< std::size_t, double, double, std::size_t, double, double >(( bp::arg("n_phi"), bp::arg("phi_min"), bp::arg("phi_max"), bp::arg("n_alpha"), bp::arg("alpha_min"), bp::arg("alpha_max") )) );
        IsGISAXSDetector_exposer.def( bp::init< IsGISAXSDetector const & >(( bp::arg("other") )) );
        { //::IsGISAXSDetector::clone
        
            typedef ::IsGISAXSDetector * ( ::IsGISAXSDetector::*clone_function_type)(  ) const;
            typedef ::IsGISAXSDetector * ( IsGISAXSDetector_wrapper::*default_clone_function_type)(  ) const;
            
            IsGISAXSDetector_exposer.def( 
                "clone"
                , clone_function_type(&::IsGISAXSDetector::clone)
                , default_clone_function_type(&IsGISAXSDetector_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IsGISAXSDetector::operator=
        
            typedef ::IsGISAXSDetector & ( ::IsGISAXSDetector::*assign_function_type)( ::IsGISAXSDetector const & ) ;
            
            IsGISAXSDetector_exposer.def( 
                "assign"
                , assign_function_type( &::IsGISAXSDetector::operator= )
                , ( bp::arg("other") )
                , bp::return_self< >() );
        
        }
        { //::SphericalDetector::createDetectorMap
        
            typedef ::OutputData< double > * ( ::SphericalDetector::*createDetectorMap_function_type)( ::Beam const &,::IDetector2D::EAxesUnits ) const;
            typedef ::OutputData< double > * ( IsGISAXSDetector_wrapper::*default_createDetectorMap_function_type)( ::Beam const &,::IDetector2D::EAxesUnits ) const;
            
            IsGISAXSDetector_exposer.def( 
                "createDetectorMap"
                , createDetectorMap_function_type(&::SphericalDetector::createDetectorMap)
                , default_createDetectorMap_function_type(&IsGISAXSDetector_wrapper::default_createDetectorMap)
                , ( bp::arg("beam"), bp::arg("units_type") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::SphericalDetector::getDefaultAxesUnits
        
            typedef ::IDetector2D::EAxesUnits ( ::SphericalDetector::*getDefaultAxesUnits_function_type)(  ) const;
            typedef ::IDetector2D::EAxesUnits ( IsGISAXSDetector_wrapper::*default_getDefaultAxesUnits_function_type)(  ) const;
            
            IsGISAXSDetector_exposer.def( 
                "getDefaultAxesUnits"
                , getDefaultAxesUnits_function_type(&::SphericalDetector::getDefaultAxesUnits)
                , default_getDefaultAxesUnits_function_type(&IsGISAXSDetector_wrapper::default_getDefaultAxesUnits) );
        
        }
        { //::SphericalDetector::getValidAxesUnits
        
            typedef ::std::vector< IDetector2D::EAxesUnits > ( ::SphericalDetector::*getValidAxesUnits_function_type)(  ) const;
            typedef ::std::vector< IDetector2D::EAxesUnits > ( IsGISAXSDetector_wrapper::*default_getValidAxesUnits_function_type)(  ) const;
            
            IsGISAXSDetector_exposer.def( 
                "getValidAxesUnits"
                , getValidAxesUnits_function_type(&::SphericalDetector::getValidAxesUnits)
                , default_getValidAxesUnits_function_type(&IsGISAXSDetector_wrapper::default_getValidAxesUnits) );
        
        }
        { //::IDetector2D::init
        
            typedef void ( ::IDetector2D::*init_function_type)( ::Beam const & ) ;
            typedef void ( IsGISAXSDetector_wrapper::*default_init_function_type)( ::Beam const & ) ;
            
            IsGISAXSDetector_exposer.def( 
                "init"
                , init_function_type(&::IDetector2D::init)
                , default_init_function_type(&IsGISAXSDetector_wrapper::default_init)
                , ( bp::arg("beam") ) );
        
        }
    }

}
