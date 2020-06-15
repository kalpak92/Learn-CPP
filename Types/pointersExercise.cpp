#include <iostream>

int main()
{

    std::cout << std::endl;

    int i{2011};
    int* iptr= &i;

    std::cout << i << std::endl;

    std::cout << "iptr: " << iptr << std::endl;
    std::cout << "*iptr: " << *iptr << std::endl;

    std::cout << std::endl;

    int * jptr = iptr;
    *jptr = 2014;

    std::cout << "iptr: " << iptr << std::endl;
    std::cout << "*iptr: " << *iptr << std::endl;

    std::cout << "jptr: " << jptr << std::endl;
    std::cout << "*jptr: " << *jptr << std::endl;

}