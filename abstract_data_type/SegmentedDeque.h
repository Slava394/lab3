#pragma once
#include <stdexcept>
#include "../sequence_lab2/ArraySequence.h"


class IndexPair
{
public:
    int segmentIndex;
    int elementIndex;
};


template <class T>
class SegmentedDeque
{
private:
    MutableArraySequence<MutableArraySequence<T>*> segments;
    int segmentSize;
    int totalSize;
    //---Decomposition---
    void CheckIndex(int index) const
    {
        if (index < 0 || index >= totalSize)
        {
            throw std::out_of_range("Index out of range");
        }
    }
    void MergeForSort(int leftIndex, int middleIndex, int rightIndex, bool (*compare)(const T&, const T&))
    {
        int leftSize = middleIndex - leftIndex + 1;
        int rightSize = rightIndex - middleIndex;
        SegmentedDeque<T> leftDeque(segmentSize);
        SegmentedDeque<T> rightDeque(segmentSize);
        for (int index = 0; index < leftSize; ++index)
        {
            leftDeque.Append(Get(leftIndex + index));
        }
        for (int index = 0; index < rightSize; ++index)
        {
            rightDeque.Append(Get(middleIndex + 1 + index));
        }
        int indexForLeftDeque = 0, indexForRightDeque = 0, indexForThisDeque = leftIndex;
        while (indexForLeftDeque < leftSize && indexForRightDeque < rightSize)
        {
            if (compare(leftDeque.Get(indexForLeftDeque), rightDeque.Get(indexForRightDeque)))
            {
                Set(leftDeque.Get(indexForLeftDeque), indexForThisDeque);
                indexForLeftDeque++;
            }
            else
            {
                Set(rightDeque.Get(indexForRightDeque), indexForThisDeque);
                indexForRightDeque++;
            }
            indexForThisDeque++;
        }
        while (indexForLeftDeque < leftSize)
        {
            Set(leftDeque.Get(indexForLeftDeque), indexForThisDeque);
            indexForLeftDeque++;
            indexForThisDeque++;
        }
        while (indexForRightDeque < rightSize)
        {
            Set(rightDeque.Get(indexForRightDeque), indexForThisDeque);
            indexForRightDeque++;
            indexForThisDeque++;
        }
    }
    [[nodiscard]] IndexPair GetSegmentAndElementIndex(int index) const
    {
        if (index < 0 || index >= totalSize)
        {
            throw std::out_of_range("Index out of range");
        }
        int resultIndex = 0;
        for (int currentSegmentIndex = 0; currentSegmentIndex < segments.GetLength(); ++currentSegmentIndex)
        {
            int currentSegmentSize = segments.Get(currentSegmentIndex)->GetLength();
            if (resultIndex + currentSegmentSize > index)
            {
                IndexPair result{currentSegmentIndex, index - resultIndex};
                return result;
            }
            resultIndex += currentSegmentSize;
        }
        throw std::out_of_range("Index out of range");
    }
public:
    //---Constructors---
    explicit SegmentedDeque(int segmentSize = 10) :
            segments(MutableArraySequence<MutableArraySequence<T>*>()),
            segmentSize(segmentSize),
            totalSize(0)
    {
        segments.Append(new MutableArraySequence<T>());
    }
    SegmentedDeque(const SegmentedDeque<T>& otherDeque) :
            segments(MutableArraySequence<MutableArraySequence<T>*>()),
            segmentSize(otherDeque.segmentSize),
            totalSize(0)
    {
        for (int index{0}; index < otherDeque.GetLength(); ++index)
        {
            Append(otherDeque.Get(index));
        }
    }
    //---Destructor---
    ~SegmentedDeque()
    {
        for (int index{0}; index < segments.GetLength(); ++index)
        {
            delete segments.Get(index);
        }
    }
    //---Getters---
    T& Get(int index) const
    {
        CheckIndex(index);
        IndexPair indexPair = GetSegmentAndElementIndex(index);
        int segmentIndex = indexPair.segmentIndex;
        int elementIndex = indexPair.elementIndex;
        return segments.Get(segmentIndex)->Get(elementIndex);
    }
    T& GetFirst() const
    {
        if (totalSize == 0)
        {
            throw std::out_of_range("Deque is empty");
        }
        return segments.Get(0)->GetFirst();
    }
    T& GetLast() const
    {
        if (totalSize == 0)
        {
            throw std::out_of_range("Deque is empty");
        }
        return segments.Get(segments.GetLength() - 1)->GetLast();
    }
    [[nodiscard]] int GetLength() const
    {
        return totalSize;
    }
    //---Setters---
    void Set(const T& value, int index)
    {
        CheckIndex(index);
        IndexPair indexPair = GetSegmentAndElementIndex(index);
        int segmentIndex = indexPair.segmentIndex;
        int elementIndex = indexPair.elementIndex;
        segments.Get(segmentIndex)->Set(value, elementIndex);
    }
    //---Other methods---
    void Prepend(const T& item)
    {
        MutableArraySequence<T>* firstSegment = segments.Get(0);
        if (firstSegment->GetLength() >= segmentSize)
        {
            firstSegment = new MutableArraySequence<T>();
            segments.Prepend(firstSegment);
        }
        firstSegment->Prepend(item);
        ++totalSize;
    }
    void Append(const T& item)
    {
        MutableArraySequence<T>* lastSegment = segments.Get(segments.GetLength() - 1);
        if (lastSegment->GetLength() >= segmentSize)
        {
            lastSegment = new MutableArraySequence<T>();
            segments.Append(lastSegment);
        }
        lastSegment->Append(item);
        ++totalSize;
    }
    void InsertAt(const T& value, int index) {
        if (index < 0 || index > totalSize)
        {
            throw std::out_of_range("Index out of range");
        }
        int segmentIndex, elementIndex;
        if (index == totalSize)
        {
            segmentIndex = segments.GetLength() - 1;
            elementIndex = segments.GetLast()->GetLength();
        }
        else
        {
            IndexPair indexPair = GetSegmentAndElementIndex(index);
            segmentIndex = indexPair.segmentIndex;
            elementIndex = indexPair.elementIndex;
        }
        MutableArraySequence<T>* currentSegment = segments.Get(segmentIndex);
        if (currentSegment->GetLength() < segmentSize)
        {
            currentSegment->InsertAt(value, elementIndex);
        }
        else
        {
            auto* newSegment = new MutableArraySequence<T>();
            for (int newIndex = elementIndex; newIndex < currentSegment->GetLength(); ++newIndex)
            {
                newSegment->Append(currentSegment->Get(newIndex));
            }
            while (currentSegment->GetLength() > elementIndex)
            {
                currentSegment->RemoveLast();
            }
            currentSegment->Append(value);
            segments.InsertAt(newSegment, segmentIndex + 1);
        }
        ++totalSize;
    }
    void RemoveFirst()
    {
        if (totalSize == 0)
        {
            throw std::out_of_range("Deque is empty");
        }
        MutableArraySequence<T>* firstSegment = segments.Get(0);
        firstSegment->RemoveFirst();
        if (firstSegment->GetLength() == 0 && segments.GetLength() > 1)
        {
            delete firstSegment;
            segments.RemoveFirst();
        }
        --totalSize;
    }
    void RemoveLast()
    {
        if (totalSize == 0)
        {
            throw std::out_of_range("Deque is empty");
        }
        MutableArraySequence<T>* lastSegment = segments.Get(segments.GetLength() - 1);
        lastSegment->RemoveLast();
        if (lastSegment->GetLength() == 0 && segments.GetLength() > 1)
        {
            delete lastSegment;
            segments.RemoveLast();
        }
        --totalSize;
    }
    void Erase(int index)
    {
        CheckIndex(index);
        IndexPair indexPair = GetSegmentAndElementIndex(index);
        int segmentIndex = indexPair.segmentIndex;
        int elementIndex = indexPair.elementIndex;
        segments.Get(segmentIndex)->Erase(elementIndex);
        if (segments.Get(segmentIndex)->GetLength() == 0 && segments.GetLength() > 1)
        {
            delete segments.Get(segmentIndex);
            segments.Erase(segmentIndex);
        }
        --totalSize;
    }
    //P.S. without copy
    void LazyConcat(SegmentedDeque<T>& otherSegmentedDeque)
    {
        for (int index{0}; index < otherSegmentedDeque.segments.GetLength(); ++index)
        {
            segments.Append(otherSegmentedDeque.segments.Get(index));
        }
        totalSize += otherSegmentedDeque.GetLength();
        otherSegmentedDeque.segments = MutableArraySequence<MutableArraySequence<T>*>();
        otherSegmentedDeque.totalSize = 0;
    }
    void Concat(SegmentedDeque<T>& otherSegmentedDeque)
    {
        for (int index{0}; index < otherSegmentedDeque.GetLength(); ++index)
        {
            this->Append(otherSegmentedDeque.Get(index));
        }
    }
    SegmentedDeque<T>& GetSubSequence(int startIndex, int endIndex)
    {
        CheckIndex(startIndex);
        if (endIndex < 0 || endIndex > totalSize)
        {
            throw std::out_of_range("Index out of range");
        }
        if (startIndex >= endIndex)
        {
            throw std::logic_error("EndIndex can`t be less then startIndex");
        }
        auto* subDeque = new SegmentedDeque<T>(segmentSize);
        for (int index{startIndex}; index <= endIndex; ++index)
        {
            subDeque->Append(this->Get(index));
        }
        return *subDeque;
    }
    //P.S. sort and merge need a comparator
    void MergeSort(int leftIndex, int rightIndex, bool (*compare)(const T&, const T&))
    {
        if (leftIndex >= rightIndex)
        {
            return;
        }
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        MergeSort(leftIndex, middleIndex, compare);
        MergeSort(middleIndex + 1, rightIndex, compare);
        MergeForSort(leftIndex, middleIndex, rightIndex, compare);
    }
    void Merge(SegmentedDeque<T>& otherSegmentedDeque, bool (*compare)(const T&, const T&))
    {
        SegmentedDeque<T> mergedDeque(segmentSize);
        int leftIndex = 0, rightIndex = 0;
        while (leftIndex < GetLength() && rightIndex < otherSegmentedDeque.GetLength())
        {
            if (compare(Get(leftIndex), otherSegmentedDeque.Get(rightIndex)))
            {
                mergedDeque.Append(Get(leftIndex));
                leftIndex++;
            }
            else
            {
                mergedDeque.Append(otherSegmentedDeque.Get(rightIndex));
                rightIndex++;
            }
        }
        while (leftIndex < GetLength())
        {
            mergedDeque.Append(Get(leftIndex));
            leftIndex++;
        }
        while (rightIndex < otherSegmentedDeque.GetLength())
        {
            mergedDeque.Append(otherSegmentedDeque.Get(rightIndex));
            rightIndex++;
        }
        *this = mergedDeque;
    }
    SegmentedDeque<T>* Map(T (*function)(const T&))
    {
        SegmentedDeque<T> result(segmentSize);
        for (int index{0}; index < totalSize; ++index)
        {
            T currentElement = Get(index);
            Set(function(currentElement), index);
        }
        return this;
    }
    SegmentedDeque<T> Where(bool (*condition)(const T&))
    {
        SegmentedDeque<T> resultDeque(segmentSize);
        for (int index{0}; index < totalSize; ++index)
        {
            if (condition(Get(index)))
            {
                resultDeque.Append(Get(index));
            }
        }
        return resultDeque;
    }
    T Reduce(T (*function)(const T&, const T&), const T& initValue)
    {
        T result = initValue;
        for (int index{0}; index < totalSize; ++index)
        {
            result = function(result, Get(index));
        }
        return result;
    }
};
