#pragma once
#include "../include/Constants and Types.h"
//Main namespace Type,that includes a needed types of attacks,monstertype and etc.
//By the name of namespace its need for increasing a damage of monsters depend on difficulty
namespace Monster_Increase_Physical_And_Magical_Factor
{
	extern float SimpleFactor{ 1.0f };
	extern float MiddleFactor{ 1.45f };
	extern float HardFactor{ 1.9f };
	extern float ImpossibleFactor{ 2.4f };
}
//Player reduction of damage by difficulty
namespace Player_Reduction_Physical_And_Magical_Factor
{
	extern float SimpleFactor{ 1.5f };
	extern float MiddleFactor{ 1.1f };
	extern float HardFactor{ 0.8f };
	extern float ImposssibleFactor{ 0.5f };
}
//Needed for ConvertStringToType.cpp
//If you want to add new style of attacks,please pay attention to function in the top
//This function returns the type of attack you need to follow the list order according to Player_Attacks
namespace ContainerOfAttacks
{
	extern std::vector<std::string> attacks{"Null","Bow","Sword","Fist"};
	extern std::vector<std::string> Phys_Monster_Attacks{ "NULL","Stone","ThrowSand","Stick","Sword" };
	extern std::vector<std::string> Magic_Monster_Attacks{"NULL","PotionOfUndying","SunLight","WaterCutter","Thunder"};
}
//Names needed for a registerMonster() in a Monster.cpp
namespace Names {
	extern std::string Witch{ "Witch" };
	extern std::string Yeti{ "Yeti" };
	extern std::string Knight{ "Knight" };
	extern std::string Goblin{ "Goblin" };
	extern std::string Null{ "NULL" };
}
//Needed a for function cooldown in cooldown.cpp
namespace cooldownDurablity
{
	extern int SimpleCooldown(15);
	extern int MiddleCooldown(10);
	extern int HardCooldown(7);
	extern int ImpossibleCooldown(4);
}
//the standard value of damage for entities
namespace StandardDamageScore
{
	namespace Player {
		extern short StandardDamageBow(20);
		extern short StandardDamageSword(25);
		extern short StandardDamageFist(10);
		extern short StandardDamageBloodBending(50);
	}
	namespace Monster {
		namespace MonstersMagicalAttack {
			extern short SunLight(35);
			extern short WaterCutter(25);
			extern short Thunder(40);
		}
		namespace MonstersPhysicalAttack {
			extern short Stone(15);
			extern short ThrowSand(10);
			extern short Stick(8);
			extern short Sword(20);
		}
	}
}
//this namespace stores damage scaling values ​​based on difficulty.
namespace IncreaseDamageMagicPlayerItems {
	//Fire Sword
	extern float FireSword_Simple{ 1.8f };
	extern float FireSword_Middle{ 1.6f };
	extern float FireSword_Hard{ 1.4f };
	extern float FireSword_Impossible{ 1.2f };
	//End Fire Sword
	//Ice Bow
	extern float IceBow_Simple{ 1.9f };
	extern float IceBow_Middle{ 1.7f };
	extern float IceBow_Hard{ 1.5f };
	extern float IceBow_Impossible{ 1.3f };
	//End Ice Bow
	//IronFist
	extern float IronFist_Simple{ 1.7f };
	extern float IronFist_Middle{ 1.5f };
	extern float IronFist_Hard{ 1.3f };
	extern float IronFist_Impossible{ 1.1f };
	//End Iron Fist
}
namespace AttackChanceForAI {
	namespace MagicAttackChance {
		//For a Witch
		extern float MagicSimpleWitch{ 0.65f };
		extern float MagicMiddleWitch{ 0.7f };
		extern float MagicHardWitch{ 0.8f };
		extern float MagicImpossibleWitch{ 0.95f };
		//For a Knight
		extern float MagicSimpleKnight{ 0.1f };
		extern float MagicMiddleKnight{ 0.15f };
		extern float MagicHardKnight{ 0.25f };
		extern float MagicImpossibleKnight{ 0.3f };
		//For a goblin
		extern float MagicSimpleGoblin{ 0.01f };
		extern float MagicMiddleGoblin{ 0.03f };
		extern float MagicHardGoblin{ 0.07f };
		extern float MagicImpossibleGoblin{ 0.1f };
		//For a Yeti
		extern float MagicSimpleYeti{ 0.15f };
		extern float MagicMiddleYeti{ 0.2f };
		extern float MagicHardYeti{ 0.3f };
		extern float MagicImpossibleYeti{ 0.35f };
	}
}
//Chars for ReplacFromMap.cpp
namespace Chars
{
	extern char Taken_Or_Defeated{ '+' };
	extern char MonsterOnMap{ '!' };
	extern char ItemMap{ '?' };
}