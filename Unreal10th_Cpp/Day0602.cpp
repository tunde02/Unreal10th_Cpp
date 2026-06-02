#include "Day0602.h"

void Day0602()
{
    Day0602_Class();

    Day0602_Virtual();
}

void Day0602_Class()
{
    Animal* TestAnimal = new Animal();

    TestAnimal->ShowInfo();

    delete TestAnimal;
    TestAnimal = nullptr;

    Eagle* MyEagle = new Eagle("독수리");
    MyEagle->Fly();
    MyEagle->ShowInfo();

    Animal* pEagle = MyEagle;
    //pEagle->Fly(); // 불가능
    pEagle->ShowInfo();

    Whale* MyWhale = new Whale("고래");
    Snake* MySnake = new Snake("뱀");
    Horse* MyHorse = new Horse("말");
    Kangaroo* MyKangaroo = new Kangaroo("캥거루");
    Monkey* MyMonkey = new Monkey("원숭이");

    MyEagle->Fly();
    MyEagle->FastFly();

    MyWhale->Swim();
    MySnake->Slide();
    MyHorse->Run();
    MyKangaroo->Jump();
    MyMonkey->Hang();

    MyEagle->ShowInfo();
    MyWhale->ShowInfo();
    MySnake->ShowInfo();
    MyHorse->ShowInfo();
    MyKangaroo->ShowInfo();
    MyMonkey->ShowInfo();

    delete MyEagle;
    MyEagle = nullptr;
    delete MyWhale;
    MyWhale = nullptr;
    delete MySnake;
    MySnake = nullptr;
    delete MyHorse;
    MyHorse = nullptr;
    delete MyKangaroo;
    MyKangaroo = nullptr;
    delete MyMonkey;
    MyMonkey = nullptr;
}

void Day0602_Virtual()
{
    Animal* Zoo[3] = { nullptr };
    Zoo[0] = new Eagle("독수리");
    Zoo[1] = new Whale("고래");
    Zoo[2] = new Horse("말");

    for (Animal* pAnimal : Zoo)
    {
        pAnimal->ShowInfo();
    }

    for (int i = 0; i < 3; i++)
    {
        delete Zoo[i]; // virtual ~Animal이 없으면 기본적인 ~Animal()만 호출되어 문제가 발생할 수도 있다
        Zoo[i] = nullptr;
    }
}

void Animal::Move()
{
    printf("%s가 움직입니다. 에너지를 %.0f 소비합니다.\n", Name.c_str(), MoveEnergy);

    Energy -= MoveEnergy;
}

void Animal::Yell() const
{
    printf("%s가 소리를 지릅니다.\n", Name.c_str());
}

void Animal::Eat()
{
    printf("%s가 먹습니다. 에너지를 %.0f 회복합니다.\n", Name.c_str(), RecoveryEnergy);

    Energy += RecoveryEnergy;
}

void Animal::Sleep()
{
    printf("%s가 잠을 잡니다.\n", Name.c_str());

    Age++;
    Energy = MaxEnergy;
}

void Animal::ShowInfo() const
{
    printf("------------------------------\n");
    printf("%s의 정보\n", Name.c_str());
    printf("이름\t: %s\n", Name.c_str());
    printf("나이\t: %d\n", Age);
    printf("에너지\t: %.0f\n", Energy);
    printf("행동\t: %s\n", Actions.c_str());
}

void Bird::Yell() const
{
    printf("%s : 짹짹\n", Name.c_str());
}

void Bird::Fly()
{
    printf("%s가 하늘을 납니다. 에너지가 %.0f 감소합니다.\n", Name.c_str(), FlyEnergy);
    Energy -= FlyEnergy;
}

void Whale::Yell() const
{
    printf("%s : 고래\n", Name.c_str());
}

void Whale::Move()
{
    printf("%s가 수영하며 움직입니다. 에너지가 %.0f 감소합니다.\n", Name.c_str(), SwimEnergy);
    Energy -= SwimEnergy;
}

void Whale::Swim()
{
    printf("%s가 수영합니다. 에너지가 %.0f 감소합니다.\n", Name.c_str(), SwimEnergy);
    Energy -= SwimEnergy;
}

void Snake::Yell() const
{
    printf("%s : 스스슥\n", Name.c_str());
}

void Snake::Move()
{
    printf("%s가 미끄러지며 움직입니다. 에너지가 %.0f 감소합니다.\n", Name.c_str(), SlideEnergy);
    Energy -= SlideEnergy;
}

void Snake::Slide()
{
    printf("%s가 미끄러집니다. 에너지가 %.0f 감소합니다.\n", Name.c_str(), SlideEnergy);
    Energy -= SlideEnergy;
}

void Horse::Move()
{
    printf("%s가 달리며 움직입니다. 에너지가 %.0f 감소합니다.\n", Name.c_str(), RunEnergy);
    Energy -= RunEnergy;
}

void Horse::Run()
{
    printf("%s가 달립니다. 에너지가 %.0f 감소합니다.\n", Name.c_str(), RunEnergy);
    Energy -= RunEnergy;
}

void Kangaroo::Move()
{
    printf("%s가 껑충 뛰며 움직입니다. 에너지가 %.0f 감소합니다.\n", Name.c_str(), JumpEnergy);
    Energy -= JumpEnergy;
}

void Kangaroo::Jump()
{
    printf("%s가 점프합니다. 에너지가 %.0f 감소합니다.\n", Name.c_str(), JumpEnergy);
    Energy -= JumpEnergy;
}

void Monkey::Move()
{
    printf("%s가 메달리며 움직입니다. 에너지가 %.0f 감소합니다.\n", Name.c_str(), HangEnergy);
    Energy -= HangEnergy;
}

void Monkey::Hang()
{
    printf("%s가 나무에 매달립니다. 에너지가 %.0f 감소합니다.\n", Name.c_str(), HangEnergy);
    Energy -= HangEnergy;
}

void Eagle::Yell() const
{
    printf("%s : 짹짹\n", Name.c_str());
}

void Eagle::Move()
{
    printf("%s가 빠르게 비행하며 움직입니다. 에너지가 %.0f 감소합니다.\n", Name.c_str(), FastFlyEnergy);
    Energy -= FastFlyEnergy;
}

void Eagle::FastFly()
{
    printf("%s가 하늘을 빠르게 납니다. 에너지가 %.0f 감소합니다.\n", Name.c_str(), FastFlyEnergy);
    Energy -= FastFlyEnergy;
}
