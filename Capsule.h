#pragma once
#include <string>
#include <iostream>
#include "Shell_Color.h"
using namespace std;
typedef enum { Common, Rare, Epic, Legendary }Rarity;
typedef enum {candy, toy}CapsuleType;

class Capsule:public Shell_color
{
public:
	Capsule(const Capsule& source) :Shell_color(source), m_name(source.m_name), m_worth(source.m_worth), m_rarity(source.m_rarity), m_type(source.m_type) {};
	Capsule():m_name(""),m_worth(0),m_rarity(Common),m_type(candy) {};
	Capsule(string name, Rarity rarity, CapsuleType type, string color);
	virtual ~Capsule()=0{};
public:
	//float virtual calculate_rarity();
	CapsuleType get_Type() { return m_type; };
	string Get_name() { return m_name; };
	Rarity get_rarity() { return m_rarity; };
private:
	string m_name;
	float m_worth;
	Rarity m_rarity;
	CapsuleType m_type;


};

