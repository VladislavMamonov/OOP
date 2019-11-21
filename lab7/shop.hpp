#ifndef SHOP_HPP
#define SHOP_HPP

#include "set.hpp"
#include "Vector.hpp"
#include <fstream>

class Shop_Storage : public Vector<string>
{
protected:
  Shop_Storage() {
    if (file_read() == 0) {
      load_data();
    }
  }

  Vector<string> shop_list;
  Vector<string> client_basket;
  Vector<string> client_orders;

  int file_read();
  void load_data();
  void save_data();

  fstream *storage_data1;
  fstream *storage_data2;

  int earning = 0;
  int quantity = 0;

  ~Shop_Storage() {
    storage_data1->close();
    storage_data2->close();
  }
};


class seller : public Shop_Storage
{
protected:
  void add_product();
  void remove_product();
  void sale_info();

private:
  int cost_error_check(int cost);
};


class client : public seller
{
protected:
  void catalog();
  void basket();
  void orders();
};


class Shop : public client
{
public:
  Shop();

private:
  void product_list();
  void seller_interface();
  void client_interface();
};

#endif
