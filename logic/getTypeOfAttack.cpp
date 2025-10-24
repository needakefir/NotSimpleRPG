#include <ctime>
#include <iostream>
#include <thread>
#include "../include/Constants and Types.h"
bool realCooldown(short seconds)
{
	short minusSeconds{ --seconds };
	clock_t end = seconds * CLOCKS_PER_SEC;
	clock_t start = clock();
	clock_t elapsed = clock() - start;
	do
	{
			//Check every second for input,else repeat std::cin;
			if (elapsed == (seconds - minusSeconds) * CLOCKS_PER_SEC)
			{
				--minusSeconds;
				std::cout << "Remaining seconds:" << minusSeconds << "\n";
			}
	} while (start < end);
	return true;
}
Type::AttackType::Player_Attacks getTypeOfAttack(short seconds)
{
	std::thread CD(realCooldown, seconds);
	std::string target;
	for (auto& i : ContainerOfAttacks::attacks)
	{
		std::cout << i << "    ";
	}
	std::cout << "\n";
	CD.detach();
	std::cout << "Input a type attack letter by letter:";
	do
	{
		std::cin >> target;
		for (auto& str : ContainerOfAttacks::attacks)
		{
			short i{};
			if (str!= target)
			{
				++i;
			}
			else
			{
				return static_cast<Type::AttackType::Player_Attacks>(i);
			}
		}
		std::cout << "Please input a type of attack again:";
	} while (true);
	return Type::AttackType::Player_Attacks::Null;
}