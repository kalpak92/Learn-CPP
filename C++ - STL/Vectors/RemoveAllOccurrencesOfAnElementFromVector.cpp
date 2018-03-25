#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void removeAllMatchingElements_nonEfficient(std::vector<int> & vec, int elem)
{
   std::vector<int>::iterator it = vec.begin();
   while(it != vec.end())
   {
     if(*it == elem)
     {
        it = vec.erase(it);
     }
     else
        it++;
  }
}
 
void removeAllMatchingElements_Efficient(std::vector<int> & vec, int elem)
{
    vec.erase(std::remove(vec.begin(), vec.end(), elem), vec.end());
}
 
void displayVector(std::vector<int> & vec)
{
   std::vector<int>::iterator it = vec.begin();

   while(it != vec.end())
       std::cout << (*it++) << " ";
   
  std::cout<<std::endl;
}
int main()
{
   int arr[10] = {1,2,5,4,5,1,5,7,8,9};
 
   std::vector<int> vec(arr , arr + 10);

   cout << "Original Vector is " << endl;

   for (int x : vec)
      cout << x << " ";

    cout << "\n" << endl;

   removeAllMatchingElements_nonEfficient(vec, 5);
   displayVector(vec);
 
   std::vector<int> vec2(arr , arr + 10);
   removeAllMatchingElements_Efficient(vec2, 5);
   displayVector(vec2);
 
   return 0;
}