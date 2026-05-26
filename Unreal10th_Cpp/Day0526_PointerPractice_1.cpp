#include "Day0526_PointerPractice_1.h"

const int MazeRowSize					= 10;
const int MazeColumnSize				= 10;
const int EncounterRate					= 40;
const int InitialHP						= 100;
const int InitialGold					= 1000;
const int MinimumDamage					= 5;
const int MaximumDamage					= 10;
const int InitialPlayerMinimumDamage	= 10;
const int InitialPlayerMaximumDamage	= 15;
const int CriticalRate					= 10;
const int CriticalDamageMultiplier		= 2;
const int InvalidPosition				= -1;

const char* ShapeRoad			= ". ";
const char* ShapeWall			= "# ";
const char* ShapeStart			= "S ";
const char* ShapeEnd			= "E ";
const char* ShapePlayer			= "P ";
const char* ShapeGrave			= "X ";
const char* ShapeMonster		= "M ";
const char* ShapeBossMonster	= "B ";
const char* ShapeShop			= "I ";
const char* ShapeRecovery		= "+ ";
const char* ShapeTrap			= "- ";
const char* ShapeTreasure		= "T ";

int* Maze = new int[MazeRowSize * MazeColumnSize]
{
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 2, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 1, 1, 1, 1, 0, 1, 0, 1,
        1, 0, 1, 3, 1, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};


void Day0526_Practice_01()
{
    // 2. 미로 탈출 게임에 랜덤 인카운터 종류 늘려보기

    int PlayerHP = InitialHP;
    int PlayerGold = InitialGold;
    int PlayerMinimumDamage = InitialPlayerMinimumDamage;
    int PlayerMaximumDamage = InitialPlayerMaximumDamage;
    int PlayerX = InvalidPosition;
    int PlayerY = InvalidPosition;

    FindStart(PlayerX, PlayerY);

    if (!(PlayerX != InvalidPosition && PlayerY != InvalidPosition))
    {
        printf("[ERROR]  유효하지 않은 플레이어 위치입니다.\n");
        return;
    }

    printf("== = 텍스트 미로 탈출 게임 == =\n");

    while (CanPlayMazeGame(PlayerHP, PlayerX, PlayerY))
    {
        system("cls");
        PrintMaze(PlayerX, PlayerY);

        PrintPlayerStatus(PlayerHP, PlayerGold, PlayerMinimumDamage, PlayerMaximumDamage);

        printf("이동할 수 있는 방향을 선택하세요(w: 위, s : 아래, a : 왼쪽, d : 오른쪽)\n");
        PrintMovableDirections(PlayerX, PlayerY);
        printf("\n : ");

        DirectionType PlayerInputDirection = GetInputDirection();
        while (!CanMoveTo(PlayerX, PlayerY, PlayerInputDirection))
        {
            printf("[ERROR]  올바른 방향을 선택하세요 : ");
            PlayerInputDirection = GetInputDirection();
        }

        // 플레이어 좌표 이동
        int DirectionIndex = DirectionType2Int(PlayerInputDirection);
        PlayerX += Dx[DirectionIndex];
        PlayerY += Dy[DirectionIndex];

        // 랜덤 인카운터
        EncounterType Encounter = None;
        bool bEncounter = IsEncountered(Encounter);
        if (bEncounter && *MazePointer(PlayerY, PlayerX) != TileEnd)
        {
            ProcessEncounter(Encounter, PlayerHP, PlayerGold, PlayerMinimumDamage, PlayerMaximumDamage);

            if (PlayerHP <= 0)
            {
                // 플레이어가 사망하였으므로 해당 타일을 무덤으로 교체
                *MazePointer(PlayerY, PlayerX) = TileGrave;
            }
        }
    }

    PrintMaze(PlayerX, PlayerY);

    if (PlayerHP > 0)
    {
        printf("\n[플레이어가 미로를 탈출했습니다!!]\n");
    }
    else
    {
        printf("\n[플레이어가 사망했습니다..]\n");
    }

    delete[] Maze;
    Maze = nullptr;
}

void PrintDivider(wchar_t Divider, int Count)
{
    printf("\n");
    for (int i = 0; i < Count; i++)
    {
        printf("%lc", Divider);
    }
    printf("\n\n");
}

int* MazePointer(int Row, int Column)
{
    return Maze + (Row * MazeColumnSize) + Column;
}

void FindStart(int& OutX, int& OutY)
{
    for (int y = 0; y < MazeRowSize; y++)
    {
        for (int x = 0; x < MazeColumnSize; x++)
        {
            if (*MazePointer(y, x) == TileStart)
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

bool CanPlayMazeGame(int PlayerHP, int PlayerX, int PlayerY)
{
    return (PlayerHP > 0) && (*MazePointer(PlayerY, PlayerX) != TileEnd);
}

void PrintMaze(int PlayerX, int PlayerY)
{
    printf("\n");
    for (int y = 0; y < MazeRowSize; y++)
    {
        for (int x = 0; x < MazeColumnSize; x++)
        {
            if (*MazePointer(y, x) == TileGrave)
            {
                printf(ShapeGrave);
            }
            else if (PlayerX == x && PlayerY == y)
            {
                printf(ShapePlayer);
            }
            else if (*MazePointer(y, x) == TileWall)
            {
                printf(ShapeWall);
            }
            else if (*MazePointer(y, x) == TileRoad)
            {
                printf(ShapeRoad);
            }
            else if (*MazePointer(y, x) == TileStart)
            {
                printf(ShapeStart);
            }
            else if (*MazePointer(y, x) == TileEnd)
            {
                printf(ShapeEnd);
            }
        }
        printf("\n");
    }
}

void PrintPlayerStatus(int PlayerHP, int PlayerGold, int PlayerMinimumDamage, int PlayerMaximumDamage)
{
    printf("\n플레이어 체력 (%d) ", PlayerHP);
    PrintHpBar(PlayerHP);
    printf("  |  플레이어 소지 금액 : %dg", PlayerGold);
    printf("  |  플레이어 데미지 : %d~%d", PlayerMinimumDamage, PlayerMaximumDamage);
    printf("\n");
}

void PrintMovableDirections(int PlayerX, int PlayerY)
{
    printf("이동 가능한 방향 : ");
    if (CanMoveTo(PlayerX, PlayerY, Up))
    {
        printf("w(↑) ");
    }
    if (CanMoveTo(PlayerX, PlayerY, Down))
    {
        printf("s(↓) ");
    }
    if (CanMoveTo(PlayerX, PlayerY, Left))
    {
        printf("a(←) ");
    }
    if (CanMoveTo(PlayerX, PlayerY, Right))
    {
        printf("d(→) ");
    }
}

DirectionType GetInputDirection()
{
    char PlayerInput = SafeInput('\0');
    DirectionType Direction = (DirectionType)(-1);

    switch (PlayerInput)
    {
        case 'w':
        case 'W':
            Direction = Up;
            break;
        case 's':
        case 'S':
            Direction = Down;
            break;
        case 'a':
        case 'A':
            Direction = Left;
            break;
        case 'd':
        case 'D':
            Direction = Right;
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
        case Up:
            return 0;
        case Down:
            return 1;
        case Left:
            return 2;
        case Right:
            return 3;
        default:
            return -1;
    }
}

bool IsValidDirectionType(DirectionType Target)
{
    switch (Target)
    {
        case Up:
        case Down:
        case Left:
        case Right:
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
        && (*MazePointer(NextY, NextX) != TileWall);
}

void PrintHpBar(int HP)
{
    const int MaximumSegments = 20;
    const int SegmentUnit = 100 / MaximumSegments;
    int HpSegments = HP / SegmentUnit;
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

int CalcDamage(int MinimumDamage, int MaximumDamage, bool& OutIsCritical)
{
    int Damage = ((rand() % (MaximumDamage - MinimumDamage)) + MinimumDamage);

    // 랜덤 숫자가 0 ~ 10이면 크리티컬
    OutIsCritical = rand() % 100 < CriticalRate;
    if (OutIsCritical)
    {
        Damage *= CriticalDamageMultiplier;
    }

    return Damage;
}

bool IsEncountered(EncounterType& Encounter)
{
    // 랜덤 숫자가 0 ~ 30면 인카운터
    int RandomNumber = (rand() % 100);
    if (RandomNumber < 15)
    {
        Encounter = Monster;
    }
    else if (RandomNumber < 25)
    {
        Encounter = Shop;
    }
    else if (RandomNumber < 30)
    {
        Encounter = Recovery;
    }
    else if (RandomNumber < 35)
    {
        Encounter = Trap;
    }
    else if (RandomNumber < 40)
    {
        Encounter = Treasure;
    }
    else
    {
        return None;
    }
}

void ProcessEncounter(EncounterType Encounter, int& PlayerHP, int& PlayerGold, int& PlayerMinimumDamage, int& PlayerMaximumDamage)
{
    PrintDivider('-', 50);

    switch (Encounter)
    {
        case Monster:
        {
            printf("[몬스터를 조우했습니다..!!]\n\n");

            int MonsterHP = InitialHP;

            while (PlayerHP > 0 && MonsterHP > 0)
            {
                printf("플레이어 체력(%d)", PlayerHP);
                PrintHpBar(PlayerHP);
                printf("  |  몬스터 체력(%d)", MonsterHP);
                PrintHpBar(MonsterHP);
                printf("\n");

                printf("공격하려면 아무 키나 입력하세요 : ");
                cin.get();

                bool IsCritical = false;
                int PlayerDamage = CalcDamage(PlayerMinimumDamage, PlayerMaximumDamage, IsCritical);

                if (!IsCritical)
                {
                    printf("[플레이어의 공격] : %d\n", PlayerDamage);
                }
                else
                {
                    printf("[플레이어의 공격 (크리티컬!)] : %d\n", PlayerDamage);
                }

                MonsterHP -= PlayerDamage;

                if (MonsterHP > 0)
                {
                    int MonsterDamage = CalcDamage(MinimumDamage, MaximumDamage, IsCritical);

                    if (!IsCritical)
                    {
                        printf("[몬스터의 공격] : %d\n", MonsterDamage);
                    }
                    else
                    {
                        printf("[몬스터의 공격 (크리티컬!)] : %d\n", MonsterDamage);
                    }

                    PlayerHP -= MonsterDamage;
                }
                else
                {
                    printf("\n[몬스터를 처치했습니다!!]\n");
                }

                printf("\n");
            }
            break;
        }
        case Shop:
        {
            printf("[상점을 방문했습니다.]\n\n");
            printf("무기를 구입하시겠습니까? (500g)\n");
            printf("1) 예  2) 아니오\n");
            printf(" : ");
            int Decision = SafeInput(0);
            while (!(Decision == 1 || Decision == 2))
            {
                printf("[ERROR]  올바른 숫자를 입력하세요 : ");
                Decision = SafeInput(0);
            }

            if (Decision == 1)
            {
                if (PlayerGold < 500)
                {
                    printf("\n[소지 금액이 부족합니다...]\n");
                }
                else
                {
                    printf("\n[무기를 구입했습니다!]\n");
                    printf("플레이어의 공격력이 10 증가합니다.\n");
                    PlayerGold -= 500;
                    PlayerMinimumDamage += 10;
                    PlayerMaximumDamage += 10;
                }
            }

            break;
        }
        case Recovery:
            printf("[쉼터를 발견했습니다.]\n");
            printf("플레이어가 체력을 50 회복합니다\n");
            PlayerHP = PlayerHP + 50 > 100 ? 100 : PlayerHP + 50;
            break;
        case Trap:
            printf("[함정을 밟았습니다...]\n");
            printf("플레이어가 체력을 15 잃습니다\n");
            PlayerHP -= 15;
            break;
        case Treasure:
            printf("[보물을 발견했습니다!!]\n");
            printf("플레이어가 1000g 를 얻었습니다\n");
            PlayerGold += 1000;
            break;
        default:
            break;
    }

    printf("다음으로 이동하려면 아무 키나 입력하세요 : ");
    cin.get();

    PrintDivider('-', 50);
}
