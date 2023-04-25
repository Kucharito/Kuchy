// OOPprojektESTERAZCestovka.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include "Customer.h"
#include "Zajazd.h"
#include "Katalog.h"
#include "ObjednavkaItem.h"
#include "Objednavka.h"

using namespace std;
/*class AbstractCustomer
{
protected:
    int id;
    vector<Objednavka*> orders;

public:
    virtual string ClassName() = 0;
    AbstractCustomer(int id)
    {
        this->id = id;
    }
    virtual ~AbstractCustomer()
    {

    }
    int GetId()
    {
        return id;
    }
    void pridajObjednavku(Objednavka* order)
    {
        orders.push_back(order);
    }
    float vypocitajCenu()
    {
        int price = 0;

        for (auto&& order : orders)
        {
            price += order->vypocitajCenu();
        }
        return price;
    }
    void PrintOrders()
    {
        this->vypis();

        cout << endl << "Orders: " << endl << endl;
        cout << "***************************" << endl;

        for (auto&& order : orders)
        {
            order->vypis();
            cout << endl;
            cout << "***************************" << endl;
        }



        cout << endl << "Total price: " << vypocitajCenu() << endl;
    }

    void vypis()
    {
        cout << this->ClassName() << endl;
        cout << " id: " << this->id << endl;
    }
};



class AbstractRegisteredCustomer : public AbstractCustomer
{
protected:
    string firstName;
    string lastName;
    string email;

public:
    AbstractRegisteredCustomer(int id, string firstName, string lastName, string email) : AbstractCustomer(id)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->email = email;
    }
    virtual ~AbstractRegisteredCustomer()
    {

    }

    string GetFirstName()
    {
        return firstName;
    }
    string GetLastName()
    {
        return lastName;
    }
    string GetEmail()
    {
        return email;
    }

    void Print()
    {
        AbstractCustomer::vypis();
        cout << " first name: " << this->firstName << endl;
        cout << " last name: " << this->lastName << endl;
        cout << " email: " << this->email << endl;

    }
};



class CompanyUser : public AbstractRegisteredCustomer
{
private:
    string company;

public:
    CompanyUser(int id, string firstName, string lastName, string email, string company) : AbstractRegisteredCustomer(id, firstName, lastName, email)
    {
        this->company = company;
    }
    virtual ~CompanyUser()
    {

    }

    string ClassName()
    {
        return "Company User";
    }

    string GetCompany()
    {
        return company;
    }

    void Print()
    {
        AbstractRegisteredCustomer::Print();
        cout << " company: " << this->company << endl;
    }
};

class RegisteredUser : public AbstractRegisteredCustomer
{
private:
    string address;

public:
    RegisteredUser(int id, string firstName, string lastName, string email, string address) : AbstractRegisteredCustomer(id, firstName, lastName, email)
    {
        this->address = address;
    }
    virtual ~RegisteredUser()
    {

    }

    string ClassName()
    {
        return "Registered User";
    }

    string GetAddress()
    {
        return address;
    }

    void Print()
    {
        AbstractRegisteredCustomer::Print();
        cout << " address: " << this->address << endl;
    }
};*/

//Tu mozno pridat vlastnika banky a zdedi z osoby alebo nieco take ssdgasdSDGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
/*class Katalog
{
private:
    int Kapacitaponuk;
    int PocetPonuk;
    vector <AbstractObjednanyZajazd*> Zajazdy;
public:
    Katalog(int kapacitaponuk)
    {
        this->Kapacitaponuk = kapacitaponuk;
       
    }
    ~Katalog()
    {
        for (auto&& zajazd : Zajazdy)
        {
            delete zajazd;
        }
        this->Kapacitaponuk = 0;
        this->PocetPonuk = 0;
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
    LetnaDovolenka(string nazovplaze, bool drinky, bool allinclusive) : AbstractObjednanyZajazd(id_Zajazdu, CenaZajazdu, NazovZajazdu)
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
    ZimnaDovolenka(string nazovstrediska, bool pozicovnalyzi, int pocetlanoviek) : AbstractObjednanyZajazd(id_Zajazdu, CenaZajazdu, NazovZajazdu)
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
        return this->Id;
    }
    void setID(int id)
    {
        this->Id = id;
    }
    AbstractObjednanyZajazd* getZajazd()
    {
        return Zajazd;
    }
    int getCount()
    {
        return this->Count;
    }
    void setCount(int count)
    {
        this->Count = count;
    }
    void vypisObjednavkaItem()
    {
        Zajazd->vypis();
        cout << "id objednavky je " << Id << "\n";
        cout << "pocet objednavok je " << Count << "\n";
    }
};
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
    float vypocitajCenu()
    {
        float cena = 0;
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
class Agentura//DO AGENTURY DAT OBJEDNAVKY KLIENTA A DRISTY TAK JAK V BANKE CLIENT A ACCOUNT
{


};*/


int main()
{
    LetnaDovolenka* Letnadovolenka = new LetnaDovolenka(1,2500,"dobry","Hawaii", false, true);
    ZimnaDovolenka* Zimnadovolenka = new ZimnaDovolenka(2,3000,"zly","Klasuberg", true, 8);

    Katalog* catalog = new Katalog(10);

    catalog->pridajZajazd(Letnadovolenka);
    catalog->pridajZajazd(Zimnadovolenka);

    cout << "PRINTING CATALOG" << endl;
    catalog->vypisKatalog();


    Objednavka* objednavka = new Objednavka(1);

    objednavka->pridatItem(1, Letnadovolenka, 1);
    objednavka->pridatItem(2, Letnadovolenka, 3);
    objednavka->pridatItem(3, Zimnadovolenka, 2);

    cout << "PRINTING ORDER" << endl;
    objednavka->vypis();

    RegisteredUser* Marek = new RegisteredUser(1, "Hynek", "Novak", "novacekek@gmail.com", "Praha 123");
    RegisteredUser* Jozef = new RegisteredUser(2, "Martin", "Smith", "smith@gmail.com", "Dubina 543");
    RegisteredUser* Otto = new RegisteredUser(3, "Jonas", "Osoba", "maly.osobacek@gmail.com", "Vitky 1136");

    CompanyUser* spravca = new CompanyUser(4, "Pepa", "Alzak", "alzacek@gmail.com", "Alza");

    vector<AbstractCustomer*> klienti{ Marek, Jozef, Otto,spravca };

    cout << "PRINTING CUSTOMERS" << endl;

    for (auto klient : klienti)
    {
        klient->vypis();
        cout << endl;
    }


    Objednavka* objednavka2 = new Objednavka(2);
    objednavka->pridatItem(1, Letnadovolenka, 69);

    Otto->pridajObjednavku(objednavka);
    Otto->pridajObjednavku(objednavka2);

    cout << "PRINTING CUSTOMER ORDERS" << endl;

    Otto->vypis();
    Otto->PrintOrders();

    for (auto&& klient : klienti)
    {
        delete klient;
    }

    delete objednavka;
    delete objednavka2;
    delete catalog;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
