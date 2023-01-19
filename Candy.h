//
// Created by Ofek Eliyahu - 207753120 and Rony Zrihen - 318917549 .
//
#pragma once
#include <string>
#include <iostream>
#include "Capsule.h"
#include "Edible.h"
using namespace std;


class Candy :public Capsule, public Edible
{
public:
	Candy(){};
	Candy(const Candy& source) :Capsule(source), Edible(source) {};
	Candy(const string &name, Rarity rarity, const string& flavor, const string& color);
	~Candy(){};

private:

};

