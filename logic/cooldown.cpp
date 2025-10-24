#include <ctime>
#include <iostream>
#include <thread>
#include "include/Constants and Types.h"
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
std::string& cooldown(short seconds)
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
	std::cin >> target;
	for (auto& i : ContainerOfAttacks::attacks)
	{
		if (i == target)
		{
			//End of cycle
			return target;
		}
		else
		{
			std::cout << "Invalid attack or you input nothing:\n";
			std::cin >> target;

		}
	}
	target = "NULL";
	return target;
}