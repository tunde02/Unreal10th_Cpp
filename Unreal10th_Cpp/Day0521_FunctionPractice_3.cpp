#include "Day0521_FunctionPractice_3.h"

const int Decide1 = 1;
const int Decide2 = 2;

int Decide1Or2()
{
	int Input = 0;

	while (!(Input == Decide1 || Input == Decide2))
	{
		Input = SafeInput();

		if (!(Input == Decide1 || Input == Decide2))
		{
			printf("ERROR: 올바른 숫자를 입력해주세요.\n");
		}
	}

	return Input;
}

void PrintCashAndBetAmount(int PlayerCash, int BetAmount)
{
	printf("[소지 금액 : %d ￦ | 현재 배팅 금액 : %d ￦]\n", PlayerCash, BetAmount);
}

void RunPractice3()
{
	//3. 홀짝 게임
	//    1. 초기 금액 및 배팅
	//        - 플레이어는 기본금 100원으로 베팅을 시작한다.
	//    2. 홀짝 선택
	//        - 플레이어가 1(홀) 또는 2(짝)을 선택한다.
	//    3. 결과 결정
	//        - 컴퓨터가 랜덤으로 1(홀) 또는 2(짝)을 선택한다.
	//        - 플레이어의 선택과 결과가 일치하면 승리(이기면 배팅금의 2배 획득), 다르면 패배(배팅금 전액 잃음).
	//    4. 연속 배팅 선택
	//        - 승리 시 플레이어는 두 가지 중 하나를 선택:
	//            - (A) 이긴 금액을 모두 다시 한 번에 배팅 (연승 도전)
	//            - (B) 이긴 금액을 얻고, 다시 100원부터 새로 배팅 시작
	//    5. 게임 종료 조건
	//        - 플레이어가 소지금이 100원 미만일 경우 게임 종료.

	const int InitialCash = 100;
	const int MinimumBetAmount = 100;
	const int BetMultiplier = 2;
	int PlayerCash = InitialCash;
	int BetAmount = MinimumBetAmount;
	int PlayerDecision, ComputerDecision = 0;
	int Turn = 1;

	while (PlayerCash >= InitialCash)
	{
		PrintGameDivider('=', 30, Turn);
		PrintCashAndBetAmount(PlayerCash, BetAmount);

		// 홀짝 선택
		printf("(1) 홀   (2)짝\n");
		printf("홀짝을 선택하세요 : ");

		PlayerDecision = Decide1Or2();

		// 결과 결정
		printf("\n[승패 판정] - ");
		ComputerDecision = (rand() % 2) + 1;
		if (PlayerDecision == ComputerDecision)
		{
			printf("플레이어가 승리했습니다!!\n");
			PlayerCash += BetAmount;

			// 연속 배팅 선택
			printf("\n[연속 배팅 선택]\n");
			PrintCashAndBetAmount(PlayerCash, BetAmount);
			printf("(1) 이긴 금액을 모두 다시 한 번에 배팅 (연승 도전)\n");
			printf("(2) 이긴 금액을 얻고, 다시 100원부터 새로 배팅 시작\n");
			printf("배팅 방법을 선택하세요 : ");

			PlayerDecision = Decide1Or2();

			if (PlayerDecision == Decide1)
			{
				BetAmount *= BetMultiplier;
			}
			else
			{
				BetAmount = MinimumBetAmount;
			}
		}
		else
		{
			PlayerCash -= BetAmount;
			BetAmount = MinimumBetAmount;
			printf("플레이어가 패배했습니다..\n");
			printf("[소지 금액 : %d￦]\n", PlayerCash);
		}

		Turn++;
	}

	printf("\n====================================================================\n");
	printf("\n[홀짝 게임이 종료되었습니다]\n");
}
