#include <string>
#include <iostream>

class Car
{
    bool lockedDoors;
    bool keyValidate;
    bool clutchPressed;
    char m_gear;

public:
    Car()
    {
        lockedDoors = true;
        keyValidate = false;
        clutchPressed = false;
        m_gear = 'N';
    }
    void remoteControl(std::string message)
    {
        if (message == "Unlock Doors")
            lockedDoors = true;
        else if (message == "Lock Doors")
            lockedDoors = true;
    }
    bool insertKey(std::string id)
    {
        if (id == "132456")
        {
            std::cout << "key validated" << std::endl;
            keyValidate = true;
        }
    }

    void tookKey()
    {
        keyValidate = false;
    }

    char getGear()
    {
        return m_gear;
    }
    void setGear(char gear)
    {
        m_gear = gear;
    }
    void startIgnation()
    {
        std::cout << "ignation started" << std::endl;
    }
    void stopIgnation()
    {
        std::cout << "ignation stopped" << std::endl;
    }
    void startElectricStarter()
    {
        std::cout << "StartElectricStarter" << std::endl;
    }
    void stopElectricStarter()
    {
        std::cout << "StopElectricStarter" << std::endl;
    }
    void switchedBatteryElectricStarter()
    {
        std::cout << "Battery Supply the Electric Starter" << std::endl;
    }
    void startFuelSupply()
    {
        std::cout << "started Fuel Supply" << std::endl;
    }
    void stopFuelSupply()
    {
        std::cout << "stopped Fuel Supply" << std::endl;
    }
    void incFuelSupply()
    {
        std::cout << "inc Fuel Supply" << std::endl;
    }
    void decFuelSupply()
    {
        std::cout << "dec Fuel Supply" << std::endl;
    }
};

class CarDrive
{
    Car *m_car;

public:
    CarDrive(Car *car)
    {
        m_car = car;
    }
    void openDoors()
    {
        std::cout << "Unlocked Doors" << std::endl;
        m_car->remoteControl("Unlock Doors");
    }
    void closeDoors()
    {
        std::cout << "Locked Doors" << std::endl;
        m_car->remoteControl("Lock Doors");
    }
    void startEngine()
    {
        m_car->insertKey("123456");
        if (m_car->getGear() != 'N')
            m_car->setGear('N');
        m_car->switchedBatteryElectricStarter();
        m_car->startElectricStarter();
        m_car->startFuelSupply();
        m_car->startIgnation();
        m_car->stopElectricStarter();
    }
    void stopEngine()
    {
        m_car->stopIgnation();
        m_car->stopFuelSupply();
        m_car->insertKey("123456");
        if (m_car->getGear() != 'N')
            m_car->setGear('N');
        m_car->tookKey();
    }
    void speedUp()
    {
        m_car->incFuelSupply();
    }
    void speedDown()
    {
        m_car->decFuelSupply();
    }
    void HoldBrakes()
    {
        std::cout << "hold brakes" << std::endl;
        m_car->decFuelSupply();
    }
};

int main()
{
    CarDrive carDrive(new Car());
    carDrive.openDoors();
    carDrive.startEngine();
    carDrive.speedUp();
    carDrive.speedDown();
    carDrive.HoldBrakes();
    carDrive.stopEngine();
    carDrive.closeDoors();
    return 0;
}

/*

used to provide a unified interface to a complex system.
an object that serves as a front-facing interface, masking a more complex underlying system

- Improve the readability & usability of a software library by masking interaction with more complex components by providing a single simplified API.
- Provide a context-specific interface to more generic functionality.


*/