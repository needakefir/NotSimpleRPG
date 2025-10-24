#pragma once
#include "Monster_AI.h"
#include "Constants and Types.h"
#include "Entity.h"
#include <string>
class Player;
class Monster : public Entity
{
public:
	Monster(int hp,std::string& name,Type::MonsterType::E_Types type);
	void setType(Type::MonsterType::E_Types type);
	Type::MonsterType::E_Types getType();
	bool attackPlayer(Player &p, Type::MonsterType::E_Types, short difficulty);
	void registerMonster(Type::MonsterType::E_Types type);
protected: 
	Monster_AI AI;
	Type::MonsterType::E_Types M_type;
	Type::AttackType::Magical_Monster_Attacks M_A;
	Type::AttackType::Physical_Monster_Attacks Ph_A;
};