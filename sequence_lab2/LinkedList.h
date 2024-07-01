#pragma once
#include <stdexcept>
#include "BaseCollection.h"


template <class T>
class LinkedList final : public BaseCollection<T>
{
private:
    //---Nested struct Node---
    struct Node
    {
        T data;
        Node *prevNode;
        Node *nextNode;

        Node() : data{T()}, nextNode{nullptr}, prevNode{nullptr} {}
        explicit Node(const T &value) : data(value), nextNode(nullptr), prevNode(nullptr) {}
    };
    Node *head;
    Node *tail;
    int length;
    //---Decomposition---
    void CopyFrom(const LinkedList<T> &otherList)
    {
        Node *oldHead = head;
        Node *oldTail = tail;
        int oldLength = length;
        head = tail = nullptr;
        length = 0;
        Node *currentNode = otherList.head;
        try
        {
            while (currentNode) {
                Append(currentNode->data);
                currentNode = currentNode->nextNode;
            }
        }
        catch (...)
        {
            Clear();
            head = oldHead;
            tail = oldTail;
            length = oldLength;
            throw std::bad_alloc();
        }
        currentNode = oldHead;
        while (currentNode)
        {
            Node* nextNode = currentNode->nextNode;
            delete currentNode;
            currentNode = nextNode;
        }
    }
    void MoveFrom(LinkedList<T> &otherList)
    {
        head = otherList.head;
        tail = otherList.tail;
        length = otherList.length;
        otherList.head = otherList.tail = otherList.targetNode = nullptr;
        otherList.length = 0;
    }
    void CheckIndexRange(int index) const
    {
        if (index < 0 || index >= length)
        {
            throw std::out_of_range("Index out of range");
        }
    }
public:
    //---Constructors---
    LinkedList() : head{nullptr}, tail{nullptr}, length{0} {}
    explicit LinkedList(const T *items, int count) : head{nullptr}, tail{nullptr}, length{0}
    {
        if (count < 0)
        {
            throw std::invalid_argument("Can`t create list with negative length");
        }
        try
        {
            for (int index{0}; index < count; ++index)
            {
                Append(items[index]);
            }
        }
        catch (...)
        {
            Clear();
            throw std::bad_alloc();
        }
    }
    LinkedList(const LinkedList<T> &otherList) : head{nullptr}, tail{nullptr}, length{0}
    {
        CopyFrom(otherList);
    }
    explicit LinkedList(const BaseCollection<T> &dynamicArray) : head{nullptr},
                                                                 tail{nullptr},
                                                                 length{0}
    {
        try
        {
            for (int index{0}; index < dynamicArray.GetSize(); ++index)
            {
                Append(dynamicArray.Get(index));
            }
        }
        catch (...)
        {
            Clear();
            throw std::bad_alloc();
        }
    }
    LinkedList(LinkedList &&otherList) noexcept : head{nullptr}, tail{nullptr}, length{0}
    {
        MoveFrom(otherList);
    }
    //---Operator overloading---
    LinkedList<T> &operator=(const LinkedList<T> &otherList)
    {
        if (this != &otherList)
        {
            CopyFrom(otherList);
        }
        return *this;
    }
    LinkedList<T> &operator=(LinkedList<T> &&otherList) noexcept
    {
        if (this != &otherList)
        {
            Clear();
            MoveFrom(otherList);
        }
        return *this;
    }
    const T &operator[](int index)
    {
        return Get(index);
    }
    LinkedList<T> &operator+=(LinkedList<T> &otherList)
    {
        Concat(otherList);
        return *this;
    }
    //---Destructor---
    ~LinkedList()
    {
        Clear();
    }
    //---Getters---
    T &GetFirst() const
    {
        if (length == 0)
        {
            throw std::invalid_argument("Can`t get first element from an empty list");
        }
        return head->data;
    }
    T &GetLast() const
    {
        if (length == 0)
        {
            throw std::invalid_argument("Can`t get last element from an empty list");
        }
        return tail->data;
    }
    T &Get(int index) const override
    {
        CheckIndexRange(index);
        Node *currentNode;
        if (index < length / 2)
        {
            currentNode = head;
            for (int newIndex{0}; newIndex < index; ++newIndex)
            {
                currentNode = currentNode->nextNode;
            }
        }
        else
        {
            currentNode = tail;
            for (int newIndex{length - 1}; newIndex > index; --newIndex)
            {
                currentNode = currentNode->prevNode;
            }
        }
        return currentNode->data;
    }
    [[nodiscard]] int GetSize() const override
    {
        return length;
    }
    //---Setters---
    void Set(const T &value, int index)
    {
        CheckIndexRange(index);
        Node *currentNode = head;
        for (int indexCount{0}; indexCount < index; ++indexCount)
        {
            currentNode = currentNode->nextNode;
        }
        currentNode->data = value;
    }
    //---Other methods---
    LinkedList<T> &GetSubList(int startIndex, int endIndex)
    {
        CheckIndexRange(startIndex);
        if (endIndex < 0 || endIndex > length)
        {
            throw std::out_of_range("Index out of range");
        }
        if (startIndex >= endIndex)
        {
            throw std::logic_error("EndIndex can`t be less then startIndex");
        }
        auto *subsequence = new LinkedList<T>();
        try
        {
            for (int index{startIndex}; index < endIndex; ++index)
            {
                subsequence->Append(Get(index));
            }
        }
        catch (...)
        {
            delete subsequence;
            throw std::bad_alloc();
        }
        return *subsequence;
    }
    void Concat(LinkedList<T> &otherList)
    {
        Node *oldTail = tail;
        Node *currentNode = otherList.head;
        try
        {
            while (currentNode)
            {
                Append(currentNode->data);
                currentNode = currentNode->nextNode;
            }
        }
        catch (...)
        {
            tail = oldTail;
            currentNode = oldTail->nextNode;
            while (currentNode)
            {
                Node *nextNode = currentNode->nextNode;
                delete currentNode;
                currentNode = nextNode;
            }
            throw std::bad_alloc();
        }
    }
    void InsertAt(const T &value, int index)
    {
        if (index < 0 || index > length)
        {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0)
        {
            Prepend(value);
            return;
        }
        if (index == length)
        {
            Append(value);
            return;
        }
        Node *currentNode = head;
        for (int indexCount{0}; indexCount < index; ++indexCount)
        {
            currentNode = currentNode->nextNode;
        }
        Node *prevNode = currentNode->prevNode;
        Node *newNode = new Node(value);
        prevNode->nextNode = newNode;
        newNode->prevNode = prevNode;
        currentNode->prevNode = newNode;
        newNode->nextNode = currentNode;
        length++;
    }
    void Erase(int index)
    {
        CheckIndexRange(index);
        if (index == 0)
        {
            RemoveFirst();
            return;
        }
        if (index == length - 1)
        {
            RemoveLast();
            return;
        }
        Node *currentNode = head, *prevNode, *nextNode;
        for (int indexCount{0}; indexCount < index; ++indexCount)
        {
            currentNode = currentNode->nextNode;
        }
        prevNode = currentNode->prevNode;
        nextNode = currentNode->nextNode;
        delete currentNode;
        prevNode->nextNode = nextNode;
        nextNode->prevNode = prevNode;
        length--;
    }
    void Prepend(const T &value)
    {
        Node* newNode = new Node(value);
        if (head)
        {
            head->prevNode = newNode;
            newNode->nextNode = head;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
        length++;
    }
    void Append(const T &value)
    {
        Node* newNode = new Node(value);
        if (tail)
        {
            tail->nextNode = newNode;
            newNode->prevNode = tail;
        }
        else
        {
            head = newNode;
        }
        tail = newNode;
        length++;
    }
    void RemoveFirst()
    {
        if (!head)
        {
            throw std::out_of_range("Can`t remove first element from an empty list");
        }
        Node* removingNode = head;
        head = head->nextNode;
        if (head)
        {
            head->prevNode = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete removingNode;
        length--;
    }
    void RemoveLast()
    {
        if (!tail)
        {
            throw std::out_of_range("Can`t remove last element from an empty list");
        }
        Node* removingNode = tail;
        tail = tail->prevNode;
        if (tail)
        {
            tail->nextNode = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete removingNode;
        length--;
    }
    void Clear()
    {
        Node *currentNode = head;
        while (currentNode)
        {
            Node* nextNode = currentNode->nextNode;
            delete currentNode;
            currentNode = nextNode;
        }
        head = tail = nullptr;
        length = 0;
    }
};
