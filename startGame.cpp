#include "include/Entity.h"
#include "include/Player.h"
#include <iostream>
#include <conio.h>
//Preliminary announcement of updateRoad;
int updateRoad(Player& P,short difficulty);
//global Player
int startGame(unsigned short code,std::string& name)
{
	Player p{100,name,0};
	setlocale(LC_ALL, "Russian");
	switch (code)
	{
	case 0:

		std::cout << "presss a D or d to go forward,A or a to go back\n";
		std::cout << "Press enter to continue\n";
		_getch();
		std::cout << "The map is looks like this:\n";
		_getch();
		std::cout << "===========================================================\n";
		std::cout << "O                                       +           +      \n";
		std::cout << "V---------------------------------------!-----------?------\n";
		std::cout << "===========================================================\n";
		_getch();
		std::cout << "The ! is meaning a monster,that you need to defeate\n";
		_getch();
		std::cout << "If higher will be a plus its meaning that monster got defeated before\n";
		_getch();
		std::cout << "You can get a item to inventory reaching a ?\n";
		std::cout << "But if there is + higher of ? its item wat got before,and you cant get him again!\n";
		std::cout << "There is 4 types of monster:Witch,Yeti,Kngiht,Goblin\n";
		_getch();
		std::cout << "And there are only 4 attack types: Fist, Sword, Bow, and Magic!\n";
		_getch();
		std::cout << "Magic is divided into two types: for weapons or standalone\n";
		_getch();
		std::cout << "To make the game more challenging at all stages, there will be an attack selection timeout!\n";
		_getch();
		std::cout << "Simple-15 seconds Middle-10, Hard-7, Impossible-4\n";
		_getch();
		std::cout << "All other mechanics you will discover only in the game :3\n";
		_getch();
		std::cout << "Good luck, and may the odds be ever in your favor!";
		_getch();
		break;
		//Simple
	case 1:
		return updateRoad(p, 1);
		//Middle
	case 2:
		return updateRoad(p, 2);
		break;
	case 3:
		//Hard
		return updateRoad(p, 3);
		break;
		//Impossible
	case 4:
		return updateRoad(p, 4);
		break;
		//Do nothing
	default:
		;
	}
}