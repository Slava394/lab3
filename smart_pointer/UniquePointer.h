#pragma once


template <class T>
class UniquePointer
{
private:
    //---Default pointer---
    T* pointer;
public:
    //---Constructors---
    explicit UniquePointer(T* newPointer = nullptr) : pointer(newPointer) {}
    UniquePointer(const UniquePointer<T>&) = delete;
    UniquePointer& operator=(const UniquePointer<T>&) = delete;
    UniquePointer(UniquePointer<T>&& otherUniquePointer) noexcept : pointer(otherUniquePointer.pointer)
    {
        otherUniquePointer.pointer = nullptr;
    }
    UniquePointer& operator=(UniquePointer<T>&& otherUniquePointer) noexcept
    {
        if (this != otherUniquePointer)
        {
            delete pointer;
            pointer = otherUniquePointer.pointer;
            otherUniquePointer.pointer = nullptr;
        }
        return *this;
    }
    //---Destructor---
    ~UniquePointer()
    {
        delete pointer;
    }
    //---Operator overloading---
    T& operator*() const
    {
        return *pointer;
    }
    T* operator->() const
    {
        return pointer;
    }
    //---Methods---
    T* Get() const
    {
        return pointer;
    }
    T* Release()
    {
        T *temp = pointer;
        pointer = nullptr;
        return temp;
    }
    void Reset(T* newPointer = nullptr)
    {
        delete pointer;
        pointer = newPointer;
    }
};
