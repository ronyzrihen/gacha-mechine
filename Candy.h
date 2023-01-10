#pragma once
#include <string>
#include <iostream>
#include "Capsule.h"
#include "Edible.h"
using namespace std;


class Candy :public Capsule, public Edible
{
public:
	Candy();
	~Candy();

private:

};

