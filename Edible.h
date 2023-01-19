//
// Created by Ofek Eliyahu - 207753120 and Rony Zrihen - 318917549 .
//
#pragma once
#include <string>
using namespace std;

class Edible 
{
public:
	Edible(){};
	Edible(const Edible& source) : m_flavor(source.m_flavor) {};
	Edible(string flavor) :m_flavor(flavor) {};
	virtual ~Edible() = 0{};

public:
	string Get_flavor() { return m_flavor; };

private:
	string m_flavor;

};

