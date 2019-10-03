#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <unistd.h>

using namespace std;

void FirstTask()
{
	srand(time(NULL));
	int rows = 200;
	int cols = 200;

	int **matrix = new int* [rows];

	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = (unsigned char)rand();
		}
	}

///////////////////////////////////////////////

	int *arr = new int[(rows * cols) * 4];
	int size = 0;

	for (int cols = 200; cols > -1; cols--) {
		for (int i = 0, j = cols; j != 200; i++) { 	//Правые диагонали,
			arr[size] = matrix[i][j];				//Правая часть
			j++;
			size++;
		}
	}

	for (int rows = 1; rows < 200; rows++) {
		for (int i = rows, j = 0; i != 200; i++) {	//Правые диагонали,
			arr[size] = matrix[i][j];				//Левая часть
			j++;
			size++;
		}
	}

	for (int cols = 0; cols < 200; cols++) {
		for (int i = 0, j = cols; j > -1; i++) {  	//Левые диагонали,
			arr[size] = matrix[i][j];				//Левая часть
			j--;
			size++;
		}
	}

	for (int rows = 1; rows < 200; rows++) {
		for (int i = rows, j = 199; i != 200; i++) {	//Левые диагонали,
			arr[size] = matrix[i][j];					//Правая часть
			j--;
			size++;
		}
	}

	int i = rows / 2;
	int j  = cols / 2;
	int step = 1;

    while (j != 0) {
        arr[size] = matrix[i][j];
        size++;

        for (int count = 0; count < step - 1; count++) {
            j++;
            arr[size] = matrix[i][j];
            size++;
        }

        for (int count = 0; count < step; count++) {
            i--;
            arr[size] = matrix[i][j];
            size++;
        }																												//Спираль
																															 //Центр
        for (int count = 0; count < step; count++) {
            j--;
            arr[size] = matrix[i][j];
            size++;
        }

        for (int count = 0; count < step; count++) {
            i++;
            arr[size] = matrix[i][j];
            size++;
        }

        if (i < rows - 1) {
            i++;
        }
        step += 2;
    }

		i = 0;
		j = 0;
		step = rows - 1;

		while (i != rows / 2 - 1 && j != cols / 2) {

			if (i == 0 && j == 0) {
				arr[size] = matrix[i][j];
				size++;
			}

			if (j > 0) {
				step -= 1;						//Уменьшаем шаг когда достигаем левой боковой стены
			}

				for (int count = 0; count < step; count++) {
						i++;
						arr[size] = matrix[i][j];
						size++;
				}

				if (j > 0) {
					step -= 1;				//Уменьшаем шаг когда преодолеваем левую боковую стену
				}

				if (i - 1 == rows / 2 - 1) {
					j++;
					arr[size] = matrix[i][j];
					size++;													//Исключение для последней итерации
					i--;
					arr[size] = matrix[i][j];
					break;
				}

				for (int count = 0; count < step; count++) {
						j++;
						arr[size] = matrix[i][j];
						size++;
				}																												//Спираль
																															 //Слева
				for (int count = 0; count < step; count++) {
						i--;
						arr[size] = matrix[i][j];
						size++;
				}

				for (int count = 0; count < step - 1; count++) {
						j--;
						arr[size] = matrix[i][j];
						size++;
				}
		}

	cout << "Вывод левых диагоналей..." << endl;
	sleep(1);

	for (int i = 0, j = 0; i < rows * cols; i++, j++) {
		cout << j << ".\t";
		cout << arr[i] << endl;
	}

	cout << "Вывод правых диагоналей..." << endl;
	sleep(1);

	for (int i = rows * cols, j = rows * cols; i < (rows * cols) * 2; i++, j++) {
		cout << j << ".\t";
		cout << arr[i] << endl;
	}

	cout << "Вывод спирали с центра..." << endl;
	sleep(1);

	for (int i = (rows * cols) * 2, j = (rows * cols) * 2; i < (rows * cols) * 3; i++, j++) {
		cout << j << ".\t";
		cout << arr[i] << endl;
	}

	cout << "Вывод спирали слева..." << endl;
	sleep(1);

	for (int i = (rows * cols) * 3, j = (rows * cols) * 3; i < (rows * cols) * 4; i++, j++) {
		cout << j <<".\t";
		cout << arr[i] << endl;
	}

//////////////////////////////////////////////
// Delete
	for (int i = 0; i < rows; i++) {
		delete [] matrix[i];
	}

	delete [] matrix;
	delete [] arr;
/////////////////////////////////////////////

}


void SecondTask()
{
	int rows;
	srand(time(NULL));

	cout << "Enter number of rows: ";
	cin >> rows;

	int cols = 1;

	int** matrix = new int* [rows];

	for (int i = 0; i < rows; i++) {
		cout << "Enter number of cols in this row: " << endl;
		matrix[i] = new int[cols];

		cout << endl;

		for (int j = 0; j < cols; j++) {
			matrix[i][j] = (unsigned char)rand();
			cout << matrix[i][j] << endl;
		}
		cout << endl;
	}

	for (int i = 0; i < rows; i++) {
		delete [] matrix[i];
	}

	delete [] matrix;
}


int main(int argc, char const *argv[])
{
	int select;

	cout << "Task: ";
	cin >> select;

	if (select == 1)
		FirstTask();
	 else if (select == 2)
	 	SecondTask();
	 else {
	 	cout << "Invalid Task" << endl;
	 	return 1;
	 }
	return 0;
}
