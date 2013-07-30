// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence 
//! @brief automatically generated boost::python code for PythonCoreAPI  

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "PythonCoreList.h"
#include "PythonInterface_free_functions.pypp.h"

namespace bp = boost::python;

void register_free_functions(){

    { //::MathFunctions::GenerateNormalRandom
    
        typedef double ( *GenerateNormalRandom_function_type )( double,double );
        
        bp::def( 
            "GenerateNormalRandom"
            , GenerateNormalRandom_function_type( &::MathFunctions::GenerateNormalRandom )
            , ( bp::arg("average"), bp::arg("std_dev") ) );
    
    }

    { //::AppVersion::GetMajorVersionNumber
    
        typedef int ( *GetMajorVersionNumber_function_type )(  );
        
        bp::def( 
            "GetMajorVersionNumber"
            , GetMajorVersionNumber_function_type( &::AppVersion::GetMajorVersionNumber ) );
    
    }

    { //::AppVersion::GetMinorVersionNumber
    
        typedef int ( *GetMinorVersionNumber_function_type )(  );
        
        bp::def( 
            "GetMinorVersionNumber"
            , GetMinorVersionNumber_function_type( &::AppVersion::GetMinorVersionNumber ) );
    
    }

    { //::GetOutputData
    
        typedef ::PyObject * ( *GetOutputData_function_type )( ::Simulation const & );
        
        bp::def( 
            "GetOutputData"
            , GetOutputData_function_type( &::GetOutputData )
            , ( bp::arg("simulation") ) );
    
    }

    { //::GetOutputDataAxis
    
        typedef ::PyObject * ( *GetOutputDataAxis_function_type )( ::Simulation const &,int );
        
        bp::def( 
            "GetOutputDataAxis"
            , GetOutputDataAxis_function_type( &::GetOutputDataAxis )
            , ( bp::arg("simulation"), bp::arg("naxis") ) );
    
    }

    { //::GetOutputDataNdimensions
    
        typedef int ( *GetOutputDataNdimensions_function_type )( ::Simulation const & );
        
        bp::def( 
            "GetOutputDataNdimensions"
            , GetOutputDataNdimensions_function_type( &::GetOutputDataNdimensions )
            , ( bp::arg("simulation") ) );
    
    }

    { //::AppVersion::GetPatchVersionNumber
    
        typedef int ( *GetPatchVersionNumber_function_type )(  );
        
        bp::def( 
            "GetPatchVersionNumber"
            , GetPatchVersionNumber_function_type( &::AppVersion::GetPatchVersionNumber ) );
    
    }

    { //::AppVersion::GetVersionNumber
    
        typedef ::std::string ( *GetVersionNumber_function_type )(  );
        
        bp::def( 
            "GetVersionNumber"
            , GetVersionNumber_function_type( &::AppVersion::GetVersionNumber ) );
    
    }

    { //::Units::deg2rad
    
        typedef double ( *deg2rad_function_type )( double );
        
        bp::def( 
            "deg2rad"
            , deg2rad_function_type( &::Units::deg2rad )
            , ( bp::arg("angle") ) );
    
    }

    { //::Units::rad2deg
    
        typedef double ( *rad2deg_function_type )( double );
        
        bp::def( 
            "rad2deg"
            , rad2deg_function_type( &::Units::rad2deg )
            , ( bp::arg("angle") ) );
    
    }

}
