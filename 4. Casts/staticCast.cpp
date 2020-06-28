#include <iostream>

class Account{};
class BankAccount: public Account{};

enum Color
{
    red,
    blue,
    green
};

int main()
{

    std::cout << std::endl;

    Account * a = nullptr;
    BankAccount * b = nullptr;

    a = static_cast<Account*> (b);                         // upcast
    a = b;                                                 // upcast

    b = static_cast<BankAccount*>(a);                      // downcast

    int i{2};
    Color col = static_cast<Color>(i);
    std::cout << "i: "  << i << std::endl;
    std::cout << "col: " << col << std::endl;

    int i2= static_cast<int>(3.14);
    std::cout << "i2: " << i2 << std::endl;

    std::cout << std::endl;

}