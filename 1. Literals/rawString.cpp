#include <iostream>
#include <string>

int main()
{

    std::cout << std::endl;

    std::string nat = "C:\temp\newFile.txt";
    std::cout << "nat " << nat << std::endl;

    // including \t \n
    std::string raw1 = std::string(R"(C:\temp\newFile.txt)");
    std::cout << "raw1 " << raw1 << std::endl;

    // including \t \n and using delimiter
    std::string raw2 = std::string(R"TRENNER(C:\temp\newFile.txt)TRENNER");
    std::cout << "raw2 " << raw2 << std::endl;   

    // raw string including "
    std::string raw3 = std::string(R"("a raw string including ")");
    std::cout << "raw3 " << raw3 << std::endl;

    std::cout << std::endl;

}