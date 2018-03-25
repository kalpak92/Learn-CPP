#include <iostream>
#include <thread>

using namespace std;

// Here both the threads are racing for the common resource : cout
void function1()
{
    for (int i = 0; i > -10; i--)
        cout << "From t1 : " << i << endl;
}

int main()
{
 
    thread t1(function1);
    
    for (int i = 0; i < 10 ; i++)
        cout <<"From Main : " << i << endl;
        
    t1.join();
        
    return 0;
}