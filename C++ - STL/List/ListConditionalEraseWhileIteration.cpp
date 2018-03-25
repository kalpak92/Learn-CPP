#include <iostream>
#include <list>
#include <algorithm>
 
int main() {
	// Create a list and initialize it with 10 elements
	std::list<int> listOfInts( { 2, 3, 3, 4, 8, 9, 4, 6, 8, 3 });
 
	// Iterate over the list using Iterators and erase elements
	// which are multiple of 3 while iterating through list
	std::list<int>::iterator it = listOfInts.begin();
	while (it != listOfInts.end()) {
		// Remove elements while iterating
		if ((*it) % 3 == 0) {
			// erase() makes the passed iterator invalid
			// But returns the iterator to the next of deleted element
			it = listOfInts.erase(it);
		} else
			it++;
	}
 
	// Iterate over the list using for_each & Lambda Function and display contents
	std::for_each(listOfInts.begin(), listOfInts.end(), [](const int & val) {
		std::cout<<val<<",";
	});
	std::cout << std::endl;
 
	return 0;
}