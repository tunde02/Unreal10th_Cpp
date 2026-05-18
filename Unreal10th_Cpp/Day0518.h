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

/*

// 1. 온도 변환기
printf("1. 온도 변환기\n");

int Celsius, Fahrenheit;
printf("섭씨 온도를 정수로 입력하세요 : ");
std::cin >> Celsius;

Fahrenheit = Celsius * 9 / 5 + 32;
printf("변환된 화씨 온도 : %d'F\n\n", Fahrenheit);

// 2. 시간 계산기
printf("2. 시간 계산기\n");

int Second, Minute, Hour;
printf("초를 입력하세요 : ");
std::cin >> Second;

Hour = Second / 3600;
Minute = (Second - (Hour * 3600)) / 60;
Second = (Second % 3600) % 60;
printf("%d시 %d분 %d초\n\n", Hour, Minute, Second);

// 3. 동전 개수 계산하기
// 500원, 100원, 50원, 10원
printf("3. 동전 개수 계산하기\n");

int Price;
int Count500, Count100, Count50, Count10;
printf("금액을 입력하세요 : ");
std::cin >> Price;

Count500 = Price / 500;
Price %= 500;
Count100 = Price / 100;
Price %= 100;
Count50 = Price / 50;
Price %= 50;
Count10 = Price / 10;
Price %= 10;
printf("필요한 동전들 ↓\n");
printf("500원 : %d개, 100원 : %d개, 50원 : %d개, 10원 : %d개\n\n", Count500, Count100, Count50, Count10);

// 4. 자리수 분리하기 (입력은 항상 세자리라고 가정)
printf("4. 자리수 분리하기 (입력은 항상 세자리라고 가정)\n");

int Number, Number100, Number10, Number1;
printf("숫자를 입력하세요 : ");
std::cin >> Number;

Number100 = Number / 100;
Number %= 100;
Number10 = Number / 10;
Number1 = Number % 10;
printf("100의 자리수 : %d, 10의 자리수 : %d, 1의 자리수 : %d\n", Number100, Number10, Number1);
printf("각 자리수의 합 : %d\n\n", Number100 + Number10 + Number1);

// 5. 파일 용량 환산기
printf("5. 파일 용량 환산기\n");

int MB, KB, Byte;
printf("파일 크기를 메가바이트(MB) 단위로 입력하세요 : ");
std::cin >> MB;

KB = MB * 1024;
Byte = KB * 1024;
printf("파일 크기 ↓\n");
printf("%dMB, %dKB, %dByte\n\n", MB, KB, Byte);

// 6. 타일 개수 계산기 (면적 구하기)
printf("6. 타일 개수 계산기 (면적 구하기)\n");

int Width, Height, WidthCount, HeightCount;
int TileSize = 30;
printf("직사각형 방의 가로 길이(cm)를 입력하세요 : ");
std::cin >> Width;
printf("직사각형 방의 세로 길이(cm)를 입력하세요 : ");
std::cin >> Height;

// 나누어 떨어지지 않는 경우에만 성립하던 수식
//Width = (Width + 30 - (Width % 30)) / 30;
//Height = (Height + 30 - (Height % 30)) / 30;

// 절대 아닐거라고 생각했던, 1을 빼거나 더하는 방식이 맞았다

WidthCount = (Width + (TileSize - 1)) / TileSize;
HeightCount = (Height + (TileSize - 1)) / TileSize;
printf("방을 채우기 위해 필요한 타일 개수 : %d\n", WidthCount* HeightCount);

*/