#include "../include/Monster_AI.h"
#include "../include/retDamageScoreByTypeOfAttack.h"
std::pair<float, float> GetChancesOfAttack(Type::MonsterType::E_Types type, short difficulty);
int NumGen(int min, int max);
//Point of start NumGen
//Must be in future depended by type of entity,like more chance to magic attack.
//But this can do a infinite loop,so...
//It need a fast generator to simple mode and more difficult to impossible.
int start{5};
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
bool Monster_AI::isAttackPhysical(std::pair<float, float>& pair, short difficulty, Type::MonsterType::E_Types type, Type::AttackType::Physical_Monster_Attacks ph)
{
	if (ph == Type::AttackType::Physical_Monster_Attacks::Null)
		return false;
	std::pair<float, float> chances{ pair };
	float tryTrue;
	//Also....
	//The r-value 2 is meaning nothing,just for a generation of attack
	//In the future this value will be depended by difficulty
	tryTrue = static_cast<float>(chances.first) * static_cast<float>(difficulty) * static_cast<float>(NumGen(start, retDamageScoreByTypeOfAttack(ph)) * 2);
	if (tryTrue >= retDamageScoreByTypeOfAttack(ph)*0.3f)
	{
		return true;
	}
	else
		return false;

}
bool Monster_AI::isAttackMagical(std::pair<float,float>& pair,short difficulty,Type::MonsterType::E_Types type,Type::AttackType::Magical_Monster_Attacks m)
{
	if (m == Type::AttackType::Magical_Monster_Attacks::Null)
		return false;
	std::pair<float, float> chances{ pair };
	float tryTrue;
		//The r-value 2 is meaning nothing,just for a generation of attack
		//In the future this value will be depended by difficulty
		tryTrue =static_cast<float>(chances.second) * static_cast<float>(difficulty) *static_cast<float>(NumGen(start,retDamageScoreByTypeOfAttack(m))*2);
		if (tryTrue >= retDamageScoreByTypeOfAttack(m)*chances.first)
		{
			return true;
		}
		else
			return false;
}
