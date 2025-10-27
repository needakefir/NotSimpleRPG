#include <iostream>
#include <conio.h>
#include "../include/Constants and Types.h"
#include "../include/Increase and Reduction Damage.h"
#include "../include/Entity.h"
#include "../include/Player.h"
#include "../include/Monster.h"
//If player dies,the return this 
constexpr auto Player_Fail = -1;
//For a updating road
constexpr auto RoadLength = 60;
//Pre-announcement of needed functions
//The description of functions in their files
void replaceCharFromMap(char* BodyPlayer, char* HeadPlayer, short length, short countRoad, std::map<int,bool>& Defeated, std::map<int,bool>& Taken);
int NumGen(int min, int max);
Type::MonsterType::E_Types RandMonsterType();
void printRoad(const char* HeadPlayer, const char* BodyPlayer, const char* roadline);
//------
//For road coordinate
unsigned int i{};
//---------
//If player getting value more than 78*N,where N is 1,2,3,4 and etc,then we need to increment a number
short countRoad{1};
//-------------------------
//Last position of defeated monster
int last{INT16_MAX};
//-------------------------
//For generation of coordinate of monster
int X;
//------------------------------
//Also for generating a monster(type)
Type::MonsterType::E_Types type;
//For a fight beetween monster and player
bool isMonsterDefeated;
//--------------------------------------
char roadline[]{   "===========================================================\n" };
char HeadPlayer[]{ "O                                                          \n" };
char BodyPlayer[]{ "V----------------------------------------------------------\n" };
//--------------------------------
bool Fight(Player& p, Monster& m, short cooldownDur, const char* roadline, short difficulty, int& X);
int updateRoad(Player& p, short difficulty)
{
	//For a cin
	std::string chooseAttack;
	//Cooldown Durablity for a func cooldown(line 9)
	short cooldownDur;
	//Initialization of cooldown
	switch (difficulty)
	{
	case 1:
		cooldownDur = cooldownDurablity::SimpleCooldown;
		break;
	case 2:
		cooldownDur = cooldownDurablity::MiddleCooldown;
		break;
	case 3:
		cooldownDur = cooldownDurablity::HardCooldown;
		break;
	case 4:
		cooldownDur = cooldownDurablity::ImpossibleCooldown;
		break;
	}
	Monster m{ 0,Names::Null,Type::MonsterType::E_Types::Null };
	//Generate type of monster
	type = RandMonsterType();
	//Generate X for monster
	X = p.getX() + NumGen(5, 8);
	//Register monster
	m.registerMonster(type);
	//Print Road
	printRoad(HeadPlayer, BodyPlayer, roadline);
	char Ctrl;
	while (true) {
		Ctrl = _getch();
	if (Ctrl == 'D' || Ctrl == 'd')
		{
			//Swapping an elements of road like: 1,2 | 2,1
			system("cls");
			std::swap(HeadPlayer[i], HeadPlayer[i + 1]);
			std::swap(BodyPlayer[i], BodyPlayer[i + 1]);
			printRoad(HeadPlayer, BodyPlayer, roadline);
			++i;
			p.addX();
			if (p.getX() == RoadLength * countRoad)
			{
				std::swap(HeadPlayer[0], HeadPlayer[RoadLength]);
				std::swap(BodyPlayer[0], BodyPlayer[RoadLength]);
				++countRoad;
				i = 0;
				system("cls");
				printRoad(HeadPlayer, BodyPlayer, roadline);
			}
			//If player reaches the X then we attack the monster.If successful,then generate new
			if (p.getX() == X)
			{
				system("pause");
				isMonsterDefeated = Fight(p, m, cooldownDur, roadline,difficulty,X);
				if (isMonsterDefeated) {
					//Adding to Monster Map
					p.addEntityToMap(X, m.getType());
					//Getting new next monster
					type = RandMonsterType();
					//Init a last position of defeated monster
					last = X;
					//Generate a new monster position
					X = p.getX() + NumGen(5, 8);
					m.registerMonster(type);
				}
				else {
					std::cout << "Game over,you loosed..." << p.getName();
					return Player_Fail;
				}
			}
		}
		if (Ctrl == 'a' || Ctrl == 'A')
		{
			if (i != 0)
			{
				system("cls");
				std::swap(HeadPlayer[i - 1], HeadPlayer[i]);
				std::swap(BodyPlayer[i - 1], BodyPlayer[i]);
				printRoad(HeadPlayer, BodyPlayer, roadline);
				p.minusX();
				--i;
			}
			else
			{
				if (countRoad > 1)
				{
					system("cls");
					--countRoad;
					replaceCharFromMap(BodyPlayer, HeadPlayer, RoadLength, countRoad, p.retDefeated(), p.retTaken());
					//Swapping an elements of road like: -,? | ?,-
					std::swap(HeadPlayer[i - 1], HeadPlayer[i]);
					std::swap(BodyPlayer[i - 1], BodyPlayer[i]);
					printRoad(HeadPlayer, BodyPlayer, roadline);
					p.minusX();
					--i;
				}
				else
				{
					std::cout << "You cant enter this area\n";
				}
			}
			//If player reaches the position of last monster,then init this monster
			if (p.getX() == last)
			{
				//Init last defeated monster,if player reaches his coordinates in X
				type = p.retMap().find(X)->second;
				m.registerMonster(type);
				isMonsterDefeated = Fight(p, m, cooldownDur, roadline, difficulty, X);
				if (isMonsterDefeated)
					continue;
				else
				{
					std::cout << "Game over,you loosed..." << p.getName();
					return Player_Fail;
				}
			}

		}
	}
}