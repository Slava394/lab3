#pragma once


template <class T>
class SharedPointer
{
private:
    //---Default pointer---
    T* pointer;
    unsigned* referenceCountPointer;
    //---Decomposition---
    void Release()
    {
        if (referenceCountPointer)
        {
            --(*referenceCountPointer);
            if (*referenceCountPointer == 0)
            {
                delete pointer;
                delete referenceCountPointer;
            }
        }
    }
public:
    //---Constructors---
    explicit SharedPointer(T* newPointer = nullptr) : pointer(newPointer)
    {
        if (newPointer)
        {
            referenceCountPointer = new unsigned{1};
        }
        else
        {
            referenceCountPointer = nullptr;
        }
    }
    SharedPointer(const SharedPointer& otherSharedPointer) :
            pointer(otherSharedPointer.pointer),
            referenceCountPointer(otherSharedPointer.referenceCountPointer)
    {
        if (referenceCountPointer)
        {
            ++(*referenceCountPointer);
        }
    }
    SharedPointer& operator=(const SharedPointer& otherSharedPointer)
    {
        if (this != &otherSharedPointer)
        {
            Release();
            pointer = otherSharedPointer.pointer;
            referenceCountPointer = otherSharedPointer.referenceCountPointer;
            if (referenceCountPointer)
            {
                ++(*referenceCountPointer);
            }
        }
        return *this;
    }
    SharedPointer(SharedPointer&& otherSharedPointer) noexcept :
            pointer(otherSharedPointer.pointer),
            referenceCountPointer(otherSharedPointer.referenceCountPointer)
    {
        otherSharedPointer.pointer = nullptr;
        otherSharedPointer.referenceCountPointer = nullptr;
    }
    SharedPointer& operator=(SharedPointer&& otherSharedPointer) noexcept
    {
        if (this != &otherSharedPointer)
        {
            Release();
            pointer = otherSharedPointer.pointer;
            referenceCountPointer = otherSharedPointer.referenceCountPointer;
            otherSharedPointer.pointer = nullptr;
            otherSharedPointer.reference = nullptr;
        }
        return *this;
    }
    //---Destructor---
    ~SharedPointer()
    {
        Release();
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
    explicit operator bool() const
    {
        return pointer != nullptr;
    }
    //---Methods---
    T* Get() const
    {
        return pointer;
    }
    [[nodiscard]] unsigned UseCount() const
    {
        return referenceCountPointer ? *referenceCountPointer : 0;
    }
};
