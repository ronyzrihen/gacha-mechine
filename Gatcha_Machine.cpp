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
	Candy* candy=dynamic_cast<Candy*>(capsule);
	Toy* toy = dynamic_cast<Toy*>(capsule);

	if (c_size == 10)
	{
		for (int i = 0; i <10; i++)
		{
			if (capsules[i]->get_rarity() == Legendary)
				legendary++;
			if (capsules[i]->get_rarity() == Epic)
				epic++;
		}

		if (legendary == 0)
		{
			if (capsule->get_rarity() == Legendary) {
				for (int i = 0; i < 10; i++)
				{
					if (capsules[i]->get_rarity() == Common || capsules[i]->get_rarity() == Rare) {
						if(candy==NULL)
							capsules[i] = new Toy(*toy);
						else
						{
							capsules[i] = new Candy(*candy);
						}
						if (epic < 2)
							cout << "There are less then two epic capsule in this machine \n";
						return;
					}
				}
			}
		}
		if (epic<2)
		{
			if (capsule->get_rarity() == Epic) {
				for (int i = 0; i < 10; i++)
				{
					if (capsules[i]->get_rarity() == Common || capsules[i]->get_rarity() == Rare) {
						if (candy == NULL)
							capsules[i] = new Toy(*toy);
						else
						{
							capsules[i] = new Candy(*candy);
						}
						if(legendary==0)

						return;
					}
				}
			}
		}
	}
}