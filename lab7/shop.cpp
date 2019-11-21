#include "shop.hpp"
#include <fstream>
#include <iostream>

using namespace std;


int Shop_Storage::file_read()
{
  storage_data1 = new fstream();
  storage_data2 = new fstream();

  storage_data1->open("storage_data1.txt");
  storage_data2->open("storage_data2.txt");

  if (storage_data1->fail() || storage_data2->fail()) {
    storage_data1->open("storage_data1.txt", ios_base::out);
    storage_data2->open("storage_data2.txt", ios_base::out);
    storage_data1->close();
    storage_data2->close();
    storage_data1->open("storage_data1.txt");
    storage_data2->open("storage_data2.txt");
    return 1;
  }
  return 0;
}


void Shop_Storage::load_data()
{
  storage_data1->clear();
  storage_data1->seekp(0, ios_base::beg);
  storage_data2->clear();
  storage_data2->seekp(0, ios_base::beg);

  while (!storage_data1->eof()) {
    string str_data1;
    string str_data2;
    getline(*storage_data1, str_data1);
    getline(*storage_data2, str_data2);

    shop_list.push(str_data1, atoi(str_data2.c_str()), shop_list.GetSize());
  }
  shop_list.pop(shop_list.GetSize() - 1);  //Удаляем последний элемент, т.к он пустой
}


void Shop_Storage::save_data()
{
  storage_data1->close();
  storage_data1->open("storage_data1.txt", ios::out);
  storage_data1->close();
  storage_data1->open("storage_data1.txt");

  storage_data2->close();
  storage_data2->open("storage_data2.txt", ios::out);
  storage_data2->close();
  storage_data2->open("storage_data2.txt");

  storage_data1->clear();
  storage_data1->seekp(0, ios_base::beg);
  storage_data2->clear();
  storage_data2->seekp(0, ios_base::beg);

  for (int i = 0; i < shop_list.GetSize(); i++) {
    *storage_data1 << shop_list[i] << endl;
  }

  for (int i = 0; i < shop_list.GetSize(); i++) {
    *storage_data2 << shop_list.GetData2(i) << endl;
  }
}


int seller::cost_error_check(int cost)
{
  if (isdigit(cost) != 0) {
    return 0;
  }
  else {
    return 1;
  }
}


void seller::add_product()
{
  cout << "Название товара: ";
  string product_name;
  cin >> product_name;

  cout << "Стоимость товара: ";
  int cost;
  cin >> cost;

  if (!cin) {
    cout << "Стоимость должна состоять из цифр!" << endl << endl;
    cin.clear();
    return;
  }

  shop_list.push(product_name, cost, shop_list.GetSize());
  cout << endl;

  save_data();
  system("clear");
}


void seller::remove_product()
{
  cout << "Введите название удаляемого товара: ";
  string product_name;
  cin >> product_name;
  cout << endl;

  if (shop_list.search(product_name) != -1) {
    shop_list.pop(shop_list.search(product_name));
  }
  else {
    cout << "Ошибка удаления" << endl;
    cout << endl;
  }
  save_data();
}


void seller::sale_info()
{
  cout << "Товара продано: " << quantity << endl;
  cout << "Прибыль: " << earning << endl << endl;
}


void Shop::product_list()
{
  for (int i = 0; i < shop_list.GetSize(); i++) {
    cout << shop_list[i] << endl;
    cout << endl;
  }
}


void client::catalog()
{
  cout << endl << "Введите имя желаемого товара: ";
  string product_select;
  cin >> product_select;
  cout << endl;

  int search_index = shop_list.search(product_select);

  if (search_index == -1) {
    cout << "Такого товара не существует" << endl << endl;
    return;
  }

  cout << "Нажмите '1' чтобы добавить в корзину" << endl;
  cout << "Нажмите '2' чтобы купить " << endl;
  cout << "Нажмите любую другую клавишу чтобы вернуться в меню" << endl << endl;

  int selection;
  cout << endl;
  cout << "selection: ";
  cin >> selection;
  cout << endl;

  if (selection == 1) {
    client_basket.push(product_select, shop_list.GetCost(), client_basket.GetSize() - 1);
    shop_list.pop(search_index);
    cout << endl;
  }

  if (selection == 2) {
    client_orders.push(product_select, shop_list.GetCost(), client_orders.GetSize() - 1);
    shop_list.pop(search_index);

    earning+= shop_list.GetCost();
    quantity++;
    cout << endl;
  }
  save_data();
}


void client::basket()
{
  int amount = 0;

  for (int i = 0; i < client_basket.GetSize(); i++) {
    cout << client_basket[i] << endl << endl;
    amount+= client_basket.GetCost();
  }

  cout << "Итого: " << amount << endl << endl;

  cout << "Нажмите '1', чтобы купить товар" << endl;
  cout << "Нажмите '2', чтобы убрать товар из корзины" << endl;
  cout << "Нажмите '3' для выхода в меню" << endl;

  int select;
  cout << endl;
  cout << "selection: ";
  cin >> select;
  cout << endl;


  if (select == 1) {
    cout << endl << "Введите имя желаемого товара: ";
    string product_select;
    cin >> product_select;
    cout << endl;
    int search_index = client_basket.search(product_select);

    if (search_index == -1) {
      cout << "Такого товара не существует" << endl << endl;
      return;
    }
    client_basket.pop(search_index);
    client_orders.push(product_select, client_basket.GetCost(), client_orders.GetSize() - 1);

    earning+=client_basket.GetCost();
    quantity++;
  }


  if (select == 2) {
    cout << endl << "Введите имя желаемого товара: ";
    string product_select;
    cin >> product_select;
    cout << endl;
    int search_index = client_basket.search(product_select);

    if (search_index == -1) {
      cout << "Такого товара не существует" << endl << endl;
      return;
    }
    client_basket.pop(search_index);
    shop_list.push(product_select, client_basket.GetCost(), shop_list.GetSize());
  }
  save_data();
}


void client::orders()
{
  for (int i = 0; i < client_orders.GetSize(); i++) {
    cout << client_orders[i] << endl << endl;
  }
  save_data();
}


Shop::Shop()
{
  cout << "Нажмите '1' если вы продавец" << endl;
  cout << "Нажмите '2' если вы покупатель" << endl;
  cout << "Нажмите любую другую клавишу, чтобы выйти" << endl;

  int select;
  cout << endl;
  cout << "selection: ";
  cin >> select;
  cout << endl;

  if (select == 1) {
    system("clear");
    seller_interface();
  }

  if (select == 2) {
    system("clear");
    client_interface();
  }
}


void Shop::seller_interface()
{
  cout << "Нажмите '1' чтобы перейти к списку товаров" << endl;
  cout << "Нажмите '2' чтобы добавить продукт" << endl;
  cout << "Нажмите '3' чтобы удалить продукт" << endl;
  cout << "Нажмите '4' чтобы узнать статистику продаж" << endl;
  cout << "Нажмите '5' чтобы выйти из аккаунта" << endl;

  int select;
  cout << endl;
  cout << "selection: ";
  cin >> select;
  cout << endl;

  if (select == 1) {
    product_list();
    seller_interface();
  }

  if (select == 2) {
    add_product();
    seller_interface();
  }

  if (select == 3) {
    remove_product();
    system("clear");
    seller_interface();
  }

  if (select == 4) {
    sale_info();
    seller_interface();
  }

  if (select == 5) {
    cout << "Нажмите '1' если вы продавец" << endl;
    cout << "Нажмите '2' если вы покупатель" << endl;
    cout << "Нажмите любую другую клавишу, чтобы выйти" << endl;

    cout << endl;
    cout << "selection: ";
    cin >> select;
    cout << endl;

    if (select == 1) {
      system("clear");
      seller_interface();
    }

    if (select == 2) {
      system("clear");
      client_interface();
    }
  }
}


void Shop::client_interface()
{
  cout << "Нажмите '1' чтобы перейти к списку товаров" << endl;
  cout << "Нажмите '2' для просмотра списка отложенных товаров" << endl;
  cout << "Нажмите '3' для просмотра заказанных товаров" << endl;
  cout << "Нажмите '4' чтобы выйти из аккаунта" << endl;

  int select;
  cout << endl;
  cout << "selection: ";
  cin >> select;
  cout << endl;

  if (select == 1) {
    product_list();
    catalog();
    client_interface();
  }

  if (select == 2) {
    basket();
    client_interface();
  }

  if (select == 3) {
    orders();
    client_interface();
  }

  if (select == 4) {
    cout << "Нажмите '1' если вы продавец" << endl;
    cout << "Нажмите '2' если вы покупатель" << endl;
    cout << "Нажмите любую другую клавишу, чтобы выйти" << endl;

    cout << endl;
    cout << "selection: ";
    cin >> select;
    cout << endl;

    if (select == 1) {
      system("clear");
      seller_interface();
    }

    if (select == 2) {
      system("clear");
      client_interface();
    }
  }
}
