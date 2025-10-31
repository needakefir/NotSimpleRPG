//A future replacement for a attack of player and monster to simplify the logic
#include "../include/Monster.h"
#include "../include/Player.h"
#include <iostream>
#define Monster_Defeated true
#define Player_Defeated false;
Type::AttackType::Player_Attacks getTypeOfAttack();
bool Fight(Player &p,Monster& m,const char* roadline,short difficulty,int& X)
{
	std::cout << roadline;
	std::cout << "You encountered a monster!\n";
	std::cout << "His characteristics:\n";
	std::cout << m;
	std::cout << roadline;
	std::cout << "Your characterstics:\n";
	std::cout << p;
	std::cout << "Choose a attack:\n";
	do
	{
		//...
		p.attackEntity(m,getTypeOfAttack(), difficulty);
		bool ValidAttack{ m.attackPlayer(p, m.getType(), difficulty) };
		if (!ValidAttack)
		{
			std::cout << "You're a lucky guy,monster doesnt attack you\n";
		}
	} while (!m.getDefeated() && !p.getDefeated());
	if (m.getDefeated())
	{
		return Monster_Defeated;
	}
	else if (p.getDefeated())
	{
		return Player_Defeated;
	}
}
