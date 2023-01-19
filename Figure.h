//
// Created by Ofek Eliyahu - 207753120 and Rony Zrihen - 318917549 .
//
#pragma once
#include <string>
#include "Gatcha_Machine.h"



class Figure
{
public:
	Figure():m_theme(0) {};
	Figure(const Figure& source) : m_theme(source.m_theme) {};
	Figure(int theme):m_theme(theme){};
	virtual ~Figure() = 0{};

private:
	int m_theme;

public:
	int Get_category() { return m_theme; };

};

