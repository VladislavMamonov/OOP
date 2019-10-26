#include "table.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void table::interface()
{
  int select;
  cout << endl << endl;
  cout << "press 1 to output tables" << endl;
  cout << endl;

  cout << "selection: ";
  cin >> select;
  if (select == 1) {
    read_file();
  }
}

void table::load_file()
{
  number = new int();

  cout << "enter the number of tables: ";
  cin >> *number;

  table_arr = new string[*number];

  for (int i = 0; i < *number; i++) {
    string name;

    cout << "Enter file name: ";
    cin >> name;

    if (name_error_check(name) == 1) {
      cout << endl;
      cout << "file must be in .txt format" << endl;
      cout << endl;
      i--;
      continue;
    }

    table_arr[i] = name;
  }
}

int table::name_error_check(string &name)
{
  string name_check;
  for (int i = name.size() - 4, j = 0; i < name.size(); i++, j++) {
    name_check.insert(name_check.begin() + j, name[i]);
  }

  if (name_check != ".txt") {
      return 1;
  }
  else {
    return 0;
  }
}

void table::read_file()
{
  for (int i = 0; i < *number; i++) {
    file = new fstream();
    file->open(table_arr[i]);

    int rows = 500, cols = 500;
    matrix = new string*[rows];

    for (int i = 0; i < rows; i++) {
      matrix[i] = new string[cols];
    }

    int rows_count = 0, cols_count = 0;

    while (!file->eof()) {
      string str;

      read_buf = new fstream();
      read_buf->open("read_buf.txt", ios_base::out);
      read_buf->close();
      read_buf->open("read_buf.txt");

      getline(*file, str);

      *read_buf << str << endl;   // Записываем считанную строчку в буфер
      read_buf->seekp(0, ios_base::beg);

      while (!read_buf->eof()) {
        getline(*read_buf, str, ' ');    // Далее из буфера считываем слова из строки
        matrix[rows_count][cols_count] = str;
        cols_count++;
      }
      cols_count = 0;
      rows_count++;
      read_buf->close();
    }

    table_output(rows, cols);
    file->close();

    for (int i = 0; i < rows; i++) {
      delete [] matrix[i];
    }
    delete [] matrix;
  }
}

void table::table_output(int &rows, int &cols)
{
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << matrix[i][j] << "\t";
    }
  }
}

table::table()
{
  load_file();
}
