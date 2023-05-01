#pragma once

#include "Zajazd.h"
#include <vector>
#include <iostream>
using namespace std;
class ProductCatalog
{
private:
    int capacity;
    int productCount;

    vector<AbstractObjednanyZajazd*> products;

public:
    ProductCatalog(int capacity);
    ~ProductCatalog();

    void AddProduct(AbstractObjednanyZajazd* product);

    void Print();
};


ProductCatalog::ProductCatalog(int capacity)
{
    this->capacity = capacity;
}
ProductCatalog::~ProductCatalog()
{
    for (auto&& product : products)
    {
        delete product;
    }
    capacity = 0;
    productCount = 0;
}

void ProductCatalog::AddProduct(AbstractObjednanyZajazd* product)
{
    if (productCount >= capacity)
        return;
    products.push_back(product);
    productCount++;
}

void ProductCatalog::Print()
{
    for (auto&& product : products)
    {
        cout << "________________" << endl;
        product->vypis();
        cout << endl;
    }

}