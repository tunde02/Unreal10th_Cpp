#include "Day0605.h"

void Day0605::Interface()
{
    IFlyable* List[2];
    Test0605_1 Test1;
    Test0605_2 Test2;

    List[0] = &Test1;
    List[1] = &Test2;
}

void Day0605::EnumClass()
{
    enum Color1 { Red, Green, Blue };
    //enum TrafficLight1 { Red, Yellow, Green }; // 재정의 오류
    enum Fruit1 { Apple, Orange, Banana };

    Color1 MyColor1 = Red;
    Fruit1 MyFruit1 = Apple;
    if (MyColor1 == MyFruit1) {
        // 일반 enum은 색상과 과일이 같다가 성립해버림
        printf("둘은 같습니다.\n");
    }

    enum class Color2 { Red, Green, Blue };
    enum class Fruit2 { Apple, Orange, Banana };

    Color2 MyColor2 = Color2::Red;
    Fruit2 MyFruit2 = Fruit2::Apple;
    //if (MyColor2 == MyFruit2) {
    //    enum class는 이런 비교 자체가 문법적으로 불가능해짐.별도의 타입이기 때문에
    //}

    Direction Dir = Direction::Up | Direction::Down;
    Dir |= Direction::Left;
    Dir &= Direction::Up;

    int a = 0;
}
