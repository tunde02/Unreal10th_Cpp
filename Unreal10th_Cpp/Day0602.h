#pragma once
#include <iostream>

void Day0602();

void Day0602_Class();
void Day0602_Virtual();

// 간단 실습
// - 동물 클래스 만들어보기
//   - 움직이면 에너지를 소비한다
//   - 소리를 지를 수 있다
//   - 먹을 수 있다. 먹으면 에너지가 증가한다
//   - 잠을 잘 수 있다. 잠을 자면 나이가 증가하고, 에너지가 완전히 회복된다
//   - 자신의 모든 정보를 출력할 수 있다

class Animal
{
protected:
    const float MaxEnergy = 100.0f;
    const float MoveEnergy = 10.0f;
    const float RecoveryEnergy = 30.0f;

    // 멤버 변수
    std::string Name = "동물";
    int Age = 0;
    float Energy = MaxEnergy;
    std::string Actions{ "Move(), Yell(), Eat(), Sleep(), ShowInfo()" };

public: // 접근 제한자
    // 생성자
    Animal() = default;
    Animal(const std::string& InName) : Name(InName) {}

    // 소멸자
    ~Animal() = default;

    // 멤버 함수
    virtual void Move();
    virtual void Yell() const;
    void Eat();
    void Sleep();
    void ShowInfo() const;

    // const: 함수 내에서 다른 멤버 변수를 수정하지 않겠다는 의미
    inline int GetAge() const { return Age; }
    inline void SetAge(int InAge) { Age = InAge; }
};

class Bird : public Animal
{
private:
    const float FlyEnergy = 20.0f;

public:
    Bird(const std::string& InName) : Animal(InName)
    {
        Actions += ", Fly()";
    }

    virtual void Yell() const override;
    void Fly();
};

class Eagle : public Bird
{
private:
    const float FastFlyEnergy = 50.0f;

public:
    Eagle(const std::string& InName) : Bird(InName)
    {
        Actions += ", FastFly()";
    }

    virtual void Yell() const override;
    virtual void Move() override;
    void FastFly();
};

// 간단 실습
// Animal의 자식 클래스 5가지 이상 만들기
// 각 자식 클래스는 자신만의 기능이 있어야 한다

class Whale : public Animal
{
private:
    const float SwimEnergy = 10.0f;

public:
    Whale(const std::string& InName) : Animal(InName)
    {
        Actions += ", Swim()";
    }

    virtual void Yell() const override;
    virtual void Move() override;
    void Swim();
};

class Snake : public Animal
{
private:
    const float SlideEnergy = 5.0f;

public:
    Snake(const std::string& InName) : Animal(InName)
    {
        Actions += ", Slide()";
    }

    virtual void Yell() const override;
    virtual void Move() override;
    void Slide();
};

class Horse : public Animal
{
private:
    const float RunEnergy = 40.0f;

public:
    Horse(const std::string& InName) : Animal(InName)
    {
        Actions += ", Run()";
    }

    virtual void Move() override;
    void Run();
};

class Kangaroo : public Animal
{
private:
    const float JumpEnergy = 15.0f;

public:
    Kangaroo(const std::string& InName) : Animal(InName)
    {
        Actions += ", Jump()";
    }

    virtual void Move() override;
    void Jump();
};

class Monkey : public Animal
{
private:
    const float HangEnergy = 25.0f;

public:
    Monkey(const std::string& InName) : Animal(InName)
    {
        Actions += ", Hang()";
    }

    virtual void Move() override;
    void Hang();
};
