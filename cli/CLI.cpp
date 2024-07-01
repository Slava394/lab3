#include <exception>
#include <iostream>
#include <sstream>
#include <readline/readline.h>
#include <readline/history.h>
#include "CLI.h"
#include "../abstract_data_type/SegmentedDeque.h"
#include "../abstract_data_type/SparseMatrix.h"


template <typename T>
class NamedSegmentedDeque
{
public:
    std::string name;
    SegmentedDeque<T> deque;
    NamedSegmentedDeque() = default;
    explicit NamedSegmentedDeque(std::string  name) : name(std::move(name)) {}
};


template <typename T>
class NamedSparseMatrix
{
public:
    std::string name;
    SparseMatrix<T> matrix;
    NamedSparseMatrix() = default;
    explicit NamedSparseMatrix(std::string  name) : name(std::move(name)) {}
};

//to handle exception with
template <typename functionType, typename ...argumentType>
void handleExceptions(functionType function, argumentType&& ...args)
{
    try
    {
        function(std::forward<argumentType>(args)...);
    }
    catch (const std::exception& exception)
    {
        std::cerr << "Error: " << exception.what() << "\n";
    }
}

//cli method for sparse matrix
template <typename T>
void printMatrix(const NamedSparseMatrix<T>& namedMatrix)
{
    for (int index{0}; index < namedMatrix.matrix.GetRowCount(); ++index)
    {
        for (int innerIndex{0}; innerIndex < namedMatrix.matrix.GetColumnCount(); ++innerIndex)
        {
            std::cout << namedMatrix.matrix.GetElement(index + 1, innerIndex + 1) << " ";
        }
        std::cout << "\n";
    }
}

template <typename T>
void setValueMatrix(NamedSparseMatrix<T>& namedMatrix, std::istringstream& args)
{
    int row, column;
    T value;
    if (args >> row >> column >> value)
    {
        namedMatrix.matrix.SetElement(row, column, value);
    }
    else
    {
        std::cerr << "Error: Invalid input\n";
    }
}

template <typename T>
void addMatrices(NamedSparseMatrix<T>& namedMatrix1, const NamedSparseMatrix<T>& namedMatrix2)
{
    namedMatrix1.matrix = namedMatrix1.matrix + namedMatrix2.matrix;
    printMatrix(namedMatrix1);
}

template <typename T>
void multiplyMatrices(NamedSparseMatrix<T>& namedMatrix1, const NamedSparseMatrix<T>& namedMatrix2)
{
    NamedSparseMatrix<T> result("result");
    result.matrix = namedMatrix1.matrix * namedMatrix2.matrix;
    printMatrix(result);
}

template <typename T>
void scalarMultiply(NamedSparseMatrix<T>& namedMatrix, std::istringstream& args)
{
    T scalar;
    if (args >> scalar)
    {
        namedMatrix.matrix = namedMatrix.matrix * scalar;
        printMatrix(namedMatrix);
    }
    else
    {
        std::cerr << "Error: Invalid scalar value\n";
    }
}

template <typename T>
void calculateEuclideanFormForMatrix(const NamedSparseMatrix<T>& namedMatrix)
{
    T norm = namedMatrix.matrix.CalculateEuclideanNorm();
    std::cout << "Euclidean norm: " << norm << "\n";
}

//cli method for segmented namedDeque
template <typename T>
void printDeque(const NamedSegmentedDeque<T>& namedDeque)
{
    for (int index{0}; index < namedDeque.deque.GetLength(); ++index)
    {
        std::cout << namedDeque.deque.Get(index) << " ";
    }
    std::cout << "\n";
}

template <typename T>
void getFirstDeque(NamedSegmentedDeque<T>& namedDeque)
{
    std::cout << "First element: " << namedDeque.deque.GetFirst() << "\n";
}

template <typename T>
void getLastDeque(NamedSegmentedDeque<T>& namedDeque)
{
    std::cout << "Last element: " << namedDeque.deque.GetLast() << "\n";
}

template <typename T>
void prependDeque(NamedSegmentedDeque<T>& namedDeque, std::istringstream& args)
{
    T value;
    while (args >> value)
    {
        namedDeque.deque.Prepend(value);
    }
    printDeque(namedDeque);
}

template <typename T>
void appendDeque(NamedSegmentedDeque<T>& namedDeque, std::istringstream& args)
{
    T value;
    while (args >> value)
    {
        namedDeque.deque.Append(value);
    }
    printDeque(namedDeque);
}

template <typename T>
void insertAtDeque(NamedSegmentedDeque<T>& namedDeque, std::istringstream& args)
{
    T value;
    int index;
    if (args >> value >> index)
    {
        namedDeque.deque.InsertAt(value, index);
    }
    else
    {
        std::cerr << "Error: Invalid value or index\n";
        return;
    }
    printDeque(namedDeque);
}

template <typename T>
void removeFirstDeque(NamedSegmentedDeque<T>& namedDeque)
{
    namedDeque.deque.RemoveFirst();
    printDeque(namedDeque);
}

template <typename T>
void removeLastDeque(NamedSegmentedDeque<T>& namedDeque)
{
    namedDeque.deque.RemoveLast();
    printDeque(namedDeque);
}

template <typename T>
void eraseDeque(NamedSegmentedDeque<T>& namedDeque, std::istringstream& args)
{
    int index;
    if (args >> index)
    {
        namedDeque.deque.Erase(index);
    }
    else
    {
        std::cerr << "Error: Invalid index\n";
        return;
    }
    printDeque(namedDeque);
}

template <typename T>
void mapDeque(NamedSegmentedDeque<T>& namedDeque, std::istringstream& args)
{
    std::string functionName;
    args >> functionName;
    if (functionName == "*3")
    {
        namedDeque.deque.Map([](const T& x) { return x * 3; });
    }
    else if (functionName == "+50")
    {
        namedDeque.deque.Map([](const T& x) { return x + 50; });
    }
    else if (functionName == "/2")
    {
        namedDeque.deque.Map([](const T& x) { return x / 2; });
    }
    else
    {
        std::cerr << "Error: Invalid function name " << functionName << ". Use '*3', '+50' or '/2'.\n";
        return;
    }
    printDeque(namedDeque);
}

template <typename T>
void whereDeque(NamedSegmentedDeque<T>& namedDeque, std::istringstream& args)
{
    std::string condition;
    args >> condition;
    NamedSegmentedDeque<T> result("result");
    if (condition == "even")
    {
        result.deque = namedDeque.deque.Where([](const T& x) { return x % 2 == 0; });
    }
    else if (condition == "odd")
    {
        result.deque = namedDeque.deque.Where([](const T& x) { return x % 2 == 1; });
    }
    else if (condition == "positive")
    {
        result.deque = namedDeque.deque.Where([](const T& x) { return x > 0; });
    }
    else
    {
        std::cerr << "Error: Invalid condition " << condition << ". Use 'even', 'odd' or 'positive'.\n";
        return;
    }
    printDeque(result);
}

template <typename T>
void reduceDeque(NamedSegmentedDeque<T>& namedDeque, std::istringstream& args)
{
    long initialValue;
    std::string functionName;
    args >> functionName;
    if (!(args >> initialValue))
    {
        std::cerr << "Error: Missing initialValue\n";
        return;
    }
    T result;
    if (functionName == "+")
    {
        result = namedDeque.deque.Reduce([](const T& a, const T& b) { return a + b; }, initialValue);
    }
    else if (functionName == "-")
    {
        result = namedDeque.deque.Reduce([](const T& a, const T& b) { return a - b; }, initialValue);
    }
    else if (functionName == "*")
    {
        result = namedDeque.deque.Reduce([](const T& a, const T& b) { return a * b; }, initialValue);
    }
    else
    {
        std::cerr << "Error: Invalid binary operation name " << functionName << ". Use '+', '-' or '*'.\n";
        return;
    }
    std::cout << "Reduce with " << functionName << ": " << result << "\n";
}

void printAllDeques(const MutableArraySequence<NamedSegmentedDeque<long>*>& namedDeques)
{
    for (int index{0}; index < namedDeques.GetLength(); ++index)
    {
        std::cout << namedDeques.Get(index)->name << " ";
    }
    std::cout << std::endl;
}

void printAllMatrices(const MutableArraySequence<NamedSparseMatrix<long>*>& namedMatrices)
{
    for (int index{0}; index < namedMatrices.GetLength(); ++index)
    {
        std::cout << namedMatrices.Get(index)->name << " ";
    }
    std::cout << std::endl;
}


void CLI()
{
    MutableArraySequence<NamedSegmentedDeque<long>*> namedDeques;
    MutableArraySequence<NamedSparseMatrix<long>*> namedMatrices;
    std::string line, command, name;
    std::cout << "CLI for SegmentedDeque<long> and SparseMatrix<long>\nType \"help\" for more information.\n";
    while (true)
    {
        line = command = name = "";
        char* input = readline(">>> ");
        if (input == nullptr)
        {
            break;
        }
        line = std::string(input);
        if (line.empty())
        {
            continue;
        }
        add_history(line.c_str());
        free(input);
        std::istringstream stringStream(line);
        stringStream >> command;
        if (command == "createDeque")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for deque\n";
                continue;
            }
            bool isExists = false;
            for (int index{0}; index < namedDeques.GetLength(); ++index)
            {
                if (namedDeques.Get(index)->name == name)
                {
                    std::cerr << "Error: Deque with name '" << name << "' already exists\n";
                    isExists = true;
                    break;
                }
            }
            if (!isExists)
            {
                auto* newDeque = new NamedSegmentedDeque<long>(name);
                long argument;
                while (stringStream >> argument)
                {
                    newDeque->deque.Append(argument);
                }
                namedDeques.Append(newDeque);
                std::cout << "Deque " << name << " created.\n";
            }
        }
        else if (command == "createMatrix")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for matrix\n";
                continue;
            }
            bool isExists = false;
            for (int index = 0; index < namedMatrices.GetLength(); ++index)
            {
                if (namedMatrices.Get(index)->name == name)
                {
                    std::cerr << "Error: Matrix with name '" << name << "' already exists\n";
                    isExists = true;
                    break;
                }
            }
            if (!isExists)
            {
                int rows, columns;
                if (stringStream >> rows >> columns)
                {
                    auto *newMatrix = new NamedSparseMatrix<long>(name);
                    newMatrix->matrix = SparseMatrix<long>(rows, columns);
                    namedMatrices.Append(newMatrix);
                    std::cout << "Matrix " << name << " created.\n";
                }
                else
                {
                    std::cerr << "Error: Missing parameters for matrix init\n";
                }
            }
        }
        else if (command == "printAllDeques")
        {
            handleExceptions<void (*)(const MutableArraySequence<NamedSegmentedDeque<long>*>&)>(
                    printAllDeques, namedDeques);
        }
        else if (command == "printAllMatrices")
        {
            handleExceptions<void (*)(const MutableArraySequence<NamedSparseMatrix<long>*>&)>(
                    printAllMatrices, namedMatrices);
        }
        else if (command == "printDeque")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for deque\n";
                continue;
            }
            for (int index{0}; index < namedDeques.GetLength(); ++index)
            {
                if (namedDeques.Get(index)->name == name)
                {
                    printDeque<long>(*(namedDeques.Get(index)));
                    break;
                }
                if (index == namedDeques.GetLength() - 1)
                {
                    std::cerr << "Error: Deque with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "printMatrix")
        {
            stringStream >> name;
            if (name.empty()) {
                std::cerr << "Error: Missing name for matrix\n";
                continue;
            }
            for (int index{0}; index < namedMatrices.GetLength(); ++index)
            {
                if (namedMatrices.Get(index)->name == name)
                {
                    printMatrix<long>(*(namedMatrices.Get(index)));
                    break;
                }
                if (index == namedMatrices.GetLength() - 1)
                {
                    std::cerr << "Error: Matrix with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "matrixSet")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for matrix\n";
                continue;
            }
            for (int index{0}; index < namedMatrices.GetLength(); ++index)
            {
                if (namedMatrices.Get(index)->name == name)
                {
                    handleExceptions<void (*)(NamedSparseMatrix<long>&, std::istringstream&)>(
                            setValueMatrix, *(namedMatrices.Get(index)), stringStream);
                    break;
                }
                if (index == namedMatrices.GetLength() - 1)
                {
                    std::cerr << "Error: Matrix with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "matrixAdd")
        {
            std::string matrix1Name, matrix2Name;
            stringStream >> matrix1Name >> matrix2Name;
            NamedSparseMatrix<long>* matrix1 = nullptr;
            NamedSparseMatrix<long>* matrix2 = nullptr;
            for (int index{0}; index < namedMatrices.GetLength(); ++index)
            {
                if (namedMatrices.Get(index)->name == matrix1Name)
                {
                    matrix1 = namedMatrices.Get(index);
                    break;
                }
            }
            for (int index{0}; index < namedMatrices.GetLength(); ++index)
            {
                if (namedMatrices.Get(index)->name == matrix2Name)
                {
                    matrix2 = namedMatrices.Get(index);
                    break;
                }
            }
            if (matrix1 && matrix2)
            {
                handleExceptions<void (*)(NamedSparseMatrix<long>&, const NamedSparseMatrix<long>&)>(
                        addMatrices, *matrix1, *matrix2);
            }
            else
            {
                std::cerr << "Error: One of the matrix not found\n";
            }
        } else if (command == "matrixMultiply") {
            std::string matrix1Name, matrix2Name;
            stringStream >> matrix1Name >> matrix2Name;
            NamedSparseMatrix<long>* matrix1 = nullptr;
            NamedSparseMatrix<long>* matrix2 = nullptr;
            for (int index{0}; index < namedMatrices.GetLength(); ++index)
            {
                if (namedMatrices.Get(index)->name == matrix1Name)
                {
                    matrix1 = namedMatrices.Get(index);
                    break;
                }
            }
            for (int index{0}; index < namedMatrices.GetLength(); ++index)
            {
                if (namedMatrices.Get(index)->name == matrix2Name)
                {
                    matrix2 = namedMatrices.Get(index);
                    break;
                }
            }
            if (matrix1 && matrix2)
            {
                handleExceptions<void (*)(NamedSparseMatrix<long>&, const NamedSparseMatrix<long>&)>(
                        multiplyMatrices, *matrix1, *matrix2);
            }
            else
            {
                std::cerr << "Error: One of the matrix not found\n";
            }
        }
        else if (command == "matrixScalarMultiply")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for matrix\n";
                continue;
            }
            for (int index{0}; index < namedMatrices.GetLength(); ++index)
            {
                if (namedMatrices.Get(index)->name == name)
                {
                    handleExceptions<void (*)(NamedSparseMatrix<long>&, std::istringstream&)>(
                            scalarMultiply, *(namedMatrices.Get(index)), stringStream);
                    break;
                }
                if (index == namedMatrices.GetLength() - 1)
                {
                    std::cerr << "Error: Matrix with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "calculateEuclideanNorm")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for matrix\n";
                continue;
            }
            for (int index{0}; index < namedMatrices.GetLength(); ++index)
            {
                if (namedMatrices.Get(index)->name == name)
                {
                    handleExceptions<void (*)(const NamedSparseMatrix<long>&)>(
                            calculateEuclideanFormForMatrix, *(namedMatrices.Get(index)));
                    break;
                }
                if (index == namedMatrices.GetLength() - 1)
                {
                    std::cerr << "Error: Matrix with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "dequeGetFirst")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for deque\n";
                continue;
            }
            for (int index{0}; index < namedDeques.GetLength(); ++index)
            {
                if (namedDeques.Get(index)->name == name)
                {
                    getFirstDeque(*(namedDeques.Get(index)));
                    break;
                }
                if (index == namedDeques.GetLength() - 1)
                {
                    std::cerr << "Error: Deque with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "dequeGetLast")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for deque\n";
                continue;
            }
            for (int index{0}; index < namedDeques.GetLength(); ++index)
            {
                if (namedDeques.Get(index)->name == name)
                {
                    getLastDeque(*(namedDeques.Get(index)));
                    break;
                }
                if (index == namedDeques.GetLength() - 1)
                {
                    std::cerr << "Error: Deque with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "dequePrepend")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for deque\n";
                continue;
            }
            for (int index{0}; index < namedDeques.GetLength(); ++index)
            {
                if (namedDeques.Get(index)->name == name)
                {
                    handleExceptions<void (*)(NamedSegmentedDeque<long>&, std::istringstream&)>(
                            prependDeque, *(namedDeques.Get(index)), stringStream);
                    break;
                }
                if (index == namedDeques.GetLength() - 1)
                {
                    std::cerr << "Error: Deque with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "dequeAppend")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for deque\n";
                continue;
            }
            for (int index{0}; index < namedDeques.GetLength(); ++index)
            {
                if (namedDeques.Get(index)->name == name)
                {
                    handleExceptions<void (*)(NamedSegmentedDeque<long>&, std::istringstream&)>(
                            appendDeque, *(namedDeques.Get(index)), stringStream);
                    break;
                }
                if (index == namedDeques.GetLength() - 1)
                {
                    std::cerr << "Error: Deque with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "dequeInsertAt")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for deque\n";
                continue;
            }
            for (int index{0}; index < namedDeques.GetLength(); ++index)
            {
                if (namedDeques.Get(index)->name == name)
                {
                    handleExceptions<void (*)(NamedSegmentedDeque<long>&, std::istringstream&)>(
                            insertAtDeque, *(namedDeques.Get(index)), stringStream);
                    break;
                }
                if (index == namedDeques.GetLength() - 1)
                {
                    std::cerr << "Error: Deque with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "dequeRemoveFirst")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for deque\n";
                continue;
            }
            for (int index{0}; index < namedDeques.GetLength(); ++index)
            {
                if (namedDeques.Get(index)->name == name)
                {
                    removeFirstDeque(*(namedDeques.Get(index)));
                    break;
                }
                if (index == namedDeques.GetLength() - 1)
                {
                    std::cerr << "Error: Deque with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "dequeRemoveLast")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for deque\n";
                continue;
            }
            for (int index{0}; index < namedDeques.GetLength(); ++index)
            {
                if (namedDeques.Get(index)->name == name)
                {
                    removeLastDeque(*(namedDeques.Get(index)));
                    break;
                }
                if (index == namedDeques.GetLength() - 1)
                {
                    std::cerr << "Error: Deque with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "dequeErase")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for deque\n";
                continue;
            }
            for (int index{0}; index < namedDeques.GetLength(); ++index)
            {
                if (namedDeques.Get(index)->name == name)
                {
                    handleExceptions<void (*)(NamedSegmentedDeque<long>&, std::istringstream&)>(
                            eraseDeque, *(namedDeques.Get(index)), stringStream);
                    break;
                }
                if (index == namedDeques.GetLength() - 1)
                {
                    std::cerr << "Error: Deque with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "dequeMap")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for deque\n";
                continue;
            }
            for (int index{0}; index < namedDeques.GetLength(); ++index)
            {
                if (namedDeques.Get(index)->name == name)
                {
                    handleExceptions<void (*)(NamedSegmentedDeque<long>&, std::istringstream&)>(
                            mapDeque, *(namedDeques.Get(index)), stringStream);
                    break;
                }
                if (index == namedDeques.GetLength() - 1)
                {
                    std::cerr << "Error: Deque with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "dequeWhere")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for deque\n";
                continue;
            }
            for (int index{0}; index < namedDeques.GetLength(); ++index)
            {
                if (namedDeques.Get(index)->name == name)
                {
                    handleExceptions<void (*)(NamedSegmentedDeque<long>&, std::istringstream&)>(
                            whereDeque, *(namedDeques.Get(index)), stringStream);
                    break;
                }
                if (index == namedDeques.GetLength() - 1)
                {
                    std::cerr << "Error: Deque with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "dequeReduce")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for deque\n";
                continue;
            }
            for (int index{0}; index < namedDeques.GetLength(); ++index)
            {
                if (namedDeques.Get(index)->name == name)
                {
                    handleExceptions<void (*)(NamedSegmentedDeque<long>&, std::istringstream&)>(
                            reduceDeque, *(namedDeques.Get(index)), stringStream);
                    break;
                }
                if (index == namedDeques.GetLength() - 1)
                {
                    std::cerr << "Error: Deque with name '" << name << "' not exists\n";
                }
            }
        }
        else if (command == "help")
        {
            std::cout << "Commands available:\n"
                      << "createDeque <name> <args (optional)> - Create a segmented deque with the specified name\n"
                      << "createMatrix <name> <rows> <columns> - Create a sparse matrix with the specified name\n"
                      << "printAllDeques - Print the deques\n"
                      << "printAllMatrices - Print the matrices\n"
                      << "printDeque <name> - Print the segmented deque with the specified name\n"
                      << "printMatrix <name> - Print the sparse matrix with the specified name\n"
                      << "matrixSet <name> <row> <column> <value> - Set the value of the sparse matrix at the specified row and column\n"
                      << "matrixAdd <name1> <name2> - Add two matrices with the specified names\n"
                      << "matrixMultiply <name1> <name2> - Multiply two matrices with the specified names\n"
                      << "matrixScalarMultiply <name> <scalar> - Multiply the matrix with the specified scalar\n"
                      << "calculateEuclideanNorm <name> - Calculate the Euclidean norm of the matrix with the specified name\n"
                      << "dequeGetFirst <name> - Print the first element of the segmented deque with the specified name\n"
                      << "dequeGetLast <name> - Print the last element of the segmented deque with the specified name\n"
                      << "dequePrepend <name> <value1> <value2> ... - Prepend values to the segmented deque with the specified name\n"
                      << "dequeAppend <name> <value1> <value2> ... - Append values to the segmented deque with the specified name\n"
                      << "dequeInsertAt <name> <value> <index> - Insert a value into the segmented deque at the specified index\n"
                      << "dequeRemoveFirst <name> - Remove the first element from the segmented deque with the specified name\n"
                      << "dequeRemoveLast <name> - Remove the last element from the segmented deque with the specified name\n"
                      << "dequeErase <name> <index> - Erase the element at the specified index from the segmented deque with the specified name\n"
                      << "dequeMap <name> <*3|+50|/2> - Apply a mapping function to the segmented deque with the specified name\n"
                      << "dequeWhere <name> <even|odd|positive> - Filter the segmented deque by 'even', 'odd', or 'positive' values\n"
                      << "dequeReduce <name> <+|-|*> <initial_value> - Reduce the segmented deque with the specified binary operation and initial value\n"
                      << "help - Display this help message\n"
                      << "exit - Exit the program\n";
        }
        else if (command == "exit")
        {
            break;
        }
        else
        {
            std::cerr << "Error: Unknown command. Type 'help' for a list of commands.\n";
        }
    }
    for (int index{0}; index < namedDeques.GetLength(); ++index) 
    {
        if (namedDeques.Get(index))
        {
            delete namedDeques.Get(index);
        }
    }
    for (int index{0}; index < namedMatrices.GetLength(); ++index) 
    {
        if (namedMatrices.Get(index))
        {
            delete namedMatrices.Get(index);
        }
    }
}
