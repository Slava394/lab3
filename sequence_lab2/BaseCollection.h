#pragma once


//P.S. for copy constructor DynamicArray <-> LinkedList
template <class T>
class BaseCollection
{
public:
    //---Virtual destructor---
    virtual T &Get(int index) const = 0;
    //---Getters---
    [[nodiscard]] virtual int GetSize() const = 0;
};
