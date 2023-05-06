// OOPzadanieEshop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Klient.h"
#include "Zajazd.h"
#include "Katalog.h"
#include "ObjednavkaItem.h"
#include "Objednavka.h"
#include "Majitel.h"
#include "Cestovka.h"
int main()
{
    Cestovka* cestovka = new Cestovka("Cestovka");
    cout << "Dobry den vitame vas na stranke cestovky ";
    cestovka->vypis();
    cout << endl;
    Majitel* osoba = new Majitel("Adam", " Kuchar", 19, " Studentska", 15.5, " Svetlana", 1);
    osoba->vypis();
    cout << endl;
    Majitel* osoba2 = new Majitel("Peter", "Kucar", 28, " Ostravska", 10.47);
    osoba2->vypis();
    

    LetnaDovolenka* Letnadovolenka = new LetnaDovolenka(1, 2500, "Exoticka dovolenka na Hawaii", "Hawaii", false, true);
    ZimnaDovolenka* Zimnadovolenka = new ZimnaDovolenka(2, 3000, "Lyzovacka v Horach", "Klasuberg", true, 8);
    LetnaDovolenka* Letnadovolenka1 = new LetnaDovolenka(3, 3500, "Exoticka dovolenka na Kanarskych", "Kanarske ostrovy", false, true);
    ZimnaDovolenka* Zimnadovolenka1 = new ZimnaDovolenka(4, 4000, "Lyzovacka v Horach", "Speikboden", true, 8);
    LetnaDovolenka* Letnadovolenka2 = new LetnaDovolenka(5, 4500, "Dovolenka v raji", "Croatia", false, true);
    ZimnaDovolenka* Zimnadovolenka2 = new ZimnaDovolenka(6, 5000, "Lyzovacka na horach", "Dolomiti", true, 8);
    LetnaDovolenka* Letnadovolenka3 = new LetnaDovolenka(7, 5500, "Dovolenka v lete", "Bulharsko", false, true);
    ZimnaDovolenka* Zimnadovolenka3 = new ZimnaDovolenka(8, 6000, "Dovolenka plna zimnej zabavy", "Kronplatz", true, 8);

    Katalog* catalog = new Katalog(10);
    //ProductCatalog* catalog = new ProductCatalog(10);

    catalog->AddProduct(Letnadovolenka);
    catalog->AddProduct(Zimnadovolenka);
    catalog->AddProduct(Letnadovolenka1);
    catalog->AddProduct(Zimnadovolenka1);
    catalog->AddProduct(Letnadovolenka2);
    catalog->AddProduct(Zimnadovolenka2);
    catalog->AddProduct(Letnadovolenka3);
    catalog->AddProduct(Zimnadovolenka3);

    cout << "\n\nSucasny katalog Cestovky\n\n";
    catalog->Print();


    Objednavka* order = new Objednavka(1);

    order->AddItem(1, Letnadovolenka, 1);
    order->AddItem(5, Zimnadovolenka, 3);
    order->AddItem(7, Letnadovolenka, 2);

    cout << "\n\nSucasne objednavky zakaznikov v cestocke\n";
    order->Print();


    RegistrovanyKlient* klient1 = new RegistrovanyKlient(1, "Adam", "Kuchar", "kucharik@gmail.com", "Presov");
    RegistrovanyKlient* klient2 = new RegistrovanyKlient(2, "Peter", "Kucar", "petrik@gmail.com", "Ostrava");
    RegistrovanyKlient* klient3 = new RegistrovanyKlient(3, "Matej", "Zemiak", "matejs@gmail.com", "Praha");

    CompanyUser* zamestnanec = new CompanyUser(4, "Damian", "On", "damians@gmail.com", "Cestovka");

    vector<Klient*> klienti{ klient2, klient1, klient3, zamestnanec };
    cout << "\n----------------------------";
    cout << "\nNasi sucasny ";
    cout << Klient::GetObjectsCount();
    cout << " zakaznici\n\n";
    cout << "----------------------------\n";

    for (auto klient : klienti)
    {
        klient->Print();
        cout << endl;
    }


    Objednavka* order2 = new Objednavka(2);
    order2->AddItem(1, Zimnadovolenka, 69);



    klient1->AddOrder(order);
    klient1->AddOrder(order2);
    cout << "\n\n\n------------------------------------------------\n";
    cout << "Objednavky zakaznikov\n\n";
   
    klient1->PrintOrders();


    Objednavka* order3 = new Objednavka(3);
    order3->AddItem(1, Zimnadovolenka3, 2);
    Objednavka* order4 = new Objednavka(4);
    order4->AddItem(1, Zimnadovolenka2, 1);

    klient2->AddOrder(order3);
    klient2->AddOrder(order4);
    cout << "\n\n\n------------------------------------------------\n";
    klient2->PrintOrders();

    for (auto&& customer : klienti)
    {
        delete customer;
    } 
    cout << "\nDakujeme ze ste si vybrali prave nas, do skoreho videnia!!\n";
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
