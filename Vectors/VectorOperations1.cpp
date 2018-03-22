#include <iostream>
#include <vector>
 
struct Sample
{
    Sample(){}
    Sample(const Sample & obj)
    {
        std::cout<<"Sample copy constructor"<<std::endl;
    }
};
int main()
{
    std::vector<Sample> vecOfInts;
 
    std::cout<<"Capacity :: "<<vecOfInts.capacity()<<std::endl;
    std::cout<<"Size :: "<<vecOfInts.size()<<std::endl;
    int capcity = vecOfInts.capacity();
    for(int i = 0; i < capcity + 1; i++)
        vecOfInts.push_back(Sample());
 
    std::cout<<"Capacity :: "<<vecOfInts.capacity()<<std::endl;
        std::cout<<"Size :: "<<vecOfInts.size()<<std::endl;
 
    for(int i = 0; i < capcity + 1; i++)
            vecOfInts.push_back(Sample());
 
    std::cout<<"Capacity :: "<<vecOfInts.capacity()<<std::endl;
    std::cout<<"Size :: "<<vecOfInts.size()<<std::endl;
 
    return 0;
}