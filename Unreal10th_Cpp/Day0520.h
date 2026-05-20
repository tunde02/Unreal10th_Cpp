#pragma once

/**************************************************

// 비트 연산자
int DataA = 6;
int DataB = 7;

printf("DataA & DataB = %d\n", DataA & DataB);
printf("DataA | DataB = %d\n", DataA | DataB);

unsigned int DataC = 6;
printf("~DataC = %u\n", ~DataC);

printf("DataA bit toggle : %d\n", DataA ^ 1);
printf("DataA bit toggle : %d\n", (DataA ^ 1) ^ 1);

// enum
enum WeekDays
{
	Mon,
	Tue,
	Wed,
	Thu,
	Fri,
	Sat,
	Sun
};

int EnumTest1 = Mon;

enum BitFlagTest
{
	Up = 1 << 0,
	Down = 1 << 1,
	Left = 1 << 2,
	Right = 1 << 3
};

int Direction = Up | Right; // 오른쪽 위
Direction = Up | Down | Left | Right; // 모든 방향

switch (Direction)
{
case Up:
	break;
case Down:
	break;
case Left:
	break;
case Right:
	break;
default:
	break;
}

**************************************************/