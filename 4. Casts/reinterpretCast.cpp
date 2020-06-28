#include <iostream>

int main()
{

    double * myDouble = new double(3.14);
    std::cout << *myDouble << std::endl;

    void * myVoid = reinterpret_cast<void*>(myDouble);

    double * myDouble1 = reinterpret_cast<double*>(myVoid); // Original value retrieved
    std::cout << *myDouble1 << std::endl;

}