#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using std::cin;

void PrintGameDivider(char Divider, int Count, int Turn);

int PlayDice(int DiceSize);

void PrintCash(int PlayerCash, int ComputerCash);

int SafeInput();

bool IsValidBetAmount(int BetAmount, int MaxBetAmount);

void RunPractice2();