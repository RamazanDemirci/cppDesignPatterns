#include <iostream>
#include <string>
#include <math.h>
#include <random>

#define f(n) for (int o = 0; o < n; o++)

enum Direction
{
    FORWARD,
    BACKWARD
};

class Engine
{
public:
    virtual double getRpm() = 0;
    virtual double getRpmRate() = 0;
    virtual void energize(double energy) = 0;
};

class Train
{

public:
    virtual void setEngine(Engine *engine) = 0;
    virtual void speedUp() = 0;
    virtual void speedDown() = 0;
    virtual void setDirection(Direction direction) = 0;
};

class ElectricEngine : public Engine
{
private:
    double m_Rpm;
    const double m_RpmMax = 13000;

public:
    virtual double getRpm() override
    {
        return m_Rpm;
    };
    virtual double getRpmRate() override
    {
        return m_Rpm / m_RpmMax;
    };
    virtual void energize(double energy) override
    {
        std::default_random_engine defEngine(time(0));
        std::uniform_real_distribution<double> dblDistro(1.0, 2.0);

        m_Rpm += energy * dblDistro(defEngine);

        if (m_Rpm > m_RpmMax)
            m_Rpm = m_RpmMax;
        else if (m_Rpm < 0)
            m_Rpm = 0;
    }
};

class DieselEngine : public Engine
{
private:
    double m_Rpm;
    const double m_RpmMax = 13000;

public:
    virtual double getRpm() override
    {
        return m_Rpm;
    };
    virtual double getRpmRate() override
    {
        return m_Rpm / m_RpmMax;
    };
    virtual void energize(double energy) override
    {
        std::default_random_engine defEngine(time(0));
        std::uniform_real_distribution<double> dblDistro(1.0, 2.0);

        m_Rpm += energy * dblDistro(defEngine);

        if (m_Rpm > m_RpmMax)
            m_Rpm = m_RpmMax;
        else if (m_Rpm < 0)
            m_Rpm = 0;
    }
};

class MonoRail : public Train
{
    double m_speed;
    const double m_speedLimit = 352.5f;
    double m_acceleration;
    Direction m_direction;

    Engine *m_engine;

public:
    MonoRail()
    {
        m_speed = 0.0f;
        m_acceleration = 0.0f;
    };
    void speedChanged()
    {
        double prevSpeed = m_speed;
        m_speed = m_engine->getRpmRate() * m_speedLimit;

        if (m_speed > m_speedLimit)
            m_speed = m_speedLimit;

        m_acceleration = (m_speed - prevSpeed) / 100;
        std::cout << "MonoRail::Speed : " << m_speed << "::Acceleration :" << m_acceleration << std::endl;
    }
    virtual void setEngine(Engine *engine) override
    {
        m_engine = engine;
    }
    virtual void speedUp() override
    {
        double energy = 1000.0f;
        m_engine->energize(energy);
        speedChanged();
    };
    virtual void speedDown() override
    {
        double energy = -1000.0f;
        m_engine->energize(energy);
        speedChanged();
    };
    virtual void setDirection(Direction direction) override
    {
        if (m_speed == 0)
            m_direction = direction;
        else
            std::cout << "Upps! You can not change direction in case of moving" << std::endl;
    };
};

class Rail : public Train
{
    double m_speed;
    const double m_speedLimit = 136.2f;
    double m_acceleration;
    Direction m_direction;

    Engine *m_engine;

public:
    Rail()
    {
        m_speed = 0.0f;
        m_acceleration = 0.0f;
    };
    void speedChanged()
    {
        double prevSpeed = m_speed;
        m_speed = m_engine->getRpmRate() * m_speedLimit;

        if (m_speed > m_speedLimit)
            m_speed = m_speedLimit;

        m_acceleration = (m_speed - prevSpeed);

        std::cout << "Rail::Speed : " << m_speed << "::Acceleration :" << m_acceleration << std::endl;
    }
    virtual void setEngine(Engine *engine) override
    {
        m_engine = engine;
    }
    virtual void speedUp() override
    {
        double energy = 1000.0f;
        m_engine->energize(energy);
        speedChanged();
    };
    virtual void speedDown() override
    {
        double energy = -1000.0f;
        m_engine->energize(energy);
        speedChanged();
    };
    virtual void setDirection(Direction direction) override
    {
        if (std::fabs(m_speed - 0.0f) > 0.01)
            m_direction = direction;
        else
            std::cout << "Upps! You can not change direction in case of moving" << std::endl;
    };
};

int main()
{
    Train *train = new Rail();
    train->setEngine(new DieselEngine());
    train->setDirection(Direction::FORWARD);
    //for (auto i : range(0, 10))
    f(10) { train->speedUp(); }
    f(12) { train->speedDown(); }
    train->setDirection(Direction::BACKWARD);
    f(2) { train->speedDown(); }
    train->setDirection(Direction::BACKWARD);
    train->setDirection(Direction::FORWARD);
    f(15) { train->speedUp(); }
}

/*
This example kartezyan problem:
First group : Rail Train, MonoRail Train, (Fast Train)
Second group : Electric Engine Train, Diesel Engine Train, (Steam Engine Train)

inheritance solution : 2*2
train

rail:train
dieselRail: rain
electricalRail: rain
(steamRailRail: rain)

monoRail:train
dieselMonoRail: monoRail
electricalMonoRail: monoRail
(steamMonoRail: monoRail)

(fastRail:train
dieselMonoRail: fastRail
electricalMonoRail: fastRail
steamFastRail: fastRail)

composition solution(bridge):

Engine
ElectricEngine: Engine
DieselEngine : Engine
(SteamEngine : Engine)

Train
MonoRail:Train
Rail:Train
(FastRail:Train)

as you can see above example inheritance way is inefficient. each include new type of train or engine we generate many class.
in the other hand, composition solution we decouple two group and we just generate new type of engine and train class. 
 


Bridge Pattern : Pointer to Implementation

Bridge Design Pattern prevents the Cartesian Product complexity explosion.

bridge is a mechanism that decouples the interface or the hierarchy from the implementation.

Benefits of Bridge Design Pattern

Bridge Design Pattern provides flexibility to develop abstraction(i.e. interface) and the implementation independently
It preserves the Open-Closed Principle,
The Bridge Design Pattern is an application of the old advice, "prefer composition over inheritance" but more smartly. 
A compile-time binding between an abstraction and its implementation should be avoided. So that an implementation can select at run-time.

When to use Bridge Design Pattern?

— When you are unsure of implementation or its variations and still you want to move forward with development.
— In case of a behavior permutation problem i.e. Cartesian Product Complexity Explosion.


What are the differences between the Adapter and Bridge Design Pattern?

— The adapter is commonly used with an existing app to make some otherwise-incompatible classes work together nicely.
— The bridge is usually designed up-front, letting you develop parts of an application independently of each other.

What are the differences between Strategy and Bridge Design Pattern?

— The strategy is a single dimension problem like a Multi-bit screwdriver.
— The bridge is a multi-dimension problem like communication types and devices.


https://softwareengineering.stackexchange.com/questions/121326/understanding-the-bridge-design-pattern
*/