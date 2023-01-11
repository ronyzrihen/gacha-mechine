#pragma once
#include <string>
#include<iostream>
#include<stdlib.h>
#include "Capsule.h"
#include "Toy.h"
#include "Candy.h"
using namespace std;

typedef enum {None,Dragon_ball_z,Naruto,Pokemon,Attack_on_titan,Bleach,SpyXFamily,Full_metal_alchemist}Series;


class Gatcha_machine
{
public:

	Gatcha_machine(Series theme, int cost ):m_theme(theme), m_capsule_cost(cost);
	~Gatcha_machine();
public:
	Capsule* Roll_for_capsule(int num);//todo
	bool insert_capsule(Capsule* capsule);
	int Get_cost() { return m_capsule_cost; };


private:
	Series m_theme;
	int m_capsule_cost;
	Capsule* capsules[10];
	Capsule** Extra_capsules;
	int c_size;
	int ec_size;
};

