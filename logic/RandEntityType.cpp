#include "../include/Constants and Types.h"
//Prelimitary declaration NumGen
int NumGen(int min, int max);
//Return pseudorandom type of monster....
Type::MonsterType::E_Types RandMonsterType()
{
	return static_cast<Type::MonsterType::E_Types>(NumGen(1, 4));
}