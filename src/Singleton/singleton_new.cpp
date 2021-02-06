#include <iostream>
#include <string>

class Log
{
private:
    Log(){};
    ~Log(){};
    static Log *instance;

public:
    Log(Log const &) = delete;
    void operator=(Log const &) = delete;
    static Log *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Log();
        }
        return instance;
    }

    void printLog(std::string message)
    {
        std::cout << message << std::endl;
    }
};

Log *Log::instance = nullptr;

int main()
{
    Log::getInstance()->printLog("My Sigleton Log");
}