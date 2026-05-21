#include "Day0521_FunctionPractice_2.h"

void PrintGameDivider(char Divider, int Count, int Turn)
{
	printf("\n");

	for (int i = 0; i < Count; i++)
	{
		printf("%c", Divider);
	}

	printf("[게임 %d]", Turn);

	for (int i = 0; i < Count; i++)
	{
		printf("%c", Divider);
	}

	printf("\n");
}

int PlayDice(int DiceSize)
{
	return (rand() % DiceSize) + 1;
}

void PrintCash(int PlayerCash, int ComputerCash)
{
	printf("[소지 금액 : %d $]  [컴퓨터 소지 금액 : %d $]\n", PlayerCash, ComputerCash);
}

int SafeInput()
{
	int Input = 0;

	cin >> Input;
	cin.clear();
	cin.ignore(10000, '\n');

	return Input;
}

bool IsValidBetAmount(int BetAmount, int MaxBetAmount)
{
	return BetAmount > 0 && BetAmount <= MaxBetAmount;
}

void RunPractice2()
{
	//2. 주사위 게임
	//    1. 초기 세팅
	//    - 플레이어와 컴퓨터 모두 일정 금액(예: 10000원)으로 시작한다.
	//    2. 1차 주사위 굴리기
	//    - 게임 시작 시, 플레이어와 컴퓨터가 각각 주사위(1~6)를 한 번 굴린다.
	//    - 각자 주사위 결과를 공개한다.
	//    3. 배팅
	//    - 이전 판에서 진 쪽이 배팅 금액을 제시한다.
	//    - 제시한 배팅 금액은 두 사람 모두의 현재 소지 금액 이하이어야 한다.
	//    - 배팅 금액은 두 사람 모두에게서 차감된다.
	//    4. 2차 주사위 굴리기
	//    - 다시 플레이어와 컴퓨터가 각각 주사위를 한 번씩 굴린다.
	//    - (1차 + 2차) 주사위의 합을 계산한다.
	//    5. 승패 판정 및 금액 증감
	//    - 합이 더 큰 쪽이 배팅 금액의 총합(즉, 2×배팅금액)을 모두 가져간다.
	//    - 동점일 경우 배팅 금액은 그대로 반환한다.
	//    6. 다음 판 진행
	//    - 소지금이 0 이하인 쪽이 나오면 게임 종료.

	const int InitialCash = 10000;
	const int DiceSize = 6;
	int PlayerCash = InitialCash, ComputerCash = InitialCash;
	int PlayerDice1 = 0, ComputerDice1 = 0;
	int PlayerDice2 = 0, ComputerDice2 = 0;
	int PlayerDiceSum = 0, ComputerDiceSum = 0;
	int MaxBetAmount = 0;
	int BetAmount = 0;
	bool PlayerLost = false;
	int Turn = 1;

	while (PlayerCash > 0 && ComputerCash > 0)
	{
		PrintGameDivider('=', 20, Turn);

		PlayerDice1 = 0;
		PlayerDice2 = 0;
		PlayerDiceSum = 0;
		ComputerDice1 = 0;
		ComputerDice2 = 0;
		ComputerDiceSum = 0;

		// 1차 주사위 굴리기
		PlayerDice1 = PlayDice(DiceSize);
		ComputerDice1 = PlayDice(DiceSize);
		printf("\n[1차 주사위 굴리기]\n");
		printf("플레이어 : %d  |  컴퓨터 : %d\n", PlayerDice1, ComputerDice1);

		// 배팅
		MaxBetAmount = PlayerCash < ComputerCash ? PlayerCash : ComputerCash;
		BetAmount = 0;

		if (PlayerLost)
		{
			do
			{
				PrintCash(PlayerCash, ComputerCash);
				printf("배팅 금액을 입력하세요 : ");
				BetAmount = SafeInput();

				if (!IsValidBetAmount(BetAmount, MaxBetAmount))
				{
					printf("적절한 배팅 금액을 다시 입력해주세요.\n");
				}
			} while (!IsValidBetAmount(BetAmount, MaxBetAmount));
		}
		else
		{
			BetAmount = (rand() % MaxBetAmount) + 1;
		}

		printf("\n[배팅 금액 : %d$]\n", BetAmount);

		PlayerCash -= BetAmount;
		ComputerCash -= BetAmount;
		printf("[배팅 금액이 소지금에서 차감됐습니다]\n");
		PrintCash(PlayerCash, ComputerCash);

		// 2차 주사위 굴리기
		PlayerDice2 = PlayDice(DiceSize);
		ComputerDice2 = PlayDice(DiceSize);
		printf("\n[2차 주사위 굴리기]\n");
		printf("플레이어 : %d  |  컴퓨터 : %d\n", PlayerDice2, ComputerDice2);

		// 승패 판정 및 금액 증감
		printf("\n[승패 판정] - ");

		PlayerDiceSum = PlayerDice1 + PlayerDice2;
		ComputerDiceSum = ComputerDice1 + ComputerDice2;

		if (PlayerDiceSum > ComputerDiceSum)
		{
			printf("플레이어가 승리했습니다!!\n");
			PlayerCash += BetAmount * 2;
			PlayerLost = false;
		}
		else if (PlayerDiceSum < ComputerDiceSum)
		{
			printf("플레이어가 패배했습니다..\n");
			ComputerCash += BetAmount * 2;
			PlayerLost = true;
		}
		else
		{
			printf("무승부\n");
			PlayerCash += BetAmount;
			ComputerCash += BetAmount;
			PlayerLost = false;
		}

		printf("[플레이어 주사위의 합 : %d]  [컴퓨터 주사위의 합 : %d]\n", PlayerDiceSum, ComputerDiceSum);
		PrintCash(PlayerCash, ComputerCash);

		Turn++;
	}

	printf("\n================================================\n");
	printf("\n[주사위 게임이 종료되었습니다]\n");
}
