//
// Created by Ofek Eliyahu - 207753120 and Rony Zrihen - 318917549 .
//
#include "Player.h"



Player::Player(const string& name, int money):
	m_name(name),
	m_money(money),
	m_capsules_won(NULL),
	m_size(0)
{

}


Player::Player():
	m_money(0),
	m_capsules_won(NULL),
	m_size(0)
{}



void Player::Play_machine(Gatcha_machine& gatcha_machine) {
	if (m_money < gatcha_machine.Get_cost()) {

		cout << "You don't have enough money \n";
		return;

	}
	Capsule *capsule;
		capsule=gatcha_machine.Roll_for_capsule(rand() % 10);
		if (capsule == NULL) {
			cout << "the machine is empty\n";
			return;
		 }

		if (m_size == 0) {
			m_capsules_won = new Capsule*;
			m_capsules_won[0] = capsule;
			m_size++;
			m_money -= gatcha_machine.Get_cost();
			cout << "You've got " << m_capsules_won[m_size - 1]->Get_name() << "! It's worth is : " << m_capsules_won[m_size - 1]->get_worth() << "$" << endl
				<< "Your balance is:" << m_money << "$\n";
			return;
		}

		Capsule** New_capsules = new Capsule * [m_size + 1];
		for (int i = 0; i < m_size; i++)
		{
			New_capsules[i] = m_capsules_won[i];
		}
		New_capsules[m_size]=capsule;
		delete m_capsules_won;
		m_capsules_won = New_capsules;
		m_size++;
		m_money -= gatcha_machine.Get_cost();
		 cout << "You've got " << m_capsules_won[m_size - 1]->Get_name() <<"! It's worth is : " << m_capsules_won[m_size-1]->get_worth() << "$" << endl
			 <<"Your balance:" << m_money << "$\n";
		return;
}



Player::~Player() {

	if (m_size>0)
	{
		for (int i = 0; i < m_size; i++) {

			delete m_capsules_won[i];
		}
		delete[] m_capsules_won;
	}
}