//
// Created by Ofek Eliyahu - 207753120 and Rony Zrihen - 318917549 .
//
#include "Candy.h"


Candy::Candy(const string& name, Rarity rarity, const string& flavor, const string& color) :
	Capsule(name, rarity, candy, color), Edible(flavor)
{};

