#include "../include/Increase and Reduction Damage.h"
float increaseDamage(Type::AttackType::Player_Attacks a, short difficulty)
{
	switch (difficulty)
	{
	case 1:
		return static_cast<float>(Player_Reduction_Physical_And_Magical_Factor::SimpleFactor);
	case 2:
		return static_cast<float> (Player_Reduction_Physical_And_Magical_Factor::MiddleFactor);
	case 3:
		return static_cast<float>( Player_Reduction_Physical_And_Magical_Factor::HardFactor);
	case 4:
		return static_cast<float> (Player_Reduction_Physical_And_Magical_Factor::ImposssibleFactor);
	}
}
float increaseDamage(Type::AttackType::Physical_Monster_Attacks Ph, short difficulty)
{
	switch (difficulty)
	{
	case 1:
		return static_cast<float>(Monster_Increase_Physical_And_Magical_Factor::SimpleFactor);
	case 2:
		return static_cast<float> (Monster_Increase_Physical_And_Magical_Factor::MiddleFactor);
	case 3:
		return static_cast<float>(Monster_Increase_Physical_And_Magical_Factor::HardFactor);
	case 4:
		return static_cast<float> (Monster_Increase_Physical_And_Magical_Factor::ImpossibleFactor);
	}
}
float increaseDamage(Type::AttackType::Magical_Monster_Attacks M, short difficulty)
{
	switch (difficulty)
	{
	case 1:
		return static_cast<float>(Monster_Increase_Physical_And_Magical_Factor::SimpleFactor);
	case 2:
		return static_cast<float> (Monster_Increase_Physical_And_Magical_Factor::MiddleFactor);
	case 3:
		return static_cast<float>(Monster_Increase_Physical_And_Magical_Factor::HardFactor);
	case 4:
		return static_cast<float> (Monster_Increase_Physical_And_Magical_Factor::ImpossibleFactor);
	}
}