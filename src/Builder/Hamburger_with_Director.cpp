#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

enum Meat
{
    Beef,
    Chicken,
    Kitten,
    Tofu
};

enum Souce
{
    Mayonnaise,
    Mustard,
    Ketchup,
    Mexican,
    Secret,
};

enum Topping
{
    cheese,
    lettuce,
    pickles,
    tomatoes,
    Mushroom,

};

std::string getMeatString(Meat meat)
{
    switch (meat)
    {
    case Beef:
        return "Beef";
    case Chicken:
        return "Chicken";
    case Kitten:
        return "Kitten";
    case Tofu:
        return "Tofu";
    default:
        std::cout << "Upps!" << std::endl;
    }
}

std::string getSouceString(Souce souce)
{
    switch (souce)
    {
    case Mayonnaise:
        return "Mayonnaise";
    case Mustard:
        return "Mustard";
    case Ketchup:
        return "Ketchup";
    case Mexican:
        return "Mexican";
    case Secret:
        return "Secret";
    default:
        std::cout << "Upps!" << std::endl;
    }
}

std::string getToppingString(Topping topping)
{
    switch (topping)
    {
    case cheese:
        return "cheese";
    case lettuce:
        return "lettuce";
    case pickles:
        return "pickles";
    case tomatoes:
        return "tomatoes";
    case Mushroom:
        return "Mushroom";
    default:
        std::cout << "Upps!" << std::endl;
    }
}

std::string center(std::string str)
{
    auto len = str.length();
    if (len < 32)
    {
        int diff = 30 - len;
        int pad1 = diff / 2;
        int pad2 = diff - pad1;
        return std::string(pad1, ' ') + str + std::string(pad2, ' ');
    }
}

//Product
class Hamburger
{
    std::string m_name;

    Meat m_meat = Meat::Beef;
    std::vector<Souce> m_souce;
    std::vector<Topping> m_topping;

public:
    void SetName(std::string name)
    {
        m_name = name;
    };

    void AddSouce(Souce souce)
    {
        m_souce.push_back(souce);
    };

    void AddMeat(Meat meat)
    {
        m_meat = meat;
    };

    void AddTopping(Topping topping)
    {
        m_topping.push_back(topping);
    };

    void Display()
    {
        std::cout << center("###########") << std::endl;
        std::cout << center("#################") << std::endl;
        std::cout << center("###### " + m_name + " ######") << std::endl;
        std::cout << center("Top Bread") << std::endl;
        std::for_each(m_topping.begin(), m_topping.end(), [](const Topping item) { std::cout << center(getToppingString(item)) << std::endl; });
        std::cout << center(getMeatString(m_meat)) << std::endl;
        std::for_each(m_souce.begin(), m_souce.end(), [](const Souce item) { std::cout << center(getSouceString(item)) << std::endl; });
        std::cout << center("Bottom Bread") << std::endl;
        std::cout << center("###### " + m_name + " ######") << std::endl;
        std::cout << center("#################") << std::endl;
    }
};

class Builder
{
public:
    virtual void AddSouce() = 0;
    virtual void AddMeat() = 0;
    virtual void AddTopping() = 0;
    virtual Hamburger *getProduct() = 0;
};

//Builder
class MexicanBurger : public Builder
{
    Hamburger *m_hamburger;

public:
    MexicanBurger()
    {
        m_hamburger = new Hamburger();
        m_hamburger->SetName("MexicanBurger");
    };

    ~MexicanBurger()
    {
        delete m_hamburger;
    };

    virtual void AddSouce() override
    {
        m_hamburger->AddSouce(Souce::Mexican);
    };

    virtual void AddMeat() override
    {
        m_hamburger->AddMeat(Meat::Beef);
    };

    virtual void AddTopping() override
    {
        m_hamburger->AddTopping(Topping::lettuce);
        m_hamburger->AddTopping(Topping::tomatoes);
        m_hamburger->AddTopping(Topping::Mushroom);
    };

    virtual Hamburger *getProduct() override
    {
        return m_hamburger;
    };
};

class CheeseBurger : public Builder
{
    Hamburger *m_hamburger;

public:
    CheeseBurger()
    {
        m_hamburger = new Hamburger();
        m_hamburger->SetName("CheeseBurger");
    };

    ~CheeseBurger()
    {
        delete m_hamburger;
    };

    virtual void AddSouce() override
    {
        m_hamburger->AddSouce(Souce::Ketchup);
        m_hamburger->AddSouce(Souce::Mayonnaise);
    };

    virtual void AddMeat() override
    {
        m_hamburger->AddMeat(Meat::Beef);
    };

    virtual void AddTopping() override
    {
        m_hamburger->AddTopping(Topping::lettuce);
        m_hamburger->AddTopping(Topping::cheese);
    };
    virtual Hamburger *getProduct() override
    {
        return m_hamburger;
    };
};

class ChickenBurger : public Builder
{
    Hamburger *m_hamburger;

public:
    ChickenBurger()
    {
        m_hamburger = new Hamburger();
        m_hamburger->SetName("ChickenBurger");
    };

    ~ChickenBurger()
    {
        delete m_hamburger;
    };

    virtual void AddSouce() override
    {
        m_hamburger->AddSouce(Souce::Mustard);
        m_hamburger->AddSouce(Souce::Secret);
    };

    virtual void AddMeat() override
    {
        m_hamburger->AddMeat(Meat::Chicken);
    };

    virtual void AddTopping() override
    {
        m_hamburger->AddTopping(Topping::lettuce);
        m_hamburger->AddTopping(Topping::cheese);
        m_hamburger->AddTopping(Topping::pickles);
    };

    virtual Hamburger *getProduct() override
    {
        return m_hamburger;
    };
};

class BurgerDirector
{
    Builder *m_builder;

public:
    void SetBuilder(Builder *builder)
    {
        m_builder = builder;
    }

    void PrepareBurger()
    {
        if (m_builder != nullptr)
        {
            m_builder->AddMeat();
            m_builder->AddSouce();
            m_builder->AddTopping();
        }
    }

    Hamburger *ServiceHamburger()
    {
        return m_builder->getProduct();
    }
};

int main()
{
    BurgerDirector *director = new BurgerDirector();
    std::cout << "Select Burger for Order" << std::endl;
    std::cout << "[1] : MexicanBurger" << std::endl;
    std::cout << "[2] : CheeseBurger" << std::endl;
    std::cout << "[3] : ChickenBurger" << std::endl;

    Builder *builder;

    int selection;
    std::cin >> selection;
    switch (selection)
    {
    case 1:
        director->SetBuilder(new MexicanBurger());
        break;
    case 2:
        director->SetBuilder(new CheeseBurger());
        break;
    case 3:
        director->SetBuilder(new ChickenBurger());
        break;
    default:
        std::cout << "Please make a valid selection";
        break;
    }

    director->PrepareBurger();
    Hamburger *hamburger = director->ServiceHamburger();
    hamburger->Display();

    return 0;
}