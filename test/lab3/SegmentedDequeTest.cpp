#include <iostream>
#include <cassert>
#include <cmath>
#include "SegmentedDequeTest.h"
#include "../../abstract_data_type/SegmentedDeque.h"
#include "../../auxiliary_types/Complex.h"
#include "../../auxiliary_types/Person.h"
#define EPSILON 1e-6


void TestDequeAddGet()
{
    std::cout << "Segmented deque add methods tests:\n";
    //---SegmentedDeque<Complex<long>> add and get---
    {
        {
            SegmentedDeque<Complex<long>> deque(3);
            deque.Append(Complex<long>(1, 2));
            deque.Append(Complex<long>(3, 4));
            deque.Prepend(Complex<long>(5, 6));
            assert(deque.GetLength() == 3);
            assert(deque.GetFirst().real == 5);
            assert(deque.GetLast().imaginary == 4);
        }
        {
            SegmentedDeque<Complex<long>> deque(3);
            deque.Append(Complex<long>(-1, -2));
            deque.Append(Complex<long>(-3, -4));
            deque.Prepend(Complex<long>(-5, -6));
            assert(deque.GetLength() == 3);
            assert(deque.GetFirst().real == -5);
            assert(deque.GetLast().imaginary == -4);
        }
        {
            SegmentedDeque<Complex<long>> deque(3);
            deque.Append(Complex<long>(0, 0));
            deque.Append(Complex<long>(3, 0));
            deque.Prepend(Complex<long>(0, 6));
            assert(deque.GetLength() == 3);
            assert(deque.GetFirst().real == 0);
            assert(deque.GetLast().imaginary == 0);
        }
        {
            SegmentedDeque<Complex<long>> deque(3);
            for (long index{0}; index < 10; ++index)
            {
                deque.Append(Complex<long>(index, index * 2));
            }
            assert(deque.GetLength() == 10);
            assert(deque.GetFirst().real == 0);
            assert(deque.GetLast().imaginary == 18);
        }
        {
            SegmentedDeque<Complex<long>> deque(3);
            deque.Append(Complex<long>(1, 2));
            deque.Prepend(Complex<long>(3, 4));
            deque.Append(Complex<long>(5, 6));
            deque.Prepend(Complex<long>(7, 8));
            assert(deque.GetLength() == 4);
            assert(deque.GetFirst().real == 7);
            assert(deque.GetLast().imaginary == 6);
        }
    }
    std::cout << "Test 1 passed: SegmentedDeque<Complex<long>> add and get methods work correctly\n";
    //---SegmentedDeque<Person> add and get---
    {
        {
            SegmentedDeque<Person> deque(3);
            Person p1(PersonID("AB", "123456"), "John", "A.", "Doe",
                      946684800);
            Person p2(PersonID("CD", "654321"), "Jane", "B.", "Smith",
                      978307200);
            Person p3(PersonID("EF", "789012"), "Alice", "C.", "Johnson",
                      1009843200);
            deque.Append(p1);
            deque.Append(p2);
            deque.Prepend(p3);
            assert(deque.GetLength() == 3);
            assert(deque.GetFirst().GetFirstName() == "Alice");
            assert(deque.GetLast().GetLastName() == "Smith");
        }
        {
            SegmentedDeque<Person> deque(3);
            Person p1(PersonID("GH", "987654"), "Bob", "D.", "Brown",
                      1041379200);
            Person p2(PersonID("IJ", "543210"), "Charlie", "E.", "Green",
                      1072915200);
            Person p3(PersonID("KL", "321098"), "Dave", "F.", "White",
                      1104537600);
            deque.Append(p1);
            deque.Append(p2);
            deque.Prepend(p3);
            assert(deque.GetLength() == 3);
            assert(deque.GetFirst().GetFirstName() == "Dave");
            assert(deque.GetLast().GetLastName() == "Green");
        }
        {
            SegmentedDeque<Person> deque(3);

            Person p1(PersonID("MN", "111111"), "Eve", "G.", "Black",
                      1136073600);
            Person p2(PersonID("OP", "222222"), "Frank", "H.", "Gray",
                      1167609600);
            Person p3(PersonID("QR", "333333"), "Grace", "I.", "Blue",
                      1199145600);
            deque.Append(p1);
            deque.Append(p2);
            deque.Prepend(p3);
            assert(deque.GetLength() == 3);
            assert(deque.GetFirst().GetID().GetSeries() == "QR");
            assert(deque.GetLast().GetID().GetNumber() == "222222");
        }
        {
            SegmentedDeque<Person> deque(3);
            for (int index{0}; index < 10; ++index)
            {
                Person p(PersonID("ST", std::to_string(index)),
                         "First" + std::to_string(index), "M.",
                         "Last" + std::to_string(index), 1230768000 + (index * 31536000));
                deque.Append(p);
            }
            assert(deque.GetLength() == 10);
            assert(deque.GetFirst().GetFirstName() == "First0");
            assert(deque.GetLast().GetLastName() == "Last9");
        }
        {
            SegmentedDeque<Person> deque(3);

            Person p1(PersonID("UV", "444444"), "Hank", "J.", "Pink",
                      1262304000);
            Person p2(PersonID("WX", "555555"), "Ivy", "K.", "Red",
                      1293840000);
            Person p3(PersonID("YZ", "666666"), "Jack", "L.", "Orange",
                      1325376000);
            Person p4(PersonID("AA", "777777"), "Karen", "M.", "Yellow",
                      1356998400);
            deque.Append(p1);
            deque.Prepend(p2);
            deque.Append(p3);
            deque.Prepend(p4);
            assert(deque.GetLength() == 4);
            assert(deque.GetFirst().GetFirstName() == "Karen");
            assert(deque.GetLast().GetFirstName() == "Jack");
        }
    }
    std::cout << "Test 2 passed: SegmentedDeque<Person> add and get methods work correctly\n";
}

void TestDequeInsertAt()
{
    std::cout << "Segmented deque insert at tests:\n";
    //---SegmentedDeque<Complex<long>> insert at---
    {
        {
            SegmentedDeque<Complex<long>> deque(3);
            deque.InsertAt(Complex<long>(1, 2), 0);
            deque.InsertAt(Complex<long>(3, 4), 1);
            deque.InsertAt(Complex<long>(5, 6), 1);
            assert(deque.GetLength() == 3);
            assert(deque.GetFirst().real == 1);
            assert(deque.Get(1).imaginary == 6);
            assert(deque.GetLast().real == 3);
        }
        {
            SegmentedDeque<Complex<long>> deque(3);
            deque.InsertAt(Complex<long>(1, 2), 0);
            deque.InsertAt(Complex<long>(3, 4), 1);
            deque.InsertAt(Complex<long>(5, 6), 1);
            deque.InsertAt(Complex<long>(7, 8), 2);
            deque.InsertAt(Complex<long>(9, 10), 4);
            assert(deque.GetLength() == 5);
            assert(deque.GetFirst().real == 1);
            assert(deque.Get(1).imaginary == 6);
            assert(deque.Get(2).real == 7);
            assert(deque.Get(3).imaginary == 4);
            assert(deque.GetLast().real == 9);
        }
        {
            SegmentedDeque<Complex<long>> deque(3);
            for (long index{0}; index < 5; ++index)
            {
                deque.Append(Complex<long>(index, index * 2));
            }
            deque.InsertAt(Complex<long>(10, 20), 2);
            assert(deque.GetLength() == 6);
            assert(deque.Get(2).real == 10);
            assert(deque.Get(2).imaginary == 20);
            assert(deque.Get(3).real == 2);
        }
    }
    std::cout << "Test 1 passed: SegmentedDeque<Complex<long>> insert at methods work correctly\n";
    //---SegmentedDeque<Person> insert at---
    {
        {
            SegmentedDeque<Person> deque(3);

            Person p1(PersonID("AB", "123456"), "John", "A.", "Doe",
                      946684800);
            Person p2(PersonID("CD", "654321"), "Jane", "B.", "Smith",
                      978307200);
            Person p3(PersonID("EF", "789012"), "Alice", "C.", "Johnson",
                      1009843200);
            deque.InsertAt(p1, 0);
            deque.InsertAt(p2, 1);
            deque.InsertAt(p3, 1);
            assert(deque.GetLength() == 3);
            assert(deque.GetFirst().GetFirstName() == "John");
            assert(deque.Get(1).GetFirstName() == "Alice");
            assert(deque.GetLast().GetFirstName() == "Jane");
        }
        {
            SegmentedDeque<Person> deque(3);
            Person p1(PersonID("GH", "987654"), "Bob", "D.", "Brown",
                      1041379200);
            Person p2(PersonID("IJ", "543210"), "Charlie", "E.", "Green",
                      1072915200);
            Person p3(PersonID("KL", "321098"), "Dave", "F.", "White",
                      1104537600);
            Person p4(PersonID("MN", "111111"), "Eve", "G.", "Black",
                      1136073600);
            Person p5(PersonID("OP", "222222"), "Frank", "H.", "Gray",
                      1167609600);
            deque.InsertAt(p1, 0);
            deque.InsertAt(p2, 1);
            deque.InsertAt(p3, 1);
            deque.InsertAt(p4, 2);
            deque.InsertAt(p5, 4);
            assert(deque.GetLength() == 5);
            assert(deque.GetFirst().GetFirstName() == "Bob");
            assert(deque.Get(1).GetFirstName() == "Dave");
            assert(deque.Get(2).GetFirstName() == "Eve");
            assert(deque.Get(3).GetFirstName() == "Charlie");
            assert(deque.GetLast().GetFirstName() == "Frank");
        }
        {
            SegmentedDeque<Person> deque(3);
            for (int index{0}; index < 5; ++index)
            {
                Person p(PersonID("ST", std::to_string(index)),
                         "First" + std::to_string(index), "M.",
                         "Last" + std::to_string(index), 1230768000 + (index * 31536000));
                deque.Append(p);
            }
            Person p1(PersonID("UV", "444444"), "Hank", "J.", "Pink",
                       1262304000);
            deque.InsertAt(p1, 2);
            assert(deque.GetLength() == 6);
            assert(deque.Get(2).GetFirstName() == "Hank");
            assert(deque.Get(3).GetFirstName() == "First2");
        }
    }
    std::cout << "Test 2 passed: SegmentedDeque<Person> insert at methods work correctly\n";
}

void TestDequeConcat()
{
    std::cout << "Segmented deque concat tests:\n";
    //---SegmentedDeque<long> concat---
    {
        {
            SegmentedDeque<long> deque1(3);
            SegmentedDeque<long> deque2(3);
            deque1.Concat(deque2);
            assert(deque1.GetLength() == 0);
        }
        {
            SegmentedDeque<long> deque1(3);
            SegmentedDeque<long> deque2(3);
            deque2.Append(1);
            deque2.Append(2);
            deque2.Append(3);
            deque1.Concat(deque2);
            assert(deque1.GetLength() == 3);
            assert(deque1.GetFirst() == 1);
            assert(deque1.GetLast() == 3);
        }
        {
            SegmentedDeque<long> deque1(3);
            SegmentedDeque<long> deque2(3);
            deque1.Append(1);
            deque1.Append(2);
            deque1.Append(3);
            deque2.Append(4);
            deque2.Append(5);
            deque2.Append(6);
            deque1.Concat(deque2);
            assert(deque1.GetLength() == 6);
            assert(deque1.GetFirst() == 1);
            assert(deque1.GetLast() == 6);
        }
        {
            SegmentedDeque<long> deque1(3);
            SegmentedDeque<long> deque2(3);
            deque1.Append(1);
            deque1.Append(2);
            deque2.Append(3);
            deque2.Append(4);
            deque2.Append(5);
            deque2.Append(6);
            deque1.Concat(deque2);
            assert(deque1.GetLength() == 6);
            assert(deque1.GetFirst() == 1);
            assert(deque1.Get(2) == 3);
            assert(deque1.GetLast() == 6);
        }
    }
    std::cout << "Test 1 passed: SegmentedDeque<long> concat works correctly\n";
    //---SegmentedDeque<double> concat---
    {
        {
            SegmentedDeque<double> deque1(3);
            SegmentedDeque<double> deque2(3);
            deque1.Concat(deque2);
            assert(deque1.GetLength() == 0);
        }
        {
            SegmentedDeque<double> deque1(3);
            SegmentedDeque<double> deque2(3);
            deque2.Append(1.1);
            deque2.Append(2.2);
            deque2.Append(3.3);
            deque1.Concat(deque2);
            assert(deque1.GetLength() == 3);
            assert(deque1.GetFirst() == 1.1);
            assert(deque1.GetLast() == 3.3);
        }
        {
            SegmentedDeque<double> deque1(3);
            SegmentedDeque<double> deque2(3);
            deque1.Append(1.1);
            deque1.Append(2.2);
            deque1.Append(3.3);
            deque2.Append(4.4);
            deque2.Append(5.5);
            deque2.Append(6.6);
            deque1.Concat(deque2);
            assert(deque1.GetLength() == 6);
            assert(deque1.GetFirst() == 1.1);
            assert(deque1.GetLast() == 6.6);
        }
        {
            SegmentedDeque<double> deque1(3);
            SegmentedDeque<double> deque2(3);
            deque1.Append(1.1);
            deque1.Append(2.2);
            deque2.Append(3.3);
            deque2.Append(4.4);
            deque2.Append(5.5);
            deque2.Append(6.6);
            deque1.Concat(deque2);
            assert(deque1.GetLength() == 6);
            assert(deque1.GetFirst() == 1.1);
            assert(deque1.Get(2) == 3.3);
            assert(deque1.GetLast() == 6.6);
        }
    }
    std::cout << "Test 2 passed: SegmentedDeque<double> concat works correctly\n";
}

void TestDequeMergeSort()
{
    std::cout << "Segmented deque sort tests:\n";
    //---SegmentedDeque<long> merge sort---
    //P.S. standard comparator aka real numbers order
    {
        {
            SegmentedDeque<long> deque(3);
            deque.MergeSort(0, -1, [](const long& a, const long& b) { return a < b; });
            assert(deque.GetLength() == 0);
        }
        {
            SegmentedDeque<long> deque(3);
            deque.Append(1);
            deque.MergeSort(0, 0, [](const long& a, const long& b) { return a < b; });
            assert(deque.GetLength() == 1);
            assert(deque.GetFirst() == 1);
        }
        {
            SegmentedDeque<long> deque(3);
            deque.Append(3);
            deque.Append(1);
            deque.Append(2);
            deque.MergeSort(0, 2, [](const long& a, const long& b) { return a < b; });
            assert(deque.GetLength() == 3);
            assert(deque.Get(0) == 1);
            assert(deque.Get(1) == 2);
            assert(deque.Get(2) == 3);
        }
        {
            SegmentedDeque<long> deque(3);
            deque.Append(3);
            deque.Append(2);
            deque.Append(1);
            deque.MergeSort(0, 2, [](const long& a, const long& b) { return a < b; });
            assert(deque.GetLength() == 3);
            assert(deque.Get(0) == 1);
            assert(deque.Get(1) == 2);
            assert(deque.Get(2) == 3);
        }
    }
    std::cout << "Test 1 passed: SegmentedDeque<long> merge sort works correctly\n";
    //---SegmentedDeque<double> merge sort---
    {
        {
            SegmentedDeque<double> deque(3);
            deque.MergeSort(0, -1, [](const double& a, const double& b) { return a < b; });
            assert(deque.GetLength() == 0);
        }
        {
            SegmentedDeque<double> deque(3);
            deque.Append(1.1);
            deque.MergeSort(0, 0, [](const double& a, const double& b) { return a < b; });
            assert(deque.GetLength() == 1);
            assert(deque.GetFirst() == 1.1);
        }
        {
            SegmentedDeque<double> deque(3);
            deque.Append(3.3);
            deque.Append(1.1);
            deque.Append(2.2);
            deque.MergeSort(0, 2, [](const double& a, const double& b) { return a < b; });
            assert(deque.GetLength() == 3);
            assert(deque.Get(0) == 1.1);
            assert(deque.Get(1) == 2.2);
            assert(deque.Get(2) == 3.3);
        }
        {
            SegmentedDeque<double> deque(3);
            deque.Append(3.3);
            deque.Append(2.2);
            deque.Append(1.1);
            deque.MergeSort(0, 2, [](const double& a, const double& b) { return a < b; });
            assert(deque.GetLength() == 3);
            assert(deque.Get(0) == 1.1);
            assert(deque.Get(1) == 2.2);
            assert(deque.Get(2) == 3.3);
        }
    }
    std::cout << "Test 2 passed: SegmentedDeque<double> merge sort works correctly\n";
}

void TestDequeWhere()
{
    std::cout << "Segmented deque where tests:\n";
    //---SegmentedDeque<long> where---
    {
        {
            SegmentedDeque<long> deque(3);
            deque.Append(-1);
            deque.Append(2);
            deque.Append(-3);
            deque.Append(4);
            deque.Append(-5);
            auto filteredDeque = deque.Where([](const long& value)
            {
                return value > 0;
            });
            assert(filteredDeque.GetLength() == 2);
            assert(filteredDeque.Get(0) == 2);
            assert(filteredDeque.Get(1) == 4);
        }
        {
            SegmentedDeque<long> deque(3);
            deque.Append(1);
            deque.Append(2);
            deque.Append(3);
            deque.Append(4);
            deque.Append(5);
            auto filteredDeque = deque.Where([](const long& value)
            {
                return value % 2 == 0;
            });
            assert(filteredDeque.GetLength() == 2);
            assert(filteredDeque.Get(0) == 2);
            assert(filteredDeque.Get(1) == 4);
        }
        {
            SegmentedDeque<long> deque(3);
            deque.Append(1);
            deque.Append(2);
            deque.Append(3);
            deque.Append(4);
            deque.Append(5);
            deque.Append(6);
            auto filteredDeque = deque.Where([](const long& value)
            {
                return value % 3 == 0;
            });
            assert(filteredDeque.GetLength() == 2);
            assert(filteredDeque.Get(0) == 3);
            assert(filteredDeque.Get(1) == 6);

        }
    }
    std::cout << "Test 1 passed: SegmentedDeque<long> where works correctly\n";
    //---SegmentedDeque<double> where---
    {
        {
            SegmentedDeque<double> deque(3);
            deque.Append(-1.0);
            deque.Append(2.0);
            deque.Append(-3.5);
            deque.Append(4.0);
            deque.Append(-5.5);
            auto filteredDeque = deque.Where([](const double& value)
            {
                return value < 0.0;
            });
            assert(filteredDeque.GetLength() == 3);
            assert(filteredDeque.Get(0) == -1.0);
            assert(filteredDeque.Get(1) == -3.5);
            assert(filteredDeque.Get(2) == -5.5);
        }
        {
            SegmentedDeque<double> deque(3);
            deque.Append(1.0);
            deque.Append(2.0);
            deque.Append(3.0);
            deque.Append(4.0);
            deque.Append(5.0);
            auto filteredDeque = deque.Where([](const double& value)
            {
                return value > 2.5;
            });
            assert(filteredDeque.GetLength() == 3);
            assert(filteredDeque.Get(0) == 3.0);
            assert(filteredDeque.Get(1) == 4.0);
            assert(filteredDeque.Get(2) == 5.0);
        }
        {
            SegmentedDeque<double> deque(3);
            deque.Append(1.5);
            deque.Append(2.3);
            deque.Append(3.8);
            deque.Append(4.0);
            deque.Append(5.7);
            auto filteredDeque = deque.Where([](const double& value)
            {
                return std::floor(value) == value;
            });
            assert(filteredDeque.GetLength() == 1);
            assert(filteredDeque.Get(0) == 4.0);
        }
    }
    std::cout << "Test 2 passed: SegmentedDeque<double> where works correctly\n";
}

void TestDequeReduce()
{
    std::cout << "Segmented deque reduce tests:\n";
    //---SegmentedDeque<long> reduce---
    {
        {
            SegmentedDeque<long> deque(3);
            deque.Append(1);
            deque.Append(2);
            deque.Append(3);
            deque.Append(4);
            deque.Append(5);
            long sum = deque.Reduce([](const long& a, const long& b) { return a + b; }, 0);
            assert(sum == 15);
        }
        {
            SegmentedDeque<long> deque(3);
            deque.Append(1);
            deque.Append(2);
            deque.Append(3);
            deque.Append(4);
            deque.Append(5);
            long product = deque.Reduce([](const long& a, const long& b) { return a * b; }, 1);
            assert(product == 120);
        }
        {
            SegmentedDeque<long> deque(3);
            deque.Append(1);
            deque.Append(7);
            deque.Append(3);
            deque.Append(4);
            deque.Append(5);
            long max = deque.Reduce([](const long& a, const long& b)
            {
                return (a > b) ? a : b;
            }, std::numeric_limits<long>::min());
            assert(max == 7);
        }
    }
    std::cout << "Test 1 passed: SegmentedDeque<long> reduce works correctly\n";
    //---SegmentedDeque<double> reduce---
    {
        {
            SegmentedDeque<double> deque(3);
            deque.Append(1.1);
            deque.Append(2.2);
            deque.Append(3.3);
            deque.Append(4.4);
            deque.Append(5.5);
            double sum = deque.Reduce([](const double& a, const double& b) { return a + b; }, 0.0);
            assert(sum == 16.5);
        }
        {
            SegmentedDeque<double> deque(3);
            deque.Append(1.1);
            deque.Append(2.0);
            deque.Append(3.5);
            deque.Append(4.4);
            deque.Append(5.0);
            double product = deque.Reduce([](const double& a, const double& b) { return a * b; }, 1.0);
            assert(std::fabs(product - 169.4) < EPSILON);
        }
        {
            SegmentedDeque<double> deque(3);
            deque.Append(1.1);
            deque.Append(7.2);
            deque.Append(3.3);
            deque.Append(4.4);
            deque.Append(5.5);
            double min = deque.Reduce([](const double& a, const double& b)
            {
                return (a < b) ? a : b;
            }, std::numeric_limits<double>::max());
            assert(min == 1.1);
        }
    }
    std::cout << "Test 2 passed: SegmentedDeque<double> reduce works correctly\n";
    //---SegmentedDeque<Person> reduce---
    {
        {
            SegmentedDeque<Person> deque(3);
            PersonID id1("Aa", "123456");
            PersonID id2("Bb", "654321");
            time_t birthDate1 = 1000000000;
            time_t birthDate2 = 1500000000;
            deque.Append(Person(id1, "Alice", "A.", "Anderson", birthDate1));
            deque.Append(Person(id2, "Bob", "B.", "Brown", birthDate2));
            Person oldest = deque.Reduce([](const Person &currentOldest, const Person &otherPerson) {
                return (otherPerson.GetBirthDate() < currentOldest.GetBirthDate()) ? otherPerson : currentOldest;
            }, deque.GetFirst());
            assert(oldest.GetID().GetSeries() == "Aa" && oldest.GetID().GetNumber() == "123456");
        }
    }
    std::cout << "Test 3 passed: SegmentedDeque<Person> reduce works correctly\n";
}

void AllSegmentedDequeTest()
{
    TestDequeAddGet();
    TestDequeInsertAt();
    TestDequeConcat();
    TestDequeMergeSort();
    TestDequeWhere();
    TestDequeReduce();
}
