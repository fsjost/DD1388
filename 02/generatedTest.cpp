/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "Test_Complex.h"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "Test_Complex.h", 4, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testRealimagAbs : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testRealimagAbs() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 15, "testRealimagAbs" ) {}
 void runTest() { suite_MyTestSuite.testRealimagAbs(); }
} testDescription_suite_MyTestSuite_testRealimagAbs;

static class TestDescription_suite_MyTestSuite_testAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAddition() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 27, "testAddition" ) {}
 void runTest() { suite_MyTestSuite.testAddition(); }
} testDescription_suite_MyTestSuite_testAddition;

static class TestDescription_suite_MyTestSuite_testSubtraction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testSubtraction() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 36, "testSubtraction" ) {}
 void runTest() { suite_MyTestSuite.testSubtraction(); }
} testDescription_suite_MyTestSuite_testSubtraction;

static class TestDescription_suite_MyTestSuite_testMultiplication : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMultiplication() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 44, "testMultiplication" ) {}
 void runTest() { suite_MyTestSuite.testMultiplication(); }
} testDescription_suite_MyTestSuite_testMultiplication;

static class TestDescription_suite_MyTestSuite_testDivision : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testDivision() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 51, "testDivision" ) {}
 void runTest() { suite_MyTestSuite.testDivision(); }
} testDescription_suite_MyTestSuite_testDivision;

static class TestDescription_suite_MyTestSuite_testMixedOperators : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMixedOperators() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 58, "testMixedOperators" ) {}
 void runTest() { suite_MyTestSuite.testMixedOperators(); }
} testDescription_suite_MyTestSuite_testMixedOperators;

static class TestDescription_suite_MyTestSuite_testBoolean : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testBoolean() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 64, "testBoolean" ) {}
 void runTest() { suite_MyTestSuite.testBoolean(); }
} testDescription_suite_MyTestSuite_testBoolean;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
