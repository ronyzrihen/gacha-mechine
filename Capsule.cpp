#include "Capsule.h"


Capsule::Capsule(string name, Rarity rarity, CapsuleType type, string color) :
	m_name(name), m_worth(0), m_rarity(rarity), m_type(type), Shell_color(color)

{
};


void  Capsule::calculate_rarity(float machine_cost) {

	switch (m_rarity)
	{
	case Common: {
		m_worth = machine_cost / 4;
		break;
	}
	case Rare: {
		m_worth = machine_cost/2;
		break;
	}
	case Epic: {
		m_worth = machine_cost;
		break;
	}
	case Legendary:
		m_worth = machine_cost * 1.5;
		break;
	
	}
}