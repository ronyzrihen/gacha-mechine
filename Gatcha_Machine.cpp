#include "Gatcha_Machine.h"

Gatcha_machine:: Gatcha_machine (Series theme, int cost) : m_theme(theme), m_capsule_cost(cost),Extra_capsules(NULL), c_size(0), ec_size(0) {
	memset(capsules, NULL, 10 * sizeof(Capsule*));

}


Capsule* Gatcha_machine::Roll_for_capsule(int num) {

	if (!c_size)
		return NULL;
	
	while (capsules[num]==NULL)
	{
		num = rand() % 10;
	}
	Capsule* random = capsules[num];
	capsules[num] = NULL;

	return random;


}



bool Gatcha_machine::insert_capsule(Capsule* capsule) {
	int epic = 0;
	int legendary = 0;
	if (c_size == 10)
	{
		for (int i = 0; i <10; i++)
		{
			if (capsule->get_Type() == legendary)
				legendary++;
			if (capsule->get_Type() == epic)
				epic++;
		}
	}
}