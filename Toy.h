#pragma once
#include <iostream>
#include <string>
#include "Figure.h"
#include "Capsule.h"

using namespace std;

class Toy :public Capsule,public Figure
{
public:
	Toy(const Toy& source) :Figure(source), Capsule(source) {};
	Toy(const string& name, Rarity rarity, int theme, const string& color);
	Toy (){};
	~Toy(){};
	



private:

};

