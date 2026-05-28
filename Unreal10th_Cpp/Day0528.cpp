#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "Day0528.h"
using std::string;

void Day0528()
{
    //Day0528_String();
    //Day0528_FileIO();
    //Day0528_Example02();
    Day0528_Structure();
}

void Day0528_String()
{
    // std::string

    const char* Temp = "Hello World!\n"; // C 스타일 문자열
    std::string Str1 = "Hello"; // C++ 스타일 문자열

    printf("%s\n", Str1.c_str());

    std::string Str2 = "World!";
    printf("%s\n", Str2.c_str());
    std::string Str3 = Str1 + " " + Str2 + '\n';
    printf("%s\n", Str3.c_str());

    std::string Str4("Hello World?"); // 생성자 사용
    Str4 += Temp; // 문자열 합치기
    Str4.append("Append");
    printf("%s\n", Str4.c_str());

    // 비교
    std::string Str5 = "Hello";
    printf("%s의 길이 : %d\n", Str5.c_str(), (int)Str5.length());

    if (Str1 == Str5)
    {
        printf("Str1과 Str5는 같습니다.\n");
    }
    if (Str1 != Str2)
    {
        printf("Str1과 Str5는 다릅니다.\n");
    }
    if (Str1 < Str2)
    {
        printf("Str1이 Str2보다 앞에 있습니다.\n");
    }

    // 특정 문자 위치 찾기
    int ePos = (int)Str1.find('e');
    printf("%s에서 'e'는 %d번 인덱스에 있습니다.\n", Str1.c_str(), ePos);

    size_t Pos = Str1.find('l');
    while (Pos != std::string::npos)
    {
        printf("%s에서 'l'은 %d번 인덱스에 있습니다.\n", Str1.c_str(), (int)Pos);
        Pos = Str1.find('l', Pos + 1);
    }

    // 간단 실습
    // std::string과 char를 파라미터로 받아서 string에 char가 어디에 있었는지 출력하는 함수 만들기
    //   - 여러 개 있으면 모두 출력
    //   - 없으면 없다고 출력
    std::string Text("Hello World!!");
    Day0528_Example01(Text, 'l');
    Day0528_Example01(Text, 'q');
}

void Day0528_FileIO()
{
    // 파일 입력
    string InputFilePath = ".\\Data\\Datafile.txt"; // .은 현재 워킹 폴더 (프로젝트 파일이 있는 곳)
    std::ifstream InputFile(InputFilePath); // 입력용 파일스트림 변수 만들기
    if (InputFile.is_open())
    {
        string FileTexts(
            (std::istreambuf_iterator<char>(InputFile)),
            std::istreambuf_iterator<char>()
        );
        printf("파일 내용 : \n%s\n", FileTexts.c_str());
        InputFile.close();
    }
    else
    {
        // 파일이 없거나 다른 이유로 열리지 않음
        printf("파일을 열 수 없습니다.\n");
    }

    // 파일 출력
    string OutputFilePath = ".\\Data\\OutTest.txt"; // .은 현재 워킹 폴더 (프로젝트 파일이 있는 곳)
    std::ofstream OutFile(OutputFilePath); // 기본적으로 덮어쓰는 방식
    //std::ofstream OutFile(OutputFilePath, std::ios::app); // 파일 뒤에 추가하는 방식
    if (OutFile.is_open())
    {
        OutFile << "Hello World!@#!@#\n";
        OutFile << "안녕하세요 128378912\n";
        OutFile.close();
    }
    else
    {
        printf("파일을 생성할 수 없습니다.\n");
    }

    // 간단 실습
    //   - 이름과 돈을 입력받아 파일로 저장하기
    //   - 파일을 불러와서 저장된 이름과 돈을 출력하기
    Day0528_Example02();
}

void Day0528_Structure()
{
    // 구조체
    Enemy Orc;
    Orc.Name = "돌쇠";
    Orc.Health = 100.0f;
    Orc.AttackPower = 10.0f;
    Orc.Reward = 5;

    Day0528_Example03_PrintEnemy1(Orc);
    printf("\n");
    Day0528_Example03_PrintEnemy2(&Orc);
    printf("\n");

    EnemyOrc TestOrc = { "쓰랄", 200.0f, 50.0f, 100 }; // 2. 중괄호 초기화
    Day0528_Example03_PrintEnemyOrc1(TestOrc);
    printf("\n");

    EnemyOrc* TestOrc2 = new EnemyOrc(3.0f);
    Day0528_Example03_PrintEnemyOrc2(TestOrc2);
    printf("\n");

    delete TestOrc2;
    TestOrc2 = nullptr;
}

void Day0528_Example01(const std::string& String, const char C)
{
    size_t Pos = String.find(C);
    if (Pos == std::string::npos)
    {
        printf("%s에서 %c는 없습니다.\n", String.c_str(), C);
        return;
    }

    while (Pos != std::string::npos)
    {
        printf("%s에서 %c는 %d번 인덱스에 있습니다.\n", String.c_str(), C, (int)Pos);
        Pos = String.find(C, Pos + 1);
    }
}

void Day0528_Example02()
{
    string FilePath = ".\\Data\\Day0528_Example02.txt";

    if (Day0528_Example02_FileOutput(FilePath) == -1)
    {
        printf("파일 열기 실패\n");
    }

    if (Day0528_Example02_FileInput(FilePath) == -1)
    {
        printf("파일 불러오기 실패\n");
    }
}

int Day0528_Example02_FileInput(const std::string FilePath)
{
    std::ifstream InputFile(FilePath);

    if (!InputFile.is_open())
    {
        printf("파일을 열 수 없습니다.\n");
        return -1;
    }

    string FileContents(
        (std::istreambuf_iterator<char>(InputFile)),
        std::istreambuf_iterator<char>()
    );
    printf("[파일 내용]\n%s\n", FileContents.c_str());

    printf("[파일 출력을 완료했습니다]\n\n");

    InputFile.close();

    return 0;
}

int Day0528_Example02_FileOutput(const std::string FilePath, std::ios_base::openmode Openmode)
{
    std::ofstream OutputFile(FilePath, Openmode);

    if (!OutputFile.is_open())
    {
        printf("파일을 열 수 없습니다.\n");
        return -1;
    }

    while (true)
    {
        printf("[입력을 종료하려면 -1 입력]\n");
        printf("이름을 입력하세요 : ");
        string Name("");
        std::getline(std::cin, Name);

        if (Name == "-1")
        {
            printf("[입력을 종료합니다]\n");
            break;
        }

        printf("돈을 입력하세요 : ");
        string Money("");
        std::getline(std::cin, Money);

        if (Money == "-1")
        {
            printf("[입력을 종료합니다]\n");
            break;
        }

        OutputFile << Name << ";;" << Money << "\n";
    }

    printf("[파일 입력을 완료했습니다]\n\n");

    OutputFile.close();

    return 0;
}

void Day0528_Example03_PrintEnemy1(const Enemy& Target)
{
    printf("[참조를 사용]\n");
    printf("적의 이름은 [%s]입니다.\n", Target.Name.c_str());
    printf("적의 체력은 [%.1f]입니다.\n", Target.Health);
    printf("적의 공격력은 [%.1f]입니다.\n", Target.AttackPower);
    printf("적의 보상은 [%d]입니다.\n", Target.Reward);
}

void Day0528_Example03_PrintEnemy2(const Enemy* const Target)
{
    printf("[포인터를 사용]\n");
    printf("적의 이름은 [%s]입니다.\n", Target->Name.c_str());
    printf("적의 체력은 [%.1f]입니다.\n", Target->Health);
    printf("적의 공격력은 [%.1f]입니다.\n", Target->AttackPower);
    printf("적의 보상은 [%d]입니다.\n", Target->Reward);
}

void Day0528_Example03_PrintEnemyOrc1(const EnemyOrc& Target)
{
    printf("[참조를 사용]\n");
    printf("적의 이름은 [%s]입니다.\n", Target.Name.c_str());
    printf("적의 체력은 [%.1f]입니다.\n", Target.Health);
    printf("적의 공격력은 [%.1f]입니다.\n", Target.AttackPower);
    printf("적의 보상은 [%d]입니다.\n", Target.Reward);
}

void Day0528_Example03_PrintEnemyOrc2(const EnemyOrc* const Target)
{
    printf("[포인터를 사용]\n");
    printf("적의 이름은 [%s]입니다.\n", Target->Name.c_str());
    printf("적의 체력은 [%.1f]입니다.\n", Target->Health);
    printf("적의 공격력은 [%.1f]입니다.\n", Target->AttackPower);
    printf("적의 보상은 [%d]입니다.\n", Target->Reward);
}
