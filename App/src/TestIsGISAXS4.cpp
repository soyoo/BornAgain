// ************************************************************************** //
//                                                                           
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      App/src/TestIsGISAXS4.cpp 
//! @brief     Implements class TestIsGISAXS4.
//
//! Homepage:  apps.jcns.fz-juelich.de/BornAgain
//! License:   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke 
//
// ************************************************************************** //

#include "TestIsGISAXS4.h"
#include "IsGISAXS04.h"
#include "IsGISAXSTools.h"
#include "OutputDataIOFactory.h"
#include "Utils.h"

#include <fstream>


TestIsGISAXS4::TestIsGISAXS4() : IFunctionalTest("TestIsGISAXS4")
{
    setOutputPath(Utils::FileSystem::GetHomePath()+"./Examples/IsGISAXS_examples/ex-4/" );
}


void TestIsGISAXS4::execute()
{
    FunctionalTests::IsGISAXS04 test;
    test.run1DDL();
    OutputDataIOFactory::writeOutputData(*test.getOutputData(FunctionalTests::IsGISAXS04::kTest_1DDL), getOutputPath()+"this_1DDL.ima");
    test.run2DDL();
    OutputDataIOFactory::writeOutputData(*test.getOutputData(FunctionalTests::IsGISAXS04::kTest_2DDL), getOutputPath()+"this_2DDLh.ima");
}


void TestIsGISAXS4::finalise()
{
        std::vector< CompareStruct > tocompare;

        tocompare.push_back( CompareStruct(getOutputPath()+"isgi_1DDL.ima.gz",  getOutputPath()+"this_1DDL.ima", "Cylinder 1DDL") );
        tocompare.push_back( CompareStruct(getOutputPath()+"isgi_2DDLh.ima.gz", getOutputPath()+"this_2DDLh.ima", "Cylinder 2DDL") );

        for(size_t i=0; i<tocompare.size(); ++i) {
            OutputData<double> *isgi_data = OutputDataIOFactory::getOutputData(tocompare[i].isginame);
            OutputData<double> *our_data = OutputDataIOFactory::getOutputData(tocompare[i].thisname);

            IsGISAXSTools::drawOutputDataComparisonResults(*our_data, *isgi_data, tocompare[i].descr, tocompare[i].descr);

            delete isgi_data;
            delete our_data;
        }

}
