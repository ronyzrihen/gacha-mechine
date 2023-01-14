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
	void Play_machine(Gatcha_machine gatcha_machine);
private:
	string m_name;
	int m_money;
	Capsule** m_capsules_won;
	int m_size;
};


