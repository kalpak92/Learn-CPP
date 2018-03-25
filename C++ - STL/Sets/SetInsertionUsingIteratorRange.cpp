#include <iostream>
#include <set>
#include <iterator>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> vecOfStrs = {"Hi", "Hello", "is", "the", "at", "Hi", "is"};

	std::set<std::string> setOfStrs;

	// Insert a Range in set
	// Range here is start and end iterators of a vector
	setOfStrs.insert(vecOfStrs.begin(), vecOfStrs.end());

	// It will insert all the elements in vector to set, but as
	// set contains only unique elements, so duplicate elements will
	// be automatically rejected.

	// But there is no way to find out how many actually inserted
	// because it doesn't return any value.

	std::cout<<"**Map Contents***"<<std::endl;

	for(auto elem : setOfStrs)
		std::cout<<elem<<" ";
	std::cout<<std::endl;

	return 0;
}