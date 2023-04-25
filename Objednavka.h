#pragma once
#include "ObjednavkaItem.h"
#include <vector>
#include <string>
using namespace std;
class Objednavka
{
private:
    int Id_objednavky;
    vector <ObjednavkaItem*> Itemy;

public:
    Objednavka(int idobjednavky)
    {
        this->Id_objednavky = idobjednavky;
    }
    ~Objednavka()
    {
        for (auto&& itemy : Itemy)
        {
            delete itemy;
        }
    }
    void pridatItem(int idobjednavky, AbstractObjednanyZajazd* zajazd, int count)
    {
        ObjednavkaItem* newItem = new ObjednavkaItem(idobjednavky, zajazd, count);
        Itemy.push_back(newItem);
    }
    void OdstranitItem(int idobjednavky, AbstractObjednanyZajazd* zajazd, int count)
    {
        for (int i = 0; i < Itemy.size(); i++)
        {
            if ((Itemy[i]->getZajazd()->getID()) == idobjednavky)
            {
                Itemy.erase(Itemy.begin() + i);
            }
        }
    }
    int vypocitajCenu()
    {
        int cena = 0;
        for (auto&& itemy : Itemy)
        {
            cena = cena + itemy->getZajazd()->getCena() * itemy->getCount();
        }
        return cena;
    }
    void vypis()
    {
        cout << "Cislo objednavky je " << Id_objednavky << "\n";
        cout << "Itemy\n";
        for (auto&& itemy : Itemy)
        {
            itemy->vypisObjednavkaItem();
        }
        cout << "Cena objednavok je " << vypocitajCenu() << "\n";
    }

};