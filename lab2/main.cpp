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

int task2()
{
	Stack stk;
	Queue turn;

	cout << "press '1' to add element in stack" << endl;
	cout << "press '2' to remove element from stack" << endl;
	cout << "press '3' to get stack info" << endl;
	cout << "press '4' to delete stack" << endl;

	for (int i = 0; stk.stack_size() != 10; i++) {
		cout << endl;
		cout << "selection: ";
		int choice;
		cin >> choice;

		if (choice == 1) {
			cout << "value: ";
			int user_data;
			cin >> user_data;
			stk.stack_push(user_data);
		}

		if (choice == 2) {
			if (stk.stack_size() == 0) {
				cout << "the stack is empty" << endl;
				continue;
			}
			cout << "delete method" << endl;
			stk.stack_pop();
		}

		if (choice == 3) {
			if (stk.stack_size() == 0) {
				cout << "the stack is empty" << endl;
			}
			for (int i = 0; i < stk.stack_size(); i++) {
				cout << stk[i] << endl;
			}
		}

		if (choice == 4) {
			cout << "clear stack" << endl;
			stk.~Stack();
		}
	}


		system("clear");
		cout << "press '1' to add element in queue" << endl;
		cout << "press '2' to remove element from queue" << endl;
		cout << "press '3' to get queue info" << endl;
		cout << "press '4' to delete queue" << endl;

		for (int i = 0; turn.queue_size() != 10; i++) {
			cout << endl;
			cout << "selection: ";
			int choice;
			cin >> choice;

			if (choice == 1) {
				cout << "value: ";
				int user_data;
				cin >> user_data;
				turn.queue_push(user_data);
			}

			if (choice == 2) {
				if (turn.queue_size() == 0) {
					cout << "the queue is empty" << endl;
					continue;
				}
				cout << "delete method" << endl;
				turn.queue_pop();
			}

			if (choice == 3) {
				if (turn.queue_size() == 0) {
					cout << "the queue is empty" << endl;
				}
				for (int i = 0; i < turn.queue_size(); i++) {
					cout << turn[i] << endl;
				}
			}

			if (choice == 4) {
				cout << "clear queue" << endl;
				turn.~Queue();
			}

	}
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

	cout << "Found element: "<< lst[1] << endl;

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
	cout << "print '1' for task 1, '2' for task 2" << endl;
	int choice = 0;

	cin >> choice;

	if (choice == 1)
	{
		system("clear");
		task1();
	}
	if (choice == 2)
	{
		system("clear");
		task2();
	}
	return 0;
}
