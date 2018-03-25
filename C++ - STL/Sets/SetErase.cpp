#include <iostream>
#include <set>
#include <iterator>
#include <string>
#include <vector>
 
int main()
{
	//Set Of Strings
	std::set<std::string> setOfStrs = {"Hi", "Hello", "is", "the", "at", "Hi", "is", "from", "that"};
 
	// Printing Contents of Set
	std::copy (setOfStrs.begin(), setOfStrs.end(), std::ostream_iterator<std::string>(std::cout, ", "));
	std::cout<<std::endl;
 
	// Search for element "is"
	std::set<std::string>::iterator it = setOfStrs.find("is");
 
	// Check if Iterator is valid
	if(it != setOfStrs.end())
	{
		// Deletes the element pointing by iterator it
		setOfStrs.erase(it);
	}
 
	// Printing Contents of Set
	std::copy (setOfStrs.begin(), setOfStrs.end(), std::ostream_iterator<std::string>(std::cout, ", "));
	std::cout<<std::endl;
 
	// Iterator pointing to "Hi" in Set
	std::set<std::string>::iterator start = setOfStrs.find("Hi");
	// Iterator pointing to "from" in Set
	std::set<std::string>::iterator last = setOfStrs.find("from");
 
	// Check if both start and last iterators are valid
	if(start != setOfStrs.end() && last != setOfStrs.end())
	{
		// Erase all elements from "Hi" to "from"
		setOfStrs.erase(start, last);
	}
 
	// Printing Contents of Set
	std::copy (setOfStrs.begin(), setOfStrs.end(), std::ostream_iterator<std::string>(std::cout, ", "));
	std::cout<<std::endl;
 
	// Erase element "that" from set
	setOfStrs.erase("that");
 
	// Printing Contents of Set
	std::copy (setOfStrs.begin(), setOfStrs.end(), std::ostream_iterator<std::string>(std::cout, ", "));
	std::cout<<std::endl;
 
	return 0;
}