#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <vector>

int main()
{

    std::cout << std::endl;

    std::vector<int> myVec(20);
    std::iota(myVec.begin(), myVec.end(), 0);

    std::cout << "myVec: ";
    for (auto i: myVec) 
        std::cout << i << " ";
    std::cout << std::endl;

    std::function< bool(int)> myBindPred = std::bind( std::logical_and<bool>(),
                                        std::bind( std::greater <int>(), std::placeholders::_1, 9 ), std::bind( std::less <int>(), std::placeholders::_1, 16 ));

    myVec.erase(std::remove_if(myVec.begin(), myVec.end(), myBindPred), myVec.end());

    std::cout << "myVec: ";
    for (auto i: myVec) 
        std::cout << i << " ";

    std::cout << "\n\n";

    std::vector<int> myVec2(20);
    std::iota(myVec2.begin(), myVec2.end(), 0);

    std::cout << "myVec2: ";
    for (auto i: myVec2) 
        std::cout << i << " ";
    std::cout << std::endl;

    auto myLambdaPred = [](int a){return (a > 9) && (a < 16);};

    myVec2.erase(std::remove_if(myVec2.begin(), myVec2.end(), myLambdaPred), myVec2.end());

    std::cout << "myVec2: ";
    for (auto i: myVec2) 
        std::cout << i << " ";

    std::cout << std::endl;

}