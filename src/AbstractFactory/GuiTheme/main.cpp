
#include <iostream>
#include <string>

/*Butons*/

class Button
{
public:
    virtual void paint() = 0;
};

class WinButton : public Button
{
public:
    WinButton()
    {
        std::cout << __FUNCTION__ << std::endl;
    }

    virtual void paint() override
    {
        std::cout << "Windows Button is painted Blue Color" << std::endl;
    }
};

class OsxButton : public Button
{
public:
    OsxButton()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    virtual void paint() override
    {
        std::cout << "Osx Button is painted Grey Color" << std::endl;
    }
};

class LinuxButton : public Button
{
public:
    LinuxButton()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    virtual void paint() override
    {
        std::cout << "Linux Button is painted Red Color" << std::endl;
    }
};

/* Labels */

class Label
{
public:
    virtual void paint() = 0;
};

class WinLabel : public Label
{
public:
    WinLabel() { std::cout << __FUNCTION__ << std::endl; }
    virtual void paint() override
    {
        std::cout << "Windows Label is painted Black Color" << std::endl;
    }
};

class OsxLabel : public Label
{
public:
    OsxLabel()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    virtual void paint() override
    {
        std::cout << "Osx Label is painted Sand Color" << std::endl;
    }
};

class LinuxLabel : public Label
{
public:
    LinuxLabel()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    virtual void paint() override
    {
        std::cout << "Linux Label is painted Ocean Sand Color" << std::endl;
    }
};

/* Factories*/

class GuiFactory
{ //This is super factory
public:
    virtual Button *createButton() = 0;
    virtual Label *createLabel() = 0;
};

class WinFactory : public GuiFactory
{
public:
    virtual Button *createButton() override
    {
        return new WinButton();
    };
    virtual Label *createLabel() override
    {
        return new WinLabel();
    };
};

class OsxFactory : public GuiFactory
{
public:
    virtual Button *createButton() override
    {
        return new OsxButton();
    };
    virtual Label *createLabel() override
    {
        return new OsxLabel();
    };
};

class LinuxFactory : public GuiFactory
{
public:
    virtual Button *createButton() override
    {
        return new LinuxButton();
    };
    virtual Label *createLabel() override
    {
        return new LinuxLabel();
    };
};

class GuiManager
{
public:
    enum OsEnum
    {
        WINDOWS,
        OSX,
        LINUX
    };

    static GuiFactory *createOsSpecificFactory(OsEnum os)
    {
        if (os == WINDOWS)
            return new WinFactory();
        else if (os == OSX)
            return new OsxFactory();
        else if (os == LINUX)
            return new LinuxFactory();
    }
};

int main()
{
    GuiFactory *factory = GuiManager::createOsSpecificFactory(GuiManager::OsEnum::LINUX);
    Button *btn = factory->createButton();
    Label *label = factory->createLabel();

    btn->paint();
    label->paint();

    return 0;
}