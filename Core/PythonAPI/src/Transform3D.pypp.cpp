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
#include "Transform3D.pypp.h"

namespace bp = boost::python;

void register_Transform3D_class(){

    { //::Geometry::Transform3D
        typedef bp::class_< Geometry::Transform3D > Transform3D_exposer_t;
        Transform3D_exposer_t Transform3D_exposer = Transform3D_exposer_t( "Transform3D", bp::init< >() );
        bp::scope Transform3D_scope( Transform3D_exposer );
        Transform3D_exposer.def( bp::init< Geometry::Transform3D const & >(( bp::arg("other") )) );
        { //::Geometry::Transform3D::clone
        
            typedef ::Geometry::Transform3D * ( ::Geometry::Transform3D::*clone_function_type)(  ) const;
            
            Transform3D_exposer.def( 
                "clone"
                , clone_function_type( &::Geometry::Transform3D::clone )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::Geometry::Transform3D::createIdentity
        
            typedef ::Geometry::Transform3D ( *createIdentity_function_type )(  );
            
            Transform3D_exposer.def( 
                "createIdentity"
                , createIdentity_function_type( &::Geometry::Transform3D::createIdentity )
                , bp::return_value_policy< bp::return_by_value >() );
        
        }
        { //::Geometry::Transform3D::createInverse
        
            typedef ::Geometry::Transform3D * ( ::Geometry::Transform3D::*createInverse_function_type)(  ) const;
            
            Transform3D_exposer.def( 
                "createInverse"
                , createInverse_function_type( &::Geometry::Transform3D::createInverse )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::Geometry::Transform3D::createRotateX
        
            typedef ::Geometry::Transform3D ( *createRotateX_function_type )( double );
            
            Transform3D_exposer.def( 
                "createRotateX"
                , createRotateX_function_type( &::Geometry::Transform3D::createRotateX )
                , ( bp::arg("phi") )
                , bp::return_value_policy< bp::return_by_value >() );
        
        }
        { //::Geometry::Transform3D::createRotateY
        
            typedef ::Geometry::Transform3D ( *createRotateY_function_type )( double );
            
            Transform3D_exposer.def( 
                "createRotateY"
                , createRotateY_function_type( &::Geometry::Transform3D::createRotateY )
                , ( bp::arg("phi") )
                , bp::return_value_policy< bp::return_by_value >() );
        
        }
        { //::Geometry::Transform3D::createRotateZ
        
            typedef ::Geometry::Transform3D ( *createRotateZ_function_type )( double );
            
            Transform3D_exposer.def( 
                "createRotateZ"
                , createRotateZ_function_type( &::Geometry::Transform3D::createRotateZ )
                , ( bp::arg("phi") )
                , bp::return_value_policy< bp::return_by_value >() );
        
        }
        Transform3D_exposer.def( bp::self * bp::self );
        { //::Geometry::Transform3D::print
        
            typedef void ( ::Geometry::Transform3D::*print_function_type)( ::std::ostream & ) const;
            
            Transform3D_exposer.def( 
                "print"
                , print_function_type( &::Geometry::Transform3D::print )
                , ( bp::arg("ostr") ) );
        
        }
        { //::Geometry::Transform3D::transformedInverse
        
            typedef ::Geometry::BasicVector3D< double > ( ::Geometry::Transform3D::*transformedInverse_function_type)( ::Geometry::BasicVector3D< double > const & ) const;
            
            Transform3D_exposer.def( 
                "transformedInverse"
                , transformedInverse_function_type( &::Geometry::Transform3D::transformedInverse )
                , ( bp::arg("v") ) );
        
        }
        { //::Geometry::Transform3D::transformedInverse
        
            typedef ::Geometry::BasicVector3D< std::complex< double > > ( ::Geometry::Transform3D::*transformedInverse_function_type)( ::Geometry::BasicVector3D< std::complex< double > > const & ) const;
            
            Transform3D_exposer.def( 
                "transformedInverse"
                , transformedInverse_function_type( &::Geometry::Transform3D::transformedInverse )
                , ( bp::arg("v") ) );
        
        }
        Transform3D_exposer.staticmethod( "createIdentity" );
        Transform3D_exposer.staticmethod( "createRotateX" );
        Transform3D_exposer.staticmethod( "createRotateY" );
        Transform3D_exposer.staticmethod( "createRotateZ" );
    }

}
