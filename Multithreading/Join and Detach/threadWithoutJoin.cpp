#include <iostream>
#include <thread>


int main()
{
    std::thread t([]{ std::cout << std::this_thread::get_id() << std::endl; });

    // But the program will not print the ID. So, add t.join().
}