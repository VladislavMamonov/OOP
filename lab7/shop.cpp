#include "shop.hpp"
#include <iostream>

using namespace std;


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
}


void seller::remove_product()
{
  cout << "Введите название удаляемого товара: ";
  string product_name;
  cin >> product_name;
  cout << endl;

  if (shop_list.search(product_name) != 1) {
    shop_list.pop(shop_list.search(product_name));
  }
  else {
    cout << "Ошибка удаления" << endl;
    cout << endl;
  }
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
}


void client::orders()
{
  for (int i = 0; i < client_orders.GetSize(); i++) {
    cout << client_orders[i] << endl << endl;
  }
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
    system("clear");
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
    system("clear");
    client_interface();
  }

  if (select == 2) {
    basket();
    system("clear");
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
