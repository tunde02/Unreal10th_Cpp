#pragma once

void Day0528();

void Day0528_String();
void Day0528_FileIO();
void Day0528_Structure();

void Day0528_Example01(const std::string& String, const char C);
void Day0528_Example02();
int Day0528_Example02_FileInput(const std::string FilePath);
int Day0528_Example02_FileOutput(const std::string FilePath, std::ios_base::openmode Openmode = std::ios::app);

struct Enemy
{
    std::string Name;
    float Health;
    float AttackPower;
    int Reward;
};

struct EnemyOrc {
    // 1. 멤버 직접 초기화
    std::string Name = "Orc";
    float Health = 100.0f;
    float AttackPower = 10.0f;
    int Reward = 5;

    //EnemyOrc() {} // 기본 생성자. 생성자가 하나도 없으면 자동으로 생긴다
    EnemyOrc() = default; // 기본 생성자를 사용한다는 의미
    EnemyOrc(std::string DefaultName) // 4. 생성자 내부 대입
    {
        Name = DefaultName;
    }
    EnemyOrc(float Modifier = 1.0f)
    {
        Health *= Modifier * 10.0f;
        AttackPower *= Modifier * 5.0f;
        Reward *= (int)(Modifier * 3.0f);
    }
    EnemyOrc(std::string _Name, float _Health, float _AttackPower, int _Reward) : Name(_Name), Health(_Health), AttackPower(_AttackPower), Reward(_Reward)
    {} // 3. 생성자 초기화 리스트
};

void Day0528_Example03_PrintEnemy1(const Enemy& Target);
void Day0528_Example03_PrintEnemy2(const Enemy* const Target);
void Day0528_Example03_PrintEnemyOrc1(const EnemyOrc& Target);
void Day0528_Example03_PrintEnemyOrc2(const EnemyOrc* const Target);
