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
	None,
	Monster,
	BossMonster,
	Shop,
	Recovery,
	Trap,
	Treasure
};
const int Dx[4] = { 0, 0, -1, 1 };
const int Dy[4] = { -1, 1, 0, 0 };
const int CIN_IGNORE_LENGTH = 10000;
const char CIN_IGNORE_DELIMITER = '\n';

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
void PrintPlayerStatus(int PlayerHP, int PlayerGold);
void PrintMovableDirections(int PlayerX, int PlayerY);
DirectionType GetInputDirection();
int DirectionType2Int(DirectionType Direction);
bool IsValidDirectionType(DirectionType Target);
bool CanMoveTo(int PlayerX, int PlayerY, DirectionType Direction);
void PrintHpBar(int HP);
int CalcDamage(int MinimumDamage, int MaximumDamage, bool& OutIsCritical);
bool IsEncountered(EncounterType& Encounter);
void ProcessEncounter(EncounterType Encounter, int& PlayerHP, int& PlayerGold, int& PlayerMinimumDamage, int& PlayerMaximumDamage);