#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

class Employee;

class Mediator
{
public:
    virtual void addEmployee(Employee *employee) = 0;
    virtual void send(Employee *employee, std::string message) = 0;
};

class Employee
{
public:
    virtual void Send(std::string message) = 0;
    virtual void Receive(std::string message) = 0;
};

class Butcher : public Employee
{
    std::string m_name;
    Mediator *m_mediator;

public:
    Butcher(Mediator *mediator, std::string name)
    {
        m_mediator = mediator;
        m_name = name;
    };

    virtual void Send(std::string message) override
    {
        m_mediator->send(this, message);
    };

    virtual void Receive(std::string message) override
    {
        std::cout << "Butcher: : " << m_name << " :: Receive : " << message << std::endl;
    };
};

class Greengrocer : public Employee
{
    std::string m_name;
    Mediator *m_mediator;

public:
    Greengrocer(Mediator *mediator, std::string name)
    {
        m_mediator = mediator;
        m_name = name;
    };

    virtual void Send(std::string message) override
    {
        m_mediator->send(this, message);
    }

    virtual void Receive(std::string message) override
    {
        std::cout << "Greengrocer: : " << m_name << " :: Receive : " << message << std::endl;
    };
};

class Patisserie : public Employee
{
    std::string m_name;
    Mediator *m_mediator;

public:
    Patisserie(Mediator *mediator, std::string name)
    {
        m_mediator = mediator;
        m_name = name;
    };

    virtual void Send(std::string message) override
    {
        m_mediator->send(this, message);
    }

    virtual void Receive(std::string message) override
    {
        std::cout << "Patisserie: : " << m_name << " :: Receive : " << message << std::endl;
    };
};

class Bakery : public Employee
{
    std::string m_name;
    Mediator *m_mediator;

public:
    Bakery(Mediator *mediator, std::string name)
    {
        m_mediator = mediator;
        m_name = name;
    };

    virtual void Send(std::string message) override
    {
        m_mediator->send(this, message);
    }

    virtual void Receive(std::string message) override
    {
        std::cout << "Bakery: : " << m_name << " :: Receive : " << message << std::endl;
    };
};

class Cashier : public Employee
{
    std::string m_name;
    Mediator *m_mediator;

public:
    Cashier(Mediator *mediator, std::string name)
    {
        m_mediator = mediator;
        m_name = name;
    };

    virtual void Send(std::string message) override
    {
        m_mediator->send(this, message);
    }

    virtual void Receive(std::string message) override
    {
        std::cout << "Cashier: : " << m_name << " :: Receive : " << message << std::endl;
    };
};

class Manager : public Mediator
{
    std::vector<Employee *> m_employees;

public:
    virtual void addEmployee(Employee *employee) override
    {
        m_employees.push_back(employee);
    }

    virtual void send(Employee *employee, std::string message) override
    {
        std::for_each(m_employees.begin(), m_employees.end(), [&](Employee *emp) {
            if (emp != employee)
            {
                emp->Receive(message);
            }
        });
    };
};

int main()
{

    Mediator *manager = new Manager();

    auto bakery = new Bakery(manager, "John");
    auto butcher = new Butcher(manager, "Mark");
    auto green_grocer = new Greengrocer(manager, "Jane");
    auto patisserie = new Patisserie(manager, "Anna");
    auto cashier = new Cashier(manager, "Hanna");
    manager->addEmployee(bakery);
    manager->addEmployee(butcher);
    manager->addEmployee(green_grocer);
    manager->addEmployee(patisserie);
    manager->addEmployee(cashier);

    manager->send(nullptr, "Folks Let's make some money!");

    bakery->Send("09:00 Report : 14 Kruvassian, 23 Bread, 12 Simit sold");
    cashier->Send("09:00 Report : total earning money is $3205");

    patisserie->Send("09:05 : Bakery, i have many customer for waiting kruvassian");
    bakery->Send("09:08 : Patisserie, 60 Kruvassian is Ready!");

    manager->send(nullptr, "OK Folks! We have done working for today. See you tomorrow. Let's go your homes and rest.");

    return 0;
}

/*

Mediator Pattern
The Mediator pattern is known as abehavioural pattern, as it's used to manage algorithms, relationships and responsibilities between objects

When Would I Use This Pattern?
The mediator is a good choice of pattern when the communication between objects is complicated, but well defined
When there are too many relationships between the objects in your code, it's time to think of having such a central point of control.

*/