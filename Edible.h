#pragma once
#include <string>
using namespace std;

class Edible 
{
public:
	Edible();
	~Edible();

public:
	string Get_flavor();

private:
	string m_flavor;

};

