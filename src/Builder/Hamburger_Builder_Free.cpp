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

//Builder
class Burger
{
    Hamburger *m_hamburger;

public:
    Burger(std::string name)
    {
        m_hamburger = new Hamburger();
        m_hamburger->SetName(name);
    };

    ~Burger()
    {
        delete m_hamburger;
    };

    Burger *AddSouce(Souce souce)
    {
        m_hamburger->AddSouce(souce);
        return this;
    };

    Burger *AddMeat(Meat meat)
    {
        m_hamburger->AddMeat(meat);
        return this;
    };

    Burger *AddTopping(Topping topping)
    {
        m_hamburger->AddTopping(topping);
        return this;
    };

    Hamburger *getProduct()
    {
        return m_hamburger;
    };
};

int main()
{
    std::cout << "Select Burger for Order" << std::endl;
    std::cout << "[1] : MexicanBurger" << std::endl;
    std::cout << "[2] : CheeseBurger" << std::endl;
    std::cout << "[3] : ChickenBurger" << std::endl;

    Burger *burger;
    int selection;
    std::cin >> selection;
    switch (selection)
    {
    case 1:
        burger = new Burger("MexicanBurger");
        burger->AddMeat(Meat::Beef)->AddSouce(Souce::Mexican)->AddTopping(Topping::cheese)->AddTopping(Topping::lettuce)->AddTopping(Topping::Mushroom);
        break;
    case 2:
        burger = new Burger("CheeseBurger");
        burger->AddMeat(Meat::Beef)->AddSouce(Souce::Ketchup)->AddSouce(Souce::Mayonnaise)->AddTopping(Topping::cheese)->AddTopping(Topping::lettuce);
        break;
    case 3:
        burger = new Burger("ChickenBurger");
        burger->AddMeat(Meat::Chicken)->AddSouce(Souce::Secret)->AddTopping(Topping::cheese)->AddTopping(Topping::lettuce)->AddTopping(Topping::pickles);
        break;
    default:
        std::cout << "Please make a valid selection";
        break;
    }

    if (burger != nullptr)
    {
        Hamburger *hamburger = burger->getProduct();
        if (burger != nullptr)
        {
            hamburger->Display();
            delete hamburger;
        }
        delete burger;
    }

    return 0;
}