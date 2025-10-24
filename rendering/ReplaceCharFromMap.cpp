#include <map>
#include "../include/Constants and Types.h"
void replaceCharFromMap(char* BodyPlayer,char* HeadPlayer, short length, short countRoad,std::map<int,bool>& Defeated,std::map<int,bool>& Taken)
{
	for (int i{ length * (countRoad - 1) }; i < length * countRoad; ++i)
	{
		if (Defeated.count(i))
		{
			BodyPlayer[i-length*(countRoad-1)] = Chars::MonsterOnMap;
			if (Defeated.find(i)->second == true)
			{
				HeadPlayer[(i-length*countRoad)+countRoad] = Chars::Taken_Or_Defeated;
			}
		}
	}
	for (int i{ length * (countRoad - 1) }; i < length * countRoad; ++i)
	{
		if (Taken.count(i))
		{
			BodyPlayer[i - length * (countRoad-1)] = Chars::ItemMap;
			if (Taken.find(i)->second == true)
			{
				HeadPlayer[(i - length * countRoad) + countRoad] = Chars::Taken_Or_Defeated;
			}
		}
	}
}