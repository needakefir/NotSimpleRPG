#pragma once
#include <map>
#include <string>
#include <vector>
#include "Entity.h"
#include "Constants and Types.h"
class Monster;
class Player : public Entity {
public:
	//Constructor
	Player(int hp, std::string& name, int X);
	void attackEntity(Monster& m, Type::AttackType::Player_Attacks a, short difficulty);
	int getX() const;
	void addX();
	void minusX();
	//Replaces a - to ! or any char
	std::map<int, Type::MonsterType::E_Types>& retMap();
	void addEntityToMap(int X, Type::MonsterType::E_Types type);
	std::vector<Type::PlayerInventoryItemType::P_Items>& retPlayerItems();
	std::map<int,bool>& retDefeated();
protected:
	//Items in Player Inventory
	std::vector<Type::PlayerInventoryItemType::P_Items> P_Items;
	//Map for Monsters
	std::map<int, Type::MonsterType::E_Types> Map_Monsters;
	//For defeated monsters and taken items
	std::map<int,bool> DefeatedMonsters;
	//X of player on road
	int P_X;
};