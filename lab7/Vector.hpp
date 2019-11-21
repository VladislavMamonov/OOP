#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "set.hpp"
#include <iostream>

using namespace std;

template <typename T>
class Vector : public List<T>
{
public:
    using List<T>::Head;
    using List<T>::Size;

    Vector() {
      Size = 0;
      Head = nullptr;
    }
    ~Vector() {
      while (Size > 0) {
        pop_back();
      }
    }

    void push(T data1, int data2, int index)
    {
        if (this->Head == nullptr) {
          index = 0;
        }

        if (index == 0 && Head != nullptr) {
          Head = new DoubleNode<T>(data1, data2, Head);
        }

        else if (index == 0 && Head == nullptr) {
            Head = new DoubleNode<T>(data1, data2);
        } else {
            DoubleNode<T>* previous = Head;
            DoubleNode<T>* next = Head;

            for (int i = 0; i < index - 1; i++) {
                previous = previous->pNext;
            }

            for (int i = 0; i < index; i++) {
                next = next->pNext;
            }

            if (previous->pNext != nullptr) {   //исключение для добавления в конец
                DoubleNode<T>* newNode = new DoubleNode<T>(data1, data2, previous->pNext, previous);
                previous->pNext = newNode;
                next->pPrev = newNode;
            } else {
                push_back(data1, data2);
            }
        }
        this->Size++;
    }

    void pop(int index)
    {
        if (index == 0) {
            pop_front();
        } else {
            DoubleNode<T>* previous = this->Head;
            DoubleNode<T>* next = this->Head;

            for (int i = 0; i < index - 1; i++) {
                previous = previous->pNext;
            }

            for (int i = 0; i < index; i++) {
                next = next->pNext;
            }

            DoubleNode<T>* toDelete = previous->pNext;

            previous->pNext = toDelete->pNext;
            next->pPrev = previous;

            delete toDelete;
            this->Size--;
        }
    }

    T& operator[](const int index)
    {
        int counter = 0;

        DoubleNode<T>* current = this->Head;

        while (current->pNext != nullptr) {
            if (counter == index) {
                cout << "Стоимость: " << current->data2 << endl;
                this->cost = current->data2;
                return current->data1;
            }
            current = current->pNext;
            counter++;
        }
        if (index > counter) {
            while (index != counter) {
                T data;
                cout << "element to add: ";
                cin >> data;
                push(data, 0, this->GetSize() - 1);
                Size--;
                counter++;
            }
            current = this->Head;
            counter = 0;

            while (current->pNext != nullptr) {
                if (counter == index) {
                    cout << "Стоимость: " << current->data2 << endl;
                    this->cost = current->data2;
                    return current->data1;
                }
                current = current->pNext;
                counter++;
            }
        }
        cout << "Стоимость: " << current->data2 << endl;
        this->cost = current->data2;
        return current->data1;
    }

    int GetData2(const int index)
    {
      int counter = 0;

      DoubleNode<T>* current = this->Head;

      while (current->pNext != nullptr) {
          if (counter == index) {
              this->cost = current->data2;
              return current->data2;
          }
          current = current->pNext;
          counter++;
      }
      this->cost = current->data2;
      return current->data2;
    }

    int search(T data1)
    {
        int index = 0;

        if (this->Head == nullptr) {
            cout << "vector is empty";
            cout << endl;
            return -1;
        } else {
            DoubleNode<T>* current = this->Head;

            if (current->data1 == data1) {
              this->cost = current->data2;
              return index;
            }

            while (current->pNext != nullptr) {
                current = current->pNext;
                index++;
                if (current->data1 == data1) {
                    this->cost = current->data2;
                    return index;
                }
            }
            if (current->pNext == nullptr) {
                return -1;
            }
        }
        return -1;
    }

private:
  void push_back(T data1, int data2)
  {
      if (this->Head == nullptr) {
          Head = new DoubleNode<T>(data1, data2);
      } else {
          DoubleNode<T>* current = this->Head;

          while (current->pNext != nullptr) {
              current = current->pNext;
          }
          current->pNext = new DoubleNode<T>(data1, data2, nullptr, current);
      }
  }

  void pop_front()
  {
      DoubleNode<T>* temp = Head;
      if (Head->pNext == nullptr) {
        delete temp;
        this->Size--;
        return;
      }

      Head = Head->pNext;
      Head->pPrev = nullptr;

      delete temp;
      this->Size--;
  }

  void pop_back()
  {
      DoubleNode<T>* temp = Head;
      DoubleNode<T>* previous = Head;

      if (previous->pNext == nullptr) {
          delete temp;
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
};

#endif
