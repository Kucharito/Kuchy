#pragma once

#include "Zajazd.h"

#include <iostream>
class OrderItem
{
private:
    int id;
    AbstractObjednanyZajazd* product;
    int count;

public:
    OrderItem(int id, AbstractObjednanyZajazd* product, int count);
    ~OrderItem();

    AbstractObjednanyZajazd* GetProduct();
    int GetCount();

    void Print();
};
OrderItem::OrderItem(int id, AbstractObjednanyZajazd* product, int count)
{
    this->id = id;
    this->product = product;
    this->count = count;
}
OrderItem::~OrderItem()
{

}

AbstractObjednanyZajazd* OrderItem::GetProduct()
{
    return product;
}
int OrderItem::GetCount()
{
    return count;
}

void OrderItem::Print()
{
    cout << "Polozka cislo " << id << ": ";
    product->vypis();
    cout << "pocet: " << count << endl;
}