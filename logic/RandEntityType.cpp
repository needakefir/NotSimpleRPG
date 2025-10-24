#include "../include/Constants and Types.h"
//Prelimitary declaration NumGen
int NumGen(int min, int max);
//Return pseudorandom type of monster....
Type::MonsterType::E_Types& RandMonsterType()
{
	short i = NumGen(1, 4);
	Type::MonsterType::E_Types  monster= static_cast<Type::MonsterType::E_Types>(i);
	return monster;
}