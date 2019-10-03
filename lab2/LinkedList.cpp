#include "lab2.hpp"


void List::pop_front()
{
	Node *temp = head;

	head = head->pNext;

	delete temp;

	Size--;
}

void List::push_back(int data)
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

void List::clear()
{
	while (Size > 0)
	{
		pop_front();
	}
}

int & List::operator[](const int index)
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

void List::push_front(int data)
{
	head = new Node(data, head);
	Size++;
}

void List::insert(int data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;		//указатель на следующий узел нового узла
		}

		Node *newNode = new Node(data, previous->pNext);

		previous->pNext = newNode;	//указатель на новый узел

		Size++;
	}

}

void List::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node *toDelete = previous->pNext;  //фиксируем указатель на удаляемый узел

		previous->pNext = toDelete->pNext;		//устанавливаем указатель предыдущего узла за удаляемым на следующий после удаляемого

		delete toDelete;

		Size--;
	}
}

void List::splice(int indexSrc, int indexDest)
{
	if (Size == 0)
	{
		return;
	}

	if (indexDest == 0)
	{
		return;
	}
	else
	{
		Node *previousSrc = this->head;
		Node *previousDest = this->head;

		for (int i = 0; i < indexSrc - 1; i++)		//Работа с указателями для места откуда начат перенос
		{
			previousSrc = previousSrc->pNext;
		}
		Node *newNode = previousSrc->pNext;

		previousSrc->pNext = newNode->pNext;



		for (int i = 0; i < indexDest - 1; i++)		//Работа с указателями для места назначения переноса
		{
			previousDest = previousDest->pNext;
		}
		Node *temp = previousDest->pNext;

		previousDest->pNext = newNode;
		newNode->pNext = temp;
	}
}


void List::pop_back()
{
	removeAt(Size - 1);
}

List::List()
{
	Size = 0;
	head = nullptr;
}

List::~List()
{
	clear();
}

int List::repeat_check(int data, int *arr)
{
	 int n = 1000;
	 for (int i = 0; i < n; i++)
	 {
		 if (arr[i] == data)
		 {
			 return 1;
		 }
		 if (arr[i] == -1)
		 {
			 arr[i] = data;
			 return 0;
		 }
	 }
	 return 0;
}
