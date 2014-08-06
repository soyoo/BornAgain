// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonCoreAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonCoreList.h"
#include "AxisDouble.pypp.h"

namespace bp = boost::python;

struct AxisDouble_wrapper : AxisDouble, bp::wrapper< AxisDouble > {

    AxisDouble_wrapper(AxisDouble const & arg )
    : AxisDouble( arg )
      , bp::wrapper< AxisDouble >(){
        // copy constructor
        
    }

    AxisDouble_wrapper(::std::string name )
    : AxisDouble( name )
      , bp::wrapper< AxisDouble >(){
        // constructor
    
    }

    AxisDouble_wrapper(::std::string name, ::std::size_t size, double start, double end )
    : AxisDouble( name, size, start, end )
      , bp::wrapper< AxisDouble >(){
        // constructor
    
    }

    AxisDouble_wrapper(::AxisBin const & source )
    : AxisDouble( boost::ref(source) )
      , bp::wrapper< AxisDouble >(){
        // constructor
    
    }

    virtual ::std::size_t findClosestIndex( double value ) const  {
        if( bp::override func_findClosestIndex = this->get_override( "findClosestIndex" ) )
            return func_findClosestIndex( value );
        else
            return this->AxisDouble::findClosestIndex( value );
    }
    
    
    ::std::size_t default_findClosestIndex( double value ) const  {
        return AxisDouble::findClosestIndex( value );
    }

    virtual ::Bin1D getBin( ::std::size_t index ) const  {
        if( bp::override func_getBin = this->get_override( "getBin" ) )
            return func_getBin( index );
        else
            return this->AxisDouble::getBin( index );
    }
    
    
    ::Bin1D default_getBin( ::std::size_t index ) const  {
        return AxisDouble::getBin( index );
    }

    virtual double getMax(  ) const  {
        if( bp::override func_getMax = this->get_override( "getMax" ) )
            return func_getMax(  );
        else
            return this->AxisDouble::getMax(  );
    }
    
    
    double default_getMax(  ) const  {
        return AxisDouble::getMax( );
    }

    virtual double getMin(  ) const  {
        if( bp::override func_getMin = this->get_override( "getMin" ) )
            return func_getMin(  );
        else
            return this->AxisDouble::getMin(  );
    }
    
    
    double default_getMin(  ) const  {
        return AxisDouble::getMin( );
    }

    virtual ::std::size_t getSize(  ) const  {
        if( bp::override func_getSize = this->get_override( "getSize" ) )
            return func_getSize(  );
        else
            return this->AxisDouble::getSize(  );
    }
    
    
    ::std::size_t default_getSize(  ) const  {
        return AxisDouble::getSize( );
    }

    virtual double operator[]( ::std::size_t index ) const  {
        if( bp::override func___getitem__ = this->get_override( "__getitem__" ) )
            return func___getitem__( index );
        else
            return this->AxisDouble::operator[]( index );
    }
    
    
    double default___getitem__( ::std::size_t index ) const  {
        return AxisDouble::operator[]( index );
    }

    virtual ::std::vector< double > getBinBoundaries(  ) const  {
        if( bp::override func_getBinBoundaries = this->get_override( "getBinBoundaries" ) )
            return func_getBinBoundaries(  );
        else
            return this->IAxis::getBinBoundaries(  );
    }
    
    
    ::std::vector< double > default_getBinBoundaries(  ) const  {
        return IAxis::getBinBoundaries( );
    }

    virtual ::std::vector< double > getBinCenters(  ) const  {
        if( bp::override func_getBinCenters = this->get_override( "getBinCenters" ) )
            return func_getBinCenters(  );
        else
            return this->IAxis::getBinCenters(  );
    }
    
    
    ::std::vector< double > default_getBinCenters(  ) const  {
        return IAxis::getBinCenters( );
    }

};

void register_AxisDouble_class(){

    { //::AxisDouble
        typedef bp::class_< AxisDouble_wrapper, bp::bases< IAxis > > AxisDouble_exposer_t;
        AxisDouble_exposer_t AxisDouble_exposer = AxisDouble_exposer_t( "AxisDouble", bp::init< std::string >(( bp::arg("name") )) );
        bp::scope AxisDouble_scope( AxisDouble_exposer );
        AxisDouble_exposer.def( bp::init< std::string, std::size_t, double, double >(( bp::arg("name"), bp::arg("size"), bp::arg("start"), bp::arg("end") )) );
        AxisDouble_exposer.def( bp::init< AxisBin const & >(( bp::arg("source") )) );
        { //::AxisDouble::findClosestIndex
        
            typedef ::std::size_t ( ::AxisDouble::*findClosestIndex_function_type )( double ) const;
            typedef ::std::size_t ( AxisDouble_wrapper::*default_findClosestIndex_function_type )( double ) const;
            
            AxisDouble_exposer.def( 
                "findClosestIndex"
                , findClosestIndex_function_type(&::AxisDouble::findClosestIndex)
                , default_findClosestIndex_function_type(&AxisDouble_wrapper::default_findClosestIndex)
                , ( bp::arg("value") ) );
        
        }
        { //::AxisDouble::getBin
        
            typedef ::Bin1D ( ::AxisDouble::*getBin_function_type )( ::std::size_t ) const;
            typedef ::Bin1D ( AxisDouble_wrapper::*default_getBin_function_type )( ::std::size_t ) const;
            
            AxisDouble_exposer.def( 
                "getBin"
                , getBin_function_type(&::AxisDouble::getBin)
                , default_getBin_function_type(&AxisDouble_wrapper::default_getBin)
                , ( bp::arg("index") ) );
        
        }
        { //::AxisDouble::getLowerBoundIndex
        
            typedef ::std::size_t ( ::AxisDouble::*getLowerBoundIndex_function_type )( double ) const;
            
            AxisDouble_exposer.def( 
                "getLowerBoundIndex"
                , getLowerBoundIndex_function_type( &::AxisDouble::getLowerBoundIndex )
                , ( bp::arg("value") ) );
        
        }
        { //::AxisDouble::getMax
        
            typedef double ( ::AxisDouble::*getMax_function_type )(  ) const;
            typedef double ( AxisDouble_wrapper::*default_getMax_function_type )(  ) const;
            
            AxisDouble_exposer.def( 
                "getMax"
                , getMax_function_type(&::AxisDouble::getMax)
                , default_getMax_function_type(&AxisDouble_wrapper::default_getMax) );
        
        }
        { //::AxisDouble::getMin
        
            typedef double ( ::AxisDouble::*getMin_function_type )(  ) const;
            typedef double ( AxisDouble_wrapper::*default_getMin_function_type )(  ) const;
            
            AxisDouble_exposer.def( 
                "getMin"
                , getMin_function_type(&::AxisDouble::getMin)
                , default_getMin_function_type(&AxisDouble_wrapper::default_getMin) );
        
        }
        { //::AxisDouble::getSize
        
            typedef ::std::size_t ( ::AxisDouble::*getSize_function_type )(  ) const;
            typedef ::std::size_t ( AxisDouble_wrapper::*default_getSize_function_type )(  ) const;
            
            AxisDouble_exposer.def( 
                "getSize"
                , getSize_function_type(&::AxisDouble::getSize)
                , default_getSize_function_type(&AxisDouble_wrapper::default_getSize) );
        
        }
        { //::AxisDouble::getUpperBoundIndex
        
            typedef ::std::size_t ( ::AxisDouble::*getUpperBoundIndex_function_type )( double ) const;
            
            AxisDouble_exposer.def( 
                "getUpperBoundIndex"
                , getUpperBoundIndex_function_type( &::AxisDouble::getUpperBoundIndex )
                , ( bp::arg("value") ) );
        
        }
        { //::AxisDouble::getVector
        
            typedef ::std::vector< double > ( ::AxisDouble::*getVector_function_type )(  ) const;
            
            AxisDouble_exposer.def( 
                "getVector"
                , getVector_function_type( &::AxisDouble::getVector ) );
        
        }
        { //::AxisDouble::initElements
        
            typedef void ( ::AxisDouble::*initElements_function_type )( ::std::size_t,double,double ) ;
            
            AxisDouble_exposer.def( 
                "initElements"
                , initElements_function_type( &::AxisDouble::initElements )
                , ( bp::arg("size"), bp::arg("start"), bp::arg("end") ) );
        
        }
        { //::AxisDouble::operator[]
        
            typedef double ( ::AxisDouble::*__getitem___function_type )( ::std::size_t ) const;
            typedef double ( AxisDouble_wrapper::*default___getitem___function_type )( ::std::size_t ) const;
            
            AxisDouble_exposer.def( 
                "__getitem__"
                , __getitem___function_type(&::AxisDouble::operator[])
                , default___getitem___function_type(&AxisDouble_wrapper::default___getitem__)
                , ( bp::arg("index") ) );
        
        }
        { //::AxisDouble::push_back
        
            typedef void ( ::AxisDouble::*push_back_function_type )( double ) ;
            
            AxisDouble_exposer.def( 
                "push_back"
                , push_back_function_type( &::AxisDouble::push_back )
                , ( bp::arg("element") ) );
        
        }
        { //::IAxis::getBinBoundaries
        
            typedef ::std::vector< double > ( ::IAxis::*getBinBoundaries_function_type )(  ) const;
            typedef ::std::vector< double > ( AxisDouble_wrapper::*default_getBinBoundaries_function_type )(  ) const;
            
            AxisDouble_exposer.def( 
                "getBinBoundaries"
                , getBinBoundaries_function_type(&::IAxis::getBinBoundaries)
                , default_getBinBoundaries_function_type(&AxisDouble_wrapper::default_getBinBoundaries) );
        
        }
        { //::IAxis::getBinCenters
        
            typedef ::std::vector< double > ( ::IAxis::*getBinCenters_function_type )(  ) const;
            typedef ::std::vector< double > ( AxisDouble_wrapper::*default_getBinCenters_function_type )(  ) const;
            
            AxisDouble_exposer.def( 
                "getBinCenters"
                , getBinCenters_function_type(&::IAxis::getBinCenters)
                , default_getBinCenters_function_type(&AxisDouble_wrapper::default_getBinCenters) );
        
        }
    }

}
