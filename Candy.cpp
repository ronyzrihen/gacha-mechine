#include "Candy.h"


Candy::Candy(const string& name, Rarity rarity, const string& flavor, const string& color) :
	Capsule(name, rarity, candy, color), Edible(flavor)
{};

