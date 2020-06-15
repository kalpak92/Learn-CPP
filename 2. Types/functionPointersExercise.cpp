#include <iostream>

void addOne(int& x)
{
    x += 1;
}

int main()
{

    void (*inc1)(int&)= addOne;
    auto inc2 = addOne;

    int a{10};

    addOne(a);
    std::cout << "after addOne(a): " << a << std::endl;
    inc1(a);

    std::cout << "after inc1(a): "  << a << std::endl;
    inc2(a);
    std::cout << "after inc2(a): "  << a << std::endl;

    std::cout << std::endl;
}