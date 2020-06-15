#include <iostream>

int main() 
{
    int i = 20;
    int& iRef = i;
    
    std::cout << "i: " << i << std::endl;
    std::cout << "iRef: " << iRef << std::endl;

    std::cout << std::endl;

    iRef = 30; // Altering the reference

    std::cout << "i: " << i << std::endl;
    std::cout << "iRef: " << iRef << std::endl;
}