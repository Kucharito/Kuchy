
#include <vector>
#include <string>
#include "Objednavka.h"
using namespace std;

class AbstractCustomer
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
    int vypocitajCenu()
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
        cout << vypocitajCenu();
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
};