#ifndef SET_HPP
#define SET_HPP

using namespace std;

template <typename T>
class Node
{
public:
    Node<T>* pNext;
    T data;

    Node(T data, Node* pNext = nullptr)
    {
        this->data = data;
        this->pNext = pNext;
    }
};

template <typename T>
class DoubleNode
{
public:
    DoubleNode<T>*pNext, *pPrev;
    T data;
    DoubleNode(T data, DoubleNode* pNext = nullptr, DoubleNode* pPrev = nullptr)
    {
        this->data = data;
        this->pNext = pNext;
        this->pPrev = pPrev;
    }
};

template <typename T>
class List
{
public:
    virtual void push(T data)
    {
        return;
    }
    virtual void pop()
    {
        return;
    }
    virtual T& operator[](const int index)
    {
        T* arg;
        return *arg;
    }

    int GetSize()
    {
        return Size;
    }

protected:
    int Size;
    Node<T>* head;

    DoubleNode<T>* Head;
};

#endif
