#include "Day0521_FunctionPractice_1.h"

int AddPlayerState(int Target, PlayerState State)
{
	int Result = Target;

	Result |= State;

	return Result;
}

int SubPlayerState(int Target, PlayerState State)
{
	int Result = Target;

	Result &= ~State;

	return Result;
}

int TogglePlayerState(int Target, PlayerState State)
{
	int Result = Target;

	Result ^= State;

	return Result;
}

void PrintPlayerState(int State)
{
	char IdleOX = State & Idle ? 'O' : 'X';
	char JumpOX = State & Jump ? 'O' : 'X';
	char AttackOX = State & Attack ? 'O' : 'X';
	char InvincibleOX = State & Invincible ? 'O' : 'X';

	printf("대기 : [%c] , 점프 : [%c] , 공격 : [%c] , 무적 : [%c]\n\n", IdleOX, JumpOX, AttackOX, InvincibleOX);
}

void RunPractice1()
{
	//1. 비트플래그를 이용한 캐릭터 상태 변환 구현하기
	//    - 캐릭터의 상태는 대기, 점프, 공격, 무적 4가지가 존재
	//    - 다음 작업을 수행하고 현재 상태 출력하기
	//    - 플레이어의 상태를 대기로 설정
	//    - 점프 상태 추가
	//    - 공격 상태 추가
	//    - 대기 상태 해제
	//    - 무적 상태 추가
	//    - 무적 상태 토글(XOR 사용)
	//    - 현재 상태를 출력할 때는 다음과 같은 양식을 따를 것
	//    - 대기 : [O] , 점프 : [O] , 공격 : [X] , 무적 : [O]

	int PlayerState = 0;

	printf("[초기 상태]\n");
	PrintPlayerState(PlayerState);

	printf("[플레이어의 상태를 대기로 설정]\n");
	PlayerState = Idle;
	PrintPlayerState(PlayerState);

	printf("[점프 상태 추가]\n");
	PlayerState = AddPlayerState(PlayerState, Jump);
	PrintPlayerState(PlayerState);

	printf("[공격 상태 추가]\n");
	PlayerState = AddPlayerState(PlayerState, Attack);
	PrintPlayerState(PlayerState);

	printf("[대기 상태 해제]\n");
	PlayerState = SubPlayerState(PlayerState, Idle);
	PrintPlayerState(PlayerState);

	printf("[무적 상태 추가]\n");
	PlayerState = AddPlayerState(PlayerState, Invincible);
	PrintPlayerState(PlayerState);

	printf("[무적 상태 토글(XOR 사용)]\n");
	PlayerState = TogglePlayerState(PlayerState, Invincible);
	PrintPlayerState(PlayerState);
}
