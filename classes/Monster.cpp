#include "../include/Constants and Types.h"
#include "../include/Monster.h"
#include "../include/Player.h"
#include "../include/Increase and Reduction Damage.h"
#include "../include/retDamageScoreByTypeOfAttack.h"
#include "../include/Entity.h"
#include "../include/Monster_AI.h"
int NumGen(int min, int max);
//Using typedef to minimize difficulty
typedef Type::AttackType::Physical_Monster_Attacks Ph_Attack;
typedef Type::AttackType::Magical_Monster_Attacks M_Attack;
std::pair<float, float> GetChancesOfAttack(Type::MonsterType::E_Types type, short difficulty);
Monster::Monster(int hp,std::string& name, Type::MonsterType::E_Types type) :Entity(hp, name), M_type(type) {}
bool Monster::attackPlayer(Player& p,Type::MonsterType::E_Types type, short difficulty)
{
	//rand%(rand-min+1)+min
	Ph_Attack ph{ static_cast<Ph_Attack>(NumGen(-1,3)) };
	M_Attack m{ static_cast<M_Attack>(NumGen(-1,3)) };
	//For every type getting chance of any type of attack for AI.
	std::pair<float, float> chances{ GetChancesOfAttack(type,difficulty) };
	//Setting a AI 
	this->AI.setMagicChanceAttack(chances.first);
	this->AI.setPhysicalChanceAttack(chances.second);
	//----------------------------------------
	bool Magic = this->AI.isAttackMagical(chances, difficulty, type, m);
	bool Physical = this->AI.isAttackPhysical(chances,difficulty, type, ph);
	while (true)
	{
		//If Magic and Physical is true,then trying to get one of parameters true.
		if (Magic ^ Physical)
		{
			Magic = this->AI.isAttackMagical(chances,difficulty, type, m);
			Physical = this->AI.isAttackPhysical(chances,difficulty, type, ph);
		}
	}
	if (Magic)
	{
		if (m != M_Attack::Null)
			p.setHP(p.getHP() - static_cast<float>(retDamageScoreByTypeOfAttack(m) * increaseDamage(m, difficulty)));
		else
		{
			return false;
		}
		if (Physical)
		{
			if (ph != Ph_Attack::Null)
			{
				p.setHP(p.getHP() - static_cast<float>(retDamageScoreByTypeOfAttack(ph) * increaseDamage(ph, difficulty)));
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}
//Needs to add hp per difficulty
void Monster::registerMonster(Type::MonsterType::E_Types type)
{
		switch (type)
		{
		case Type::MonsterType::E_Types::Witch:
			this->setHP(130);
			this->setName(Names::Witch);
			this->setType(Type::MonsterType::E_Types::Witch);
			break;
		case Type::MonsterType::E_Types::Knight:
			this->setHP(180);
			this->setName(Names::Knight);
			this->setType(Type::MonsterType::E_Types::Knight);
			break;
		case Type::MonsterType::E_Types::Goblin:
			this->setHP(90);
			this->setName(Names::Goblin);
			this->setType(Type::MonsterType::E_Types::Goblin);
			break;
		case Type::MonsterType::E_Types::Yeti:
			this->setHP(250);
			this->setName(Names::Yeti);
			this->setType(Type::MonsterType::E_Types::Yeti);
			break;
		}
}
Type::MonsterType::E_Types Monster::getType()
{
	return this->M_type;
}
void Monster::setType(Type::MonsterType::E_Types type){this->M_type = type;}