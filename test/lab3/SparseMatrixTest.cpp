#include <iostream>
#include <cassert>
#include "SparseMatrixTest.h"
#include "../../abstract_data_type/SparseMatrix.h"
#include "../../auxiliary_types/Complex.h"
#define EPSILON 1e-6


void TestSparseMatrixCreation()
{
    std::cout << "Sparse matrix creation tests:\n";
    //---SparseMatrix<double> creation---
    {
        {
            SparseMatrix<double> sm1(3, 3);
            sm1.SetElement(1, 1, 1.0);
            sm1.SetElement(1, 2, 2.0);
            sm1.SetElement(2, 1, 3.0);
            assert(std::fabs(sm1.GetElement(1, 1) - 1.0) < EPSILON);
            assert(std::fabs(sm1.GetElement(1, 2) - 2.0) < EPSILON);
            assert(std::fabs(sm1.GetElement(2, 1) - 3.0) < EPSILON);
            assert(std::fabs(sm1.GetElement(3, 3)) < EPSILON);
        }
        {
            SparseMatrix<double> sm2(4, 4);
            sm2.SetElement(2, 1, 5.5);
            sm2.SetElement(1, 2, 6.5);
            sm2.SetElement(2, 2, 7.5);
            sm2.SetElement(3, 3, 8.5);
            assert(std::fabs(sm2.GetElement(2, 1) - 5.5) < EPSILON);
            assert(std::fabs(sm2.GetElement(1, 2) - 6.5) < EPSILON);
            assert(std::fabs(sm2.GetElement(2, 2) - 7.5) < EPSILON);
            assert(std::fabs(sm2.GetElement(3, 3) - 8.5) < EPSILON);
            assert(std::fabs(sm2.GetElement(2, 3)) < EPSILON);
        }
        {
            SparseMatrix<double> sm3(2, 2);
            sm3.SetElement(2, 2, 1.1);
            sm3.SetElement(2, 1, 2.2);
            sm3.SetElement(1, 2, 3.3);
            sm3.SetElement(1, 1, 4.4);
            assert(std::fabs(sm3.GetElement(2, 2) - 1.1) < EPSILON);
            assert(std::fabs(sm3.GetElement(2, 1) - 2.2) < EPSILON);
            assert(std::fabs(sm3.GetElement(1, 2) - 3.3) < EPSILON);
            assert(std::fabs(sm3.GetElement(1, 1) - 4.4) < EPSILON);
        }
        {
            SparseMatrix<double> sm4(5, 5);
            sm4.SetElement(2, 2, 10.0);
            sm4.SetElement(3, 3, 20.0);
            sm4.SetElement(4, 4, 30.0);
            assert(std::fabs(sm4.GetElement(2, 2) - 10.0) < EPSILON);
            assert(std::fabs(sm4.GetElement(3, 3) - 20.0) < EPSILON);
            assert(std::fabs(sm4.GetElement(4, 4) - 30.0) < EPSILON);
            assert(std::fabs(sm4.GetElement(1, 1)) < EPSILON);
            assert(std::fabs(sm4.GetElement(5, 5)) < EPSILON);
        }
        {
            SparseMatrix<double> sm5(3, 3);
            sm5.SetElement(1, 1, 100.0);
            sm5.SetElement(2, 2, 200.0);
            assert(std::fabs(sm5.GetElement(1, 1) - 100.0) < EPSILON);
            assert(std::fabs(sm5.GetElement(2, 2) - 200.0) < EPSILON);
            assert(std::fabs(sm5.GetElement(1, 2)) < EPSILON);
            assert(std::fabs(sm5.GetElement(2, 1)) < EPSILON);
            assert(std::fabs(sm5.GetElement(3, 3)) < EPSILON);
        }
    }
    std::cout << "Test 1 passed: SparseMatrix<double> created and elements set successfully\n";
    //---SparseMatrix<Complex<int>> creation---
    {
        {
            SparseMatrix<Complex<double>> sm1(3, 3);
            sm1.SetElement(3, 3, Complex<double>(1.0, 1.0));
            sm1.SetElement(3, 1, Complex<double>(2.0, 2.0));
            sm1.SetElement(1, 3, Complex<double>(3.0, 3.0));
            assert(std::fabs(sm1.GetElement(3, 3).real - 1.0) < EPSILON &&
            std::fabs(sm1.GetElement(3, 3).imaginary - 1.0) < EPSILON);
            assert(std::fabs(sm1.GetElement(3, 1).real - 2.0) < EPSILON &&
            std::fabs(sm1.GetElement(3, 1).imaginary - 2.0) < EPSILON);
            assert(std::fabs(sm1.GetElement(1, 3).real - 3.0) < EPSILON &&
            std::fabs(sm1.GetElement(1, 3).imaginary - 3.0) < EPSILON);
            assert(std::fabs(sm1.GetElement(2, 2).real) < EPSILON &&
            std::fabs(sm1.GetElement(2, 2).imaginary) < EPSILON);
        }
        {
            SparseMatrix<Complex<double>> sm2(4, 4);
            sm2.SetElement(4, 4, Complex<double>(4.5, 1.0));
            sm2.SetElement(3, 1, Complex<double>(5.5, 2.0));
            sm2.SetElement(1, 3, Complex<double>(6.5, 3.0));
            sm2.SetElement(2, 2, Complex<double>(7.5, 4.0));
            sm2.SetElement(3, 3, Complex<double>(8.5, 5.0));
            assert(std::fabs(sm2.GetElement(4, 4).real - 4.5) < EPSILON &&
            std::fabs(sm2.GetElement(4, 4).imaginary - 1.0) < EPSILON);
            assert(std::fabs(sm2.GetElement(3, 1).real - 5.5) < EPSILON &&
            std::fabs(sm2.GetElement(3, 1).imaginary - 2.0) < EPSILON);
            assert(std::fabs(sm2.GetElement(1, 3).real - 6.5) < EPSILON &&
            std::fabs(sm2.GetElement(1, 3).imaginary - 3.0) < EPSILON);
            assert(std::fabs(sm2.GetElement(2, 2).real - 7.5) < EPSILON &&
            std::fabs(sm2.GetElement(2, 2).imaginary - 4.0) < EPSILON);
            assert(std::fabs(sm2.GetElement(3, 3).real - 8.5) < EPSILON &&
            std::fabs(sm2.GetElement(3, 3).imaginary - 5.0) < EPSILON);
            assert(std::fabs(sm2.GetElement(2, 3).real) < EPSILON &&
            std::fabs(sm2.GetElement(2, 3).imaginary) < EPSILON);
        }
        {
            SparseMatrix<Complex<double>> sm3(2, 2);
            sm3.SetElement(2, 2, Complex<double>(1.1, 0.5));
            sm3.SetElement(2, 1, Complex<double>(2.2, 1.5));
            sm3.SetElement(1, 2, Complex<double>(3.3, 2.5));
            sm3.SetElement(1, 1, Complex<double>(4.4, 3.5));
            assert(std::fabs(sm3.GetElement(2, 2).real - 1.1) < EPSILON &&
            std::fabs(sm3.GetElement(2, 2).imaginary - 0.5) < EPSILON);
            assert(std::fabs(sm3.GetElement(2, 1).real - 2.2) < EPSILON &&
            std::fabs(sm3.GetElement(2, 1).imaginary - 1.5) < EPSILON);
            assert(std::fabs(sm3.GetElement(1, 2).real - 3.3) < EPSILON &&
            std::fabs(sm3.GetElement(1, 2).imaginary - 2.5) < EPSILON);
            assert(std::fabs(sm3.GetElement(1, 1).real - 4.4) < EPSILON &&
            std::fabs(sm3.GetElement(1, 1).imaginary - 3.5) < EPSILON);
        }
        {
            SparseMatrix<Complex<double>> sm4(3, 3);
            sm4.SetElement(1, 1, Complex<double>(10.0, 1.0));
            sm4.SetElement(2, 2, Complex<double>(20.0, 2.0));
            assert(std::fabs(sm4.GetElement(1, 1).real - 10.0) < EPSILON &&
            std::fabs(sm4.GetElement(1, 1).imaginary - 1.0) < EPSILON);
            assert(std::fabs(sm4.GetElement(2, 2).real - 20.0) < EPSILON &&
            std::fabs(sm4.GetElement(2, 2).imaginary - 2.0) < EPSILON);
            assert(std::fabs(sm4.GetElement(1, 2).real) < EPSILON &&
            std::fabs(sm4.GetElement(1, 2).imaginary) < EPSILON);
            assert(std::fabs(sm4.GetElement(2, 1).real) < EPSILON &&
            std::fabs(sm4.GetElement(2, 1).imaginary) < EPSILON);
        }
        {
            SparseMatrix<Complex<double>> sm5(2, 2);
            sm5.SetElement(2, 2, Complex<double>(-1.0, -1.0));
            sm5.SetElement(2, 1, Complex<double>(-2.0, -2.0));
            sm5.SetElement(1, 2, Complex<double>(-3.0, -3.0));
            sm5.SetElement(1, 1, Complex<double>(-4.0, -4.0));
            assert(std::fabs(sm5.GetElement(2, 2).real + 1.0) < EPSILON &&
            std::fabs(sm5.GetElement(2, 2).imaginary + 1.0) < EPSILON);
            assert(std::fabs(sm5.GetElement(2, 1).real + 2.0) < EPSILON &&
            std::fabs(sm5.GetElement(2, 1).imaginary + 2.0) < EPSILON);
            assert(std::fabs(sm5.GetElement(1, 2).real + 3.0) < EPSILON &&
            std::fabs(sm5.GetElement(1, 2).imaginary + 3.0) < EPSILON);
            assert(std::fabs(sm5.GetElement(1, 1).real + 4.0) < EPSILON &&
            std::fabs(sm5.GetElement(1, 1).imaginary + 4.0) < EPSILON);
        }
    }
    std::cout << "Test 2 passed: SparseMatrix<Complex<int>> created and elements set successfully\n";
}

void TestSparseMatrixAddition()
{
    std::cout << "Sparse matrix addition tests:\n";
    //---SparseMatrix<double> addition tests---
    {
        {
            SparseMatrix<double> sm1(3, 3);
            sm1.SetElement(3, 3, 1.0);
            sm1.SetElement(3, 1, 2.0);
            sm1.SetElement(1, 3, 3.0);
            SparseMatrix<double> sm2(3, 3);
            sm2.SetElement(3, 3, 4.0);
            sm2.SetElement(1, 1, 5.0);
            sm2.SetElement(2, 2, 6.0);
            SparseMatrix<double> result = sm1 + sm2;
            assert(std::fabs(result.GetElement(3, 3) - 5.0) < EPSILON);
            assert(std::fabs(result.GetElement(3, 1) - 2.0) < EPSILON);
            assert(std::fabs(result.GetElement(1, 3) - 3.0) < EPSILON);
            assert(std::fabs(result.GetElement(1, 1) - 5.0) < EPSILON);
            assert(std::fabs(result.GetElement(2, 2) - 6.0) < EPSILON);
            assert(std::fabs(result.GetElement(2, 3)) < EPSILON);
        }
        {
            SparseMatrix<double> sm1(2, 2);
            sm1.SetElement(2, 2, 1.5);
            sm1.SetElement(1, 1, 2.5);
            SparseMatrix<double> sm2(2, 2);
            sm2.SetElement(2, 2, 3.5);
            sm2.SetElement(1, 2, 4.5);
            SparseMatrix<double> result = sm1 + sm2;
            assert(std::fabs(result.GetElement(2, 2) - 5.0) < EPSILON);
            assert(std::fabs(result.GetElement(1, 1) - 2.5) < EPSILON);
            assert(std::fabs(result.GetElement(1, 2) - 4.5) < EPSILON);
            assert(std::fabs(result.GetElement(2, 1)) < EPSILON);
        }
        {
            SparseMatrix<double> sm1(3, 3);
            sm1.SetElement(3, 3, 0.1);
            sm1.SetElement(1, 1, 0.2);
            sm1.SetElement(2, 2, 0.3);
            SparseMatrix<double> sm2(3, 3);
            sm2.SetElement(3, 3, 0.9);
            sm2.SetElement(1, 1, 0.8);
            sm2.SetElement(2, 2, 0.7);
            SparseMatrix<double> result = sm1 + sm2;
            assert(std::fabs(result.GetElement(3, 3) - 1.0) < EPSILON);
            assert(std::fabs(result.GetElement(1, 1) - 1.0) < EPSILON);
            assert(std::fabs(result.GetElement(2, 2) - 1.0) < EPSILON);
            assert(std::fabs(result.GetElement(2, 1)) < EPSILON);
        }
        {
            SparseMatrix<double> sm1(4, 4);
            sm1.SetElement(3, 3, 1.1);
            sm1.SetElement(1, 1, 2.2);
            SparseMatrix<double> sm2(4, 4);
            sm2.SetElement(2, 2, 3.3);
            sm2.SetElement(4, 4, 4.4);
            SparseMatrix<double> result = sm1 + sm2;
            assert(std::fabs(result.GetElement(3, 3) - 1.1) < EPSILON);
            assert(std::fabs(result.GetElement(1, 1) - 2.2) < EPSILON);
            assert(std::fabs(result.GetElement(2, 2) - 3.3) < EPSILON);
            assert(std::fabs(result.GetElement(4, 4) - 4.4) < EPSILON);
            assert(std::fabs(result.GetElement(2, 1)) < EPSILON);
        }
        {
            SparseMatrix<double> sm1(3, 3);
            sm1.SetElement(3, 3, 1.0);
            sm1.SetElement(1, 1, 2.0);
            sm1.SetElement(2, 2, 3.0);
            SparseMatrix<double> sm2(3, 3);
            sm2.SetElement(3, 3, -1.0);
            sm2.SetElement(1, 1, -2.0);
            sm2.SetElement(2, 2, -3.0);
            SparseMatrix<double> result = sm1 + sm2;
            assert(std::fabs(result.GetElement(2, 1)) < EPSILON);
            assert(std::fabs(result.GetElement(1, 1)) < EPSILON);
            assert(std::fabs(result.GetElement(2, 2)) < EPSILON);
            assert(std::fabs(result.GetElement(1, 2)) < EPSILON);
        }
    }
    std::cout << "Test 1 passed: SparseMatrix<double> addition works correctly\n";
    //---SparseMatrix<Complex<double>> addition tests---
    {
        {
            SparseMatrix<Complex<double>> sm1(3, 3);
            sm1.SetElement(3, 3, Complex<double>(1.0, 1.0));
            sm1.SetElement(3, 1, Complex<double>(2.0, 2.0));
            sm1.SetElement(1, 3, Complex<double>(3.0, 3.0));
            SparseMatrix<Complex<double>> sm2(3, 3);
            sm2.SetElement(3, 3, Complex<double>(4.0, 4.0));
            sm2.SetElement(1, 1, Complex<double>(5.0, 5.0));
            sm2.SetElement(2, 2, Complex<double>(6.0, 6.0));
            SparseMatrix<Complex<double>> result = sm1 + sm2;
            assert(std::fabs(result.GetElement(3, 3).real - 5.0) < EPSILON &&
            std::fabs(result.GetElement(3, 3).imaginary - 5.0) < EPSILON);
            assert(std::fabs(result.GetElement(3, 1).real - 2.0) < EPSILON &&
            std::fabs(result.GetElement(3, 1).imaginary - 2.0) < EPSILON);
            assert(std::fabs(result.GetElement(1, 3).real - 3.0) < EPSILON &&
            std::fabs(result.GetElement(1, 3).imaginary - 3.0) < EPSILON);
            assert(std::fabs(result.GetElement(1, 1).real - 5.0) < EPSILON &&
            std::fabs(result.GetElement(1, 1).imaginary - 5.0) < EPSILON);
            assert(std::fabs(result.GetElement(2, 2).real - 6.0) < EPSILON &&
            std::fabs(result.GetElement(2, 2).imaginary - 6.0) < EPSILON);
            assert(std::fabs(result.GetElement(2, 3).real) < EPSILON &&
            std::fabs(result.GetElement(2, 3).imaginary) < EPSILON);
        }
        {
            SparseMatrix<Complex<double>> sm1(2, 2);
            sm1.SetElement(2, 2, Complex<double>(1.5, 1.5));
            sm1.SetElement(1, 1, Complex<double>(2.5, 2.5));
            SparseMatrix<Complex<double>> sm2(2, 2);
            sm2.SetElement(2, 2, Complex<double>(3.5, 3.5));
            sm2.SetElement(1, 2, Complex<double>(4.5, 4.5));
            SparseMatrix<Complex<double>> result = sm1 + sm2;
            assert(std::fabs(result.GetElement(2, 2).real - 5.0) < EPSILON &&
            std::fabs(result.GetElement(2, 2).imaginary - 5.0) < EPSILON);
            assert(std::fabs(result.GetElement(1, 1).real - 2.5) < EPSILON &&
            std::fabs(result.GetElement(1, 1).imaginary - 2.5) < EPSILON);
            assert(std::fabs(result.GetElement(1, 2).real - 4.5) < EPSILON &&
            std::fabs(result.GetElement(1, 2).imaginary - 4.5) < EPSILON);
            assert(std::fabs(result.GetElement(2, 1).real) < EPSILON &&
            std::fabs(result.GetElement(2, 1).imaginary) < EPSILON);
        }
        {
            SparseMatrix<Complex<double>> sm1(3, 3);
            sm1.SetElement(3, 3, Complex<double>(0.1, 0.1));
            sm1.SetElement(1, 1, Complex<double>(0.2, 0.2));
            sm1.SetElement(2, 2, Complex<double>(0.3, 0.3));
            SparseMatrix<Complex<double>> sm2(3, 3);
            sm2.SetElement(3, 3, Complex<double>(0.9, 0.9));
            sm2.SetElement(1, 1, Complex<double>(0.8, 0.8));
            sm2.SetElement(2, 2, Complex<double>(0.7, 0.7));
            SparseMatrix<Complex<double>> result = sm1 + sm2;
            assert(std::fabs(result.GetElement(3, 3).real - 1.0) < EPSILON &&
            std::fabs(result.GetElement(3, 3).imaginary - 1.0) < EPSILON);
            assert(std::fabs(result.GetElement(1, 1).real - 1.0) < EPSILON &&
            std::fabs(result.GetElement(1, 1).imaginary - 1.0) < EPSILON);
            assert(std::fabs(result.GetElement(2, 2).real - 1.0) < EPSILON &&
            std::fabs(result.GetElement(2, 2).imaginary - 1.0) < EPSILON);
            assert(std::fabs(result.GetElement(3, 1).real) < EPSILON &&
            std::fabs(result.GetElement(2, 1).imaginary) < EPSILON);
        }
        {
            SparseMatrix<Complex<double>> sm1(4, 4);
            sm1.SetElement(4, 4, Complex<double>(1.1, 1.1));
            sm1.SetElement(1, 1, Complex<double>(2.2, 2.2));
            SparseMatrix<Complex<double>> sm2(4, 4);
            sm2.SetElement(2, 2, Complex<double>(3.3, 3.3));
            sm2.SetElement(3, 3, Complex<double>(4.4, 4.4));
            SparseMatrix<Complex<double>> result = sm1 + sm2;
            assert(std::fabs(result.GetElement(4, 4).real - 1.1) < EPSILON &&
            std::fabs(result.GetElement(4, 4).imaginary - 1.1) < EPSILON);
            assert(std::fabs(result.GetElement(1, 1).real - 2.2) < EPSILON &&
            std::fabs(result.GetElement(1, 1).imaginary - 2.2) < EPSILON);
            assert(std::fabs(result.GetElement(2, 2).real - 3.3) < EPSILON &&
            std::fabs(result.GetElement(2, 2).imaginary - 3.3) < EPSILON);
            assert(std::fabs(result.GetElement(3, 3).real - 4.4) < EPSILON &&
            std::fabs(result.GetElement(3, 3).imaginary - 4.4) < EPSILON);
            assert(std::fabs(result.GetElement(4, 1).real) < EPSILON &&
            std::fabs(result.GetElement(4, 1).imaginary) < EPSILON);
        }
        {
            SparseMatrix<Complex<double>> sm1(3, 3);
            sm1.SetElement(3, 3, Complex<double>(1.0, 1.0));
            sm1.SetElement(1, 1, Complex<double>(2.0, 2.0));
            sm1.SetElement(2, 2, Complex<double>(3.0, 3.0));
            SparseMatrix<Complex<double>> sm2(3, 3);
            sm2.SetElement(3, 3, Complex<double>(-1.0, -1.0));
            sm2.SetElement(1, 1, Complex<double>(-2.0, -2.0));
            sm2.SetElement(2, 2, Complex<double>(-3.0, -3.0));
            SparseMatrix<Complex<double>> result = sm1 + sm2;
            assert(std::fabs(result.GetElement(3, 3).real) < EPSILON &&
            std::fabs(result.GetElement(3, 3).imaginary) < EPSILON);
            assert(std::fabs(result.GetElement(1, 1).real) < EPSILON &&
            std::fabs(result.GetElement(1, 1).imaginary) < EPSILON);
            assert(std::fabs(result.GetElement(2, 2).real) < EPSILON &&
            std::fabs(result.GetElement(2, 2).imaginary) < EPSILON);
            assert(std::fabs(result.GetElement(3, 1).real) < EPSILON &&
            std::fabs(result.GetElement(3, 1).imaginary) < EPSILON);
        }
    }
    std::cout << "Test 2 passed: SparseMatrix<Complex<double>> addition works correctly\n";
}

void TestSparseMatrixMultiplication()
{
    std::cout << "Sparse matrix multiplication tests:\n";
    //---SparseMatrix<long> multiplication tests---
    {
        {
            SparseMatrix<long> sm1(3, 3);
            sm1.SetElement(3, 3, 1);
            sm1.SetElement(3, 1, 2);
            sm1.SetElement(1, 3, 3);
            SparseMatrix<long> sm2(3, 3);
            sm2.SetElement(3, 3, 4);
            sm2.SetElement(1, 1, 5);
            sm2.SetElement(2, 2, 6);
            SparseMatrix<long> result = sm1 * sm2;
            assert(result.GetElement(3, 3) == 4);
            assert(result.GetElement(3, 1) == 10);
            assert(result.GetElement(1, 3) == 12);
            assert(result.GetElement(1, 1) == 0);
            assert(result.GetElement(2, 2) == 0);
        }
        {
            SparseMatrix<long> sm1(2, 2);
            sm1.SetElement(2, 2, 1);
            sm1.SetElement(1, 1, 2);
            SparseMatrix<long> sm2(2, 2);
            sm2.SetElement(2, 2, 3);
            sm2.SetElement(1, 2, 4);
            SparseMatrix<long> result = sm1 * sm2;
            assert(result.GetElement(2, 2) == 3);
            assert(result.GetElement(1, 2) == 8);
            assert(result.GetElement(2, 1) == 0);
            assert(result.GetElement(1, 1) == 0);
        }
        {
            SparseMatrix<long> sm1(3, 3);
            sm1.SetElement(3, 3, 0);
            sm1.SetElement(1, 1, 0);
            sm1.SetElement(2, 2, 0);
            SparseMatrix<long> sm2(3, 3);
            sm2.SetElement(3, 3, 1);
            sm2.SetElement(1, 1, 1);
            sm2.SetElement(2, 2, 1);
            SparseMatrix<long> result = sm1 * sm2;
            assert(result.GetElement(3, 3) == 0);
            assert(result.GetElement(1, 1) == 0);
            assert(result.GetElement(2, 2) == 0);
        }
        {
            SparseMatrix<long> sm1(4, 4);
            sm1.SetElement(4, 4, 1);
            sm1.SetElement(1, 1, 2);
            SparseMatrix<long> sm2(4, 4);
            sm2.SetElement(2, 2, 3);
            sm2.SetElement(3, 3, 4);
            SparseMatrix<long> result = sm1 * sm2;
            assert(result.GetElement(4, 4) == 0);
            assert(result.GetElement(1, 1) == 0);
            assert(result.GetElement(2, 2) == 0);
            assert(result.GetElement(3, 3) == 0);
        }
        {
            SparseMatrix<long> sm1(3, 3);
            sm1.SetElement(3, 3, 1);
            sm1.SetElement(1, 1, 2);
            sm1.SetElement(2, 2, 3);
            SparseMatrix<long> sm2(3, 3);
            sm2.SetElement(3, 3, 1);
            sm2.SetElement(1, 1, 1);
            sm2.SetElement(2, 2, 1);
            SparseMatrix<long> result = sm1 * sm2;
            assert(result.GetElement(3, 3) == 1);
            assert(result.GetElement(1, 1) == 2);
            assert(result.GetElement(2, 2) == 3);
        }
    }
    std::cout << "Test 1 passed: SparseMatrix<long> multiplication works correctly\n";
    //---SparseMatrix<Complex<long>> multiplication tests---
    {
        {
            SparseMatrix<Complex<long>> sm1(3, 3);
            sm1.SetElement(3, 3, Complex<long>(1, 1));
            sm1.SetElement(3, 1, Complex<long>(2, 2));
            sm1.SetElement(1, 3, Complex<long>(3, 3));
            SparseMatrix<Complex<long>> sm2(3, 3);
            sm2.SetElement(3, 3, Complex<long>(4, 4));
            sm2.SetElement(1, 1, Complex<long>(5, 5));
            sm2.SetElement(2, 2, Complex<long>(6, 6));
            SparseMatrix<Complex<long>> result = sm1 * sm2;
            assert(result.GetElement(3, 3).real == 0 && result.GetElement(3, 3).imaginary == 8);
            assert(result.GetElement(3, 1).real == 0 && result.GetElement(3, 1).imaginary == 20);
            assert(result.GetElement(1, 3).real == 0 && result.GetElement(1, 3).imaginary == 24);
            assert(result.GetElement(1, 1).real == 0 && result.GetElement(1, 1).imaginary == 0);
            assert(result.GetElement(2, 2).real == 0 && result.GetElement(2, 2).imaginary == 0);
        }
        {
            SparseMatrix<Complex<long>> sm1(2, 2);
            sm1.SetElement(2, 2, Complex<long>(1, 1));
            sm1.SetElement(1, 1, Complex<long>(2, 2));
            SparseMatrix<Complex<long>> sm2(2, 2);
            sm2.SetElement(2, 2, Complex<long>(3, 3));
            sm2.SetElement(1, 2, Complex<long>(4, 4));
            SparseMatrix<Complex<long>> result = sm1 * sm2;
            assert(result.GetElement(2, 2).real == 0 && result.GetElement(2, 2).imaginary == 6);
            assert(result.GetElement(1, 2).real == 0 && result.GetElement(1, 2).imaginary == 16);
            assert(result.GetElement(2, 1).real == 0 && result.GetElement(2, 1).imaginary == 0);
            assert(result.GetElement(1, 1).real == 0 && result.GetElement(1, 1).imaginary == 0);
        }
        {
            SparseMatrix<Complex<long>> sm1(3, 3);
            sm1.SetElement(3, 3, Complex<long>(0, 0));
            sm1.SetElement(1, 1, Complex<long>(0, 0));
            sm1.SetElement(2, 2, Complex<long>(0, 0));
            SparseMatrix<Complex<long>> sm2(3, 3);
            sm2.SetElement(3, 3, Complex<long>(1, 1));
            sm2.SetElement(1, 1, Complex<long>(1, 1));
            sm2.SetElement(2, 2, Complex<long>(1, 1));
            SparseMatrix<Complex<long>> result = sm1 * sm2;
            assert(result.GetElement(3, 3).real == 0 && result.GetElement(3, 3).imaginary == 0);
            assert(result.GetElement(1, 1).real == 0 && result.GetElement(1, 1).imaginary == 0);
            assert(result.GetElement(2, 2).real == 0 && result.GetElement(2, 2).imaginary == 0);
        }
        {
            SparseMatrix<Complex<long>> sm1(4, 4);
            sm1.SetElement(4, 4, Complex<long>(1, 1));
            sm1.SetElement(1, 1, Complex<long>(2, 2));
            SparseMatrix<Complex<long>> sm2(4, 4);
            sm2.SetElement(2, 2, Complex<long>(3, 3));
            sm2.SetElement(3, 3, Complex<long>(4, 4));
            SparseMatrix<Complex<long>> result = sm1 * sm2;
            assert(result.GetElement(4, 4).real == 0 && result.GetElement(4, 4).imaginary == 0);
            assert(result.GetElement(1, 1).real == 0 && result.GetElement(1, 1).imaginary == 0);
            assert(result.GetElement(2, 2).real == 0 && result.GetElement(2, 2).imaginary == 0);
            assert(result.GetElement(3, 3).real == 0 && result.GetElement(3, 3).imaginary == 0);
        }
        {
            SparseMatrix<Complex<long>> sm1(3, 3);
            sm1.SetElement(3, 3, Complex<long>(1, 1));
            sm1.SetElement(1, 1, Complex<long>(2, 2));
            sm1.SetElement(2, 2, Complex<long>(3, 3));
            SparseMatrix<Complex<long>> sm2(3, 3);
            sm2.SetElement(3, 3, Complex<long>(1, 1));
            sm2.SetElement(1, 1, Complex<long>(1, 1));
            sm2.SetElement(2, 2, Complex<long>(1, 1));
            SparseMatrix<Complex<long>> result = sm1 * sm2;
            assert(result.GetElement(3, 3).real == 0 && result.GetElement(3, 3).imaginary == 2);
            assert(result.GetElement(1, 1).real == 0 && result.GetElement(1, 1).imaginary == 4);
            assert(result.GetElement(2, 2).real == 0 && result.GetElement(2, 2).imaginary == 6);
        }
    }
    std::cout << "Test 2 passed: SparseMatrix<Complex<long>> multiplication works correctly\n";
}

void TestSparseMatrixScalarMultiplication()
{
    std::cout << "Sparse matrix scalar multiplication tests:\n";
    //---SparseMatrix<long> scalar multiplication tests---
    {
        {
            SparseMatrix<long> sm1(3, 3);
            sm1.SetElement(2, 2, 1);
            sm1.SetElement(2, 1, 2);
            sm1.SetElement(1, 2, 3);
            long scalar = 2;
            SparseMatrix<long> result = sm1 * scalar;
            assert(result.GetElement(2, 2) == 2);
            assert(result.GetElement(2, 1) == 4);
            assert(result.GetElement(1, 2) == 6);
            assert(result.GetElement(1, 1) == 0);
            assert(result.GetElement(3, 3) == 0);
        }
        {
            SparseMatrix<long> sm1(2, 2);
            sm1.SetElement(2, 2, 1);
            sm1.SetElement(1, 1, 2);
            long scalar = 3;
            SparseMatrix<long> result = sm1 * scalar;
            assert(result.GetElement(2, 2) == 3);
            assert(result.GetElement(1, 1) == 6);
            assert(result.GetElement(2, 1) == 0);
            assert(result.GetElement(1, 2) == 0);
        }
        {
            SparseMatrix<long> sm1(3, 3);
            sm1.SetElement(3, 3, 0);
            sm1.SetElement(1, 1, 0);
            sm1.SetElement(2, 2, 0);
            long scalar = 4;
            SparseMatrix<long> result = sm1 * scalar;
            assert(result.GetElement(3, 3) == 0);
            assert(result.GetElement(1, 1) == 0);
            assert(result.GetElement(2, 2) == 0);
        }
        {
            SparseMatrix<long> sm1(4, 4);
            sm1.SetElement(4, 4, 1);
            sm1.SetElement(1, 1, 2);
            long scalar = -1;
            SparseMatrix<long> result = sm1 * scalar;
            assert(result.GetElement(4, 4) == -1);
            assert(result.GetElement(1, 1) == -2);
            assert(result.GetElement(2, 2) == 0);
            assert(result.GetElement(3, 3) == 0);
        }
        {
            SparseMatrix<long> sm1(3, 3);
            sm1.SetElement(3, 3, 1);
            sm1.SetElement(1, 1, 2);
            sm1.SetElement(2, 2, 3);
            long scalar = 0;
            SparseMatrix<long> result = sm1 * scalar;
            assert(result.GetElement(3, 3) == 0);
            assert(result.GetElement(1, 1) == 0);
            assert(result.GetElement(2, 2) == 0);
        }
    }
    std::cout << "Test 1 passed: SparseMatrix<long> scalar multiplication works correctly\n";
    //---SparseMatrix<Complex<long>> scalar multiplication tests---
    {
        {
            SparseMatrix<Complex<long>> sm1(3, 3);
            sm1.SetElement(3, 3, Complex<long>(1, 1));
            sm1.SetElement(3, 1, Complex<long>(2, 2));
            sm1.SetElement(1, 3, Complex<long>(3, 3));
            Complex<long> scalar{2, 0};
            SparseMatrix<Complex<long>> result = sm1 * scalar;
            assert(result.GetElement(3, 3).real == 2 && result.GetElement(3, 3).imaginary == 2);
            assert(result.GetElement(3, 1).real == 4 && result.GetElement(3, 1).imaginary == 4);
            assert(result.GetElement(1, 3).real == 6 && result.GetElement(1, 3).imaginary == 6);
            assert(result.GetElement(1, 1).real == 0 && result.GetElement(1, 1).imaginary == 0);
            assert(result.GetElement(2, 2).real == 0 && result.GetElement(2, 2).imaginary == 0);
        }
        {
            SparseMatrix<Complex<long>> sm1(2, 2);
            sm1.SetElement(2, 2, Complex<long>(1, 1));
            sm1.SetElement(1, 1, Complex<long>(2, 2));
            Complex<long> scalar{3, 0};
            SparseMatrix<Complex<long>> result = sm1 * scalar;
            assert(result.GetElement(2, 2).real == 3 && result.GetElement(2, 2).imaginary == 3);
            assert(result.GetElement(1, 1).real == 6 && result.GetElement(1, 1).imaginary == 6);
            assert(result.GetElement(2, 1).real == 0 && result.GetElement(2, 1).imaginary == 0);
            assert(result.GetElement(1, 2).real == 0 && result.GetElement(1, 2).imaginary == 0);
        }
        {
            SparseMatrix<Complex<long>> sm1(3, 3);
            sm1.SetElement(3, 3, Complex<long>(0, 0));
            sm1.SetElement(1, 1, Complex<long>(0, 0));
            sm1.SetElement(2, 2, Complex<long>(0, 0));
            Complex<long> scalar{4, 0};
            SparseMatrix<Complex<long>> result = sm1 * scalar;
            assert(result.GetElement(3, 3).real == 0 && result.GetElement(3, 3).imaginary == 0);
            assert(result.GetElement(1, 1).real == 0 && result.GetElement(1, 1).imaginary == 0);
            assert(result.GetElement(2, 2).real == 0 && result.GetElement(2, 2).imaginary == 0);
        }
        {
            SparseMatrix<Complex<long>> sm1(4, 4);
            sm1.SetElement(4, 4, Complex<long>(1, 1));
            sm1.SetElement(1, 1, Complex<long>(2, 2));
            Complex<long> scalar{-1, 0};
            SparseMatrix<Complex<long>> result = sm1 * scalar;
            assert(result.GetElement(4, 4).real == -1 && result.GetElement(4, 4).imaginary == -1);
            assert(result.GetElement(1, 1).real == -2 && result.GetElement(1, 1).imaginary == -2);
            assert(result.GetElement(2, 2).real == 0 && result.GetElement(2, 2).imaginary == 0);
            assert(result.GetElement(3, 3).real == 0 && result.GetElement(3, 3).imaginary == 0);
        }
        {
            SparseMatrix<Complex<long>> sm1(3, 3);
            sm1.SetElement(3, 3, Complex<long>(1, 1));
            sm1.SetElement(1, 1, Complex<long>(2, 2));
            sm1.SetElement(2, 2, Complex<long>(3, 3));
            Complex<long> scalar{0, 0};
            SparseMatrix<Complex<long>> result = sm1 * scalar;
            assert(result.GetElement(3, 3).real == 0 && result.GetElement(3, 3).imaginary == 0);
            assert(result.GetElement(1, 1).real == 0 && result.GetElement(1, 1).imaginary == 0);
            assert(result.GetElement(2, 2).real == 0 && result.GetElement(2, 2).imaginary == 0);
        }
    }
    std::cout << "Test 2 passed: SparseMatrix<Complex<long>> scalar multiplication works correctly\n";
}

void TestSparseMatrixEuclideanNorm()
{
    std::cout << "Sparse matrix euclidean norm tests:\n";
    {
        SparseMatrix<double> sm(3, 3);
        sm.SetElement(3, 3, 1.0);
        sm.SetElement(3, 1, 2.0);
        sm.SetElement(1, 3, 3.0);
        double norm = sm.CalculateEuclideanNorm();
        assert(std::fabs(norm - std::sqrt(1.0 + 4.0 + 9.0)) < EPSILON);
    }
    {
        SparseMatrix<double> sm(2, 2);
        sm.SetElement(2, 2, 1.0);
        sm.SetElement(1, 1, 2.0);
        double norm = sm.CalculateEuclideanNorm();
        assert(std::fabs(norm - std::sqrt(1.0 + 4.0)) < EPSILON);
    }
    {
        SparseMatrix<double> sm(3, 3);
        sm.SetElement(3, 3, 0.0);
        sm.SetElement(1, 1, 0.0);
        sm.SetElement(2, 2, 0.0);
        double norm = sm.CalculateEuclideanNorm();
        assert(std::fabs(norm - 0.0) < EPSILON);
    }
    {
        SparseMatrix<double> sm(4, 4);
        sm.SetElement(4, 4, 1.0);
        sm.SetElement(1, 1, 2.0);
        sm.SetElement(2, 2, 3.0);
        sm.SetElement(3, 3, 4.0);
        double norm = sm.CalculateEuclideanNorm();
        assert(std::fabs(norm - std::sqrt(1.0 + 4.0 + 9.0 + 16.0)) < EPSILON);
    }
    {
        SparseMatrix<double> sm(3, 3);
        sm.SetElement(3, 3, -1.0);
        sm.SetElement(1, 1, -2.0);
        sm.SetElement(2, 2, -3.0);
        double norm = sm.CalculateEuclideanNorm();
        assert(std::fabs(norm - std::sqrt(1.0 + 4.0 + 9.0)) < EPSILON);
    }
    std::cout << "Test 1 passed: SparseMatrix<double> calculation of euclidean norm works correctly\n";
}

void AllSparseMatrixTest()
{
    TestSparseMatrixCreation();
    TestSparseMatrixAddition();
    TestSparseMatrixMultiplication();
    TestSparseMatrixScalarMultiplication();
    TestSparseMatrixEuclideanNorm();
}
