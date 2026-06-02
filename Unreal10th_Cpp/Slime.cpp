#include "Slime.h"
#include "Player.h"

void Slime::ApplyDamage(Actor& Target) const
{
    int Damage = GetDamage();
    bool IsCritical = (rand() % 100) * 0.01f < CriticalRate;
    bool IsRust = (rand() & 100) * 0.01f < RustRate;

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

    if (IsRust)
    {
        printf("[%s의 부식] : 공격력이 %d 낮아졌습니다.\n", Name.c_str(), RustAmount);

        int PrevMinDamage = Target.GetMinDamage();
        int RustedMinDamage = PrevMinDamage - RustAmount > 5 ? PrevMinDamage - RustAmount : 5;
        int PrevMaxDamage = Target.GetMaxDamage();
        int RustedMaxDamage = PrevMaxDamage - RustAmount > 10 ? PrevMaxDamage - RustAmount : 10;

        Target.SetMinDamage(RustedMinDamage);
        Target.SetMaxDamage(RustedMaxDamage);
    }

    Target.TakeDamage(Damage);
}
