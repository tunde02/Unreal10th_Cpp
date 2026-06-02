#pragma once
#include "Monster.h"

class Slime : public Monster
{
private:
    const int RustAmount = 5;
    const float RustRate = 0.2f;

public:
    Slime(const std::string& InName, int InHp, int InMinDamage, int InMaxDamage, float InCriticalRate, int InCriticalMultiplier, int InReward) : Monster(InName, InHp, InMinDamage, InMaxDamage, InCriticalRate, InCriticalMultiplier, InReward) {}

    virtual void ApplyDamage(Actor& Target) const override;
};
