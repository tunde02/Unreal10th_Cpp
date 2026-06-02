#include "Kobold.h"

void Kobold::TakeDamage(int Damage)
{
    bool IsEvaded = (rand() % 100) * 0.01f < EvasionRate;

    if (IsEvaded)
    {
        printf("[%s의 회피] : %s가 공격을 회피해 데미지를 받지 않았습니다.\n", Name.c_str(), Name.c_str());
    }
    else
    {
        Actor::TakeDamage(Damage);
    }
}
