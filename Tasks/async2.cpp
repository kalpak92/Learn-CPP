#include <iostream>
#include <thread>
#include <future>
#include <algorithm>
#include <chrono>

typedef long int ull;

ull findOdd(ull start, ull end)
{
    std::cout << "Task Thread id " << std::this_thread::get_id() << std::endl;
    ull oddSum = 0;
    for(ull i = start; i <= end; i++)
    {
        if(i & 1)
        {
            oddSum += i;
        }
    }
    return oddSum;
}

int main()
{
    ull start = 0;
    ull end = 19000000000;
    std::cout << "Main Thread id " << std::this_thread::get_id() << std::endl;
    std::future<ull> result = std::async(std::launch::async, findOdd, start, end);

    std::cout << "Waiting for Result !!" << std::endl;
    std::cout << "Result : " << result.get() << std::endl;
    std::cout << "Completed !!" << std::endl;
}