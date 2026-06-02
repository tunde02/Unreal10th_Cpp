#pragma once
#include "Actor.h"

class Monster : public Actor
{
private:
    int Reward = 0;

public:
    Monster(const std::string& InName, int InHp, int InMinDamage, int InMaxDamage, float InCriticalRate, int InCriticalMultiplier, int InReward) : Actor(InName, InHp, InMinDamage, InMaxDamage, InCriticalRate, InCriticalMultiplier), Reward(InReward) {}

    inline int GetReward() const { return Reward; }
};
