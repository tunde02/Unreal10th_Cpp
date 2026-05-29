#include "Day0529.h"

void Day0529()
{
    // 연산자 오버로딩
    MazeEnemy E1("오크", 1);
    MazeEnemy E2("슬라임", 2);

    PrintEnemyInfo(E1);
    PrintEnemyInfo(E2);

    // 간단 실습
    // 1. MazeEnemy에 -연산자 오버로딩하기
    //   E5 = E1 - E2;
    // 2. MazeEnemy에 *연산자 오버로딩하기 (*의 오른쪽 값은 float)
    //   E6 = E5 * 2;
    // 3. MazeEnemy에 *=연산자 오버로딩하기 (*의 오른쪽 값은 float)
    //   E6 *= 3;
    MazeEnemy E5 = E1 - E2;
    PrintEnemyInfo(E5);

    MazeEnemy E6 = E5 * 2.0f;
    PrintEnemyInfo(E6);

    E6 *= 3.0f;
    PrintEnemyInfo(E6);
}

void PrintEnemyInfo(MazeEnemy& InMazeEnemy)
{
    printf("-------------------------\n");
    printf("이름   : %s\n", InMazeEnemy.Name.c_str());
    printf("체력   : %d\n", InMazeEnemy.Health);
    printf("공격력 : %d ~ %d\n", InMazeEnemy.AttackPowerMin, InMazeEnemy.AttackPowerMax);
    printf("보상   : %d\n", InMazeEnemy.Reward);
    printf("-------------------------\n");
}

MazeEnemy FusionEnemy(MazeEnemy& InMazeEnemy1, MazeEnemy& InMazeEnemy2)
{
    MazeEnemy Result;
    Result.Name = InMazeEnemy1.Name + InMazeEnemy2.Name;
    Result.AttackPowerMin = (InMazeEnemy1.AttackPowerMin + InMazeEnemy2.AttackPowerMin) / 2;
    Result.AttackPowerMax = InMazeEnemy1.AttackPowerMax + InMazeEnemy2.AttackPowerMax;
    Result.Reward = InMazeEnemy1.Reward + InMazeEnemy1.Reward;

    return Result;
}
