#pragma once

#include "Zajazd.h"
using namespace std;
class Katalog
{
private:
    int Kapacitaponuk;
    int PocetPonuk;
    vector <AbstractObjednanyZajazd*> Zajazdy;
public:
    Katalog(int kapacitaponuk)
    {
        this->Kapacitaponuk = kapacitaponuk;
        
        //this->Zajazdy = zajazdy;
    }
    ~Katalog()
    {
        for (auto&& zajazd : Zajazdy)
        {
            delete zajazd;
        }
        Kapacitaponuk = 0;
        PocetPonuk = 0;
    }
    void pridajZajazd(AbstractObjednanyZajazd* zajazd)
    {
        if (PocetPonuk >= Kapacitaponuk)
        {
            return;
        }
        Zajazdy.push_back(zajazd);
        PocetPonuk++;
    }
    void vypisKatalog()
    {
        for (auto&& zajazd : Zajazdy)
        {
            zajazd->vypis();
            cout << endl;
        }
    }
};
