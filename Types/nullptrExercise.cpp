#include <iostream>
using namespace std;

int main() 
{
    int* pi = nullptr;       // OK
    std::cout << pi << std::endl;

    // int i = nullptr;      // ERROR

    bool b{nullptr};         // OK
    std::cout << b << std::endl;
}