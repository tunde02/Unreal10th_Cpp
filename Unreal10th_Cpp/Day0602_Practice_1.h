#pragma once
#include <string>
#include "Position.h"
#include "Player.h"
#include "Monster.h"

/*
미로 탈출 게임에 클래스 적용하기
- 적과 플레이어의 부모인 Actor 클래스 만들기
  - 공통 함수로 ApplyDamage, TakeDamage가 있어야 한다.
- Player 클래스 만들고 적용하기(Actor를 상속 받아야 함)
- Monster 클래스 만들기(Actor를 상속 받아야 함)
- 3종류 이상의 몬스터 클래스 만들기(Monster 클래스를 상속 받아야 함)
- 전투시 랜덤한 몬스터가 등장하게 수정
- 결과는 플레이 영상 링크 제출
*/

namespace Day0602_Practice_1
{
    void Day0602_Practice_1();

    enum TileType
    {
        TT_Road			= 0,
        TT_Wall			= 1,
        TT_Start		= 2,
        TT_End			= 3,
        TT_Player		= 4,
        TT_Grave		= 5,
        TT_Monster		= 6,
        TT_BossMonster	= 7,
        TT_Shop			= 8,
        TT_Recovery		= 9,
        TT_Trap			= 10,
        TT_Treasure		= 11
    };

    enum DirectionType
    {
        DT_Up,
        DT_Down,
        DT_Left,
        DT_Right
    };

    enum EncounterType
    {
        ET_None,
        ET_Monster,
        ET_Shop,
        ET_Recovery,
        ET_Trap,
        ET_Treasure
    };

    const int EncounterRate					= 40;
    const int PlayerInitialHP				= 100;
    const int PlayerInitialGold				= 1000;
    const int PlayerInitialMinimumDamage	= 10;
    const int PlayerInitialMaximumDamage	= 15;
    const int MonsterInitialHP				= 100;
    const int MonsterDefaultReward			= 300;
    const int MonsterMinimumDamage			= 5;
    const int MonsterMaximumDamage			= 10;
    const float InitialCriticalRate			= 0.1f;
    const int InitialCriticalMultiplier		= 2;
    const int InvalidPosition				= -1;

    const char* const ShapeRoad			= ". ";
    const char* const ShapeWall			= "# ";
    const char* const ShapeStart		= "S ";
    const char* const ShapeEnd			= "E ";
    const char* const ShapePlayer		= "P ";
    const char* const ShapeGrave		= "X ";
    const char* const ShapeMonster		= "M ";
    const char* const ShapeShop			= "I ";
    const char* const ShapeRecovery		= "+ ";
    const char* const ShapeTrap			= "- ";
    const char* const ShapeTreasure		= "T ";

    const int Dx[4] = { 0, 0, -1, 1 };
    const int Dy[4] = { -1, 1, 0, 0 };

    struct MonsterData
    {
        std::string Name{};
        int Hp = 0;
        int MinDamage = 0;
        int MaxDamage = 0;
        float CriticalRate = 0.0f;
        int CriticalMultiplier = 0;
        int Reward = 0;

        MonsterData() = default;
        MonsterData(const std::string& InName, int InHp, int InMinDamage, int InMaxDamage, float InCriticalRate, int InCriticalMultiplier, int InReward) : Name(InName), Hp(InHp), Reward(InReward), MinDamage(InMinDamage), MaxDamage(InMaxDamage), CriticalRate(InCriticalRate), CriticalMultiplier(InCriticalMultiplier) {}
    };

    const int NumberOfMonsterTypes = 3;
    const MonsterData MonsterDatas[3]{
        MonsterData("고블린", 100, 3, 7, 0.1f, 2, 100),
        MonsterData("코볼트", 30, 5, 10, 0.3f, 2, 300),
        MonsterData("슬라임", 50, 5, 10, 0.1f, 2, 500)
    };

    void StartMazeGame();
    int* LoadMazeData(const std::string FilePath);
    int* MazeTileAt(int X, int Y);
    Position FindStart();
    bool CanPlayMazeGame(const Player& InPlayer);
    void PrintMaze(const Player& InPlayer);
    void PrintPlayerStatus(const Player& InPlayer);
    void PrintMovableDirections(const Player& InPlayer);
    DirectionType GetInputDirection();
    int DirectionType2Int(DirectionType Direction);
    bool IsValidDirectionType(DirectionType Target);
    bool CanMoveTo(const Player& InPlayer, DirectionType Direction);
    void PrintHpBar(int Hp);
    std::string GetHpBarString(int Hp);
    EncounterType IsEncountered();
    void ProcessEncounter(EncounterType Encounter, Player& InPlayer);
    void ProcessBattle(Player& InPlayer);
    Monster* SpawnMonster();
    void ProcessShop(Player& InPlayer);
    void ProcessRecovery(Player& InPlayer);
    void ProcessTrap(Player& InPlayer);
    void ProcessTreasure(Player& InPlayer);
    void RecordMazeTile(const Player& InPlayer, EncounterType Encounter);
}
