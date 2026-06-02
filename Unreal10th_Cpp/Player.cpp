#include "Player.h"

void Player::ApplyDamage(Actor& Target) const
{
    int Damage = GetDamage();
    bool IsCritical = (rand() % 100) * 0.01f < CriticalRate;

    if (IsCritical)
    {
        Damage *= CriticalMultiplier;
    }

    if (!IsCritical)
    {
        printf("[%s의 공격] : %d\n", Name.c_str(), Damage);
    }
    else
    {
        printf("[%s의 공격 (크리티컬!)] : %d\n", Name.c_str(), Damage);
    }

    Target.TakeDamage(Damage);
}

void Player::Move(int InX, int InY)
{
    PlayerPosition = PlayerPosition + Position{ InX, InY };
}

void Player::EarnGold(int GoldAmount)
{
    Gold += GoldAmount;
}

void Player::LoseGold(int GoldAmount)
{
    Gold -= GoldAmount;
}

void Player::BuyWeapon(int Price, int WeaponDamage)
{
    if (Gold >= Price)
    {
        printf("\n[무기를 구입했습니다!]\n");
        printf("플레이어의 공격력이 %d 증가합니다.\n", WeaponDamage);

        LoseGold(Price);
        MinDamage += WeaponDamage;
        MaxDamage += WeaponDamage;
    }
    else
    {
        printf("\n[소지 금액이 부족합니다...]\n");
    }
}

void Player::EncounterRecovery(int RecoveryAmount)
{
    printf("[쉼터를 발견했습니다.]\n");
    printf("플레이어가 체력을 %d 회복합니다\n", RecoveryAmount);

    Hp += RecoveryAmount;
    if (Hp > PlayerMaxHp)
    {
        Hp = PlayerMaxHp;
    }
}

void Player::EncounterTrap(int TrapDamage)
{
    printf("[함정을 밟았습니다...]\n");
    printf("플레이어가 체력을 %d 잃습니다\n", TrapDamage);

    TakeDamage(TrapDamage);
}

void Player::EncounterTreasure(int TreasureValue)
{
    printf("[보물을 발견했습니다!!]\n");
    printf("플레이어가 %dg 를 얻었습니다\n", TreasureValue);

    Gold += TreasureValue;
}
