#pragma once
#include <string>


class Figure
{
public:
	Figure(const Figure& source) : m_theme(source.m_theme) {};
	Figure():m_theme(0){};
	virtual ~Figure() = 0;

private:
	int m_theme;

public:
	int Get_category();

};

