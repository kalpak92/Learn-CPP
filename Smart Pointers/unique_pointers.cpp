#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> up1(new int(2011));
    // std::unique_ptr<int> up2 = up1;             // ERROR
    std::unique_ptr<int> up2 = std::move(up1);     // Ownership handover

    return 0;
}
