#include <iostream>
#include <list>
#include <string>
#include <algorithm>
 
int main()
{
	std::list<std::string> listOfStrs = {
								"is", "of",
								"the", "Hi",
								"Hello", "from" };
 
	// Check if an element exists in list
 
	// Create a list Iterator
	std::list<std::string>::iterator it;
 
	// Fetch the iterator of element with value 'the'
	it = std::find(listOfStrs.begin(), listOfStrs.end(), "the");
 
	// Check if iterator points to end or not
	if(it != listOfStrs.end())
	{
		// It does not point to end, it means element exists in list
		std::cout<<"'the' exists in list "<<std::endl;
	}
	else
	{
		// It points to end, it means element does not exists in list
		std::cout<<"'the' does not exists in list"<<std::endl;
	}
 
}