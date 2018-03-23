#include<iostream>
#include<set>

std::set<int> setOfNumbers;

void checkAndInsert(int num)
{
  if(setOfNumbers.insert(num).second)
     std::cout<<"Number "<<num<<" inserted sucessfuly\n";
 else
     std::cout<<"Number "<<num<<" was already present in set\n";
 
}
int main()
{
    checkAndInsert(2);
    checkAndInsert(3);
    checkAndInsert(2);
    checkAndInsert(1);
 
   // Check the size of set
   std::cout<<setOfNumbers.size()<<std::endl;
 
   // Iterate through all the elements in a set and display the value.
   for (std::set<int>::iterator it=setOfNumbers.begin(); it!=setOfNumbers.end(); ++it)
      std::cout << *it << " " ;
   std::cout<<"\n";

  return 0;
}