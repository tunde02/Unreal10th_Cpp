#include "Goblin.h"
#include "Player.h"

void Goblin::ApplyDamage(Actor& Target) const
{
    int Damage = GetDamage();
    bool IsCritical = (rand() % 100) * 0.01f < CriticalRate;
    bool IsSteal = (rand() & 100) * 0.01f < StealRate;

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

    if (IsSteal)
    {
        printf("[%s의 도둑질] : 골드를 %d 잃습니다.\n", Name.c_str(), StealAmount);

        Player* MyPlayer = dynamic_cast<Player*>(&Target);
        if (MyPlayer != nullptr)
        {
            MyPlayer->LoseGold(StealAmount);
        }
    }

    Target.TakeDamage(Damage);
}
