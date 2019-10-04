#include "lab2.hpp"

int & Stack::operator[](const int index)
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

int & Queue::operator[](const int index)
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
