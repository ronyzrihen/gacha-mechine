//
// Created by Ofek Eliyahu - 207753120 and Rony Zrihen - 318917549 .
//
#include "Toy.h"


Toy::Toy(const string& name, Rarity rarity, int theme, const string& color)
	:
	Capsule(name, rarity, toy, color), 
	Figure(theme) {}


