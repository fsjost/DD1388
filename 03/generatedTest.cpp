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
bool suite_TestSuite1_init = false;
#include "bintest.h"

static TestSuite1 suite_TestSuite1;

static CxxTest::List Tests_TestSuite1 = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestSuite1( "bintest.h", 4, "TestSuite1", suite_TestSuite1, Tests_TestSuite1 );

static class TestDescription_suite_TestSuite1_testNull : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSuite1_testNull() : CxxTest::RealTestDescription( Tests_TestSuite1, suiteDescription_TestSuite1, 7, "testNull" ) {}
 void runTest() { suite_TestSuite1.testNull(); }
} testDescription_suite_TestSuite1_testNull;

static class TestDescription_suite_TestSuite1_testOne : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSuite1_testOne() : CxxTest::RealTestDescription( Tests_TestSuite1, suiteDescription_TestSuite1, 18, "testOne" ) {}
 void runTest() { suite_TestSuite1.testOne(); }
} testDescription_suite_TestSuite1_testOne;

static class TestDescription_suite_TestSuite1_testMore : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSuite1_testMore() : CxxTest::RealTestDescription( Tests_TestSuite1, suiteDescription_TestSuite1, 30, "testMore" ) {}
 void runTest() { suite_TestSuite1.testMore(); }
} testDescription_suite_TestSuite1_testMore;

static class TestDescription_suite_TestSuite1_testShitLoads : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSuite1_testShitLoads() : CxxTest::RealTestDescription( Tests_TestSuite1, suiteDescription_TestSuite1, 48, "testShitLoads" ) {}
 void runTest() { suite_TestSuite1.testShitLoads(); }
} testDescription_suite_TestSuite1_testShitLoads;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
