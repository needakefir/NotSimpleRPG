#pragma once
#include <string>
#include <vector>
//Main namespace Type,that includes a needed types of attacks,monstertype and etc.
namespace Type
{
	namespace AttackType
	{
		//Potion Of Undying gives a protection from any damage before the attack
		//That needed for Monster_AI class.
		//SunLight and WaterCutter can be used by any monster,but witch has more priority
		enum class Magical_Monster_Attacks {
			Null = 1,
			PotionOfUndying,
			SunLight,
			WaterCutter,
			Thunder,
		};
		//Witch has the lowest priority of physical attack
		 enum class  Physical_Monster_Attacks {
			Null=1,
			Stone,
			ThrowSand,
			Stick,
			Sword,
		}; 
		 enum class Player_Attacks
		{
			 Null=1,
			//Physical
			BOW,
			SWORD,
			FIST
		};
		 enum class Player_Attacks_AddOns
		 {
			 //-Magical Addon to Physical
			 FireSword,
			 IceBow,
			 IronFist,
			 //-Magic
			 //BloodBending is increase a damage of player,but set a lower hp and get more chance to die from one physical or magical attack.
			 //Needs to be added in future.
		 };
	}
	namespace MonsterType {
		enum class E_Types {
			//Null-Nothing
			Null,
			Witch,
			Knight,
			Goblin,
			Yeti,
		};
	}
	namespace PlayerInventoryItemType
	{
		//FirePaper is the one of items in inventory,that give a player resistance to a fire attack;
		//A shield gives a resistance for a physical attacks of monsters;
		// IceBall gives resistance for a Ice Attacks;
		// RespawnPaper can respawn player,and player can continue the game from place he dies;
			enum class P_Items {
				FirePaper,
				Shield,
				IceBall,
				RespawnPaper,
				FireSwordPaper,
				IceBowPaper,
				IronFistPaper
			};
	}
}
//By the name of namespace its need for increasing a damage of monsters depend on difficulty
namespace Monster_Increase_Physical_And_Magical_Factor
{
	extern float SimpleFactor;
	extern float MiddleFactor;
	extern float HardFactor;
	 extern float ImpossibleFactor;
}
//Player reduction of damage by difficulty
namespace Player_Reduction_Physical_And_Magical_Factor
{
	extern float SimpleFactor;
	extern float MiddleFactor;
	extern float HardFactor;
	 extern float ImposssibleFactor;
}
//Needed for ConvertStringToType.cpp
//If you want to add new style of attacks,please pay attention to function in the top
//This function returns the type of attack you need to follow the list order according to Player_Attacks
namespace ContainerOfAttacks
{
	extern std::vector<std::string> attacks;
	extern std::vector<std::string> Phys_Monster_Attacks;
	extern std::vector<std::string> Magic_Monster_Attacks;
}
//Names needed for a registerMonster() in a Monster.cpp
namespace Names {
	extern std::string Witch;
	extern std::string Yeti;
	extern std::string Knight;
	extern std::string Goblin;
	extern std::string Null;
}
//the standard value of damage for entities
namespace StandardDamageScore
{
	namespace Player {
		extern short StandardDamageBow;
		extern short StandardDamageSword;
		extern short StandardDamageFist;
		extern short StandardDamageBloodBending;
	}
	namespace Monster {
		namespace MonstersMagicalAttack {
			extern short SunLight;
			extern short WaterCutter;
			extern short Thunder;
		}
		namespace MonstersPhysicalAttack {
			extern short Stone;
			extern short ThrowSand;
			extern short Stick;
			extern short Sword;
		}
	}
}
//this namespace stores damage scaling values ​​based on difficulty.
namespace IncreaseDamageMagicPlayerItems{
	//Fire Sword
	extern float FireSword_Simple;
	extern float FireSword_Middle;
	extern float FireSword_Hard;
	extern float FireSword_Impossible;
	//End Fire Sword
	//Ice Bow
	extern float IceBow_Simple;
	extern float IceBow_Middle;
		extern float IceBow_Hard;
	extern float IceBow_Impossible;
	//End Ice Bow
	//IronFist
	extern float IronFist_Simple;
	extern float IronFist_Middle;
	extern float IronFist_Hard;
	extern float IronFist_Impossible;
	//End Iron Fist
}
namespace AttackChanceForAI {
	namespace MagicAttackChance {
		//For a Witch
		extern float MagicSimpleWitch;
		extern float MagicMiddleWitch;
		extern float MagicHardWitch;
		extern float MagicImpossibleWitch;
		//For a Knight
		extern float MagicSimpleKnight;
		extern float MagicMiddleKnight;
		extern float MagicHardKnight;
		extern float MagicImpossibleKnight;
		//For a goblin
		extern float MagicSimpleGoblin;
		extern float MagicMiddleGoblin;
		extern float MagicHardGoblin;
		extern float MagicImpossibleGoblin;
		//For a Yeti
		extern float MagicSimpleYeti;
		extern float MagicMiddleYeti;
		extern float MagicHardYeti;
		extern float MagicImpossibleYeti;
	}
}
//Chars for ReplacFromMap.cpp
namespace Chars
{
	extern char Taken_Or_Defeated;
	extern char MonsterOnMap;
	extern char ItemMap;
}