#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    vector <int> g1;
 
    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    // Capacity Functions
    cout << "Size : " << g1.size();
    cout << "\nCapacity : " << g1.capacity();
    cout << "\nMax_Size : " << g1.max_size();
 
    return 0;
 
}