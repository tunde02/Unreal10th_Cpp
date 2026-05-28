#include <iostream>
#include <string>
#include <fstream>
#include "Utils.h"
#include "Day0528_Practice_1.h"

namespace Day0528_Practice_1
{
    int* Maze = nullptr;
    int MazeRowSize = 0;
    int MazeColumnSize = 0;

    void Day0528_Practice_1()
    {
        // MapData.txt 파일에서 미로 정보 불러오기
        std::string FilePath = ".\\Data\\MapData.txt";

        Maze = LoadMazeData(FilePath);

        printf("플레이어의 이름을 입력하세요 : ");
        std::string PlayerName("");
        std::getline(std::cin, PlayerName);

        PlayerData Player(PlayerName);
        
        FindStart(Player.X, Player.Y);

        if (!(Player.X != InvalidPosition && Player.Y != InvalidPosition))
        {
            printf("[ERROR] 유효하지 않은 플레이어 위치입니다.\n");
            return;
        }

        while (CanPlayMazeGame(Player))
        {
            system("cls");
            PrintMaze(Player.X, Player.Y);

            PrintPlayerStatus(Player);

            printf("이동할 수 있는 방향을 선택하세요(w: 위, s : 아래, a : 왼쪽, d : 오른쪽)\n");
            PrintMovableDirections(Player.X, Player.Y);
            printf("\n : ");

            DirectionType PlayerInputDirection = GetInputDirection();
            while (!CanMoveTo(Player.X, Player.Y, PlayerInputDirection))
            {
                printf("[ERROR] 올바른 방향을 선택하세요 : ");
                PlayerInputDirection = GetInputDirection();
            }

            // 플레이어 좌표 이동
            int DirectionIndex = DirectionType2Int(PlayerInputDirection);
            Player.X += Dx[DirectionIndex];
            Player.Y += Dy[DirectionIndex];

            // 랜덤 인카운터
            EncounterType Encounter = IsEncountered();
            if (Encounter != ET_None && *MazeTileAt(Player.X, Player.Y) != TT_End)
            {
                //ProcessEncounter(Encounter, PlayerHP, PlayerGold, PlayerMinimumDamage, PlayerMaximumDamage);
                //RecordMazeTile(PlayerX, PlayerY, Encounter);
                ProcessEncounter(Encounter, Player);
                RecordMazeTile(Player.X, Player.Y, Encounter);

                if (Player.Hp <= 0)
                {
                    // 플레이어가 사망하였으므로 해당 타일을 무덤으로 교체
                    *MazeTileAt(Player.X, Player.Y) = TT_Grave;
                }
            }
        }

        PrintMaze(Player.X, Player.Y);

        if (Player.Hp > 0)
        {
            printf("\n[%s가 미로를 탈출했습니다!!]\n", Player.Name.c_str());
        }
        else
        {
            printf("\n[%s가 사망했습니다..]\n", Player.Name.c_str());
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

    void FindStart(int& OutX, int& OutY)
    {
        for (int y = 0; y < MazeRowSize; y++)
        {
            for (int x = 0; x < MazeColumnSize; x++)
            {
                if (*MazeTileAt(x, y) == TT_Start)
                {
                    OutX = x;
                    OutY = y;
                    return;
                }
            }
        }

        // Start가 존재하지 않음
        OutX = InvalidPosition;
        OutY = InvalidPosition;
    }

    bool CanPlayMazeGame(PlayerData& Player)
    {
        return (Player.Hp > 0) && (*MazeTileAt(Player.X, Player.Y) != TT_End);
    }

    void PrintMaze(int PlayerX, int PlayerY)
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
                else if (PlayerX == x && PlayerY == y)
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

    void PrintPlayerStatus(PlayerData& Player)
    {
        int PlayerNameLength = (int)strlen(Player.Name.c_str());
        printf("┌─");
        for (int i = 0; i < PlayerNameLength; i++)
        {
            printf("─");
        }
        printf("─┐\n");
        printf("│ %s │\n", Player.Name.c_str());
        printf("└─");
        for (int i = 0; i < PlayerNameLength; i++)
        {
            printf("─");
        }
        printf("─┘\n");

        std::string HpString("체력 (" + std::to_string(Player.Hp) + ") " + GetHpBarString(Player.Hp));
        printf("%s\n", HpString.c_str());
        printf("소지 금액 : %dg\n", Player.Gold);
        printf("데미지 : %d ~ %d\n", Player.MinimumDamage, Player.MaximumDamage);
        printf("\n");
    }

    void PrintMovableDirections(int PlayerX, int PlayerY)
    {
        printf("이동 가능한 방향 : ");
        if (CanMoveTo(PlayerX, PlayerY, DT_Up))
        {
            printf("w(↑) ");
        }
        if (CanMoveTo(PlayerX, PlayerY, DT_Down))
        {
            printf("s(↓) ");
        }
        if (CanMoveTo(PlayerX, PlayerY, DT_Left))
        {
            printf("a(←) ");
        }
        if (CanMoveTo(PlayerX, PlayerY, DT_Right))
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

    bool CanMoveTo(int PlayerX, int PlayerY, DirectionType Direction)
    {
        if (!IsValidDirectionType(Direction))
        {
            return false;
        }

        int DirectionIndex = DirectionType2Int(Direction);
        int NextX = PlayerX + Dx[DirectionIndex];
        int NextY = PlayerY + Dy[DirectionIndex];

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

    int CalcDamage(int MinimumDamage, int MaximumDamage, int CriticalRate, int CriticalMultiplier, bool& OutIsCritical)
    {
        int Damage = ((rand() % (MaximumDamage - MinimumDamage)) + MinimumDamage);

        OutIsCritical = rand() % 100 < CriticalRate;
        if (OutIsCritical)
        {
            Damage *= CriticalMultiplier;
        }

        return Damage;
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

    void ProcessEncounter(EncounterType Encounter, PlayerData& Player)
    {
        Utils::PrintDivider('-', 50);

        switch (Encounter)
        {
            case ET_Monster:
                ProcessBattle(Player);
                break;
            case ET_Shop:
                ProcessShop(Player);
                break;
            case ET_Recovery:
                ProcessRecovery(Player);
                break;
            case ET_Trap:
                ProcessTrap(Player);
                break;
            case ET_Treasure:
                ProcessTreasure(Player);
                break;
            default:
                break;
        }

        if (Player.Hp > 0)
        {
            printf("다음으로 이동하려면 아무 키나 입력하세요 : ");
            std::cin.get();
        }

        Utils::PrintDivider('-', 50);
    }

    void ProcessBattle(PlayerData& Player)
    {
        MonsterData* Monster = SpawnMonster();
        printf("[%s를 조우했습니다..!!]\n\n", Monster->Name.c_str());

        while (Player.Hp > 0 && Monster->Hp > 0)
        {
            printf("%s 체력(%d)", Player.Name.c_str(), Player.Hp);
            PrintHpBar(Player.Hp);
            printf("  |  %s 체력(%d)", Monster->Name.c_str(), Monster->Hp);
            PrintHpBar(Monster->Hp);
            printf("\n");

            printf("공격하려면 아무 키나 입력하세요 : ");
            std::cin.get();

            bool IsCritical = false;
            int PlayerDamage = CalcDamage(Player.MinimumDamage, Player.MaximumDamage, Player.CriticalRate, Player.CriticalMultiplier, IsCritical);

            if (!IsCritical)
            {
                printf("[%s의 공격] : %d\n", Player.Name.c_str(), PlayerDamage);
            }
            else
            {
                printf("[%s의 공격 (크리티컬!)] : %d\n", Player.Name.c_str(), PlayerDamage);
            }

            Monster->Hp -= PlayerDamage;

            if (Monster->Hp > 0)
            {
                int MonsterDamage = CalcDamage(Monster->MinimumDamage, Monster->MaximumDamage, Monster->CriticalRate, Monster->CriticalMultiplier, IsCritical);

                if (!IsCritical)
                {
                    printf("[%s의 공격] : %d\n", Monster->Name.c_str(), MonsterDamage);
                }
                else
                {
                    printf("[%s의 공격 (크리티컬!)] : %d\n", Monster->Name.c_str(), MonsterDamage);
                }

                Player.Hp -= MonsterDamage;
            }
            else
            {
                printf("\n[%s를 처치했습니다!!]\n", Monster->Name.c_str());

                Player.Gold += Monster->Reward;
            }

            printf("\n");
        }

        delete Monster;
        Monster = nullptr;
    }

    MonsterData* SpawnMonster()
    {
        int RandomMonsterDataIndex = rand() % MonsterTypeNum;
        MonsterData* Monster = new MonsterData(
            MonsterDatas[RandomMonsterDataIndex].Name,
            MonsterDatas[RandomMonsterDataIndex].Hp,
            MonsterDatas[RandomMonsterDataIndex].Reward,
            MonsterDatas[RandomMonsterDataIndex].MinimumDamage,
            MonsterDatas[RandomMonsterDataIndex].MaximumDamage,
            MonsterDatas[RandomMonsterDataIndex].CriticalRate,
            MonsterDatas[RandomMonsterDataIndex].CriticalMultiplier
        );
        return Monster;
    }

    void ProcessShop(PlayerData & Player)
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
            if (Player.Gold < WeaponPrice)
            {
                printf("\n[소지 금액이 부족합니다...]\n");
            }
            else
            {
                printf("\n[무기를 구입했습니다!]\n");
                printf("플레이어의 공격력이 %d 증가합니다.\n", WeaponDamage);
                Player.Gold -= WeaponPrice;
                Player.MinimumDamage += WeaponDamage;
                Player.MaximumDamage += WeaponDamage;
            }
        }
    }

    void ProcessRecovery(PlayerData & Player)
    {
        const int RecoveryAmount = 50;

        printf("[쉼터를 발견했습니다.]\n");
        printf("플레이어가 체력을 %d 회복합니다\n", RecoveryAmount);
        Player.Hp = Player.Hp + RecoveryAmount > 100 ? 100 : Player.Hp + RecoveryAmount;
    }

    void ProcessTrap(PlayerData & Player)
    {
        const int TrapDamage = 15;

        printf("[함정을 밟았습니다...]\n");
        printf("플레이어가 체력을 %d 잃습니다\n", TrapDamage);
        Player.Hp = Player.Hp - TrapDamage < 0 ? 0 : Player.Hp - TrapDamage;
    }

    void ProcessTreasure(PlayerData & Player)
    {
        const int TreasureValue = 1000;

        printf("[보물을 발견했습니다!!]\n");
        printf("플레이어가 %dg 를 얻었습니다\n", TreasureValue);
        Player.Gold += TreasureValue;
    }

    void RecordMazeTile(int PlayerX, int PlayerY, EncounterType Encounter)
    {
        switch (Encounter)
        {
            case ET_Monster:
                *MazeTileAt(PlayerX, PlayerY) = TT_Monster;
                break;
            case ET_Shop:
                *MazeTileAt(PlayerX, PlayerY) = TT_Shop;
                break;
            case ET_Recovery:
                *MazeTileAt(PlayerX, PlayerY) = TT_Recovery;
                break;
            case ET_Trap:
                *MazeTileAt(PlayerX, PlayerY) = TT_Trap;
                break;
            case ET_Treasure:
                *MazeTileAt(PlayerX, PlayerY) = TT_Treasure;
                break;
            default:
                break;
        }
    }
}
