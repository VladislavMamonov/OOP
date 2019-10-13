#ifndef MENU_HPP
#define MENU_HPP
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class terminal
{
protected:
  terminal();
  ~terminal();

  void input();
  void output();
  void search();
  void delete_word();

private:
  void file_read();
  void file_output();

  fstream *file;
  fstream *terminal_data;
};

class menu : public terminal
{
public:
  void interface();

private:
  void Str_Add() {
    input();
  }

  void Show_Text() {
    output();
  }

  void Word_Search() {
    search();
  }

  void Word_Delete() {
    delete_word();
  }
};

#endif
