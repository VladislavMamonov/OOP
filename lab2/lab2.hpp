#ifndef LAB2_HPP
#define LAB2_HPP

class List
{
public:
	List();
	~List();

	//Удаление первого элемента
	void pop_front();

	//Добавление в конец
	void push_back(int data);

	//Очистка списка
	void clear();

	//Получение размера списка
	int GetSize() {
		 return Size;
	 }

	//Оператор для получения доступа к элементу списка
	int& operator[](const int index);

	//Добавление в начало
	void push_front(int data);

	//Добавление элемента по индексу
	void insert(int data, int index);

	//Удаление элемента по индексу
	void removeAt(int index);

	//Удаление последнего элемента
	void pop_back();

	//перенос элемента
	void splice(int indexSrc, int indexDest);

	//проверка на повтор элементов в связном списке
	int repeat_check(int data, int *arr);

private:
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


#endif
