#pragma once
#include <string>
#include <iostream>
using namespace std;
typedef enum { Common, Rare, Epic, Legendary }Rarity;
typedef enum {Candy, Toy}CapsuleType;

class Capsule 
{
public:
	Capsule();
	virtual ~Capsule()=0;
public:
	float virtual calculate_rarity();
	CapsuleType get_Type();
	string Get_name();
private:
	string m_name;
	int m_worth;
	Rarity rarity;
	CapsuleType type;


};

