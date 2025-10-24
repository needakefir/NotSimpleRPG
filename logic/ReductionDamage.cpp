#include "../include/Constants and Types.h"
#include "../include/Increase and Reduction Damage.h"
float ReductionDamageForPlayer(short difficulty)
{
	switch (difficulty)
	{
	case 1:
		return Player_Reduction_Physical_And_Magical_Factor::SimpleFactor;
	case 2:
		return Player_Reduction_Physical_And_Magical_Factor::MiddleFactor;
	case 3:
		return Player_Reduction_Physical_And_Magical_Factor::HardFactor;
	case 4:
		return Player_Reduction_Physical_And_Magical_Factor::ImposssibleFactor;
	}
}