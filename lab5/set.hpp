#ifndef SET_HPP
#define SET_HPP

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
	class Node
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
};


class Stack : public List
{
public:
  Stack() {
    Size = 0;
    head = nullptr;
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
    Size = 0;
    head = nullptr;
  }
  ~Queue() {
    clear();
  }

  void push(int data) override;
  void pop() override;
  int &operator[](const int index) override;
};

#endif
