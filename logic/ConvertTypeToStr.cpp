#include "../include/Constants and Types.h"
typedef Type::AttackType::Physical_Monster_Attacks Ph_Attack;
typedef Type::AttackType::Magical_Monster_Attacks M_Attack;
std::string ConvertTypeToStr(Ph_Attack ph=Ph_Attack::Null, M_Attack m=M_Attack::Null)
{
	if (ph == Ph_Attack::Null)
		;
		else
		{
			for (size_t i{1}; i <= ContainerOfAttacks::Phys_Monster_Attacks.size(); ++i)
			{
				if (ph == static_cast<Ph_Attack>(i))
				{
					return ContainerOfAttacks::Phys_Monster_Attacks[i--];
				}
			}
		}
	if (m == M_Attack::Null)
		;
		else
		{
			for (size_t i{1}; i <= ContainerOfAttacks::Magic_Monster_Attacks.size(); ++i)
			{
				if (m == static_cast<M_Attack>(i))
				{
					return ContainerOfAttacks::Magic_Monster_Attacks[i--];
				}
			}
		}
	};