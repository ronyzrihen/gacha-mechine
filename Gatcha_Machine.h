#pragma once
#include <string>
#include "Capsule.h"

typedef enum {None,Dragon_ball_z,Naruto,Pokemon,Attack_on_titan,Bleach,SpyXFamily,Full_metal_alchemist}Series;


class Gatcha_machine
{
public:
	Gatcha_machine();
	~Gatcha_machine();
public:
	Capsule* Roll_for_capsule(int num);//todo
	bool insert_capsule(Capsule capsule);
	int Get_cost() { return m_capsule_cost; };


private:
	Series m_theme;
	int m_capsule_cost;
	Capsule** capsules;
	Capsule** Extra_capsules;

};

