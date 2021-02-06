#include <iostream>
#include <string>

class Log
{
private:
    Log(){};

public:
    Log(Log const &) = delete;
    void operator=(Log const &) = delete;
    static Log &getInstance()
    {
        static Log instance;

        return instance;
    }

    void printLog(std::string message)
    {
        std::cout << message << std::endl;
    }
};

int main()
{
    Log::getInstance().printLog("My Sigleton Log");
}