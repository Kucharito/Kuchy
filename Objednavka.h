#pragma once

#include "ObjednavkaItem.h"
#include <vector>

#include <iostream>
using namespace std;
class Order
{
private:
    int id;
    vector<OrderItem*> items;

public:
    Order(int id);
    ~Order();

    void AddItem(int id, AbstractObjednanyZajazd* product, int count);
    void RemoveItem(int id);

    int CalculatePrice();
    void Print();
};
Order::Order(int id)
{
    this->id = id;
}
Order::~Order()
{
    for (auto&& item : items)
    {
        delete item;
    }

}

void Order::AddItem(int id, AbstractObjednanyZajazd* product, int count)
{
    OrderItem* newItem = new OrderItem(id, product, count);
    items.push_back(newItem);
}
void Order::RemoveItem(int id)
{
    for (int i = 0; i < items.size(); i++)
    {
        if ((items[i]->GetProduct()->getID()) == id)
            items.erase(items.begin() + i);
    }
}

int Order::CalculatePrice()
{
    int price = 0;

    for (auto&& item : items)
    {
        price += item->GetProduct()->getCena() * item->GetCount();
    }

    return price;
}
void Order::Print()
{
    cout << "Order number: " << id << endl << endl;
    cout << "Items: " << endl << endl;

    for (auto&& item : items)
    {

        cout << "_____________" << endl;
        item->Print();
        cout << endl;
    }

    cout << "_____________" << endl;
    cout << "Total price: " << CalculatePrice() << endl;

}