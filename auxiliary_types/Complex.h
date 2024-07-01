#pragma once
#include <stdexcept>

//P.S. some scalar type
template <class T>
class Complex
{
public:
    T real;
    T imaginary;
    //---Constructors---
    Complex() : real(T()), imaginary(T()) {}
    Complex(T real, T imaginary) : real(real), imaginary(imaginary) {}
    //---Destructor---
    ~Complex() = default;
    //---Operator overloading---
    Complex<T> operator+(const Complex<T>& otherComplex) const
    {
        return Complex<T>(real + otherComplex.real, imaginary + otherComplex.imaginary);
    }
    Complex<T> operator-(const Complex<T>& otherComplex) const
    {
        return Complex<T>(real - otherComplex.real, imaginary - otherComplex.imaginary);
    }
    Complex<T> operator*(const Complex<T>& otherComplex) const
    {
        return Complex<T>(real * otherComplex.real - imaginary * otherComplex.imaginary,
                          real * otherComplex.imaginary + imaginary * otherComplex.real);
    }
    Complex<T> operator/(const Complex<T>& otherComplex) const
    {
        T intermediateResult = otherComplex.real * otherComplex.real +
                             + otherComplex.imaginary * otherComplex.imaginary;
        if (intermediateResult == 0)
        {
            throw std::runtime_error("Error: Division by zero");
        }
        return Complex<T>((real * otherComplex.real + imaginary * otherComplex.imaginary) / intermediateResult,
                          (- (real * otherComplex.imaginary) + imaginary * otherComplex.real) / intermediateResult);
    }
    bool operator==(const Complex<T>& otherComplex) const
    {
        return real == otherComplex.real && imaginary == otherComplex.imaginary;
    }
    bool operator!=(const Complex<T>& otherComplex) const
    {
        return real != otherComplex.real || imaginary != otherComplex.imaginary;
    }
    Complex<T> operator-() const
    {
        return Complex<T>(-real, -imaginary);
    }
    Complex<T> operator+() const
    {
        return Complex<T>(*this);
    }
    Complex<T>& operator+=(const Complex<T>& otherComplex)
    {
        real += otherComplex.real;
        imaginary += otherComplex.imaginary;
        return *this;
    }
    //---Operator overloading (for scalar from real part only)---
    template <class ScalarType>
    Complex<T> operator+(const ScalarType& otherScalar) const
    {
        return Complex<T>(real + otherScalar, imaginary);
    }
    template <class ScalarType>
    Complex<T> operator-(const ScalarType& otherScalar) const
    {
        return Complex<T>(real - otherScalar, imaginary);
    }
    template <class ScalarType>
    Complex<T> operator*(const ScalarType& otherScalar) const
    {
        return Complex<T>(real * otherScalar, imaginary * otherScalar);
    }
    template <class ScalarType>
    Complex<T> operator/(const ScalarType& otherScalar) const
    {

        if (otherScalar == 0)
        {
            throw std::runtime_error("Error: Division by zero");
        }
        return Complex<T>(real / otherScalar, imaginary / otherScalar);
    }
};
