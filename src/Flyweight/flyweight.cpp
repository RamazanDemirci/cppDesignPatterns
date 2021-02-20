#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <map>

#define f(n) for (int i = 0; i < n; i++)

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

double gen(double size)
{
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_real_distribution<> dis(1.0f, size);
    return dis(gen);
}

class SoldierModel
{
    Weapon m_weapon;
    Strategy m_strategy;
    std::string m_company;
    double m_width;
    double m_height;

public:
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
    void getDutyArea(double &w, double &h)
    {
        w = m_width;
        h = m_height;
    }
    void setDutyArea(double w, double h)
    {
        m_width = w;
        m_height = h;
    }

public:
};

class Soldier
{
    double m_posx;
    double m_posy;

    SoldierModel *m_soldierModel;

public:
    Soldier(SoldierModel *model)
    {
        m_soldierModel = model;
    }
    void getPosition(double &x, double &y)
    {
        x = m_posx;
        y = m_posy;
    }

    void setPosition(double x, double y)
    {
        m_posx = x;
        m_posy = x;
    }

    void setSoldierModel(SoldierModel *model)
    {
        m_soldierModel = model;
    }

    SoldierModel *getSoldierModel()
    {
        return m_soldierModel;
    }

    void performMission()
    {
        std::cout << "Mission completed " << m_soldierModel->getCompany() << std::endl;
    }

    void reportYourself()
    {
        std::cout << "I am a soldier of " << m_soldierModel->getCompany()
                  << " my duty is " << strStrategy(m_soldierModel->getStrategy())
                  << " and i have weapon " << strWeapon(m_soldierModel->getWeapon())
                  << " my position is : [" << m_posx << "," << m_posy << "] "
                  << "Sir!"
                  << std::endl;
    }
};

class SoldierFactory
{
    std::unordered_map<std::string, SoldierModel *> m_soldierModels;

public:
    ~SoldierFactory()
    {
        while (!m_soldierModels.empty())
        {
            auto it = m_soldierModels.begin();
            delete it->second;
            m_soldierModels.erase(it);
        }
    }

    Soldier *getSoldier(std::string company)
    {
        if (m_soldierModels.find(company) == m_soldierModels.end())
        {
            std::cout << "Upps! There is no such that company : " << company << std::endl;
            return nullptr;
        }

        return new Soldier(m_soldierModels[company]);
    }

    void createSoldier(SoldierModel *sm)
    {
        m_soldierModels[sm->getCompany()] = sm;
    }
};

void setStartPosition(Soldier *s)
{
    double w;
    double h;
    s->getSoldierModel()->getDutyArea(w, h);
    s->setPosition(gen(w), gen(h));
}

void updatePosition(Soldier *s)
{
    double x;
    double y;
    s->getPosition(x, y);
    s->setPosition(x + gen(2), y + gen(2));
}

void reportCompany(std::vector<Soldier *> company)
{
    std::for_each(company.begin(), company.end(), [](Soldier *s) {
        s->reportYourself();
    });
}

void Mission(std::string mission, std::vector<Soldier *> &company)
{

    std::cout << mission << " Mission Start " << std::endl;

    std::for_each(company.begin(), company.end(), [](Soldier *s) {
        setStartPosition(s);
        s->performMission();
        updatePosition(s);
    });

    reportCompany(company);
}

int main()
{
    std::cout << "hello";

    auto soldierFactory = new SoldierFactory();

    auto sm = new SoldierModel();
    sm->setCompany("Easy Company");
    sm->setDutyArea(40.0f, 20.0f);
    sm->setWeapon(Weapon::M1_Garand);
    sm->setStrategy(Strategy::Offensive_Charge);
    soldierFactory->createSoldier(sm);

    sm->setCompany("Rangers Company");
    sm->setDutyArea(80.0f, 10.0f);
    sm->setWeapon(Weapon::M1919A4);
    sm->setStrategy(Strategy::Defensive_Fortification);
    soldierFactory->createSoldier(sm);

    sm->setCompany("Flash Company");
    sm->setDutyArea(200.0f, 50.0f);
    sm->setWeapon(Weapon::Smoke_Grenade);
    sm->setStrategy(Strategy::Deceptive_FalseFlag);
    soldierFactory->createSoldier(sm);

    sm->setCompany("Wariors Company");
    sm->setDutyArea(40.0f, 150.0f);
    sm->setWeapon(Weapon::Luger_P08);
    sm->setStrategy(Strategy::Offensive_Ambush);
    soldierFactory->createSoldier(sm);

    std::vector<Soldier *> easyCompany;
    std::vector<Soldier *> rangerCompany;
    std::vector<Soldier *> flashCompany;
    std::vector<Soldier *> wariorsCompany;

    f(18)
    {
        auto soldier = soldierFactory->getSoldier("Easy Company");
        easyCompany.push_back(soldier);
    }

    f(12)
    {
        auto soldier = soldierFactory->getSoldier("Rangers Company");
        rangerCompany.push_back(soldier);
    }

    f(15)
    {
        auto soldier = soldierFactory->getSoldier("Flash Company");
        flashCompany.push_back(soldier);
    }

    f(20)
    {
        auto soldier = soldierFactory->getSoldier("Wariors Company");
        wariorsCompany.push_back(soldier);
    }

    Mission("DDay", easyCompany);
    Mission("Paris", flashCompany);
    Mission("MachineDefense", rangerCompany);
    Mission("Charge", wariorsCompany);
}

/*


refs :
https://gameprogrammingpatterns.com/flyweight.html
*/