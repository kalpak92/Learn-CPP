#include <iostream>

struct X
{
    int data;
};

int main()
{

    int X:: * p = &X::data;

    X object;
    object.data = 2011;

    X* objptr = new X;
    objptr->data = 2014;


    int k = object.*p;
    int l = objptr->*p;

    std::cout << "k: " << k << std::endl;
    std::cout << "l: " << l << std::endl;

    std::cout << std::endl;
}