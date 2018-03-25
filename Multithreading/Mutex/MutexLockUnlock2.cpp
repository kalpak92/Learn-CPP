#include <iostream>
#include <thread>
#include <mutex>
#include <string>

using namespace std;

mutex m1;

void shared_print(string msg, int id)
{
	m1.lock();
	cout << msg << " :: " << id << endl;
	m1.unlock();
}

void function1()
{
    for (int i = 0; i > -10; i--)
        shared_print("From t1", i);
}

int main()
{
 
    thread t1(function1);
    
    for (int i = 0; i < 10 ; i++)
        shared_print("From Main", i);
        
    t1.join();
        
    return 0;
}