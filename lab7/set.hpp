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
    T data1;
    int data2;
    DoubleNode(T data1, int data2, DoubleNode* pNext = nullptr, DoubleNode* pPrev = nullptr)
    {
        this->data2 = data2;
        this->data1 = data1;
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
    virtual void pop(int index)
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

    int GetCost()
    {
      return cost;
    }

protected:
    int Size, cost;
    Node<T>* head;

    DoubleNode<T>* Head;
};

#endif
