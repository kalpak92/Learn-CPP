#include <algorithm>
#include <iostream>
#include <string>

struct MyData{};

std::string function( const MyData & ) 
{
    return "lvalue reference";
}

std::string function( MyData && ) 
{
    return "rvalue reference";
}

int main()
{

    std::cout << std::endl;

    MyData myData;

    std::cout << "function(myData): " << function(myData) << std::endl;
    std::cout << "function(MyData()): " << function(MyData()) << std::endl;
    std::cout << "function(std::move(myData)): " << function(std::move(myData)) << std::endl;

    std::cout << std::endl;

}