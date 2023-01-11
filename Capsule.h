#pragma once
#include <string>
#include <iostream>
using namespace std;
typedef enum { Common, Rare, Epic, Legendary }Rarity;
typedef enum {candy, toy}CapsuleType;

class Capsule 
{
public:
	Capsule(const Capsule& source) :m_name(source.m_name), m_worth(source.m_worth), m_rarity(source.m_rarity), m_type(source.m_type) {};
	Capsule();
	virtual ~Capsule()=0;
public:
	float virtual calculate_rarity();
	CapsuleType get_Type();
	string Get_name();

private:
	string m_name;
	int m_worth;
	Rarity m_rarity;
	CapsuleType m_type;


};

