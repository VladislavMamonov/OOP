#ifndef SHOP_HPP
#define SHOP_HPP

#include "set.hpp"
#include "Vector.hpp"

class Shop_Storage
{
protected:
  Vector<string> shop_list;
  Vector<string> client_basket;
  Vector<string> client_orders;

  int earning = 0;
  int quantity = 0;
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
  void seller_interface();
  void client_interface();

private:
  void product_list();
};

#endif
