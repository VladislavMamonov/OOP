#include "table.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

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

    table_arr[i] = name;
  }
}

void table::read_file()
{
  for (int i = 0; i < *number; i++) {
    file = new fstream();
    file->open(table_arr[i]);

    arr = new string[1000];
    int count = 0;

    for (int i = 0; !file->eof(); i++) {
      string str;

      getline(*file, str, ' ');

      arr[i] = str;
      count++;
    }

    cout << arr[4] << endl;

    table_output(count);
    file->close();
    delete [] arr;
  }
}

void table::table_output(int &count)
{
  for (int i = 0; i < count; i++) {
      cout << arr[i] << "\t";
  }
}

table::table()
{
  load_file();
}
