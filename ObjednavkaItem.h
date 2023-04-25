#pragma once

#include "Zajazd.h"
using namespace std;

class ObjednavkaItem
{
private:
    int Id;
    AbstractObjednanyZajazd* Zajazd;
    int Count;

public:
    ObjednavkaItem(int id, AbstractObjednanyZajazd* zajazd, int count)
    {
        this->Id = id;
        this->Zajazd = zajazd;
        this->Count = count;
    }
    ~ObjednavkaItem()
    {

    }
    int getID()
    {
        return Id;
    }
    AbstractObjednanyZajazd* getZajazd()
    {
        return Zajazd;
    }
    int getCount()
    {
        return Count;
    }
    void vypisObjednavkaItem()
    {
        Zajazd->vypis();
        cout << "id objednavky je " << Id << "\n";
        cout << "pocet objednavok je " << Count << "\n";
    }
};