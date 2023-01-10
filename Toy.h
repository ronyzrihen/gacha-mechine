#pragma once
#include <iostream>
#include <string>
#include "Figure.h"
#include "Capsule.h"


class Toy :public Capsule,public Figure
{
public:
	Toy ();
	~Toy();

private:

};

