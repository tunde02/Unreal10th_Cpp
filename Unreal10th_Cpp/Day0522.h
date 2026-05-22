#pragma once

void Day0522_Array();
void Day0522_Array_Example01();
void Day0522_Array_Example02();
void Day0522_Array_Example03();

void Day0522_Casting();

void Day0522_Reference();
void Test_Reference(int& OutData1, int& OutData2, int& OutData3);

void Day0522_ArrayParameter();
void Test_ArrayParameter(int* Array, int Length);

void Day0522_ArrayParameter_Example01(int* Array, int Length);

void Day0522_ArrayParameter_Example02(int* Array, int Length);
void SumAndAverageOfArray(int* Array, int Length, int& OutSum, float& OutAverage);
void MinAndMaxOfArray(int* Array, int Length, int& OutMin, int& OutMax);

void Day0522_ArrayParameter_Example03(int* Array, int Length);
void FisherYatesShuffle(int* Array, int Length);

void Day0522_Practice01();

void Day0522_Practice02();
void FlipArray(int* Array, int Length);

void Day0522_Practice03();

void Day0522_Practice04();
enum TileType { Road, Wall, Start, End, Player };
enum DirectionType { Up, Down, Left, Right, DirectionCount };
void ShowMaze(int* Array, int RowLength, int ColumnLength);
TileType IntToTileType(int TileInt);
int TileTypeToint(TileType Tile);
DirectionType IntToDirection(int DirectionInt);
int DirectionTypeToInt(DirectionType Direction);
bool IsPlayerWin(int PlayerX, int PlayerY, int EndX, int EndY);
bool CanMoveTo(int* Array, int RowLength, int ColumnLength, int PlayerX, int PlayerY, DirectionType Direction);
void ShowMovableDirections(int* Array, int RowLength, int ColumnLength, int PlayerX, int PlayerY);
DirectionType InputDirection();