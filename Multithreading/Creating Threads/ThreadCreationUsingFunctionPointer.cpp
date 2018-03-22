#include <iostream>
#include <thread>

using namespace std;
 
void thread_function()
{
    for(int i = 0; i < 10; i++)
        std::cout<<"thread function Executing - " << i <<std::endl;
}
 
int main()  
{
    
    std::thread threadObj(thread_function);
    
    for(int i = 0; i < 10; i++)
        std::cout<<"Display From MainThread \n"<<std::endl;
        
    threadObj.join();    
    std::cout<<"Exit of Main function"<<std::endl;
    return 0;
}