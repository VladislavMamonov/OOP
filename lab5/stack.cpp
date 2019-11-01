#include "set.hpp"

void Stack::push(int data)
{
  head = new Node(data, head);
  Size++;
}

void Stack::pop()
{
  Node *temp = head;
  head = head->pNext;

  delete temp;
  Size--;
}

int &Stack::operator[](const int index)
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
