#ifndef TABLE_HPP
#define TABLE_HPP
#include <fstream>

using namespace std;

class table
{
public:
  table();
  void interface();

private:
  fstream *file;
  fstream *read_buf;
  string *table_arr;
  string **matrix;
  int *number;

  void load_file();
  int name_error_check(string &name);
  void read_file();
  void table_output(int &rows, int &cols);
};

#endif
