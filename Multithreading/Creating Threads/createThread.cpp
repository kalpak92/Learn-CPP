#include <thread>
#include <iostream>

void helloFunction()
{
    std::cout << "Hello from a function." << std::endl;
}

class HelloFunctionObject
{
    public:
        void operator()() const
        {
            std::cout << "Hello from a function object." << std::endl;
        }
};

int main()
{
    std::cout << std::endl;

    std::thread t1(helloFunction);

    HelloFunctionObject obj;
    std::thread t2(obj);

    std::thread t3([]{std::cout << "Hello from a lambda." << std::endl;});

    t1.join();
    t2.join();
    t2.join();

    std::cout << std::endl;
};