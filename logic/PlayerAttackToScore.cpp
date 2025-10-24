#include "../include/Constants and Types.h"
typedef Type::AttackType::Player_Attacks Player_A;
int PlayerAttackToScore(Player_A a)
{
    switch (a)
    {
    case Player_A::BOW:
        return StandardDamageScore::Player::StandardDamageBow;
    case Player_A::FIST:
            return StandardDamageScore::Player::StandardDamageFist;
    case Player_A::SWORD:
        return StandardDamageScore::Player::StandardDamageSword;
    }
}