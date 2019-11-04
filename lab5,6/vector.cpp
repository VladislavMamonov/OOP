#include "set.hpp"
#include <iostream>

using namespace std;

void Vector::push(int data)
{
  int index;

  cout << "Position to add: ";
  cin >> index;

  if (this->Head == nullptr) {
    index = 0;
  }

  if (index == 0 && this->Head != nullptr) {
    Head = new DoubleNode(data, Head);
  }
  else if (index == 0 && this->Head == nullptr) {
    Head = new DoubleNode(data);
  }
  else {
    DoubleNode *previous = this->Head;
    DoubleNode *next = this->Head;

    for (int i = 0; i < index - 1; i++) {
      previous = previous->pNext;		//указатель на предыдущий узел нового узла
    }

    for (int i = 0; i < index; i++) {
      next = next->pNext;
    }


    if (previous->pNext != nullptr) {
      DoubleNode *newNode = new DoubleNode(data, previous->pNext, previous);
      previous->pNext = newNode;	//указатель на новый узел
      next->pPrev = newNode;
    }
    else {      //обработка добавления элемента в конец списка
      push_back(data);
    }
  }
  this->Size++;
}


void Vector::pop()
{
  int index;

  cout << "Position to delete: ";
  cin >> index;

  if (index == 0) {
		pop_front();
	}
	else {
		DoubleNode *previous = this->Head;
		DoubleNode *next = this->Head;

		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

    for (int i = 0; i < index; i++) {
      next = next->pNext;
    }

		DoubleNode *toDelete = previous->pNext;  //фиксируем указатель на удаляемый узел

    previous->pNext = toDelete->pNext;		//устанавливаем указатель предыдущего узла за удаляемым на следующий после удаляемого
    next->pPrev = previous;

		delete toDelete;
		this->Size--;
  }
}


void Vector::pop_front()
{
  DoubleNode *temp = Head;

  Head = Head->pNext;
  Head->pPrev = nullptr;

  delete temp;
  this->Size--;
}


void Vector::pop_back()
{
  DoubleNode *temp = Head;
  DoubleNode *previous = Head;

  if (previous->pNext == nullptr) {   //Исключение для ситуации,
    delete temp;                      //когда последний элемент голова
    this->Size--;
    return;
  }

  while (temp->pNext != nullptr) {
    temp = temp->pNext;
  }

  while (previous->pNext != temp) {
    previous = previous->pNext;
  }

  previous->pNext = nullptr;
  temp->pPrev = nullptr;

  delete temp;
  this->Size--;
}


void Vector::push_back(int data)
{
  if (this->Head == nullptr)
  {
    Head = new DoubleNode(data);
  }
  else
  {
    DoubleNode *current = this->Head;

    while (current->pNext != nullptr)
    {
      current = current->pNext;
    }
    current->pNext = new DoubleNode(data, nullptr, current);
  }
}


int & Vector::operator[](const int index)
{
  int counter = 0;

  DoubleNode *current = this->Head;

  while (current != nullptr)
  {
    if (counter == index)
    {
      return current->data;
    }
    current = current->pNext;
    counter++;
  }
  if (index > counter) {
    while (index != counter) {
      int data;
      cout << "element to add: ";
      cin >> data;
      this->push(data);
      counter++;
    }
  }
}


int Vector::search(int data)
{
  int index = 0;

  if (this->Head == nullptr) {
    cout << "vector is empty";
  }
  else {
    DoubleNode *current = this->Head;

    while (current->pNext != nullptr) {
      current = current->pNext;
      index++;
      if (current->data == data) {
        cout << "item index: " << index << endl;
        return current->data;
      }
    }
    if (current->pNext == nullptr) {
      cout << "could not find item" << endl;
    }
  }
  return 1;
}
