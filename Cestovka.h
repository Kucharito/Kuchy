#pragma once
#include <iostream>
#include <string>

using namespace std;
class Cestovka
{
private:
	string nazov;
public:
	Cestovka(string nazov)
	{
		this->nazov = nazov;
	}
	~Cestovka()
	{

	}
	string getNazov()
	{
		return this->nazov;
	}
	void vypis()
	{
		cout << "s nazvom " << nazov << "\n";
	}
};