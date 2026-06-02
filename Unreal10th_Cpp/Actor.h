#pragma once
#include <string>

class Actor
{
protected:
    std::string Name{};
    int Hp = 0;
    int MinDamage = 0;
    int MaxDamage = 0;
    float CriticalRate = 0.0f;
    int CriticalMultiplier = 0;

public:
    Actor() = default;
    Actor(const std::string& InName, int InHp, int InMinDamage, int InMaxDamage, float InCriticalRate, int InCriticalMultiplier) : Name(InName), Hp(InHp), MinDamage(InMinDamage), MaxDamage(InMaxDamage), CriticalRate(InCriticalRate), CriticalMultiplier(InCriticalMultiplier) {}

    virtual void ApplyDamage(Actor& Target) const;
    virtual void ApplyDamage(Actor& Target, bool IsCritical) const;
    virtual void TakeDamage(int Damage);
    bool IsAlive() const;

    inline std::string GetName() const { return Name; }
    inline int GetHp() const { return Hp; }
    inline void SetHp(int InHp) { Hp = InHp; }
    inline int GetMinDamage() const { return MinDamage; }
    inline void SetMinDamage(int InMinDamage) { MinDamage = InMinDamage; }
    inline int GetMaxDamage() const { return MaxDamage; }
    inline void SetMaxDamage(int InMaxDamage) { MaxDamage = InMaxDamage; }
    inline int GetDamage() const { return (rand() % (MaxDamage - MinDamage)) + MinDamage; }
    inline float GetCriticalRate() const { return CriticalRate; }
};
