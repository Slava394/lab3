#pragma once
#include <stdexcept>
#include <complex>
#include "../sequence_lab2/ArraySequence.h"


template <class T>
class MatrixElement
{
public:
    int row;
    int column;
    T value;
    //---Constructors---
    MatrixElement() : row(0), column(0), value(T()) {}
    MatrixElement(int row, int column, T value) : row(row), column(column), value(value) {}
};


template <class T>
class SparseMatrix
{
private:
    int rowCount;
    int columnCount;
    MutableArraySequence<MatrixElement<T>> elements;
    //---Decomposition---
    void Check(int rowNumber, int columnNumber) const
    {
        if (rowNumber < 1 || rowNumber > rowCount || columnNumber < 1 || columnNumber > columnCount)
        {
            throw std::out_of_range("Index out of range");
        }
    }
    [[nodiscard]] int FindElementIndex(int row, int column) const
    {
        for (int index{0}; index < elements.GetLength(); ++index)
        {
            if (elements.Get(index).row == row && elements.Get(index).column == column)
            {
                return index;
            }
        }
        return -1;
    }
public:
    //---Constructors---
    explicit SparseMatrix(int rows = 0, int columns = 0) :
            rowCount(rows),
            columnCount(columns),
            elements(MutableArraySequence<MatrixElement<T>>()) {}
    SparseMatrix(const SparseMatrix<T>& sparseMatrix) :
            rowCount(sparseMatrix.rowCount), columnCount(sparseMatrix.columnCount), elements(sparseMatrix.elements) {}
    //---Destructor---
    ~SparseMatrix() = default;
    //---Operator overloading---
    SparseMatrix<T> operator+(const SparseMatrix<T>& otherSparseMatrix) const
    {
        return Add(otherSparseMatrix);
    }
    SparseMatrix<T> operator*(const SparseMatrix<T>& otherSparseMatrix) const
    {
        return Multiply(otherSparseMatrix);
    }
    SparseMatrix<T> operator*(const T& scalar) const
    {
        return MultiplyByScalar(scalar);
    }
    //---Getters---
    T GetElement(int row, int column) const
    {
        Check(row, column);
        int index = FindElementIndex(row, column);
        if (index != -1)
        {
            return elements.Get(index).value;
        }
        T defaultValue = T();
        return defaultValue;
    }
    [[nodiscard]] int GetRowCount() const
    {
        return rowCount;
    }
    [[nodiscard]] int GetColumnCount() const
    {
        return columnCount;
    }
    [[nodiscard]] int GetNonNullElementCount() const
    {
        return elements.GetLength();
    }
    //---Setters---
    void SetElement(int row, int column, const T& value)
    {
        Check(row, column);
        int index = FindElementIndex(row, column);
        if (index != -1)
        {
            T defaultValue = T();
            if (value != defaultValue)
            {
                elements.Get(index).value = value;
            }
            else
            {
                elements.Erase(index);
            }
        }
        else
        {
            T defaultValue = T();
            if (value != defaultValue)
            {
                elements.Append(MatrixElement<T>(row, column, value));
            }
        }
    }
    void setRowCount(int newRowCount)
    {
        rowCount = newRowCount;
    }
    void setColumnCount(int newColumnCount)
    {
        columnCount = newColumnCount;
    }
    //---Matrix operation---
    SparseMatrix<T> Add(const SparseMatrix<T>& otherSparseMatrix) const
    {
        if (rowCount != otherSparseMatrix.rowCount || columnCount != otherSparseMatrix.columnCount)
        {
            throw std::invalid_argument("Matrices of different sizes");
        }
        SparseMatrix<T> resultSparseMatrix(rowCount, columnCount);
        for (int index{0}; index < elements.GetLength(); ++index)
        {
            auto& element = elements.Get(index);
            resultSparseMatrix.SetElement(element.row, element.column, element.value);
        }
        for (int index{0}; index < otherSparseMatrix.elements.GetLength(); ++index)
        {
            auto& element = otherSparseMatrix.elements.Get(index);
            T intermediateResult = resultSparseMatrix.GetElement(element.row,
                                                                 element.column) + element.value;
            resultSparseMatrix.SetElement(element.row,
                                          element.column,
                                          intermediateResult);
        }
        return resultSparseMatrix;
    }
    SparseMatrix<T> Multiply(const SparseMatrix<T>& otherSparseMatrix) const
    {
        if (columnCount != otherSparseMatrix.rowCount)
        {
            throw std::invalid_argument("The number of columns of the left element must "
                                        "be equal to the number of rows of the right");
        }
        SparseMatrix<T> resultSparseMatrix(rowCount, otherSparseMatrix.columnCount);
        for (int index{0}; index < elements.GetLength(); ++index)
        {
            auto& element = elements.Get(index);
            for (int innerIndex{0}; innerIndex < otherSparseMatrix.columnCount; ++innerIndex)
            {
                T intermediateResult = resultSparseMatrix.GetElement(element.row, innerIndex + 1) +
                        element.value * otherSparseMatrix.GetElement(element.column, innerIndex + 1);
                resultSparseMatrix.SetElement(element.row,
                                              innerIndex + 1,
                                              intermediateResult);
            }
        }
        return resultSparseMatrix;
    }
    SparseMatrix<T> MultiplyByScalar(const T& scalar) const
    {
        SparseMatrix<T> result(rowCount, columnCount);
        for (int index{0}; index < elements.GetLength(); ++index)
        {
            auto& element = elements.Get(index);
            result.SetElement(element.row, element.column, element.value * scalar);
        }
        return result;
    }
    //---Euclidean norm (not unitary)---
    T CalculateEuclideanNorm() const
    {
        T norm = T();
        for (int index{0}; index < elements.GetLength(); ++index)
        {
            auto& element = elements.Get(index);
            norm = norm + element.value * element.value;
        }
        return std::sqrt(norm);
    }
};