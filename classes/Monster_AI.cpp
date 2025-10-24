#include "../include/Monster_AI.h"
#include "../include/retDamageScoreByTypeOfAttack.h"
std::pair<float, float> GetChancesOfAttack(Type::MonsterType::E_Types type, short difficulty);
int NumGen(int min, int max);
//Point of start NumGen
int start{ 1 };
void Monster_AI::setMagicChanceAttack(float value)
{
	this->MagicChanceAttack = value;
}
float Monster_AI::getMagicChanceAttack()
{
	return this->MagicChanceAttack;
}

void Monster_AI::setPhysicalChanceAttack(float value)
{
	this->PhysicalChanceAttack = value;
}
float Monster_AI::getPhysicalhanceAttack()
{
	return this->PhysicalChanceAttack;
}
bool Monster_AI::isAttackMagical(std::pair<float,float>& pair,short difficulty,Type::MonsterType::E_Types type,Type::AttackType::Magical_Monster_Attacks m)
{
	std::pair<float, float> chances{ pair };
	float tryTrue;
	while (true)
	{
		tryTrue =static_cast<float>(chances.second) * static_cast<float>(difficulty) *static_cast<float>(NumGen(start,retDamageScoreByTypeOfAttack(m)));
		if (tryTrue == retDamageScoreByTypeOfAttack(m))
		{
			return true;
		}
	} 
}
bool Monster_AI::isAttackPhysical(std::pair<float,float>& pair,short difficulty, Type::MonsterType::E_Types type, Type::AttackType::Physical_Monster_Attacks ph)
{
	std::pair<float, float> chances{ pair };
	float tryTrue;
	while (true)
	{
			tryTrue = static_cast<float>(chances.first) * static_cast<float>(difficulty) * static_cast<float>(NumGen(start, static_cast<int>(retDamageScoreByTypeOfAttack(ph))));
			if (tryTrue == retDamageScoreByTypeOfAttack(ph))
			{
				return true;
			}
	}
}