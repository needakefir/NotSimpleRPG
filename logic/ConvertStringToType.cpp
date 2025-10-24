#include "../include/Constants and Types.h"
Type::AttackType::Player_Attacks ConvertStringToType( const std::string& source)
{
	short i{};
	for (auto& str : ContainerOfAttacks::attacks)
	{
		if (str == source)
		{
			return static_cast<Type::AttackType::Player_Attacks>(i);
		}
		++i;
	}
}
