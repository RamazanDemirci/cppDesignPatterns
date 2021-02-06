#include <memory>
#include <iostream>
#include <string>

class Log
{
public:
    Log(Log const &) = delete;
    Log &operator=(Log const &) = delete;

    static std::shared_ptr<Log> getInstance()
    {
        static std::shared_ptr<Log> s{new Log};
        return s;
    }

    void printLog(std::string message)
    {
        std::cout << message << std::endl;
    }

private:
    Log() {}
};

int main()
{
    Log::getInstance()->printLog("My Sigleton Log");
}