#include <iostream>
#include <typeinfo>

int main()
{

    std::cout << std::endl;

    // types
    if (typeid(int) == typeid(long long))
    {
        std::cout << "The types int and long long are the same" << std::endl;
    }
    else
    {
        std::cout << "The types int and long long are different" << std::endl;
    }
    
    std::cout << "typeid(int).name(): "  << typeid(int).name() << std::endl;
    std::cout << "typeid(long long).name(): "  << typeid(long long).name() << std::endl;

    std::cout << std::endl;

    // variables
    int i{2011};
    int long long il{2011};

    std::cout << "typeid(i).name(): "  << typeid(i).name() << std::endl;
    std::cout << "typeid(il).name(): "  << typeid(il).name() << std::endl;

    if (typeid(i) == typeid(il))
    {
        std::cout << "The variables i and il are of the same type" << std::endl;
    }
    else
    {
        std::cout << "The variables i and il are of different types" << std::endl;
    }

    std::cout << std::endl;

}