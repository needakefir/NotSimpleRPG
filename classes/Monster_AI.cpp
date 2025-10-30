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
bool Monster_AI::isAttackMagical(std::pair<float, float>& pair, short difficulty, Type::MonsterType::E_Types type, Type::AttackType::Magical_Monster_Attacks m)
{
	if (m == Type::AttackType::Magical_Monster_Attacks::Null)
		return false;
	float tryTrue;
	if (pair.first > pair.second)
	{
		tryTrue= pair.first * NumGen(start * difficulty,retDamageScoreByTypeOfAttack(m) * difficulty);
	}
	else { tryTrue = pair.first/1.4f * NumGen(start, retDamageScoreByTypeOfAttack(m)); }
	if(tryTrue>=(retDamageScoreByTypeOfAttack(m)/2.0f))
		return true;
	else
		return false;
}
bool Monster_AI::isAttackPhysical(std::pair<float, float>& pair, short difficulty, Type::MonsterType::E_Types type, Type::AttackType::Physical_Monster_Attacks ph)
{
	if (ph == Type::AttackType::Physical_Monster_Attacks::Null)
		return false;
	float tryTrue;
	if (pair.second > pair.first)
	{
		tryTrue = pair.second * NumGen(start * difficulty, retDamageScoreByTypeOfAttack(ph) * difficulty);
	}
	else { tryTrue = pair.second / 1.4f * NumGen(start, retDamageScoreByTypeOfAttack(ph)); }
	if (tryTrue >= (retDamageScoreByTypeOfAttack(ph) / 2.0f))
		return true;
	else
		return false;
}