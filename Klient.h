#pragma once

#include "Objednavka.h"
#include<vector>
#include <iostream>
using namespace std;


class Klient
{
protected:
    int id;
    vector<Order*> orders;
    static int objektCount;
public:
    Klient(int id);
    virtual ~Klient();

    virtual string ClassName() = 0;

    int GetId();
    static int GetObjectsCount();
    void AddOrder(Order* order);
    int CalculatePrice();
    void PrintOrders();

    virtual void Print();
};
Klient::Klient(int id)
{
    this->id = id;
    Klient::objektCount++;
}
Klient::~Klient()
{
    Klient::objektCount = objektCount - 1;
}

int Klient::GetId()
{
    return id;
}

void Klient::AddOrder(Order* order)
{
    orders.push_back(order);
}
int Klient::CalculatePrice()
{
    int price = 0;

    for (auto&& order : orders)
    {
        price += order->CalculatePrice();
    }

    return price;
}
void Klient::PrintOrders()
{
    this->Print();

    cout << endl << "Orders: " << endl << endl;
    cout << "***************************" << endl;

    for (auto&& order : orders)
    {
        order->Print();
        cout << endl;
        cout << "***************************" << endl;
    }



    cout << endl << "Total price: " << CalculatePrice() << endl;
}

void Klient::Print()
{
    cout << this->ClassName() << endl;
    cout << " id: " << this->id << endl;
}
int Klient::objektCount = 0;
int Klient::GetObjectsCount()
{
    return Klient::objektCount;
}


class NeregistrovanyKlient : public Klient
{
protected:
    string firstName;
    string lastName;
    string email;

public:
    NeregistrovanyKlient(int id, string firstName, string lastName, string email);
    virtual ~NeregistrovanyKlient();

    string GetFirstName();
    string GetLastName();
    string GetEmail();

    void Print();
};
NeregistrovanyKlient::NeregistrovanyKlient(int id, string firstName, string lastName, string email) : Klient(id)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
}
NeregistrovanyKlient::~NeregistrovanyKlient()
{

}

string NeregistrovanyKlient::GetFirstName()
{
    return firstName;
}
string NeregistrovanyKlient::GetLastName()
{
    return lastName;
}
string NeregistrovanyKlient::GetEmail()
{
    return email;
}

void NeregistrovanyKlient::Print()
{
    Klient::Print();
    cout << " first name: " << this->firstName << endl;
    cout << " last name: " << this->lastName << endl;
    cout << " email: " << this->email << endl;

}

class CompanyUser : public NeregistrovanyKlient
{
private:
    string company;

public:
    CompanyUser(int id, string firstName, string lastName, string email, string company);
    virtual ~CompanyUser();

    string ClassName();

    string GetCompany();

    void Print();
};

CompanyUser::CompanyUser(int id, string firstName, string lastName, string email, string company) : NeregistrovanyKlient(id, firstName, lastName, email)
{
    this->company = company;
}
CompanyUser::~CompanyUser()
{

}

string CompanyUser::ClassName()
{
    return "Zamestnanec spolocnosti";
}

string CompanyUser::GetCompany()
{
    return company;
}

void CompanyUser::Print()
{
    NeregistrovanyKlient::Print();
    cout << " company: " << this->company << endl;
}

class RegistrovanyKlient : public NeregistrovanyKlient
{
private:
    string address;

public:
    RegistrovanyKlient(int id, string firstName, string lastName, string email, string address);
    virtual ~RegistrovanyKlient();

    string ClassName();

    string GetAddress();

    void Print();
};
RegistrovanyKlient::RegistrovanyKlient(int id, string firstName, string lastName, string email, string address) : NeregistrovanyKlient(id, firstName, lastName, email)
{
    this->address = address;
}
RegistrovanyKlient::~RegistrovanyKlient()
{

}

string RegistrovanyKlient::ClassName()
{
    return "Registrovany klient";
}

string RegistrovanyKlient::GetAddress()
{
    return address;
}

void RegistrovanyKlient::Print()
{
    NeregistrovanyKlient::Print();
    cout << " address: " << this->address << endl;
}