#pragma  once
#include <stdexcept>
#include "BaseCollection.h"


template <class T>
class Sequence
{
public:
    //---Virtual destructor---
    virtual ~Sequence() = default;
    //---Getters---
    virtual T &GetFirst() const = 0;
    virtual T &GetLast() const = 0;
    virtual T &Get(int index) const = 0;
    [[nodiscard]] virtual int GetLength() const = 0;
    virtual const BaseCollection<T> &GetDataHolder() const = 0;
    //---Setters---
    virtual Sequence<T> &Set(const T &value, int index) = 0;
    //---Other methods---
    virtual Sequence<T> &Prepend(const T &item) = 0;
    virtual Sequence<T> &Append(const T &item) = 0;
    virtual Sequence<T> &InsertAt(const T &item, int index) = 0;
    virtual Sequence<T> &RemoveFirst() = 0;
    virtual Sequence<T> &RemoveLast() = 0;
    virtual Sequence<T> &Erase(int index) = 0;
    //---Map-reduce---
    virtual Sequence<T> &GetSubSequence(int startIndex, int endIndex) = 0;
    virtual Sequence<T> &Map(T (*function)(const T &argument)) = 0;
    virtual Sequence<T> &Where(bool (*condition)(const T &argument)) = 0;
    virtual T Reduce(T (*function)(const T &leftArgument, const T &rightArgument), const T &initialValue) = 0;
    //P.S. concat has separate implementation
};
