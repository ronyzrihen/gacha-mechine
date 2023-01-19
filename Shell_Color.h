//
// Created by Ofek Eliyahu - 207753120 and Rony Zrihen - 318917549 .
//
#pragma once
#include <string>

using namespace std;

class Shell_color
{
public:
	Shell_color(){};
	Shell_color(const Shell_color& source) :m_color(source.m_color) {};
	Shell_color(const string& color) :m_color(color) {};
	virtual~Shell_color()=0{};
public:
	string Get_color() { return m_color; };
private:
	string m_color;
};

