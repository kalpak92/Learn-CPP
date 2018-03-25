#include <iostream>
#include <list>
#include <iterator>

using namespace std;
 
int main()
{
    std::list<int> listOfNumbers;
 
    //Inserting elements at end in list
    listOfNumbers.push_back(5);
    listOfNumbers.push_back(6);
 
    //Inserting elements at front in list
    listOfNumbers.push_front(2);
    listOfNumbers.push_front(1);
    
    cout << "The initial list is: " ;
    // Iterating over list elements and display them
    std::list<int>::iterator it = listOfNumbers.begin();
    while(it != listOfNumbers.end())
    {
        std::cout<<(*it)<<"  ";
        it++;
    }
    std::cout<<std::endl;
 
 
    //Inserting elements in between the list using
    // insert(pos,elem) member function. Let's iterate to
    // 3rd position
    it = listOfNumbers.begin();
    it++;
    it++;
    // Iterator 'it' is at 3rd position.
    listOfNumbers.insert(it, 4);
 
    cout << "Inserting an Element at the 3rd position : ";
    // Iterating over list elements and display them
    it = listOfNumbers.begin();
    while(it != listOfNumbers.end())
    {
        std::cout<<(*it)<<"  ";
        it++;
    }
    std::cout<<std::endl;
 
 
    //Erasing elements in between the list using
    // erase(position) member function. Let's iterate to
    // 3rd position
    it = listOfNumbers.begin();
    it++;
    it++;
    // Iterator 'it' is at 3rd position. Now erase this element.
    listOfNumbers.erase(it);
 
    cout << "Erasing the element at the 3rd position: ";
    // Iterating over list elements and display them
    it = listOfNumbers.begin();
    while(it != listOfNumbers.end())
    {
        std::cout<<(*it)<<"  ";
        it++;
    }
    std::cout<<std::endl; 
    
    //Lets remove all elements with value greater than 3.
    listOfNumbers.remove_if([](int elem) { if(elem > 3)
                    return true;
                else
                    return false;
            });
    
    cout << "Removing all elements greater than 3: ";
    it = listOfNumbers.begin();
    while(it != listOfNumbers.end())
    {
        std::cout<<(*it)<<"  ";
        it++;
    }
    std::cout<<std::endl;
 
    return 0;
}