//
// Created by Ofek Eliyahu - 207753120 and Rony Zrihen - 318917549 .
//
#pragma once
#include <iostream>
#include<string>
#include<stdlib.h>
#include "Capsule.h"
#include "Gatcha_Machine.h"
using namespace std;



class Player
{
public:
	Player();
	Player(const string& name, int money);
	~Player();
public:
	void Play_machine(Gatcha_machine& gatcha_machine);
private:

	int m_size;
	int m_money;
	string m_name;
	Capsule** m_capsules_won;
};


