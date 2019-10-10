#ifndef MENU_HPP
#define MENU_HPP
#include <fstream>
#include <string>

class menu
{
public:
  menu();
  ~menu();

  void file_input();
  void file_output();

private:
  void file_read();
};

#endif
