// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonFitAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonFitList.h"
#include "SquaredFunctionDefault.pypp.h"

namespace bp = boost::python;

struct SquaredFunctionDefault_wrapper : SquaredFunctionDefault, bp::wrapper< SquaredFunctionDefault > {

    SquaredFunctionDefault_wrapper( )
    : SquaredFunctionDefault( )
      , bp::wrapper< SquaredFunctionDefault >(){
        // null constructor
    
    }

    virtual double calculateSquaredDifference( double real_value, double simulated_value ) const  {
        if( bp::override func_calculateSquaredDifference = this->get_override( "calculateSquaredDifference" ) )
            return func_calculateSquaredDifference( real_value, simulated_value );
        else{
            return this->SquaredFunctionDefault::calculateSquaredDifference( real_value, simulated_value );
        }
    }
    
    double default_calculateSquaredDifference( double real_value, double simulated_value ) const  {
        return SquaredFunctionDefault::calculateSquaredDifference( real_value, simulated_value );
    }

    virtual double calculateSquaredError( double real_value, double simulated_value=0 ) const  {
        if( bp::override func_calculateSquaredError = this->get_override( "calculateSquaredError" ) )
            return func_calculateSquaredError( real_value, simulated_value );
        else{
            return this->SquaredFunctionDefault::calculateSquaredError( real_value, simulated_value );
        }
    }
    
    double default_calculateSquaredError( double real_value, double simulated_value=0 ) const  {
        return SquaredFunctionDefault::calculateSquaredError( real_value, simulated_value );
    }

    virtual ::SquaredFunctionDefault * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->SquaredFunctionDefault::clone(  );
        }
    }
    
    ::SquaredFunctionDefault * default_clone(  ) const  {
        return SquaredFunctionDefault::clone( );
    }

};

void register_SquaredFunctionDefault_class(){

    { //::SquaredFunctionDefault
        typedef bp::class_< SquaredFunctionDefault_wrapper, bp::bases< ISquaredFunction >, boost::noncopyable > SquaredFunctionDefault_exposer_t;
        SquaredFunctionDefault_exposer_t SquaredFunctionDefault_exposer = SquaredFunctionDefault_exposer_t( "SquaredFunctionDefault", bp::init< >() );
        bp::scope SquaredFunctionDefault_scope( SquaredFunctionDefault_exposer );
        { //::SquaredFunctionDefault::calculateSquaredDifference
        
            typedef double ( ::SquaredFunctionDefault::*calculateSquaredDifference_function_type)( double,double ) const;
            typedef double ( SquaredFunctionDefault_wrapper::*default_calculateSquaredDifference_function_type)( double,double ) const;
            
            SquaredFunctionDefault_exposer.def( 
                "calculateSquaredDifference"
                , calculateSquaredDifference_function_type(&::SquaredFunctionDefault::calculateSquaredDifference)
                , default_calculateSquaredDifference_function_type(&SquaredFunctionDefault_wrapper::default_calculateSquaredDifference)
                , ( bp::arg("real_value"), bp::arg("simulated_value") ) );
        
        }
        { //::SquaredFunctionDefault::calculateSquaredError
        
            typedef double ( ::SquaredFunctionDefault::*calculateSquaredError_function_type)( double,double ) const;
            typedef double ( SquaredFunctionDefault_wrapper::*default_calculateSquaredError_function_type)( double,double ) const;
            
            SquaredFunctionDefault_exposer.def( 
                "calculateSquaredError"
                , calculateSquaredError_function_type(&::SquaredFunctionDefault::calculateSquaredError)
                , default_calculateSquaredError_function_type(&SquaredFunctionDefault_wrapper::default_calculateSquaredError)
                , ( bp::arg("real_value"), bp::arg("simulated_value")=0 ) );
        
        }
        { //::SquaredFunctionDefault::clone
        
            typedef ::SquaredFunctionDefault * ( ::SquaredFunctionDefault::*clone_function_type)(  ) const;
            typedef ::SquaredFunctionDefault * ( SquaredFunctionDefault_wrapper::*default_clone_function_type)(  ) const;
            
            SquaredFunctionDefault_exposer.def( 
                "clone"
                , clone_function_type(&::SquaredFunctionDefault::clone)
                , default_clone_function_type(&SquaredFunctionDefault_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
    }

}
