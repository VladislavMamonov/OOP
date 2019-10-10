#include "menu.hpp"
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

fstream *file = new fstream();

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
    getline(*file, str);
    cout << str << endl;
  }
}

void menu::file_search()
{
  file->seekp(0, ios_base::beg);

  string str_user;
  cout << "Enter the search word: ";
  cin >> str_user;
  cout << endl;

  int count = 0;    //кол-во совпадений
  int position = 0;      //номер строки

  while (!file->eof()) {
    string lookup;

    getline(*file, lookup);
    position++;

    if (lookup == str_user) {
      count++;
    }
  }
  cout << "matches found: " << count << endl;
  cout << "position: " << position << endl;
}

menu::menu()
{
  file_read();
}

menu::~menu()
{
  file->close();
}
