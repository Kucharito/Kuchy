#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Osoba
{
protected:
	string meno;
	string priezvisko;
	int vek;

public:
	Osoba(string meno, string priezvisko, int vek)
	{
		this->meno = meno;
		this->priezvisko = priezvisko;
		this->vek = vek;
	}
	virtual ~Osoba()
	{

	}
	virtual string Meno() = 0;
	string getMeno()
	{
		return this->meno;
	}
	string getPriezvisko()
	{
		return this->priezvisko;
	}
	int getVek()
	{
		return this->vek;
	}
	virtual void vypis()
	{
		cout << "" << this->Meno() << "\n";
		cout << "----------------------------\n";
		cout << "Meno je " << meno << "\n";
		cout << "Priezvisko je " << priezvisko << "\n";
		cout << "vek je " << vek << "\n";
	}
};
class pisak : public Osoba
{
private:
	string adresa;
	float vyplata;
	string nazovpartnera;
	int kontrakt;
public:
	pisak(string meno, string priezvisko, int vek, string adresa, float vyplata, string nazovpartnera, int kontrakt) : Osoba(meno, priezvisko, vek)
	{
		this->adresa = adresa;
		this->vyplata = vyplata;
		this->nazovpartnera = nazovpartnera;
		this->kontrakt = kontrakt;
	}
	pisak(string meno, string priezvisko, int vek, string adresa, float vyplata) :Osoba(meno, priezvisko, vek)
	{
		this->vyplata = vyplata;
		this->adresa = adresa;
		this->nazovpartnera = " Ziaden";
		this->kontrakt = NULL;
	}
	virtual ~pisak()
	{

	}
	string getAdresa()
	{
		return this->adresa;
	}
	float getVyplata()
	{
		return this->vyplata;
	}
	string getNazovpartnera()
	{
		return this->nazovpartnera;
	}
	int getKontrakt()
	{
		return this->kontrakt;
	}
	string Meno()
	{
		return "Majitel";
	}
	void vypis()
	{
		Osoba::vypis();
		cout << "toto je adresa " << adresa << "\n";
		cout << "Toto je vyplata " << vyplata << "\n";
		cout << "Nazov partnera " << nazovpartnera << "\n";
		cout << "Pocet rokov na ako dlho je podpisany kontrakt s partnerom: " << kontrakt << "\n";
	}
};