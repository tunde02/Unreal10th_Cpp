#pragma once

/*

int Age = 0;

printf("자신의 나이를 입력하세요 : ");
std::cin >> Age;

printf("당신의 나이는 %d세 입니다.", Age);

// 변수 (Variable)
// - 변하는 숫자
// - 컴퓨터한테 값을 기억시키기 위해 만들고 사용한다
// - 메모리의 일정 공간을 확보하고 이름을 붙여 사용한다
// - DATA_TYPE VARIABLE_NAME; 형식으로 선언

// 명명 규칙
// - 중요하다
// - 길이가 길어지더라도 알아보기 쉽고 간결해야한다
// 

// int (Integer)
// - 정수형 타입 (소수점이 없는 숫자)
// - 일반적으로 32bit 크기를 가진다 (CPU가 한 번에 처리할 수 있는 데이터 크기에 따라 달라짐)
// - 숫자 범위를 벗어나는 값을 넣으면 넘쳐서 반대쪽으로 돌아가버린다 (오버플로우, 언더플로우)

*/

/*

int Number = 10; // 대입 연산자로 Number에 10을 넣었다.
printf("%5d\n", Number); // Number를 정수 5자리로 출력해라. (숫자가 5자리보다 크다고 짤리지는 않음)

Number = 20; // 대입 연산자로 Number에 20을 넣었다.
printf("%5d\n", Number);
Number = 5 + 10; // 산술 연산자 +를 이용해서 5와 10을 더하고, 그 결과를 Number에 대입한다.
printf("%5d\n", Number);
Number = 7 % 3; // 산술 연산자 %를 이용해서 7을 3으로 나눈 나머지를 구하고(1), 그 결과를 Number에 대입한다.
printf("%5d\n", Number);

int Temp1 = 7;

Number += Temp1; // Number와 Temp1의 값을 더하고, 그 결과를 Number에 대입한다. (Number = 8)
printf("%5d\n", Number);
Number *= Temp1; // Number와 Temp1의 값을 곱하고, 그 결과를 Number에 대입한다. (Number = 56)
printf("%5d\n", Number);

Number--; // (Number = 55)
printf("%5d\n", Number);
Number--; // (Number = 54)
printf("%5d\n", Number);
Number--; // (Number = 53)
printf("%5d\n", Number);

*/

/*

// 간단 실습
// 두 수를 입력받아 스왑하기
printf("두 수를 입력받아 스왑하기\n");
int A1, B1;
printf("숫자를 입력하세요 : ");
std::cin >> A1;
printf("또다른 숫자를 입력하세요 : ");
std::cin >> B1;

int Temp = A1;
A1 = B1;
B1 = Temp;
printf("스왑 결과 : %d, %d\n\n", A1, B1);

// 두 수를 입력받아 합을 출력하기
printf("두 수를 입력받아 합을 출력하기\n");
int A2, B2;
printf("숫자를 입력하세요 : ");
std::cin >> A2;
printf("또다른 숫자를 입력하세요 : ");
std::cin >> B2;

printf("두 수의 합 : %d\n\n", A2 + B2);

// 사각형의 가로, 세로를 입력받아 넓이를 출력하기
printf("사각형의 가로, 세로를 입력받아 넓이를 출력하기\n");
int Width, Height;
printf("사각형의 가로 길이를 입력하세요 : ");
std::cin >> Width;
printf("사각형의 가로 길이를 입력하세요 : ");
std::cin >> Height;

printf("사각형의 넓이 : %d\n\n", Width * Height);

// 두 수를 입력받아 나머지를 출력하기 - % 연사자 사용
printf("두 수를 입력받아 나머지를 출력하기 - % 연사자 사용\n");
int A3, B3;
printf("숫자를 입력하세요 : ");
std::cin >> A3;
printf("또다른 숫자를 입력하세요 : ");
std::cin >> B3;

printf("첫 번째 수를 두 번째 수로 나눈 나머지 : %d\n\n", A3 % B3);

// 두 수를 입력받아 나머지를 출력하기 - % 연사자 사용 X
printf("두 수를 입력받아 나머지를 출력하기 - % 연사자 사용 X\n");
int A4, B4;
printf("숫자를 입력하세요 : ");
std::cin >> A4;
printf("또다른 숫자를 입력하세요 : ");
std::cin >> B4;

printf("첫 번째 수를 두 번째 수로 나눈 나머지 : %d\n\n", A4 - (A4 / B4 * B4));

*/