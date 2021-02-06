#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Stooge
{
public:
    virtual Stooge *clone() = 0;
    virtual void slap_stick() = 0;
};

class Factory
{
public:
    static Stooge *make_stooge(int choice);

private:
    static Stooge *s_prototypes[4];
};

class Larry : public Stooge
{
public:
    Stooge *clone()
    {
        std::cout << "Larry::clone" << std::endl;
        //return new Larry;
        return new Larry(*this);
    }
    void slap_stick()
    {
        cout << "Larry: poke eyes\n";
    }
};
class Moe : public Stooge
{
public:
    Stooge *clone()
    {
        std::cout << "Moe::clone" << std::endl;
        //return new Moe;
        return new Moe(*this);
    }
    void slap_stick()
    {
        cout << "Moe: slap head\n";
    }
};
class Curly : public Stooge
{
public:
    Curly()
    {
        std::cout << "Curly::CTOR";
    }
    Curly(const Curly &c)
    {
        std::cout << "Curly::Copy CTOR";
    }

    Stooge *clone()
    {
        std::cout << "Curly::clone" << std::endl;
        //return new Curly; /*#1*/
        return new Curly(*this); /*#2*/
    }
    void slap_stick()
    {
        cout << "Curly: suffer abuse\n";
    }
};

Stooge *Factory::s_prototypes[] = {0, new Larry, new Moe, new Curly};
Stooge *Factory::make_stooge(int choice)
{
    return s_prototypes[choice]->clone();
}

int main()
{
    std::vector<Stooge *> roles;
    int choice;

    while (true)
    {
        cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
        cin >> choice;
        if (choice < 1 || choice > 3)
            break;
        roles.push_back(Factory::make_stooge(choice));
        std::cout << "size : " << roles.size() << std::endl;
    }

    for (int i = 0; i < roles.size(); ++i)
        roles[i]->slap_stick();
    for (int i = 0; i < roles.size(); ++i)
        delete roles[i];
}

/*
#1 : this just call default CTOR not Copy CTOR, thus this not apply shallow or deep copy. just create new object.
#2 : this not call default CTOR but Copy CTOR, thus this apply shallow or deep copy in Copy CTOR.
*/