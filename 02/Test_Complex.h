#include <cxxtest/TestSuite.h>
#include "complex2.0.cpp"

class MyTestSuite: public CxxTest::TestSuite {
  public:
    // DEFINING A LOT OF NUMBERS TO USE
    Complex zeroNumb;                                             //SHOULD CREATE (0,0)
    Complex onlyReal = Complex(5.3,0);
    Complex onlyImag = Complex(0,-6.5);
    Complex combinedNumber = Complex(4.3,-2.9);
    Complex dragHer = onlyReal + onlyImag;
    Complex constanten = 4_i;

    // TEST STANDARD THINGS
    void testRealimagAbs() {
      TS_ASSERT_EQUALS(real(onlyReal), 5.3);
      TS_ASSERT_EQUALS(real(onlyImag), 0);
      TS_ASSERT_EQUALS(imag(onlyReal), 0);
      TS_ASSERT_EQUALS(imag(onlyImag), -6.5);
      TS_ASSERT_DELTA(abs(combinedNumber), 5.18652099,1e-6);
      TS_ASSERT_DELTA(abs(zeroNumb), 0,1e-7);
      TS_ASSERT_EQUALS(real(onlyReal),onlyReal.real());
      TS_ASSERT_EQUALS(imag(constanten),constanten.imag());
    }

    // TESTING ADDITION
    void testAddition() {
      TS_ASSERT_EQUALS(onlyReal+onlyImag, Complex(5.3,-6.5));
      TS_ASSERT_EQUALS(onlyImag+2_i, Complex(0,-4.5));
      TS_ASSERT_EQUALS(onlyReal+onlyImag+3, Complex(8.3,-6.5));
      TS_ASSERT_EQUALS(0+0, Complex(0,0));
      TS_ASSERT_EQUALS(onlyReal+=onlyReal, Complex(10.6,0));
    }

    // TESTING SUBTRACTION
    void testSubtraction() {
      TS_ASSERT_EQUALS(onlyReal-onlyImag, Complex(10.6,6.5));
      TS_ASSERT_EQUALS(1-onlyImag, Complex(1,6.5));
      TS_ASSERT_EQUALS(4-5_i, Complex(4,-5));
      TS_ASSERT_EQUALS(onlyReal-=Complex(5.3,0), Complex(5.3,0)); //RETURN TO ORIGINAL ONLYREAL
    }

    // TESTING MULTIPLICATION
    void testMultiplication() {
      TS_ASSERT_EQUALS(combinedNumber*0, Complex(0,0));
      TS_ASSERT_DELTA(abs(combinedNumber*onlyImag), 33.7124,1e-3);
      TS_ASSERT_EQUALS(combinedNumber/combinedNumber, Complex(1,0));
    }

    // TESTING DIVISION
    void testDivision() {
      TS_ASSERT_EQUALS(onlyImag/6.5,Complex(0,-1));
      TS_ASSERT_EQUALS(0/combinedNumber,Complex(0,0));
      TS_ASSERT_DELTA(abs(2_i/combinedNumber), 0.385615,1e-5);
    }

    // TESTING MIXED OPERATIONS
    void testMixedOperators() {
      TS_ASSERT_EQUALS(5_i+4+2-3,Complex(3,5));
      TS_ASSERT_EQUALS(10/2-2_i,Complex(5,-2));
      TS_ASSERT_EQUALS(5+1_i+combinedNumber, Complex(9.3,-1.9));
    }

    void testBoolean() {
      TS_ASSERT_EQUALS(onlyReal==onlyImag,false);
      TS_ASSERT_EQUALS(onlyReal==5.3,true);
      TS_ASSERT_EQUALS(onlyImag==5_i,false);
      TS_ASSERT_EQUALS(0_i!=onlyReal,true);
      TS_ASSERT_EQUALS(onlyReal!=onlyReal,false);
      TS_ASSERT_EQUALS(zeroNumb==0, true)
    }
};


/*
// OPERATORS

constexpr Complex operator""_i(long double a);



// HOW TO GET CXXTEST TO WORK:
// 1. Write the test complex file "TEST FILE".h
// 2. cxxtestgen --error-printer -o "GENERATED TEST".cpp "TEST FILE".h
// 3. g++ -std=c++11 "NAME ON RUNNER FILE".out "GENERATED TEST".cpp
// 4. Run ./"NAME ON RUNNER FILE"

*/
