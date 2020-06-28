#include <iostream>

int main() 
{
    int i = 1998; // Rvalue
    decltype(i) i2 = 2011; // Same as int i2 = 2011

    decltype((i)) iRef = i2; // (i) is an lvalue, reference returned
    std::cout << "iRef: " << iRef << std::endl;
    std::cout << "i2: " << i2 << std::endl;

    std::cout << std::endl;

    iRef = 2012;
    std::cout << "iRef: " << iRef << std::endl;
    std::cout << "i2: " << i2 << std::endl; // iRef is a reference after all
}