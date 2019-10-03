#include "lab2.hpp"
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


int task1()
{
	srand(time(NULL));
	List lst;
	int n = 1000;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = (unsigned char)rand();
	}


	for (int i = 0; i < n; i++)
	{
		if (sqrt(arr[i]) - (unsigned char)sqrt(arr[i]) == 0)
		{
			lst.push_back(arr[i]);			//Запись в список полных квадратов
		}
		i++;
	}


	int arr_buf[n];
	fill_n(arr_buf, n, -1);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		if (lst.repeat_check(lst[i], arr_buf) == 1)
		{
			lst.removeAt(i);						//удаление одинаковых элементов списка
			i--;
		}
	}

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	delete [] arr;

	return 0;
}


int main()
{

	List lst;
	lst.push_front(5);
	lst.push_front(7);
	lst.push_front(101);
	lst.push_back(13);
	lst.push_back(26);
	lst.push_back(45);
	lst.push_front(1);

	cout <<"Found element: "<< lst[1] << endl;

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "pop_back " << endl;
	lst.pop_back();

	cout << endl << "insert 1337" << endl << endl;
	lst.insert(1337, 3);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "splice 1337" << endl << endl;
	lst.splice(3, 1);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	lst.removeAt(1);
	cout << endl << "removeAt 2 element" << endl;
	cout << endl;

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl;
	cout << "print '1' for task" << endl;
	int choice = 0;

	cin >> choice;

	if (choice == 1)
	{
		lst.clear();
		system("clear");
		task1();
	}
	else
	{
		return 0;
	}
}
