#include "Toy.h"


Toy::Toy(const string& name, Rarity rarity, int theme, const string& color)
	:
	Capsule(name, rarity, toy, color), 
	Figure(theme) {}


