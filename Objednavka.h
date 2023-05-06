#pragma once

#include "ObjednavkaItem.h"
#include <vector>

#include <iostream>
using namespace std;
class Objednavka
{
private:
    int id;
    vector<OrderItem*> items;

public:
    Objednavka(int id);
    ~Objednavka();

    void AddItem(int id, AbstractObjednanyZajazd* product, int count);
    void RemoveItem(int id);

    int CalculatePrice();
    void Print();
};
Objednavka::Objednavka(int id)
{
    this->id = id;
}
Objednavka::~Objednavka()
{
    for (auto&& item : items)
    {
        delete item;
    }

}

void Objednavka::AddItem(int id, AbstractObjednanyZajazd* product, int count)
{
    OrderItem* newItem = new OrderItem(id, product, count);
    items.push_back(newItem);
}
void Objednavka::RemoveItem(int id)
{
    for (int i = 0; i < items.size(); i++)
    {
        if ((items[i]->GetProduct()->getID()) == id)
            items.erase(items.begin() + i);
    }
}

int Objednavka::CalculatePrice()
{
    int price = 0;

    for (auto&& item : items)
    {
        price += item->GetProduct()->getCena() * item->GetCount();
    }

    return price;
}
void Objednavka::Print()
{
    cout << "Objednavka cislo: " << id << endl << endl;
    cout << "Polozky: " << endl << endl;

    for (auto&& item : items)
    {

        cout << "" << endl;
        item->Print();
        cout << endl;
    }

    cout << "" << endl;
    cout << "Total price: " << CalculatePrice() << endl;

}