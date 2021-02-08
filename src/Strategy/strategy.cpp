#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <array>
#include <algorithm>

class Behavior
{
public:
    virtual int perform() = 0;
};
class StraightPunch : public Behavior
{
public:
    virtual int perform() override
    {
        const int point = 10;
        std::cout << "Performed StraightPunch got " << point << " points" << std::endl;
        return point;
    };
};
class CrossesPunch : public Behavior
{
    virtual int perform() override
    {
        const int point = 12;
        std::cout << "Performed CrossesPunch got " << point << " points" << std::endl;
        return point;
    };
};
class HooksPunch : public Behavior
{
    virtual int perform() override
    {
        const int point = 14;
        std::cout << "Performed HooksPunch got " << point << " points" << std::endl;
        return point;
    };
};
class UppercutPunch : public Behavior
{
    virtual int perform() override
    {
        const int point = 16;
        std::cout << "Performed UppercutPunch got " << point << " points" << std::endl;
        return point;
    };
};
class HurricaneKick : public Behavior
{
    virtual int perform() override
    {
        const int point = 12;
        std::cout << "Performed HurricaneKick got " << point << " points" << std::endl;
        return point;
    };
};
class Hadoken : public Behavior
{
    virtual int perform() override
    {
        const int point = 20;
        std::cout << "Performed Hadoken got " << point << " points" << std::endl;
        return point;
    };
};
class ScissorKick : public Behavior
{
    virtual int perform() override
    {
        const int point = 8;
        std::cout << "Performed ScissorKick got " << point << " points" << std::endl;
        return point;
    };
};
class RoundhouseKick : public Behavior
{
    virtual int perform() override
    {
        const int point = 10;
        std::cout << "Performed RoundhouseKick got " << point << " points" << std::endl;
        return point;
    };
};

class Fighter
{
    std::string m_name;
    int m_points;
    int m_age;
    std::map<std::string, Behavior *> m_behaviorMap;

public:
    Fighter()
    {
        m_points = 0;
    }

    std::string getName()
    {
        return m_name;
    }
    void setName(std::string name)
    {
        m_name = name;
    }
    int getAge()
    {
        return m_age;
    }
    void setAge(int age)
    {
        m_age = age;
    }
    int getPoints()
    {
        return m_points;
    }
    void addBehavior(std::string key, Behavior *b)
    {
        if (key != "")
            m_behaviorMap[key] = b;
    };
    void performBehavior(std::string key)
    {
        if (m_behaviorMap.find(key) == m_behaviorMap.end())
        {
            std::cout << "key : " << key << "not Found" << std::endl;
            std::cout << "performBehavior not execute scuccesfully" << std::endl;
            return;
        }
        std::cout << m_name << "::";
        m_points += m_behaviorMap[key]->perform();
    };
};

int gen(int size)
{
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, size);
    return dis(gen);
}

std::string winnerDecorate(std::string str)
{
    std::string res = "";
    std::for_each(
        str.begin(),
        str.end(),
        [&](unsigned char c) {
            res.push_back(c);
            res.push_back(' ');
        });
    return res;
}

int main()
{
    std::array<std::string, 6> paulBK = {"StraightPunch", "HooksPunch", "Hadoken", "UppercutPunch", "HurricaneKick", "RoundhouseKick"};
    std::array<std::string, 5> ChunLiBK = {"StraightPunch", "CrossesPunch", "UppercutPunch", "HurricaneKick", "ScissorKick"};

    Fighter *left = new Fighter();
    left->setName("Paul");
    left->setAge(26);
    left->addBehavior("StraightPunch", new StraightPunch());
    left->addBehavior("HooksPunch", new HooksPunch());
    left->addBehavior("Hadoken", new Hadoken());
    left->addBehavior("UppercutPunch", new UppercutPunch());
    left->addBehavior("HurricaneKick", new HurricaneKick());
    left->addBehavior("RoundhouseKick", new RoundhouseKick());

    Fighter *right = new Fighter();
    right->setName("Chun Li");
    right->setAge(20);
    right->addBehavior("StraightPunch", new StraightPunch());
    right->addBehavior("CrossesPunch", new CrossesPunch());
    right->addBehavior("UppercutPunch", new UppercutPunch());
    right->addBehavior("HurricaneKick", new HurricaneKick());
    right->addBehavior("ScissorKick", new ScissorKick());
    std::cout << "LeftSide : " << left->getName() << std::endl;
    std::cout << "RightSide : " << right->getName() << std::endl;
    std::cout << "FIGHT START" << std::endl;

    std::cout << ":::->" << gen(18) << std::endl;

    while (left->getPoints() < 200 && right->getPoints() < 200)
    {
        if (gen(18) % 2 == 0)
            left->performBehavior(paulBK[gen(paulBK.size() - 1)]);
        else
            right->performBehavior(ChunLiBK[gen(ChunLiBK.size() - 1)]);

        std::cout << left->getName() << " points :" << left->getPoints() << "  -----------  " << right->getName() << " points : " << right->getPoints() << std::endl;
    }

    if (left->getPoints() > 199)
        std::cout << "The Winner : " << winnerDecorate(left->getName()) << std::endl;
    else if (right->getPoints() > 199)
        std::cout << "The Winner : " << winnerDecorate(right->getName()) << std::endl;
}

/*
Strategy Pattern

The Strategy pattern is known as a behavioural pattern - it's used to manage algorithms, relationships and responsibilities between objects

Where Would I Use This Pattern?
The Strategy pattern is to be used where you want to choose the algorithm to use at runtime.
 A good use of the Strategy pattern would be saving files in different formats, running various sorting algorithms, or file compression.
*/