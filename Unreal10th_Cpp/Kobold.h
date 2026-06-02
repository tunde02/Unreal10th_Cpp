#pragma once
#include "Monster.h"

class Kobold : public Monster
{
private:
    const float EvasionRate = 0.3f;

public:
    Kobold(const std::string& InName, int InHp, int InMinDamage, int InMaxDamage, float InCriticalRate, int InCriticalMultiplier, int InReward) : Monster(InName, InHp, InMinDamage, InMaxDamage, InCriticalRate, InCriticalMultiplier, InReward) {}

    virtual void TakeDamage(int Damage) override;
};
