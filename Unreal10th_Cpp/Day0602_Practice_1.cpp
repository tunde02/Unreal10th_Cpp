#include <fstream>
#include "Day0602_Practice_1.h"
#include "Utils.h"
#include "Position.h"
#include "Player.h"
#include "Monster.h"
#include "Goblin.h"
#include "Slime.h"
#include "Kobold.h"

namespace Day0602_Practice_1
{
    void Day0602_Practice_1()
    {
        StartMazeGame();
    }

    int* Maze = nullptr;
    int MazeRowSize = 0;
    int MazeColumnSize = 0;

    void StartMazeGame()
    {
        // MapData.txt 파일에서 미로 정보 불러오기
        std::string FilePath = ".\\Data\\MapData.txt";

        Maze = LoadMazeData(FilePath);

        printf("플레이어의 이름을 입력하세요 : ");
        std::string PlayerName("");
        std::getline(std::cin, PlayerName);

        Player MyPlayer{
            PlayerName,
            PlayerInitialHP,
            PlayerInitialMinimumDamage,
            PlayerInitialMaximumDamage,
            InitialCriticalRate,
            InitialCriticalMultiplier,
            Position{ InvalidPosition, InvalidPosition },
            PlayerInitialGold
        };

        MyPlayer.SetPosition(FindStart());

        if (!(MyPlayer.GetX() != InvalidPosition && MyPlayer.GetY() != InvalidPosition))
        {
            printf("[ERROR] 유효하지 않은 플레이어 위치입니다.\n");
            return;
        }

        while (CanPlayMazeGame(MyPlayer))
        {
            system("cls");
            PrintMaze(MyPlayer);

            PrintPlayerStatus(MyPlayer);

            printf("이동할 수 있는 방향을 선택하세요(w: 위, s : 아래, a : 왼쪽, d : 오른쪽)\n");
            PrintMovableDirections(MyPlayer);
            printf("\n : ");

            DirectionType PlayerInputDirection = GetInputDirection();
            while (!CanMoveTo(MyPlayer, PlayerInputDirection))
            {
                printf("[ERROR] 올바른 방향을 선택하세요 : ");
                PlayerInputDirection = GetInputDirection();
            }

            // 플레이어 좌표 이동
            int DirectionIndex = DirectionType2Int(PlayerInputDirection);
            MyPlayer.Move(Dx[DirectionIndex], Dy[DirectionIndex]);

            // 랜덤 인카운터
            EncounterType Encounter = IsEncountered();
            if (Encounter != ET_None && *MazeTileAt(MyPlayer.GetX(), MyPlayer.GetY()) != TT_End)
            {
                ProcessEncounter(Encounter, MyPlayer);
                RecordMazeTile(MyPlayer, Encounter);

                if (!MyPlayer.IsAlive())
                {
                    // 플레이어가 사망하였으므로 해당 타일을 무덤으로 교체
                    *MazeTileAt(MyPlayer.GetX(), MyPlayer.GetY()) = TT_Grave;
                }
            }
        }

        PrintMaze(MyPlayer);
        PrintPlayerStatus(MyPlayer);

        if (MyPlayer.IsAlive())
        {
            printf("\n[%s가 미로를 탈출했습니다!!]\n", MyPlayer.GetName().c_str());
        }
        else
        {
            printf("\n[%s가 사망했습니다..]\n", MyPlayer.GetName().c_str());
        }

        delete[] Maze;
        Maze = nullptr;
    }

    int* LoadMazeData(const std::string FilePath)
    {
        std::ifstream InputFile(FilePath);

        if (!InputFile.is_open())
        {
            printf("[ERROR] 미로 맵 정보를 불러오는데 실패했습니다.\n");
            return nullptr;
        }

        std::string FileContents(
            (std::istreambuf_iterator<char>(InputFile)),
            std::istreambuf_iterator<char>()
        );

        std::string MazeRowColumnString = FileContents.substr(0, FileContents.find('\n'));
        MazeRowSize = atoi(MazeRowColumnString.substr(MazeRowColumnString.find(',') + 1, strlen(MazeRowColumnString.c_str())).c_str());
        MazeColumnSize = atoi(MazeRowColumnString.substr(0, MazeRowColumnString.find(',')).c_str());

        int* LoadedMaze = new int[MazeRowSize * MazeColumnSize] { 0 };

        int MazeDataStartIndex = (int)FileContents.find('\n') + 1;
        int FileSize = (int)strlen(FileContents.c_str());
        int* TempMazePointer = LoadedMaze;
        int CurrentCursor = MazeDataStartIndex;

        while (CurrentCursor < FileSize)
        {
            std::string TileString("");
            while (CurrentCursor < FileSize && FileContents[CurrentCursor] != ',' && FileContents[CurrentCursor] != '\n')
            {
                TileString += FileContents[CurrentCursor++];
            }
            *TempMazePointer++ = atoi(TileString.c_str());
            CurrentCursor++;
        }

        InputFile.close();

        return LoadedMaze;
    }

    int* MazeTileAt(int X, int Y)
    {
        return Maze + Y * MazeColumnSize + X;
    }

    Position FindStart()
    {
        for (int y = 0; y < MazeRowSize; y++)
        {
            for (int x = 0; x < MazeColumnSize; x++)
            {
                if (*MazeTileAt(x, y) == TT_Start)
                {
                    return Position{ x, y };
                }
            }
        }

        // Start가 존재하지 않음
        return Position{ InvalidPosition , InvalidPosition };
    }

    bool CanPlayMazeGame(const Player& InPlayer)
    {
        return (InPlayer.IsAlive()) && (*MazeTileAt(InPlayer.GetX(), InPlayer.GetY()) != TT_End);
    }

    void PrintMaze(const Player& InPlayer)
    {
        printf("\n");
        for (int y = 0; y < MazeRowSize; y++)
        {
            for (int x = 0; x < MazeColumnSize; x++)
            {
                if (*MazeTileAt(x, y) == TT_Grave)
                {
                    printf(ShapeGrave);
                }
                else if (InPlayer.GetX() == x && InPlayer.GetY() == y)
                {
                    printf(ShapePlayer);
                }
                else if (*MazeTileAt(x, y) == TT_Wall)
                {
                    printf(ShapeWall);
                }
                else if (*MazeTileAt(x, y) == TT_Road)
                {
                    printf(ShapeRoad);
                }
                else if (*MazeTileAt(x, y) == TT_Start)
                {
                    printf(ShapeStart);
                }
                else if (*MazeTileAt(x, y) == TT_End)
                {
                    printf(ShapeEnd);
                }
                else if (*MazeTileAt(x, y) == TT_Monster)
                {
                    printf(ShapeMonster);
                }
                else if (*MazeTileAt(x, y) == TT_Shop)
                {
                    printf(ShapeShop);
                }
                else if (*MazeTileAt(x, y) == TT_Recovery)
                {
                    printf(ShapeRecovery);
                }
                else if (*MazeTileAt(x, y) == TT_Trap)
                {
                    printf(ShapeTrap);
                }
                else if (*MazeTileAt(x, y) == TT_Treasure)
                {
                    printf(ShapeTreasure);
                }
            }
            printf("\n");
        }
    }

    void PrintPlayerStatus(const Player& InPlayer)
    {
        int PlayerNameLength = (int)strlen(InPlayer.GetName().c_str());
        printf("┌─");
        for (int i = 0; i < PlayerNameLength; i++)
        {
            printf("─");
        }
        printf("─┐\n");
        printf("│ %s │\n", InPlayer.GetName().c_str());
        printf("└─");
        for (int i = 0; i < PlayerNameLength; i++)
        {
            printf("─");
        }
        printf("─┘\n");

        std::string HpString("체력 (" + std::to_string(InPlayer.GetHp()) + ") " + GetHpBarString(InPlayer.GetHp()));
        printf("%s\n", HpString.c_str());
        printf("소지 금액 : %dg\n", InPlayer.GetGold());
        printf("데미지 : %d ~ %d\n", InPlayer.GetMinDamage(), InPlayer.GetMaxDamage());
        printf("현재 위치 : (%d, %d)\n", InPlayer.GetX(), InPlayer.GetY());
        printf("\n");
    }

    void PrintMovableDirections(const Player& InPlayer)
    {
        printf("이동 가능한 방향 : ");
        if (CanMoveTo(InPlayer, DT_Up))
        {
            printf("w(↑) ");
        }
        if (CanMoveTo(InPlayer, DT_Down))
        {
            printf("s(↓) ");
        }
        if (CanMoveTo(InPlayer, DT_Left))
        {
            printf("a(←) ");
        }
        if (CanMoveTo(InPlayer, DT_Right))
        {
            printf("d(→) ");
        }
    }

    DirectionType GetInputDirection()
    {
        char PlayerInput = Utils::SafeInput('\0');
        DirectionType Direction = (DirectionType)(-1);

        switch (PlayerInput)
        {
            case 'w':
            case 'W':
                Direction = DT_Up;
                break;
            case 's':
            case 'S':
                Direction = DT_Down;
                break;
            case 'a':
            case 'A':
                Direction = DT_Left;
                break;
            case 'd':
            case 'D':
                Direction = DT_Right;
                break;
            default:
                break;
        }

        return Direction;
    }

    int DirectionType2Int(DirectionType Direction)
    {
        switch (Direction)
        {
            case DT_Up:
                return 0;
            case DT_Down:
                return 1;
            case DT_Left:
                return 2;
            case DT_Right:
                return 3;
            default:
                return -1;
        }
    }

    bool IsValidDirectionType(DirectionType Target)
    {
        switch (Target)
        {
            case DT_Up:
            case DT_Down:
            case DT_Left:
            case DT_Right:
                return true;
            default:
                return false;
        }
    }

    bool CanMoveTo(const Player& InPlayer, DirectionType Direction)
    {
        if (!IsValidDirectionType(Direction))
        {
            return false;
        }

        int DirectionIndex = DirectionType2Int(Direction);
        int NextX = InPlayer.GetX() + Dx[DirectionIndex];
        int NextY = InPlayer.GetY() + Dy[DirectionIndex];

        return (-1 < NextY && NextY < MazeRowSize)
            && (-1 < NextX && NextX < MazeColumnSize)
            && (*MazeTileAt(NextX, NextY) != TT_Wall);
    }

    void PrintHpBar(int Hp)
    {
        const int MaximumSegments = 20;
        const int SegmentUnit = 100 / MaximumSegments;
        int HpSegments = Hp / SegmentUnit;
        int BlankSegments = MaximumSegments - HpSegments;

        printf("[");
        if (HpSegments > 0)
        {
            for (int i = 0; i < HpSegments; i++)
            {
                printf("=");
            }

            for (int i = 0; i < BlankSegments; i++)
            {
                printf(" ");
            }
        }
        else
        {
            printf("-");
            for (int i = 1; i < BlankSegments; i++)
            {
                printf(" ");
            }
        }
        printf("]");
    }

    std::string GetHpBarString(int Hp)
    {
        const int SegmentUnit = 5;
        const int MinimumSegmentNum = 20;

        std::string HpBar("[");
        int HpSegments = Hp / SegmentUnit;
        int BlankSegments = MinimumSegmentNum - HpSegments;

        if (HpSegments > 0)
        {
            for (int i = 0; i < HpSegments; i++)
            {
                HpBar += "=";
            }

            for (int i = 0; i < BlankSegments; i++)
            {
                HpBar += " ";
            }
        }
        else
        {
            HpBar += "-";
            for (int i = 1; i < BlankSegments; i++)
            {
                HpBar += " ";
            }
        }

        HpBar += "]";

        return HpBar;
    }

    EncounterType IsEncountered()
    {
        const int MonsterRate   = 15;
        const int ShopRate      = 10;
        const int RecoveryRate  = 5;
        const int TrapRate      = 5;
        const int TreasureRate  = 5;

        int RandomNumber = (rand() % 100);
        if (RandomNumber < MonsterRate)
        {
            return ET_Monster;
        }
        else if (RandomNumber < MonsterRate + ShopRate)
        {
            return ET_Shop;
        }
        else if (RandomNumber < MonsterRate + ShopRate + RecoveryRate)
        {
            return ET_Recovery;
        }
        else if (RandomNumber < MonsterRate + ShopRate + RecoveryRate + TrapRate)
        {
            return ET_Trap;
        }
        else if (RandomNumber < MonsterRate + ShopRate + RecoveryRate + TrapRate + TreasureRate)
        {
            return ET_Treasure;
        }
        else
        {
            return ET_None;
        }
    }

    void ProcessEncounter(EncounterType Encounter, Player& InPlayer)
    {
        Utils::PrintDivider('-', 50);

        switch (Encounter)
        {
            case ET_Monster:
                ProcessBattle(InPlayer);
                break;
            case ET_Shop:
                ProcessShop(InPlayer);
                break;
            case ET_Recovery:
                ProcessRecovery(InPlayer);
                break;
            case ET_Trap:
                ProcessTrap(InPlayer);
                break;
            case ET_Treasure:
                ProcessTreasure(InPlayer);
                break;
            default:
                break;
        }

        if (InPlayer.IsAlive())
        {
            printf("다음으로 이동하려면 아무 키나 입력하세요 : ");
            std::cin.get();
        }

        Utils::PrintDivider('-', 50);
    }

    void ProcessBattle(Player& InPlayer)
    {
        Monster* SpawnedMonster = SpawnMonster();
        printf("[%s를 조우했습니다..!!]\n\n", SpawnedMonster->GetName().c_str());

        while (InPlayer.IsAlive() && SpawnedMonster->GetHp() > 0)
        {
            printf("%s 체력(%d)", InPlayer.GetName().c_str(), InPlayer.GetHp());
            PrintHpBar(InPlayer.GetHp());
            printf("  |  %s 체력(%d)", SpawnedMonster->GetName().c_str(), SpawnedMonster->GetHp());
            PrintHpBar(SpawnedMonster->GetHp());
            printf("\n");

            printf("공격하려면 아무 키나 입력하세요 : ");
            std::cin.get();

            InPlayer.ApplyDamage(*SpawnedMonster);

            if (SpawnedMonster->IsAlive())
            {
                SpawnedMonster->ApplyDamage(InPlayer);
            }
            else
            {
                printf("\n[%s를 처치했습니다!!]\n", SpawnedMonster->GetName().c_str());

                InPlayer.EarnGold(SpawnedMonster->GetReward());
            }

            printf("\n");
        }

        delete SpawnedMonster;
        SpawnedMonster = nullptr;
    }

    Monster* SpawnMonster()
    {
        int RandomMonsterDataIndex = rand() % NumberOfMonsterTypes;
        switch (RandomMonsterDataIndex)
        {
            case 0:
                return new Goblin{
                    MonsterDatas[RandomMonsterDataIndex].Name,
                    MonsterDatas[RandomMonsterDataIndex].Hp,
                    MonsterDatas[RandomMonsterDataIndex].MinDamage,
                    MonsterDatas[RandomMonsterDataIndex].MaxDamage,
                    MonsterDatas[RandomMonsterDataIndex].CriticalRate,
                    MonsterDatas[RandomMonsterDataIndex].CriticalMultiplier,
                    MonsterDatas[RandomMonsterDataIndex].Reward
                };
            case 1:
                return new Kobold{
                    MonsterDatas[RandomMonsterDataIndex].Name,
                    MonsterDatas[RandomMonsterDataIndex].Hp,
                    MonsterDatas[RandomMonsterDataIndex].MinDamage,
                    MonsterDatas[RandomMonsterDataIndex].MaxDamage,
                    MonsterDatas[RandomMonsterDataIndex].CriticalRate,
                    MonsterDatas[RandomMonsterDataIndex].CriticalMultiplier,
                    MonsterDatas[RandomMonsterDataIndex].Reward
                };
            case 2:
                return new Slime{
                    MonsterDatas[RandomMonsterDataIndex].Name,
                    MonsterDatas[RandomMonsterDataIndex].Hp,
                    MonsterDatas[RandomMonsterDataIndex].MinDamage,
                    MonsterDatas[RandomMonsterDataIndex].MaxDamage,
                    MonsterDatas[RandomMonsterDataIndex].CriticalRate,
                    MonsterDatas[RandomMonsterDataIndex].CriticalMultiplier,
                    MonsterDatas[RandomMonsterDataIndex].Reward
                };
            default:
                return new Goblin{
                    MonsterDatas[RandomMonsterDataIndex].Name,
                    MonsterDatas[RandomMonsterDataIndex].Hp,
                    MonsterDatas[RandomMonsterDataIndex].MinDamage,
                    MonsterDatas[RandomMonsterDataIndex].MaxDamage,
                    MonsterDatas[RandomMonsterDataIndex].CriticalRate,
                    MonsterDatas[RandomMonsterDataIndex].CriticalMultiplier,
                    MonsterDatas[RandomMonsterDataIndex].Reward
                };
        }
    }

    void ProcessShop(Player& InPlayer)
    {
        const int WeaponPrice = 500;
        const int WeaponDamage = 10;

        printf("[상점을 방문했습니다.]\n\n");
        printf("무기를 구입하시겠습니까? (%dg)\n", WeaponPrice);
        printf("1) 예  2) 아니오\n");
        printf(" : ");
        int Decision = Utils::SafeInput(0);
        while (!(Decision == 1 || Decision == 2))
        {
            printf("[ERROR] 올바른 숫자를 입력하세요 : ");
            Decision = Utils::SafeInput(0);
        }

        if (Decision == 1)
        {
            InPlayer.BuyWeapon(WeaponPrice, WeaponDamage);
        }
    }

    void ProcessRecovery(Player& InPlayer)
    {
        const int RecoveryAmount = 50;

        InPlayer.EncounterRecovery(RecoveryAmount);
    }

    void ProcessTrap(Player& InPlayer)
    {
        const int TrapDamage = 15;

        InPlayer.EncounterTrap(TrapDamage);
    }

    void ProcessTreasure(Player& InPlayer)
    {
        const int TreasureValue = 1000;

        InPlayer.EncounterTreasure(TreasureValue);
    }

    void RecordMazeTile(const Player& InPlayer, EncounterType Encounter)
    {
        switch (Encounter)
        {
            case ET_Monster:
                *MazeTileAt(InPlayer.GetX(), InPlayer.GetY()) = TT_Monster;
                break;
            case ET_Shop:
                *MazeTileAt(InPlayer.GetX(), InPlayer.GetY()) = TT_Shop;
                break;
            case ET_Recovery:
                *MazeTileAt(InPlayer.GetX(), InPlayer.GetY()) = TT_Recovery;
                break;
            case ET_Trap:
                *MazeTileAt(InPlayer.GetX(), InPlayer.GetY()) = TT_Trap;
                break;
            case ET_Treasure:
                *MazeTileAt(InPlayer.GetX(), InPlayer.GetY()) = TT_Treasure;
                break;
            default:
                break;
        }
    }
}
