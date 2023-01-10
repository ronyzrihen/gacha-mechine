#pragma once
#include <string>

using namespace std;


class Shell_color
{
public:
	Shell_color();
	~Shell_color();
public:
	string Get_color();
private:
	string m_color;
};

