#pragma once

#include "Zajazd.h"
#include <vector>
#include <iostream>
using namespace std;
class Katalog
{
private:
    int capacity;
    int productCount;
    vector<AbstractObjednanyZajazd*> products;

public:
    Katalog(int capacity);
    ~Katalog();

    void AddProduct(AbstractObjednanyZajazd* product);

    void Print();
};


Katalog::Katalog(int capacity)
{
    this->capacity = capacity;
}
Katalog::~Katalog()
{
    for (auto&& product : products)
    {
        delete product;
    }
    capacity = 0;
    productCount = 0;
}

void Katalog::AddProduct(AbstractObjednanyZajazd* product)
{
    if (productCount >= capacity)
        return;
    products.push_back(product);
    productCount++;
}

void Katalog::Print()
{
    for (auto&& product : products)
    {
        cout << "________________" << endl;
        product->vypis();
        cout << endl;
    }

}