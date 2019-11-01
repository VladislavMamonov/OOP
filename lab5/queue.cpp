#include "set.hpp"

void Queue::push(int data)
{
  if (head == nullptr)
  {
    head = new Node(data);
  }
  else
  {
    Node *current = this->head;

    while (current->pNext != nullptr)
    {
      current = current->pNext;
    }
    current->pNext = new Node(data);
  }
  Size++;
}

void Queue::pop()
{
  Node *temp = head;
  head = head->pNext;

  delete temp;
  Size--;
}

int &Queue::operator[](const int index)
{
	int counter = 0;

	Node *current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
	return current->data;
}
