#include <iostream>
#include <typeinfo>

template<typename T1, typename T2>
auto add(T1 first, T2 second) -> decltype(first + second)
{
    return first + second;
}

int main()
{

    std::cout << std::endl;

    std::cout << "add(1, 1)= " << add(1, 1) << std::endl;
    std::cout << "typeid(add(1, 1)).name()= " << typeid(add(1, 1)).name() << std::endl;

    std::cout << std::endl;

    std::cout << "add(1, 2.1)= " << add(1, 2.1) << std::endl;
    std::cout << "typeid(add(1, 2.1)).name()= " << typeid(add(1, 2.1)).name() << std::endl;

    std::cout << std::endl;

    std::cout << "add(1000LL, 5)= " << add(1000LL, 5) << std::endl;
    std::cout << "typeid(add(1000LL, 5)).name()= " << typeid(add(1000LL, 5)).name() << std::endl;

    std::cout << std::endl;

}