#pragma once
#include <string>
#include<iostream>
#include<stdlib.h>
#include "Capsule.h"
#include "Shell_Color.h"
#include "Toy.h"
#include "Candy.h"
using namespace std;

typedef enum {None,Dragon_ball_z,Naruto,Pokemon,Attack_on_titan,Bleach,SpyXFamily,Full_metal_alchemist}Series;


class Gatcha_machine :public Shell_color
{
public:
	Gatcha_machine() {};
    Gatcha_machine (Series theme,const string& color, int cost);
	~Gatcha_machine();
public:
	Capsule* Roll_for_capsule(int num);//todo
	bool insert_capsule(Capsule* capsule);
	int Get_cost() { return m_capsule_cost; };
    void insert_extra(Capsule* capsule);
	int get_c_size() { return c_size; };
	Series get_theme() { return m_theme; };
	void print(ostream& out);

private:
	Series m_theme;
	int m_capsule_cost;
	Capsule* capsules[10];
	Capsule** Extra_capsules;
	int c_size;
	int ec_size;
};

ostream& operator << (ostream& out, Gatcha_machine& source);