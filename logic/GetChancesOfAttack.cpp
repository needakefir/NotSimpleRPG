#include "../include/Constants and Types.h"
std::pair<float,float> GetChancesOfAttack(Type::MonsterType::E_Types type,short difficulty)
{
	std::pair<float, float> chances;
	switch (type)
	{
	case Type::MonsterType::E_Types::Witch:
		switch (difficulty)
		{
		case 1:
			 chances.first = AttackChanceForAI::MagicAttackChance::MagicSimpleWitch;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicSimpleWitch;
			break;
		case 2:
			chances.first = AttackChanceForAI::MagicAttackChance::MagicMiddleWitch;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicMiddleWitch;
			break;
		case 3:
			chances.first = AttackChanceForAI::MagicAttackChance::MagicHardWitch;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicHardWitch;
			break;
		case 4:
			chances.first = AttackChanceForAI::MagicAttackChance::MagicImpossibleWitch;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicImpossibleWitch;
			break;
		}
		break;
	case Type::MonsterType::E_Types::Knight:
		switch (difficulty)
		{
		case 1:
			chances.first = AttackChanceForAI::MagicAttackChance::MagicSimpleKnight;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicSimpleKnight;
			break;
		case 2:
			chances.first = AttackChanceForAI::MagicAttackChance::MagicMiddleKnight;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicMiddleKnight;
			break;
		case 3:
			chances.first = AttackChanceForAI::MagicAttackChance::MagicHardKnight;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicHardKnight;
			break;
		case 4:
			chances.first = AttackChanceForAI::MagicAttackChance::MagicImpossibleKnight;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicImpossibleKnight;
			break;
		}
		break;
	case Type::MonsterType::E_Types::Goblin:
		switch (difficulty)
		{
		case 1:
			chances.first = AttackChanceForAI::MagicAttackChance::MagicSimpleGoblin;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicSimpleGoblin;
			break;
		case 2:
			chances.first = AttackChanceForAI::MagicAttackChance::MagicMiddleGoblin;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicMiddleGoblin;
			break;
		case 3:
			chances.first = AttackChanceForAI::MagicAttackChance::MagicHardGoblin;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicHardGoblin;
			break;
		case 4:
			chances.first = AttackChanceForAI::MagicAttackChance::MagicImpossibleGoblin;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicImpossibleGoblin;
			break;
		}
		break;
	case Type::MonsterType::E_Types::Yeti:
		switch (difficulty)
		{
		case 1:
			chances.first = AttackChanceForAI::MagicAttackChance::MagicSimpleYeti;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicSimpleYeti;
			break;
		case 2:
			chances.first = AttackChanceForAI::MagicAttackChance::MagicMiddleYeti;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicMiddleYeti;
			break;
		case 3:
			chances.first = AttackChanceForAI::MagicAttackChance::MagicHardYeti;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicHardYeti;
			break;
		case 4:
			chances.first = AttackChanceForAI::MagicAttackChance::MagicImpossibleYeti;
			chances.second = 1.0f - AttackChanceForAI::MagicAttackChance::MagicImpossibleYeti;
			break;
		}
		break;
	}
	return chances;
}