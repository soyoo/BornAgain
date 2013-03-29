// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "AttLimits.h"
#include "IChiSquaredModule.h"
#include "IMinimizer.h"
#include "ChiSquaredModule.h"
#include "FitSuite.h"
#include "FitSuiteParameters.h"
#include "MinimizerFactory.h"
#include "PythonPlusplusFitHelper.h"
#include "MathFunctions.h"
#include "ISquaredFunction.h"
#include "IOutputDataNormalizer.h"
#include "OutputDataNormalizer.pypp.h"

namespace bp = boost::python;

struct OutputDataNormalizer_wrapper : OutputDataNormalizer, bp::wrapper< OutputDataNormalizer > {

    OutputDataNormalizer_wrapper(OutputDataNormalizer const & arg )
    : OutputDataNormalizer( arg )
      , bp::wrapper< OutputDataNormalizer >(){
        // copy constructor
        
    }

    OutputDataNormalizer_wrapper(double scale=1.0e+0, double shift=0.0 )
    : OutputDataNormalizer( scale, shift )
      , bp::wrapper< OutputDataNormalizer >(){
        // constructor
    
    }

    virtual ::OutputDataNormalizer * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->OutputDataNormalizer::clone(  );
        }
    }
    
    ::OutputDataNormalizer * default_clone(  ) const  {
        return OutputDataNormalizer::clone( );
    }

    virtual ::OutputData< double > * createNormalizedData( ::OutputData< double > const & data ) const  {
        if( bp::override func_createNormalizedData = this->get_override( "createNormalizedData" ) )
            return func_createNormalizedData( boost::ref(data) );
        else{
            return this->OutputDataNormalizer::createNormalizedData( boost::ref(data) );
        }
    }
    
    ::OutputData< double > * default_createNormalizedData( ::OutputData< double > const & data ) const  {
        return OutputDataNormalizer::createNormalizedData( boost::ref(data) );
    }

    virtual void setMaximumIntensity( double max_intensity ) {
        if( bp::override func_setMaximumIntensity = this->get_override( "setMaximumIntensity" ) )
            func_setMaximumIntensity( max_intensity );
        else{
            this->OutputDataNormalizer::setMaximumIntensity( max_intensity );
        }
    }
    
    void default_setMaximumIntensity( double max_intensity ) {
        OutputDataNormalizer::setMaximumIntensity( max_intensity );
    }

};

void register_OutputDataNormalizer_class(){

    bp::class_< OutputDataNormalizer_wrapper, bp::bases< IOutputDataNormalizer > >( "OutputDataNormalizer", bp::init< bp::optional< double, double > >(( bp::arg("scale")=1.0e+0, bp::arg("shift")=0.0 )) )    
        .def( 
            "clone"
            , (::OutputDataNormalizer * ( ::OutputDataNormalizer::* )(  ) const)(&::OutputDataNormalizer::clone)
            , (::OutputDataNormalizer * ( OutputDataNormalizer_wrapper::* )(  ) const)(&OutputDataNormalizer_wrapper::default_clone)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "createNormalizedData"
            , (::OutputData< double > * ( ::OutputDataNormalizer::* )( ::OutputData< double > const & ) const)(&::OutputDataNormalizer::createNormalizedData)
            , (::OutputData< double > * ( OutputDataNormalizer_wrapper::* )( ::OutputData< double > const & ) const)(&OutputDataNormalizer_wrapper::default_createNormalizedData)
            , ( bp::arg("data") )
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "setMaximumIntensity"
            , (void ( ::OutputDataNormalizer::* )( double ) )(&::OutputDataNormalizer::setMaximumIntensity)
            , (void ( OutputDataNormalizer_wrapper::* )( double ) )(&OutputDataNormalizer_wrapper::default_setMaximumIntensity)
            , ( bp::arg("max_intensity") ) );

}
