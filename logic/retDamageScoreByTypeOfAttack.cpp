#include "../include/Constants and Types.h"
//Choose by a player attack 
int retDamageScoreByTypeOfAttack(Type::AttackType::Player_Attacks a)
{
	switch (a)
	{
		case Type::AttackType::Player_Attacks::BOW:
			return StandardDamageScore::Player::StandardDamageBow;
		case Type::AttackType::Player_Attacks::FIST:
			return StandardDamageScore::Player::StandardDamageFist;
		case Type::AttackType::Player_Attacks::SWORD:
			return StandardDamageScore::Player::StandardDamageSword;
	}
}
//Choose by a magical attack of monster
int retDamageScoreByTypeOfAttack(Type::AttackType::Magical_Monster_Attacks m)
{
	switch (m)
	{
	case Type::AttackType::Magical_Monster_Attacks::SunLight:
		return StandardDamageScore::Monster::MonstersMagicalAttack::SunLight;
	case Type::AttackType::Magical_Monster_Attacks::Thunder:
		return StandardDamageScore::Monster::MonstersMagicalAttack::Thunder;
	case Type::AttackType::Magical_Monster_Attacks::WaterCutter:
		return StandardDamageScore::Monster::MonstersMagicalAttack::WaterCutter;

	}
}
//Choose by a physical attack of monster
int retDamageScoreByTypeOfAttack(Type::AttackType::Physical_Monster_Attacks ph)
{
	switch (ph)
	{
	case Type::AttackType::Physical_Monster_Attacks::Stick:
		return StandardDamageScore::Monster::MonstersPhysicalAttack::Stick;
	case Type::AttackType::Physical_Monster_Attacks::Stone:
		return StandardDamageScore::Monster::MonstersPhysicalAttack::Stone;
	case Type::AttackType::Physical_Monster_Attacks::Sword:
		return StandardDamageScore::Monster::MonstersPhysicalAttack::Sword;
		case Type::AttackType::Physical_Monster_Attacks::ThrowSand:
			return StandardDamageScore::Monster::MonstersPhysicalAttack::ThrowSand;

	}
}