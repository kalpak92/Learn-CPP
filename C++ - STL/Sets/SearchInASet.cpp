#include<iostream>
#include<set>
#include<string>
int main()
{
	std::set<std::string> setOfNumbers;
 
	// Lets insert four elements
	setOfNumbers.insert("first");
	setOfNumbers.insert("second");
	setOfNumbers.insert("third");
	setOfNumbers.insert("first");
 
	// Search for element in set using find member function
	std::set<std::string>::iterator it = setOfNumbers.find("second");
	if(it != setOfNumbers.end())
		std::cout<<"'first'  found"<<std::endl;
	else
		std::cout<<"'first' not found"<<std::endl;
 
	// Search for element in set using find member function
	it = setOfNumbers.find("fourth");
	if(it != setOfNumbers.end())
		std::cout<<"'fourth'  found"<<std::endl;
	else
		std::cout<<"'fourth' not found"<<std::endl;
 
	return 0;
}