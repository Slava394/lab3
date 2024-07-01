#include <iostream>
#include <cassert>
#include "SmartPointerTest.h"
#include "../../smart_pointer/UniquePointer.h"
#include "../../smart_pointer/SharedPointer.h"

void TestUniquePointer()
{
    std::cout << "Unique pointer tests:\n";
    //---Double tests---
    {
        UniquePointer<double> up1(new double(3.14));
        assert(*up1 == 3.14);
        std::cout << "Test 1 passed: UniquePointer<double> created successfully\n";

        UniquePointer<double> up2 = std::move(up1);
        assert(up1.Get() == nullptr);
        assert(*up2 == 3.14);
        std::cout << "Test 2 passed: UniquePointer<double> moved successfully\n";

        up2.Reset(new double(2.71));
        assert(*up2 == 2.71);
        std::cout << "Test 3 passed: UniquePointer<double> reset successfully\n";
    }
    //---Long tests---
    {
        UniquePointer<long> up1(new long(1234567890L));
        assert(*up1 == 1234567890L);
        std::cout << "Test 4 passed: UniquePointer<long> created successfully\n";

        UniquePointer<long> up2 = std::move(up1);
        assert(up1.Get() == nullptr);
        assert(*up2 == 1234567890L);
        std::cout << "Test 5 passed: UniquePointer<long> moved successfully\n";

        up2.Reset(new long(9876543210L));
        assert(*up2 == 9876543210L);
        std::cout << "Test 6 passed: UniquePointer<long> reset successfully\n";
    }
}

void TestSharedPointer()
{
    std::cout << "Shared pointer tests:\n";
    //---Double tests---
    {
        SharedPointer<double> sp1(new double(2.71));
        assert(*sp1 == 2.71);
        assert(sp1.UseCount() == 1);
        std::cout << "Test 1 passed: SharedPointer<double> created successfully\n";

        SharedPointer<double> sp2 = sp1;
        assert(sp1.UseCount() == 2);
        assert(sp2.UseCount() == 2);
        assert(*sp2 == 2.71);
        std::cout << "Test 2 passed: SharedPointer<double> copied successfully\n";

        SharedPointer<double> sp3 = std::move(sp1);
        assert(sp1.Get() == nullptr);
        assert(sp3.UseCount() == 2);
        assert(*sp3 == 2.71);
        std::cout << "Test 3 passed: SharedPointer<double> moved successfully\n";
    }
    //---Long tests---
    {
        SharedPointer<long> sp1(new long(1234567890L));
        assert(*sp1 == 1234567890L);
        assert(sp1.UseCount() == 1);
        std::cout << "Test 4 passed: SharedPointer<long> created successfully\n";

        SharedPointer<long> sp2 = sp1;
        assert(sp1.UseCount() == 2);
        assert(sp2.UseCount() == 2);
        assert(*sp2 == 1234567890L);
        std::cout << "Test 5 passed: SharedPointer<long> copied successfully\n";

        SharedPointer<long> sp3 = std::move(sp1);
        assert(sp1.Get() == nullptr);
        assert(sp3.UseCount() == 2);
        assert(*sp3 == 1234567890L);
        std::cout << "Test 6 passed: SharedPointer<long> moved successfully\n";
    }
}

void AllSmartPointerTest()
{
    TestUniquePointer();
    TestSharedPointer();
}
