#pragma once
#include <stdio.h>

enum PlayerState
{
	Idle = 1 << 0,
	Jump = 1 << 1,
	Attack = 1 << 2,
	Invincible = 1 << 3
};

int AddPlayerState(int Target, PlayerState State);

int SubPlayerState(int Target, PlayerState State);

int TogglePlayerState(int Target, PlayerState State);

void PrintPlayerState(int State);

void RunPractice1();