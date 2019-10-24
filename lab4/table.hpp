#ifndef TABLE_HPP
#define TABLE_HPP
#include <fstream>

using namespace std;

class table
{
public:

public:
  table();

  fstream *file;
  string *table_arr;
  string *arr;
  int *number;

  void load_file();
  void read_file();
  void table_output(int &count);
};

#endif
