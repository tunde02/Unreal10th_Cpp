#include "Actor.h"
#include <stdlib.h>

void Actor::ApplyDamage(Actor& Target) const
{
    int Damage = (rand() % (MaxDamage - MinDamage)) + MinDamage;
    bool IsCritical = (rand() % 100) * 0.01f < CriticalRate;

    if (IsCritical)
    {
        Damage *= CriticalMultiplier;
    }

    Target.TakeDamage(Damage);
}

void Actor::ApplyDamage(Actor& Target, bool IsCritical) const
{
    int Damage = (rand() % (MaxDamage - MinDamage)) + MinDamage;

    if (IsCritical)
    {
        Damage *= CriticalMultiplier;
    }

    Target.TakeDamage(Damage);
}

void Actor::TakeDamage(int Damage)
{
    Hp -= Damage;
    if (Hp < 0)
    {
        Hp = 0;
    }
}

bool Actor::IsAlive() const
{
    return Hp > 0;
}
