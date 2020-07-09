#include <iostream>
#include <string>

int main()
{
    std::string str;

    auto idx = str.find("no");
    if (idx == std::string::npos) 
        std::cout << "not found";  // not found

    str = {"dkeu84kf8k48kdj39kdj74945du942"};
    std::string str2{"84"};

    std::cout << str.find('8') << std::endl;                              // 4
    std::cout << str.rfind('8') << std::endl;                             // 11
    std::cout << str.find('8', 10) << std::endl;                          // 11
    std::cout << str.find(str2) << std::endl;                             // 4
    std::cout << str.rfind(str2) << std::endl;                            // 4
    std::cout << str.find(str2, 10) << std::endl;                         // 18446744073709551615

    str2="0123456789";

    std::cout << str.find_first_of("678") << std::endl;                    // 4
    std::cout << str.find_last_of("678") << std::endl;                     // 20
    std::cout << str.find_first_of("678", 10) << std::endl;                // 11
    std::cout << str.find_first_of(str2) << std::endl;                     // 4
    std::cout << str.find_last_of(str2) << std::endl;                      // 29
    std::cout << str.find_first_of(str2, 10) << std::endl;                 // 10
    std::cout << str.find_first_not_of("678") << std::endl;                // 0
    std::cout << str.find_last_not_of("678") << std::endl;                 // 29
    std::cout << str.find_first_not_of("678", 10) << std::endl;            // 10
    std::cout << str.find_first_not_of(str2) << std::endl;                 // 0
    std::cout << str.find_last_not_of(str2) << std::endl;                  // 26
    std::cout << str.find_first_not_of(str2, 10) << std::endl;             // 12
    
    return 0;
}