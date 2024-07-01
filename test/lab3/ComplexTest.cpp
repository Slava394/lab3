#include <iostream>
#include <cassert>
#include <cmath>
#include "ComplexTest.h"
#include "../../auxiliary_types/Complex.h"
#define EPSILON 1e-6


void TestComplexConstructors()
{
    std::cout << "Complex constructors tests:\n";
    //---Complex<int> constructors---
    {
        Complex<int> c1;
        assert(c1.real == 0 && c1.imaginary == 0);

        Complex<int> c2(3, 4);
        assert(c2.real == 3 && c2.imaginary == 4);

        Complex<int> c3(c2);
        assert(c3.real == 3 && c3.imaginary == 4);

        Complex<int> c4 = c2;
        assert(c4.real == 3 && c4.imaginary == 4);

        Complex<int> c5(-2, -5);
        assert(c5.real == -2 && c5.imaginary == -5);

        Complex<int> c6(1, 2);
        c6 += Complex<int>(3, 4);
        assert(c6.real == 4 && c6.imaginary == 6);

        Complex<int> c7(0, 0);
        c7 += Complex<int>(-1, -1);
        assert(c7.real == -1 && c7.imaginary == -1);
    }
    std::cout << "Test 1 passed: Complex<int> created successfully\n";
    //---Complex<long> constructors---
    {
        Complex<long> c1;
        assert(c1.real == 0 && c1.imaginary == 0);

        Complex<long> c2(1234567890L, -987654321L);
        assert(c2.real == 1234567890L && c2.imaginary == -987654321L);

        Complex<long> c3(c2);
        assert(c3.real == 1234567890L && c3.imaginary == -987654321L);

        Complex<long> c4 = c2;
        assert(c4.real == 1234567890L && c4.imaginary == -987654321L);

        Complex<long> c5(-9876543210L, 123456789L);
        assert(c5.real == -9876543210L && c5.imaginary == 123456789L);

        Complex<long> c6(1000000000L, 2000000000L);
        c6 += Complex<long>(-3000000000L, 4000000000L);
        assert(c6.real == -2000000000L && c6.imaginary == 6000000000L);

        Complex<long> c7(0L, 0L);
        c7 += Complex<long>(-1L, -1L);
        assert(c7.real == -1L && c7.imaginary == -1L);
    }
    std::cout << "Test 2 passed: Complex<long> created successfully\n";
    //---Complex<double> constructors---
    {
        Complex<double> c1;
        assert(c1.real == 0.0 && c1.imaginary == 0.0);

        Complex<double> c2(1.5, -2.5);
        assert(c2.real == 1.5 && c2.imaginary == -2.5);

        Complex<double> c3(c2);
        assert(c3.real == 1.5 && c3.imaginary == -2.5);

        Complex<double> c4 = c2;
        assert(c4.real == 1.5 && c4.imaginary == -2.5);

        Complex<double> c5(-3.75, 4.25);
        assert(c5.real == -3.75 && c5.imaginary == 4.25);

        Complex<double> c6(2.0, 3.0);
        c6 += Complex<double>(-1.0, 2.0);
        assert(c6.real == 1.0 && c6.imaginary == 5.0);

        Complex<double> c7(0.001, 0.002);
        c7 += Complex<double>(-0.003, -0.004);
        assert(c7.real == -0.002 && c7.imaginary == -0.002);
    }
    std::cout << "Test 3 passed: Complex<double> created successfully\n";
}

void TestComplexAddition()
{
    std::cout << "Complex addition tests:\n";
    //---Complex<int> addition---
    {
        Complex<int> c1(1, 2);
        Complex<int> c2(3, 4);
        Complex<int> result1 = c1 + c2;
        assert(result1.real == 4 && result1.imaginary == 6);

        Complex<int> c3(-5, -10);
        Complex<int> c4(5, 10);
        Complex<int> result2 = c3 + c4;
        assert(result2.real == 0 && result2.imaginary == 0);

        Complex<int> c5(0, 0);
        Complex<int> c6(0, 0);
        Complex<int> result3 = c5 + c6;
        assert(result3.real == 0 && result3.imaginary == 0);

        Complex<int> c7(123, 456);
        Complex<int> c8(-123, -456);
        Complex<int> result4 = c7 + c8;
        assert(result4.real == 0 && result4.imaginary == 0);

        Complex<int> c9(-999, 999);
        Complex<int> c10(999, -999);
        Complex<int> result5 = c9 + c10;
        assert(result5.real == 0 && result5.imaginary == 0);
    }
    std::cout << "Test 1 passed: Complex<int> addition works correctly\n";
    //---Complex<long> addition---
    {
        Complex<long> c1(1234567890, 9876543210);
        Complex<long> c2(-1234567890, -9876543210);
        Complex<long> result1 = c1 + c2;
        assert(result1.real == 0 && result1.imaginary == 0);

        Complex<long> c3(9876543210, -1234567890);
        Complex<long> c4(-9876543210, 1234567890);
        Complex<long> result2 = c3 + c4;
        assert(result2.real == 0 && result2.imaginary == 0);

        Complex<long> c5(1234567890, 9876543210);
        Complex<long> c6(0, 0);
        Complex<long> result3 = c5 + c6;
        assert(result3.real == 1234567890 && result3.imaginary == 9876543210);

        Complex<long> c7(0, 0);
        Complex<long> c8(1234567890, 9876543210);
        Complex<long> result4 = c7 + c8;
        assert(result4.real == 1234567890 && result4.imaginary == 9876543210);

        Complex<long> c9(9876543210, 1234567890);
        Complex<long> c10(-9876543210, -1234567890);
        Complex<long> result5 = c9 + c10;
        assert(result5.real == 0 && result5.imaginary == 0);
    }
    std::cout << "Test 2 passed: Complex<long> addition works correctly\n";
    //---Complex<double> addition---
    {
        Complex<double> c1(1.5, 2.5);
        Complex<double> c2(3.5, 4.5);
        Complex<double> result1 = c1 + c2;
        assert(fabs(result1.real - 5.0) < EPSILON && fabs(result1.imaginary - 7.0) < EPSILON);

        Complex<double> c3(-5.5, -10.5);
        Complex<double> c4(5.5, 10.5);
        Complex<double> result2 = c3 + c4;
        assert(fabs(result2.real) < EPSILON && fabs(result2.imaginary) < EPSILON);

        Complex<double> c5(0.0, 0.0);
        Complex<double> c6(0.0, 0.0);
        Complex<double> result3 = c5 + c6;
        assert(fabs(result3.real) < EPSILON && fabs(result3.imaginary) < EPSILON);

        Complex<double> c7(123.456, 456.789);
        Complex<double> c8(-123.456, -456.789);
        Complex<double> result4 = c7 + c8;
        assert(fabs(result4.real) < EPSILON && fabs(result4.imaginary) < EPSILON);

        Complex<double> c9(-999.999, 999.999);
        Complex<double> c10(999.999, -999.999);
        Complex<double> result5 = c9 + c10;
        assert(fabs(result5.real) < EPSILON && fabs(result5.imaginary) < EPSILON);
    }
    std::cout << "Test 3 passed: Complex<double> addition works correctly\n";
}

void TestComplexSubtraction()
{
    std::cout << "Complex subtraction tests:\n";
    //---Complex<int> subtraction---
    {
        Complex<int> c1(1, 2);
        Complex<int> c2(3, 4);
        Complex<int> result1 = c1 - c2;
        assert(result1.real == -2 && result1.imaginary == -2);

        Complex<int> c3(-5, -10);
        Complex<int> c4(5, 10);
        Complex<int> result2 = c3 - c4;
        assert(result2.real == -10 && result2.imaginary == -20);

        Complex<int> c5(0, 0);
        Complex<int> c6(0, 0);
        Complex<int> result3 = c5 - c6;
        assert(result3.real == 0 && result3.imaginary == 0);

        Complex<int> c7(123, 456);
        Complex<int> c8(-123, -456);
        Complex<int> result4 = c7 - c8;
        assert(result4.real == 246 && result4.imaginary == 912);

        Complex<int> c9(-999, 999);
        Complex<int> c10(999, -999);
        Complex<int> result5 = c9 - c10;
        assert(result5.real == -1998 && result5.imaginary == 1998);
    }
    std::cout << "Test 1 passed: Complex<int> subtraction works correctly\n";
    //---Complex<long> subtraction---
    {
        Complex<long> c1(1234567890, 9876543210);
        Complex<long> c2(1234567890, 9876543210);
        Complex<long> result1 = c1 - c2;
        assert(result1.real == 0 && result1.imaginary == 0);

        Complex<long> c3(9876543210, -1234567890);
        Complex<long> c4(-9876543210, 1234567890);
        Complex<long> result2 = c3 - c4;
        assert(result2.real == 19753086420 && result2.imaginary == -2469135780);

        Complex<long> c5(1234567890, 9876543210);
        Complex<long> c6(0, 0);
        Complex<long> result3 = c5 - c6;
        assert(result3.real == 1234567890 && result3.imaginary == 9876543210);

        Complex<long> c7(0, 0);
        Complex<long> c8(1234567890, 9876543210);
        Complex<long> result4 = c7 - c8;
        assert(result4.real == -1234567890 && result4.imaginary == -9876543210);

        Complex<long> c9(9876543210, 1234567890);
        Complex<long> c10(-9876543210, -1234567890);
        Complex<long> result5 = c9 - c10;
        assert(result5.real == 19753086420 && result5.imaginary == 2469135780);
    }
    std::cout << "Test 2 passed: Complex<long> subtraction works correctly\n";
    //---Complex<double> subtraction---
    {
        Complex<double> c1(1.5, 2.5);
        Complex<double> c2(3.5, 4.5);
        Complex<double> result1 = c1 - c2;
        assert(fabs(result1.real + 2.0) < EPSILON && fabs(result1.imaginary + 2.0) < EPSILON);

        Complex<double> c3(-5.5, -10.5);
        Complex<double> c4(5.5, 10.5);
        Complex<double> result2 = c3 - c4;
        assert(fabs(result2.real + 11.0) < EPSILON && fabs(result2.imaginary + 21.0) < EPSILON);

        Complex<double> c5(0.0, 0.0);
        Complex<double> c6(0.0, 0.0);
        Complex<double> result3 = c5 - c6;
        assert(fabs(result3.real) < EPSILON && fabs(result3.imaginary) < EPSILON);

        Complex<double> c7(123.456, 456.789);
        Complex<double> c8(-123.456, -456.789);
        Complex<double> result4 = c7 - c8;
        assert(fabs(result4.real - 246.912) < EPSILON && fabs(result4.imaginary - 913.578) < EPSILON);

        Complex<double> c9(-999.999, 999.999);
        Complex<double> c10(999.999, -999.999);
        Complex<double> result5 = c9 - c10;
        assert(fabs(result5.real + 1999.998) < EPSILON && fabs(result5.imaginary - 1999.998) < EPSILON);
    }
    std::cout << "Test 3 passed: Complex<double> subtraction works correctly\n";
}

void TestComplexMultiplication()
{
    std::cout << "Complex multiplication tests:\n";
    //---Complex<int> multiplication---
    {
        Complex<int> c1(1, 2);
        Complex<int> c2(3, 4);
        Complex<int> result1 = c1 * c2;
        assert(result1.real == -5 && result1.imaginary == 10);

        Complex<int> c3(-5, -10);
        Complex<int> c4(5, 10);
        Complex<int> result2 = c3 * c4;
        assert(result2.real == 75 && result2.imaginary == -100);

        Complex<int> c5(0, 0);
        Complex<int> c6(0, 0);
        Complex<int> result3 = c5 * c6;
        assert(result3.real == 0 && result3.imaginary == 0);

        Complex<int> c7(123, 456);
        Complex<int> c8(-123, -456);
        Complex<int> result4 = c7 * c8;
        assert(result4.real == 192807 && result4.imaginary == -112176);

        Complex<int> c9(-999, 999);
        Complex<int> c10(999, -999);
        Complex<int> result5 = c9 * c10;
        assert(result5.real == 0 && result5.imaginary == 1996002);
    }
    std::cout << "Test 1 passed: Complex<int> multiplication works correctly\n";
    //---Complex<long> multiplication---
    {
        Complex<long> c1(123, 678);
        Complex<long> c2(-987, -543);
        Complex<long> result1 = c1 * c2;
        assert(result1.real == 246753 && result1.imaginary == -735975);

        Complex<long> c3(678, -123);
        Complex<long> c4(-123, 678);
        Complex<long> result2 = c3 * c4;
        assert(result2.real == 0 && result2.imaginary == 474813);

        Complex<long> c5(100, 100);
        Complex<long> c6(200, 200);
        Complex<long> result3 = c5 * c6;
        assert(result3.real == 0 && result3.imaginary == 40000);

        Complex<long> c7(0, 0);
        Complex<long> c8(-123, 678);
        Complex<long> result4 = c7 * c8;
        assert(result4.real == 0 && result4.imaginary == 0);

        Complex<long> c9(-987, -123);
        Complex<long> c10(654, 789);
        Complex<long> result5 = c9 * c10;
        assert(result5.real == -548451 && result5.imaginary == -859185);
    }
    std::cout << "Test 2 passed: Complex<long> multiplication works correctly\n";
    //---Complex<double> multiplication---
    {
        Complex<double> c1(1.5, 2.5);
        Complex<double> c2(3.5, 4.5);
        Complex<double> result1 = c1 * c2;
        assert(fabs(result1.real + 6.0) < EPSILON && fabs(result1.imaginary - 15.5) < EPSILON);

        Complex<double> c3(-5.5, -10.5);
        Complex<double> c4(5.5, 10.5);
        Complex<double> result2 = c3 * c4;
        assert(fabs(result2.real - 80) < EPSILON && fabs(result2.imaginary + 115.5) < EPSILON);

        Complex<double> c5(0.0, 0.0);
        Complex<double> c6(0.0, 0.0);
        Complex<double> result3 = c5 * c6;
        assert(fabs(result3.real) < EPSILON && fabs(result3.imaginary) < EPSILON);

        Complex<double> c7(123.456, 456.789);
        Complex<double> c8(-123.456, -456.789);
        Complex<double> result4 = c7 * c8;
        assert(fabs(result4.real - 193414.806585) < EPSILON && fabs(result4.imaginary + 112786.685568) < EPSILON);

        Complex<double> c9(-999.999, 999.999);
        Complex<double> c10(999.999, -999.999);
        Complex<double> result5 = c9 * c10;
        assert(fabs(result5.real) < EPSILON && fabs(result5.imaginary - 1999996.000002) < EPSILON);
    }
    std::cout << "Test 3 passed: Complex<double> multiplication works correctly\n";
}

void TestComplexDivision()
{
    std::cout << "Complex division tests:\n";
    //---Complex<int> division---
    {
        Complex<int> c1(1, 2);
        Complex<int> c2(3, 4);
        Complex<int> result1 = c1 / c2;
        assert(result1.real == 0 && result1.imaginary == 0);

        Complex<int> c3(-5, -10);
        Complex<int> c4(5, 10);
        Complex<int> result2 = c3 / c4;
        assert(result2.real == -1 && result2.imaginary == 0);

        Complex<int> c5(0, 0);
        Complex<int> c6(0, 1);
        Complex<int> result3 = c5 / c6;
        assert(result3.real == 0 && result3.imaginary == 0);

        Complex<int> c7(123, 456);
        Complex<int> c8(-123, -456);
        Complex<int> result4 = c7 / c8;
        assert(result4.real == -1 && result4.imaginary == 0);

        Complex<int> c9(-999, 999);
        Complex<int> c10(999, -999);
        Complex<int> result5 = c9 / c10;
        assert(result5.real == -1 && result5.imaginary == 0);
    }
    std::cout << "Test 1 passed: Complex<int> division works correctly\n";
    //---Complex<long> division---
    {
        Complex<long> c1(123, 678);
        Complex<long> c2(-987, -543);
        Complex<long> result1 = c1 / c2;
        assert(result1.real == 0 && result1.imaginary == 0);

        Complex<long> c3(678, -123);
        Complex<long> c4(-123, 678);
        Complex<long> result2 = c3 / c4;
        assert(result2.real == 0 && result2.imaginary == 0);

        Complex<long> c5(100, 100);
        Complex<long> c6(200, 200);
        Complex<long> result3 = c5 / c6;
        assert(result3.real == 0 && result3.imaginary == 0);

        Complex<long> c7(0, 0);
        Complex<long> c8(-123, 678);
        Complex<long> result4 = c7 / c8;
        assert(result4.real == 0 && result4.imaginary == 0);

        Complex<long> c9(-987, -123);
        Complex<long> c10(654, 789);
        Complex<long> result5 = c9 / c10;
        assert(result5.real == 0 && result5.imaginary == 0);
    }
    std::cout << "Test 2 passed: Complex<long> division works correctly\n";
    //---Complex<double> division---
    {
        Complex<double> c1(1.5, 2.5);
        Complex<double> c2(3.5, 4.5);
        Complex<double> result1 = c1 / c2;
        assert(fabs(result1.real - 0.507692) < EPSILON && fabs(result1.imaginary - 0.0615385) < EPSILON);

        Complex<double> c3(-5.5, -10.5);
        Complex<double> c4(5.5, 10.5);
        Complex<double> result2 = c3 / c4;
        assert(fabs(result2.real + 1) < EPSILON && fabs(result2.imaginary) < EPSILON);

        Complex<double> c5(0.0, 0.0);
        Complex<double> c6(0.0, 0.5);
        Complex<double> result3 = c5 / c6;
        assert(fabs(result3.real) < EPSILON && fabs(result3.imaginary) < EPSILON);

        Complex<double> c7(123.456, 456.789);
        Complex<double> c8(-123.456, -456.789);
        Complex<double> result4 = c7 / c8;
        assert(fabs(result4.real + 1) < EPSILON && fabs(result4.imaginary) < EPSILON);

        Complex<double> c9(-999.999, 999.999);
        Complex<double> c10(999.999, -999.999);
        Complex<double> result5 = c9 / c10;
        assert(fabs(result5.real + 1) < EPSILON && fabs(result5.imaginary) < EPSILON);
    }
    std::cout << "Test 3 passed: Complex<double> division works correctly\n";
}

void AllComplexTest()
{
    TestComplexConstructors();
    TestComplexAddition();
    TestComplexSubtraction();
    TestComplexMultiplication();
    TestComplexDivision();
}
