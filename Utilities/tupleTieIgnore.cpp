#include <functional>
#include <iostream>
#include <tuple>

int main()
{

    std::cout << std::endl;

    // make a tuple
    auto tup1 = std::make_tuple(1, 2, 3);

    // print the values
    std::cout << "std::tuple tup1: ("<< std::get<0>(tup1) << ", " << std::get<1>(tup1) << ", " << std::get<2>(tup1) << ")" << std::endl;

    std::cout << std::endl;

    int first = 1;
    int second = 2;
    int third = 3;
    int fourth = 4;

    // create a tuple with references
    auto tup2 = std::make_tuple(std::cref(first), std::ref(second), std::ref(third), fourth);

    // print the values
    std::cout << "std::tuple tup2: (" << std::get<0>(tup2) << ", " << std::get<1>(tup2) << ", " << std::get<2>(tup2) << ", " << std::get<3>(tup2) << ")" <<  std::endl;

    std::cout << std::endl;

    //change the values
    // will not work, because of std::cref(first)
    // std::get<0>(tup2)= 1001;
    first = 1001;
    std::get<1>(tup2) = 1002;
    third = 1003;
    fourth = 1004;

    // print the values
    std::cout << "std::tuple tup2: (" << std::get<0>(tup2) << ", " << std::get<1>(tup2) << ", " << std::get<2>(tup2) << ", " << std::get<3>(tup2) << ")" << std::endl;
    std::cout << "global variables: " << first << " " << second << " " << third << " " << fourth << std::endl;

    std::cout << std::endl;

    first = 1;
    second = 2;
    third = 3;
    fourth = 4;

    // create tup3 and set the variables
    auto tup3 = std::tie(first, second, third, fourth) = std::make_tuple(1001, 1002, 1003, 1004);

    // print the values
    std::cout << "std::tuple tup3: (" << std::get<0>(tup3) << ", " << std::get<1>(tup3) << ", " << std::get<2>(tup3) << ", " << std::get<3>(tup3) << ")" << std::endl;
    std::cout << "global variables: " << first << " " << second << " " << third << " " << fourth << std::endl;

    std::cout << std::endl;

    int a;
    int b;

    // bind the 2th and 4th argument to a and b
    std::tie(std::ignore, a, std::ignore, b)= tup3;

    // print the values
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << std::endl;

    // will also work for std::pair
    std::tie(a, b) = std::make_pair(3001, 3002);

    // print the values
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << std::endl;

}
