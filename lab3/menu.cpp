#include "menu.hpp"
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

ofstream *file = new ofstream();

void menu::file_read()
{
  string name;

  cout << "Enter file name: ";
  getline(cin, name);

  file->open(name);
}

void menu::file_input()
{
  file->seekp(0, ios_base::end);  //указатель в конец файла

  cout << "Enter the string: ";
  string str;
  getline(cin, str);

  *file << str << endl;
}

void menu::file_output()
{
  file->seekp(0, ios_base::beg); //указатель в начало файла

  while (!file->eof()) {
    string str;
    getline(file, str);
    cout << str << endl;
  }
}

menu::menu()
{
  file_read();
}

menu::~menu()
{
  file->close();
}
