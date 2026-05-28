#pragma once

namespace Day0528_Practice_1
{
	void Day0528_Practice_1();

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
		BossMonster,
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
	const int InitialCriticalRate			= 10;
	const int InitialCriticalMultiplier		= 2;
	const int InvalidPosition				= -1;

	const char* const ShapeRoad			= ". ";
	const char* const ShapeWall			= "# ";
	const char* const ShapeStart		= "S ";
	const char* const ShapeEnd			= "E ";
	const char* const ShapePlayer		= "P ";
	const char* const ShapeGrave		= "X ";
	const char* const ShapeMonster		= "M ";
	const char* const ShapeBossMonster	= "B ";
	const char* const ShapeShop			= "I ";
	const char* const ShapeRecovery		= "+ ";
	const char* const ShapeTrap			= "- ";
	const char* const ShapeTreasure		= "T ";

	const int Dx[4] = { 0, 0, -1, 1 };
	const int Dy[4] = { -1, 1, 0, 0 };

	extern int* Maze;

	struct PlayerData
	{
		std::string Name = "플레이어";
		int Hp = PlayerInitialHP;
		int Gold = PlayerInitialGold;
		int MinimumDamage = PlayerInitialMinimumDamage;
		int MaximumDamage = PlayerInitialMaximumDamage;
		int CriticalRate = InitialCriticalRate;
		int CriticalMultiplier = InitialCriticalMultiplier;
		int X = InvalidPosition;
		int Y = InvalidPosition;

		PlayerData() = default;
		PlayerData(const std::string _Name)
		{
			if (_Name != "")
			{
				Name = _Name;
			}
		}
	};

	struct MonsterData
	{
		std::string Name = "몬스터";
		int Hp = PlayerInitialHP;
		int Reward = MonsterDefaultReward;
		int MinimumDamage = PlayerInitialMinimumDamage;
		int MaximumDamage = PlayerInitialMaximumDamage;
		int CriticalRate = InitialCriticalRate;
		int CriticalMultiplier = InitialCriticalMultiplier;

		MonsterData() = default;
		MonsterData(const std::string _Name, int _Hp, int _Reward, int _MinimumDamage, int _MaximumDamage, int _CriticalRate, int _CriticalMultiplier) : Name(_Name), Hp(_Hp), Reward(_Reward), MinimumDamage(_MinimumDamage), MaximumDamage(_MaximumDamage), CriticalRate(_CriticalRate), CriticalMultiplier(_CriticalMultiplier) {}
	};

	const int MonsterTypeNum = 4;
	const MonsterData MonsterDatas[] = { 
		MonsterData(
			"고블린",
			50,
			100,
			3,
			7,
			5,
			2
		),
		MonsterData(
			"코볼트",
			30,
			300,
			5,
			10,
			30,
			2
		),
		MonsterData(
			"오크",
			200,
			1000,
			10,
			20,
			5,
			2
		),
		MonsterData(
			"슬라임",
			100,
			500,
			5,
			10,
			10,
			2
		)
	};

	int* LoadMazeData(const std::string FilePath);
	int* MazeTileAt(int X, int Y);
	void FindStart(int& OutX, int& OutY);
	bool CanPlayMazeGame(PlayerData& Player);
	void PrintMaze(int PlayerX, int PlayerY);
	void PrintPlayerStatus(PlayerData& Player);
	void PrintMovableDirections(int PlayerX, int PlayerY);
	DirectionType GetInputDirection();
	int DirectionType2Int(DirectionType Direction);
	bool IsValidDirectionType(DirectionType Target);
	bool CanMoveTo(int PlayerX, int PlayerY, DirectionType Direction);
	void PrintHpBar(int Hp);
	std::string GetHpBarString(int Hp);
	int CalcDamage(int MinimumDamage, int MaximumDamage, int CriticalRate, int CriticalMultiplier, bool& OutIsCritical);
	EncounterType IsEncountered();
	void ProcessEncounter(EncounterType Encounter, PlayerData& Player);
	void ProcessBattle(PlayerData& Player);
	MonsterData* SpawnMonster();
	void ProcessShop(PlayerData& Player);
	void ProcessRecovery(PlayerData& Player);
	void ProcessTrap(PlayerData& Player);
	void ProcessTreasure(PlayerData& Player);
	void RecordMazeTile(int PlayerX, int PlayerY, EncounterType Encounter);
}
