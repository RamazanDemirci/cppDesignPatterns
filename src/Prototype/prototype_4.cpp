#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

class Fighter
{
private:
    std::string m_name;
    int m_age;
    std::array<int, 50> m_avatar;
    std::vector<std::array<int, 20>> m_sounds;

public:
    Fighter()
    {
        std::cout << "Fighter::CTOR" << std::endl;
    }

    ~Fighter()
    {
        std::cout << "Fighter" << m_name << "::DTOR" << std::endl;
    }

    Fighter(const Fighter &f)
    {
        std::cout << "Fighter::Copy CTOR" << std::endl;
        m_name = f.m_name + "(cloned)";
        m_age = f.m_age;
        m_avatar = f.m_avatar;
        std::copy(f.m_sounds.begin(), f.m_sounds.end(), std::back_inserter(m_sounds));
    }

    std::string getName()
    {
        std::cout << m_name << std::endl;
        return m_name;
    }

    void setName(std::string name)
    {
        m_name = name;
    }

    int getAge()
    {
        std::cout << m_age << std::endl;
        return m_age;
    }

    void setAge(int age)
    {
        m_age = age;
    }

    void displayAvatar()
    {
        std::cout << "Avatar Display : ";
        std::copy(m_avatar.begin(), m_avatar.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    void setAvatar(std::array<int, 50> avatar)
    {
        std::copy(avatar.begin(), avatar.end(), std::begin(m_avatar));
    }

    void playSound()
    {
        std::cout << "Sound Playing : ";
        std::copy(m_sounds[0].begin(), m_sounds[0].end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    void addSound(std::array<int, 20> sound)
    {
        m_sounds.push_back(sound);
    }

    Fighter *clone()
    {
        std::cout << "Fighter" << m_name << "::clone" << std::endl;
        //return new Paul;         //#1
        return new Fighter(*this); //#2
    }
    void slap_stick()
    {
        cout << "Paul: poke eyes" << std::endl;
    }
};

class Factory
{
public:
    static Fighter *CreateFighter(std::string fighter);

    static void AddPrototype(std::string name, Fighter *fighter);

private:
    static std::map<std::string, Fighter *> prototypes;
};

std::map<std::string, Fighter *> Factory::prototypes{};

Fighter *Factory::CreateFighter(std::string name)
{
    if (prototypes[name] == nullptr)
    {
        Fighter *fighter;
        fighter = new Fighter();
        return fighter;
    }
    else
        return prototypes[name]->clone();
}

void Factory::AddPrototype(std::string name, Fighter *fighter)
{
    prototypes[name] = fighter;
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
    Factory::AddPrototype(fighter->getName(), fighter);

    roles.push_back(fighter);

    fighter = Factory::CreateFighter("ChunLi");
    fighter->setName("ChunLi");
    fighter->setAge(20);
    fighter->setAvatar(ChunliAvatar);
    fighter->addSound(ChunliSound1);
    fighter->addSound(ChunliSound2);
    Factory::AddPrototype(fighter->getName(), fighter);

    roles.push_back(fighter);

    fighter = Factory::CreateFighter("Ryu");
    fighter->setName("Ryu");
    fighter->setAge(23);
    fighter->setAvatar(RyuAvatar);
    fighter->addSound(RyuSound1);
    fighter->addSound(RyuSound2);
    Factory::AddPrototype(fighter->getName(), fighter);

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

i reorganize example code because there are unnecessary code repetition and we dont have speacilize data or algorithm for hero, at least for now. 

Benefits of prototype Design Pattern

Provides a lower latency in creation of objects
Provides easier way of cloning objects
Reduces the load on the database for fetching the data
Improves overall application performance
Reduces the effort of cloning an object for the application developer
Make the cloning code independent of the implementing classes
Allows you to easily modify the existing class and its prototyping function which would not have been the case if cloning takes place elsewhere
*/
