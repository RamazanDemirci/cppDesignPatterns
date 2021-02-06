#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

class Fighter
{
public:
    virtual void getName() = 0;
    virtual void setName(std::string name) = 0;
    virtual void getAge() = 0;
    virtual void setAge(int age) = 0;
    virtual void displayAvatar() = 0;
    virtual void setAvatar(std::array<int, 50> avatar) = 0;
    virtual void playSound() = 0;
    virtual void addSound(std::array<int, 20> sound) = 0;
    virtual Fighter *clone() = 0;
    virtual void slap_stick() = 0;
};

class Paul : public Fighter
{
private:
    std::string m_name;
    int m_age;
    std::array<int, 50> m_avatar;
    std::vector<std::array<int, 20>> m_sounds;

public:
    Paul()
    {
        std::cout << "Paul::CTOR" << std::endl;
    }

    ~Paul()
    {
        std::cout << "Paul::DTOR" << std::endl;
    }

    Paul(const Paul &p)
    {
        std::cout << "Paul::Copy CTOR" << std::endl;
        m_name = p.m_name;
        m_age = p.m_age;
        m_avatar = m_avatar;
        std::copy(p.m_sounds.begin(), p.m_sounds.end(), std::back_inserter(m_sounds));
    }

    virtual void getName() override
    {
        std::cout << m_name << std::endl;
    }

    virtual void setName(std::string name) override
    {
        m_name = name;
    }

    virtual void getAge() override
    {
        std::cout << m_age << std::endl;
    }

    virtual void setAge(int age) override
    {
        m_age = age;
    }

    virtual void displayAvatar() override
    {
        std::cout << "Avatar Display : ";
        std::copy(m_avatar.begin(), m_avatar.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    virtual void setAvatar(std::array<int, 50> avatar) override
    {
        std::copy(avatar.begin(), avatar.end(), std::begin(m_avatar));
    }

    virtual void playSound() override
    {
        std::cout << "Sound Playing : ";
        std::copy(m_sounds[0].begin(), m_sounds[0].end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    virtual void addSound(std::array<int, 20> sound) override
    {
        m_sounds.push_back(sound);
    }

    virtual Fighter *clone() override
    {
        std::cout << "Paul::clone" << std::endl;
        //return new Paul;        /*#1*/
        return new Paul(*this); /*#2*/
    }
    void slap_stick()
    {
        cout << "Paul: poke eyes" << std::endl;
    }
};

class Ryu : public Fighter
{
private:
    std::string m_name;
    int m_age;
    std::array<int, 50> m_avatar;
    std::vector<std::array<int, 20>> m_sounds;

public:
    Ryu()
    {
        std::cout << "Ryu::CTOR" << std::endl;
    }

    ~Ryu()
    {
        std::cout << "Ryu::DTOR" << std::endl;
    }

    Ryu(const Ryu &r)
    {
        std::cout << "Ryu::Copy CTOR" << std::endl;
        m_name = r.m_name;
        m_age = r.m_age;
        m_avatar = m_avatar;
        std::copy(r.m_sounds.begin(), r.m_sounds.end(), std::back_inserter(m_sounds));
    }

    virtual void getName() override
    {
        std::cout << m_name << std::endl;
    }

    virtual void setName(std::string name) override
    {
        m_name = name;
    }

    virtual void getAge() override
    {
        std::cout << m_age << std::endl;
    }

    virtual void setAge(int age) override
    {
        m_age = age;
    }

    virtual void displayAvatar() override
    {
        std::cout << "Avatar Display : ";
        std::copy(m_avatar.begin(), m_avatar.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    virtual void setAvatar(std::array<int, 50> avatar) override
    {
        std::copy(avatar.begin(), avatar.end(), std::begin(m_avatar));
    }

    virtual void playSound() override
    {
        std::cout << "Sound Playing : ";
        std::copy(m_sounds[0].begin(), m_sounds[0].end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    virtual void addSound(std::array<int, 20> sound) override
    {
        m_sounds.push_back(sound);
    }
    virtual Fighter *clone() override
    {
        std::cout << "Ryu::clone" << std::endl;
        //return new Ryu;
        return new Ryu(*this);
    }
    void slap_stick()
    {
        cout << "Ryu: slap head" << std::endl;
    }
};

class ChunLi : public Fighter
{
private:
    std::string m_name;
    int m_age;
    std::array<int, 50> m_avatar;
    std::vector<std::array<int, 20>> m_sounds;

public:
    ChunLi()
    {
        std::cout << "ChunLi::CTOR" << std::endl;
    }
    ~ChunLi()
    {
        std::cout << "ChunLi::DTOR" << std::endl;
    }
    ChunLi(const ChunLi &c)
    {
        std::cout << "ChunLi::Copy CTOR" << std::endl;
        m_name = c.m_name;
        m_age = c.m_age;
        m_avatar = m_avatar;
        std::copy(c.m_sounds.begin(), c.m_sounds.end(), std::back_inserter(m_sounds));
    }

    virtual void getName() override
    {
        std::cout << m_name << std::endl;
    }

    virtual void setName(std::string name) override
    {
        m_name = name;
    }

    virtual void getAge() override
    {
        std::cout << m_age << std::endl;
    }

    virtual void setAge(int age) override
    {
        m_age = age;
    }

    virtual void displayAvatar() override
    {
        std::cout << "Avatar Display : ";
        std::copy(m_avatar.begin(), m_avatar.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    virtual void setAvatar(std::array<int, 50> avatar) override
    {
        std::copy(avatar.begin(), avatar.end(), std::begin(m_avatar));
    }

    virtual void playSound() override
    {
        std::cout << "Sound Playing : ";
        std::copy(m_sounds[0].begin(), m_sounds[0].end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    virtual void addSound(std::array<int, 20> sound) override
    {
        m_sounds.push_back(sound);
    }

    Fighter *clone()
    {
        std::cout << "ChunLi::clone" << std::endl;
        //return new ChunLi;
        return new ChunLi(*this);
    }
    void slap_stick()
    {
        cout << "ChunLi: suffer abuse" << std::endl;
    }
};

class Factory
{
public:
    static Fighter *CreateFighter(std::string fighter);

private:
    static std::map<std::string, Fighter *> prototypes;
};

std::map<std::string, Fighter *> Factory::prototypes{};

Fighter *Factory::CreateFighter(std::string name)
{
    if (prototypes[name] == nullptr)
    {
        Fighter *fighter;
        if (name == "Paul")
            fighter = new Paul();
        else if (name == "Ryu")
            fighter = new Ryu();
        else if (name == "ChunLi")
            fighter = new ChunLi();
        else
            return nullptr;

        return prototypes[name] = fighter;
    }
    else
        return prototypes[name]->clone();
}

int main()
{
    std::vector<Fighter *> roles;
    std::string choice;

    std::array<int, 20> ChunliSound1 = {0x43, 0x68, 0x75, 0x6e, 0x4c, 0x69, 0x20, 0x53, 0x6f, 0x75, 0x6e, 0x64, 0x31};
    std::array<int, 20> RyuSound1 = {0x52, 0x79, 0x75, 0x20, 0x53, 0x6f, 0x75, 0x6e, 0x64, 0x31};
    std::array<int, 20> PaulSound1 = {0x50, 0x61, 0x75, 0x6c, 0x20, 0x53, 0x6f, 0x75, 0x6e, 0x64, 0x3120};

    std::array<int, 20> ChunliSound2 = {0x43, 0x68, 0x75, 0x6e, 0x4c, 0x69, 0x20, 0x53, 0x6f, 0x75, 0x6e, 0x64, 0x32};
    std::array<int, 20> RyuSound2 = {0x52, 0x79, 0x75, 0x20, 0x53, 0x6f, 0x75, 0x6e, 0x64, 0x32};
    std::array<int, 20> PaulSound2 = {0x50, 0x61, 0x75, 0x6c, 0x20, 0x53, 0x6f, 0x75, 0x6e, 0x64, 0x32};

    std::array<int, 50> ChunliAvatar = {0x43, 0x68, 0x75, 0x6e, 0x4c, 0x69, 0x20, 0x41, 0x76, 0x61, 0x74, 0x61, 0x72};
    std::array<int, 50> RyuAvatar = {0x52, 0x79, 0x75, 0x20, 0x41, 0x76, 0x61, 0x74, 0x61, 0x72};
    std::array<int, 50> PaulAvatar = {0x50, 0x61, 0x75, 0x6c, 0x20, 0x41, 0x76, 0x61, 0x74, 0x61, 0x72};

    Fighter *fighter = Factory::CreateFighter("Paul");
    fighter->setName("Paul");
    fighter->setAge(26);
    fighter->setAvatar(PaulAvatar);
    fighter->addSound(PaulSound1);
    fighter->addSound(PaulSound2);

    roles.push_back(fighter);

    fighter = Factory::CreateFighter("ChunLi");
    fighter->setName("ChunLi");
    fighter->setAge(20);
    fighter->setAvatar(ChunliAvatar);
    fighter->addSound(ChunliSound1);
    fighter->addSound(ChunliSound2);

    roles.push_back(fighter);

    fighter = Factory::CreateFighter("Ryu");
    fighter->setName("Ryu");
    fighter->setAge(23);
    fighter->setAvatar(RyuAvatar);
    fighter->addSound(RyuSound1);
    fighter->addSound(RyuSound2);

    roles.push_back(fighter);

    fighter = Factory::CreateFighter("Paul");
    roles.push_back(fighter);

    fighter = Factory::CreateFighter("Ryu");
    roles.push_back(fighter);

    fighter = Factory::CreateFighter("ChunLi");
    roles.push_back(fighter);

    for (int i = 0; i < roles.size(); ++i)
    {
        std::cout << "\n### Fighter on Stage ###" << std::endl;
        roles[i]->getName();
        roles[i]->getAge();
        roles[i]->displayAvatar();
        roles[i]->playSound();

        roles[i]->slap_stick();
    }

    for (int i = 0; i < roles.size(); ++i)
        delete roles[i];
}

/*
#1 : this just call default CTOR not Copy CTOR, thus this not apply shallow or deep copy. just create new object.
#2 : this not call default CTOR but Copy CTOR, thus this apply shallow or deep copy in Copy CTOR.

$ : if we dont deep copy in copy ctor getName, getAge, displayAvatar and playSound function will be crash beacuse cloned object don't have any detail data.
    because of this we have done deep coy in Copy Ctor.

Benefits of prototype Design Pattern

Provides a lower latency in creation of objects
Provides easier way of cloning objects
Reduces the load on the database for fetching the data
Improves overall application performance
Reduces the effort of cloning an object for the application developer
Make the cloning code independent of the implementing classes
Allows you to easily modify the existing class and its prototyping function which would not have been the case if cloning takes place elsewhere
*/
