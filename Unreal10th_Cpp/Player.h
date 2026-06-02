#pragma once
#include "Actor.h"
#include "Position.h"

class Player : public Actor
{
private:
    const int PlayerMaxHp = 100;
    Position PlayerPosition{ -1, -1 };
    int Gold = 0;

public:
    Player(const std::string& InName, int InHp, int InMinDamage, int InMaxDamage, float InCriticalRate, int InCriticalMultiplier, Position InPosition, int InGold) : Actor(InName, InHp, InMinDamage, InMaxDamage, InCriticalRate, InCriticalMultiplier), PlayerPosition(InPosition), Gold(InGold)
    {
        if (InName == "")
        {
            Name = "플레이어";
        }
    }

    virtual void ApplyDamage(Actor& Target) const override;

    void Move(int InX, int InY);
    void EarnGold(int GoldAmount);
    void LoseGold(int GoldAmount);
    void BuyWeapon(int Price, int WeaponDamage);
    void EncounterRecovery(int RecoveryAmount);
    void EncounterTrap(int TrapDamage);
    void EncounterTreasure(int TreasureValue);

    inline void SetPosition(Position InPosition) { PlayerPosition = InPosition; }
    inline int GetX() const { return PlayerPosition.X; }
    inline int GetY() const { return PlayerPosition.Y; }
    inline int GetGold() const { return Gold; }
};
