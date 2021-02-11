#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

#include <map>

#define f(n) for (int o = 0; o < n; o++)

enum Weapon
{
    M1_Garand,
    Luger_P08,
    Smoke_Grenade,
    Hand_Grenade,
    M1919A4
};

enum Strategy
{
    Deceptive_Disinformation,
    Deceptive_MilitaryCamouflage,
    Deceptive_Demoralization,
    Deceptive_FalseFlag,
    Defensive_DelayingDefence,
    Defensive_CounterAttack,
    Defensive_Fortification,
    Defensive_ShellScrapes,
    Offensive_Charge,
    Offensive_Ambush,
    Offensive_Skirmish,
    Offensive_TrenchRaiding
};

std::string strWeapon(Weapon w)
{
    switch (w)
    {

    case M1_Garand:
        return "M1_Garand";
    case Luger_P08:
        return "Luger_P08";
    case Smoke_Grenade:
        return "Smoke_Grenade";
    case Hand_Grenade:
        return "Hand_Grenade";
    case M1919A4:
        return "M1919A4";
    }
}
std::string strStrategy(Strategy s)
{
    switch (s)
    {

    case Deceptive_Disinformation:
        return "Deceptive_Disinformation";
    case Deceptive_MilitaryCamouflage:
        return "Deceptive_MilitaryCamouflage";
    case Deceptive_Demoralization:
        return "Deceptive_Demoralization";
    case Deceptive_FalseFlag:
        return "Deceptive_FalseFlag";
    case Defensive_DelayingDefence:
        return "Defensive_DelayingDefence";
    case Defensive_CounterAttack:
        return "Defensive_CounterAttack";
    case Defensive_Fortification:
        return "Defensive_Fortification";
    case Defensive_ShellScrapes:
        return "Defensive_ShellScrapes";
    case Offensive_Charge:
        return "Offensive_Charge";
    case Offensive_Ambush:
        return "Offensive_Ambush";
    case Offensive_Skirmish:
        return "Offensive_Skirmish";
    case Offensive_TrenchRaiding:
        return "Offensive_TrenchRaiding";
    }
}

class Soldier
{
    Weapon m_weapon;
    Strategy m_strategy;
    std::string m_company;

public:
    Soldier(std::string company)
    {
        m_company = company;
    }
    std::string getCompany()
    {
        return m_company;
    }
    void setCompany(std::string c)
    {
        m_company = c;
    }
    Weapon getWeapon()
    {
        return m_weapon;
    }
    void setWeapon(Weapon w)
    {
        m_weapon = w;
    }
    Strategy getStrategy()
    {
        return m_strategy;
    }
    void setStrategy(Strategy s)
    {
        m_strategy = s;
    }

    void performMission()
    {
        std::cout << "I am a soldier of " << m_company << "my duty is " << strStrategy(m_strategy) << " and i have weapon " << strWeapon(m_weapon) << std::endl;
    }
};

class SoldierFactory
{
    static std::unordered_map<std::string, Soldier *> m_soldiers;

public:
    static Soldier *getSoldier(std::string company)
    {
        if (m_soldiers.find(company) == m_soldiers.end())
        {
            m_soldiers[company] = new Soldier(company);
        }

        return m_soldiers[company];
    }
};

std::unordered_map<std::string, Soldier *> SoldierFactory::m_soldiers{};

void MachineDefense(Soldier *s)
{
    s->setWeapon(Weapon::M1919A4);
    s->setStrategy(Strategy::Defensive_Fortification);
    s->performMission();
}

void Charge(Soldier *s)
{
    s->setWeapon(Weapon::M1_Garand);
    s->setStrategy(Strategy::Offensive_Charge);
    s->performMission();
}

void Paris(Soldier *s)
{
    s->setWeapon(Weapon::Luger_P08);
    s->setStrategy(Strategy::Deceptive_Disinformation);
    s->performMission();
}

void DDay(Soldier *s)
{
    s->setWeapon(Weapon::M1_Garand);
    s->setStrategy(Strategy::Offensive_Ambush);
    s->performMission();
}

int main()
{

    f(180)
    {
        auto soldier = SoldierFactory::getSoldier("Easy Company");
        DDay(soldier);
    }
    f(120)
    {
        auto soldier = SoldierFactory::getSoldier("Rangers Company");
        MachineDefense(soldier);
    }

    f(152)
    {
        auto soldier = SoldierFactory::getSoldier("Flash Company");
        Charge(soldier);
    }

    f(200)
    {
        auto soldier = SoldierFactory::getSoldier("Wariors Company");
        Paris(soldier);
    }
}