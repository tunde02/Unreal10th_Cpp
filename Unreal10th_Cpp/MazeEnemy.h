#pragma once
#include <string>

struct MazeEnemy
{
    std::string Name = "고블린";
    int Health = 20;
    int AttackPowerMin = 5;
    int AttackPowerMax = 10;
    int Reward = 100;

    MazeEnemy()
    {
        Health = 25;
        AttackPowerMin = 3;
        AttackPowerMax = 8;
        Reward = 120;
    }

    //MazeEnemy(const std::string& InName)
    //    : Name(InName)
    //{
    //}
    MazeEnemy(const std::string& InName, int InLevel)
        : Name(InName)
    {
        Health *= InLevel;
        AttackPowerMin *= InLevel;
        AttackPowerMax *= InLevel;
        Reward *= InLevel;
    }

    // + 연산자를 오버로딩한다.
    // 결과는 MazeEnemy타입으로 나온다.
    // 계산 대상은 나와 other이다.
    // this : 자기 자신의 주소
    MazeEnemy operator+(const MazeEnemy& other) const // 이 const는 멤버를 수정하지 않는다.
    {
        MazeEnemy Result;

        Result.Name = this->Name + other.Name;
        Result.Health = this->Health + other.Health;
        Result.AttackPowerMin = (this->AttackPowerMin + other.AttackPowerMin) / 2;
        Result.AttackPowerMax = this->AttackPowerMax + other.AttackPowerMax;
        Result.Reward = this->Reward + this->Reward;

        return Result;
    }
    MazeEnemy operator-(const MazeEnemy& other) const
    {
        MazeEnemy Result;

        Result.Health = this->Health - other.Health;
        Result.AttackPowerMin = (this->AttackPowerMin - other.AttackPowerMin) / 2;
        Result.AttackPowerMax = this->AttackPowerMax - other.AttackPowerMax;
        Result.Reward = this->Reward - other.Reward;

        return Result;
    }
    MazeEnemy operator*(float FloatNumber) const
    {
        MazeEnemy Result;

        Result.Health = (int)(this->Health * FloatNumber);
        Result.AttackPowerMin = (int)(this->AttackPowerMin * FloatNumber);
        Result.AttackPowerMax = (int)(this->AttackPowerMax * FloatNumber);
        Result.Reward = (int)(this->Reward * FloatNumber);

        return Result;
    }
    MazeEnemy& operator*=(float FloatNumber)
    {
        this->Health *= FloatNumber;
        this->AttackPowerMin *= FloatNumber;
        this->AttackPowerMax *= FloatNumber;
        this->Reward *= FloatNumber;

        return *this;
    }
};