#pragma once
#include <iostream>
#include <stdlib.h>
using std::cin;

void Day0526_Practice_01();

enum TileType
{
	TileRoad		= 0,
	TileWall		= 1,
	TileStart		= 2,
	TileEnd			= 3,
	TilePlayer		= 4,
	TileGrave		= 5,
	TileMonster		= 6,
	TileBossMonster = 7,
	TileShop		= 8,
	TileRecovery	= 9,
	TileTrap		= 10,
	TileTreasure	= 11
};

enum DirectionType
{
	Up,
	Down,
	Left,
	Right
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
const int CIN_IGNORE_LENGTH = 10000;
const char CIN_IGNORE_DELIMITER = '\n';

extern int* Maze;

template <typename T>
T SafeInput(T DefaultValue)
{
	T Input = DefaultValue;
	cin >> Input;
	cin.clear();
	cin.ignore(CIN_IGNORE_DELIMITER, CIN_IGNORE_DELIMITER);

	return Input;
}
void PrintDivider(wchar_t Divider, int Count);

int* MazePointer(int Row, int Column);
void FindStart(int& OutX, int& OutY);
bool CanPlayMazeGame(int PlayerHP, int PlayerX, int PlayerY);
void PrintMaze(int PlayerX, int PlayerY);
void PrintPlayerStatus(int PlayerHP, int PlayerGold, int PlayerMinimumDamage, int PlayerMaximumDamage);
void PrintMovableDirections(int PlayerX, int PlayerY);
DirectionType GetInputDirection();
int DirectionType2Int(DirectionType Direction);
bool IsValidDirectionType(DirectionType Target);
bool CanMoveTo(int PlayerX, int PlayerY, DirectionType Direction);
void PrintHpBar(int HP);
int CalcDamage(int MinimumDamage, int MaximumDamage, bool& OutIsCritical);
EncounterType IsEncountered();
void ProcessEncounter(EncounterType Encounter, int& PlayerHP, int& PlayerGold, int& PlayerMinimumDamage, int& PlayerMaximumDamage);
void ProcessBattle(int& PlayerHP, int& PlayerMinimumDamage, int& PlayerMaximumDamage);
void ProcessShop(int& PlayerGold, int& PlayerMinimumDamage, int& PlayerMaximumDamage);
void ProcessRecovery(int& PlayerHP);
void ProcessTrap(int& PlayerHP);
void ProcessTreasure(int& PlayerGold);
void RecordMazeTile(int PlayerX, int PlayerY, EncounterType Encounter);
