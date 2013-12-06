#include "TestFunctionalTests.h"
#include "ProgramOptions.h"
#include "MessageService.h"
#include <iostream>
#include <vector>
#include <string>

TestFunctionalTests::TestFunctionalTests()
{

}


void TestFunctionalTests::execute()
{
    std::cout << "TestFunctionalTest::execute() -> Hello World." << std::endl;

   if(!readTestNames()) return;


}


bool TestFunctionalTests::readTestNames()
{
    if (mp_options->find("functest")) {
        m_testNames = (*mp_options)["functest"].as<std::vector<std::string> >();
    }

    bool areCorrectNames(true);
    if(m_testNames.empty()) {
        std::cout << "TestFunctionalTest::readTestNames() -> Info. No tests specified. Select one or more from list below." << std::endl;
        areCorrectNames = false;
    }

    for(size_t i=0; i<m_testNames.size(); ++i) {
        if(!m_testRegistry.isRegisteredName(m_testNames[i])) {
            std::cout << "TestFunctionalTest::readTestNames() -> Info. Not registered test with name '" << m_testNames[i] << "'." << std::endl;
            areCorrectNames = false;
        }
    }

    if(areCorrectNames) {
        return true;
    } else {
        m_testRegistry.printCatalogue();
        std::cout << std::endl;
        return false;
    }
}
