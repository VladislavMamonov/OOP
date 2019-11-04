#ifndef SET_HPP
#define SET_HPP

#include <iostream>

using namespace std;

class List
{
public:
  ~List();

   virtual void push(int data) = 0;
   virtual void pop() = 0;
   virtual int& operator[](const int index) = 0;

   int GetSize() {
     return Size;
   }

   //Очистка списка
   void clear();

protected:
	class Node     //Односвязный список
	{
	public:
		Node *pNext;
		int data;

		Node(int data, Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node *head;

  class DoubleNode    //Двусвязный список
  {
  public:
    DoubleNode *pNext, *pPrev;
    int data;
    DoubleNode(int data, DoubleNode *pNext = nullptr, DoubleNode *pPrev = nullptr) {
      this->data = data;
      this->pNext = pNext;
      this->pPrev = pPrev;
    }
  };
  DoubleNode *Head;
};


class Stack : public List
{
public:
  Stack() {
    this->Size = 0;
    this->head = nullptr;
  }
  ~Stack() {
    clear();
  }

  void push(int data) override;
  void pop() override;
  int &operator[](const int index) override;
};


class Queue : public List
{
public:
  Queue() {
    this->Size = 0;
    this->head = nullptr;
  }
  ~Queue() {
    this->clear();
  }

  void push(int data) override;
  void pop() override;
  int &operator[](const int index) override;
};


class Vector : public List
{
public:
  Vector() {
    this->Size = 0;
    this->Head = nullptr;
  }
  ~Vector() {
    while (this->Size > 0) {
      pop_back();
    }
  }

  void push(int data) override;
  void pop() override;
  int &operator[](const int index) override;

  int search(int data);

private:
  void pop_front();
  void pop_back();
  void push_back(int data);
};

#endif
