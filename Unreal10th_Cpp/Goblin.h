#pragma once
#include "Monster.h"

class Goblin : public Monster
{
private:
    const int StealAmount = 30;
    const float StealRate = 0.5f;

public:
    Goblin(const std::string& InName, int InHp, int InMinDamage, int InMaxDamage, float InCriticalRate, int InCriticalMultiplier, int InReward) : Monster(InName, InHp, InMinDamage, InMaxDamage, InCriticalRate, InCriticalMultiplier, InReward) {}

    virtual void ApplyDamage(Actor& Target) const override;
};
