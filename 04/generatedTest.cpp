/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
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
#include "cxx_test.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "cxx_test.cpp", 5, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test_constructors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_constructors() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 8, "test_constructors" ) {}
 void runTest() { suite_MyTestSuite.test_constructors(); }
} testDescription_suite_MyTestSuite_test_constructors;

static class TestDescription_suite_MyTestSuite_test_addition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_addition() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 26, "test_addition" ) {}
 void runTest() { suite_MyTestSuite.test_addition(); }
} testDescription_suite_MyTestSuite_test_addition;

static class TestDescription_suite_MyTestSuite_test_subtraction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_subtraction() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 40, "test_subtraction" ) {}
 void runTest() { suite_MyTestSuite.test_subtraction(); }
} testDescription_suite_MyTestSuite_test_subtraction;

static class TestDescription_suite_MyTestSuite_test_multiplication : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_multiplication() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 54, "test_multiplication" ) {}
 void runTest() { suite_MyTestSuite.test_multiplication(); }
} testDescription_suite_MyTestSuite_test_multiplication;

static class TestDescription_suite_MyTestSuite_test_excel_functions : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_excel_functions() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 64, "test_excel_functions" ) {}
 void runTest() { suite_MyTestSuite.test_excel_functions(); }
} testDescription_suite_MyTestSuite_test_excel_functions;

static class TestDescription_suite_MyTestSuite_test_reset : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_reset() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 85, "test_reset" ) {}
 void runTest() { suite_MyTestSuite.test_reset(); }
} testDescription_suite_MyTestSuite_test_reset;

static class TestDescription_suite_MyTestSuite_test_identity : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_identity() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 93, "test_identity" ) {}
 void runTest() { suite_MyTestSuite.test_identity(); }
} testDescription_suite_MyTestSuite_test_identity;

static class TestDescription_suite_MyTestSuite_test_random_functions : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_random_functions() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 100, "test_random_functions" ) {}
 void runTest() { suite_MyTestSuite.test_random_functions(); }
} testDescription_suite_MyTestSuite_test_random_functions;

static class TestDescription_suite_MyTestSuite_test_output : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_output() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 115, "test_output" ) {}
 void runTest() { suite_MyTestSuite.test_output(); }
} testDescription_suite_MyTestSuite_test_output;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
