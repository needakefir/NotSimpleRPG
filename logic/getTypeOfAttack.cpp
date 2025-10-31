#include <iostream>
#include "../include/Constants and Types.h"
Type::AttackType::Player_Attacks getTypeOfAttack()
{
	std::string target;
	for (auto& i : ContainerOfAttacks::attacks)
	{
		std::cout << i << "    ";
	}
	std::cout << "\n";
	std::cout << "Input a type attack letter by letter:";
	do
	{
		std::cin >> target;
		for (size_t i{1}; i < ContainerOfAttacks::attacks.size(); ++i)
		{
			if (target == ContainerOfAttacks::attacks[i])
			{
				std::cout << "You choosed a " << target << "\n";
				return static_cast<Type::AttackType::Player_Attacks>(++i);
			}
		}
		std::cout << "Please input a type of attack again:";
	} while (true);
	return Type::AttackType::Player_Attacks::Null;
}