#pragma once

#include <string>
using namespace std;
class AbstractObjednanyZajazd
{
protected:
    int id_Zajazdu;
    float CenaZajazdu;
    string NazovZajazdu;

public:
    AbstractObjednanyZajazd(int id_zajazdu, float cenazajazdu, string nazovzajadzdu)
    {
        this->id_Zajazdu = id_zajazdu;
        this->CenaZajazdu = cenazajazdu;
        this->NazovZajazdu = nazovzajadzdu;
    }
    virtual ~AbstractObjednanyZajazd()
    {

    }
    virtual string typDovolenky() = 0;
    int getID()
    {
        return id_Zajazdu;
    }
    float getCena()
    {
        return CenaZajazdu;
    }
    string getNazov()
    {
        return NazovZajazdu;
    }
    virtual void vypis()
    {
        cout << this->typDovolenky() << endl;
        cout << " Catalog id: " << this->id_Zajazdu << endl;
        cout << " Nazov: " << this->CenaZajazdu << endl;
        cout << " Cena: " << this->NazovZajazdu << endl;
    }
};

class LetnaDovolenka : public AbstractObjednanyZajazd
{
private:
    string Nazovplaze;
    bool Drinky;
    bool AllInclusive;

public:
    LetnaDovolenka(int id_Zajazdu,float CenaZajazdu,string NazovZajazdu,string nazovplaze, bool drinky, bool allinclusive) : AbstractObjednanyZajazd(id_Zajazdu, CenaZajazdu, NazovZajazdu)
    {
        this->Nazovplaze = nazovplaze;
        this->Drinky = drinky;
        this->AllInclusive = allinclusive;
    }
    virtual ~LetnaDovolenka()
    {

    }

    string typDovolenky()
    {
        return "Letna dovolenka";
    }
    string getNazovplaze()
    {
        return Nazovplaze;
    }
    bool getDrinky()
    {
        return Drinky;
    }
    bool getAllInclusive()
    {
        return AllInclusive;
    }
    void vypis()
    {
        AbstractObjednanyZajazd::vypis();
        cout << " Drinky " << (this->Drinky ? "Su v cene" : "Nie su v cene") << endl;
        cout << " AllInclusive" << (this->AllInclusive ? "Ano" : " Nie ") << endl;
        cout << "Nazovplaze" << this->Nazovplaze << "\n";
    }

};
class ZimnaDovolenka : public AbstractObjednanyZajazd
{
private:
    string NazovStrediska;
    bool PozicovnaLyzi;
    int PocetLanoviek;
public:
    ZimnaDovolenka(int id_Zajazdu, float CenaZajazdu, string NazovZajazdu,string nazovstrediska, bool pozicovnalyzi, int pocetlanoviek) : AbstractObjednanyZajazd(id_Zajazdu, CenaZajazdu, NazovZajazdu)
    {
        this->NazovStrediska = nazovstrediska;
        this->PozicovnaLyzi = pozicovnalyzi;
        this->PocetLanoviek = pocetlanoviek;
    }
    virtual ~ZimnaDovolenka()
    {

    }
    string typDovolenky()
    {
        return "Zimna dovolenka";
    }
    string getStredisko()
    {
        return NazovStrediska;
    }
    bool getPozicovnaLyzi()
    {
        return PozicovnaLyzi;
    }
    int getPocetLanoviek()
    {
        return PocetLanoviek;
    }
    void vypis()
    {
        AbstractObjednanyZajazd::vypis();
        cout << "Nazov strediska je " << this->NazovStrediska << "\n";
        cout << " Pozicovna lyzi je v stredisku  " << (this->PozicovnaLyzi ? "Ano " : "Nie") << endl;
        cout << "Pocet lanoviek v stredisko " << this->NazovStrediska << " je " << this->PocetLanoviek << "\n";
    }
};
