#include <iostream>
#include <string>

template <class T>
class Singleton
{
public:
    Singleton &operator=(const Singleton &) = delete;
    Singleton &operator=(Singleton &&) = delete;

    static T &getInstance()
    {
        if (!instance)
            instance = new T_Instance;
        return *instance;
    }

protected:
    Singleton() {}

private:
    struct T_Instance : public T
    {
        T_Instance() : T() {}
    };

    static inline T *instance = nullptr;
};

class Log : public Singleton<Log>
{
protected:
    Log(){};

public:
    void printLog(std::string message)
    {
        std::cout << message << std::endl;
    }
};

int main()
{
    Log::getInstance().printLog("My Sigleton Log");
}