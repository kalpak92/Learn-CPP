#include <iostream>
#include <map>
#include <string>
 
int main() {
 
	// Map of string & int i.e. words as key & there
	// occurrence count as values
	std::map<std::string, int> wordMap = { { "is", 6 }, { "the", 5 },
			{ "hat", 9 }, { "at", 6 }, { "of", 2 }, { "hello", 1 } };
 
 
	std::cout << "Map Entries Before Deletion" << std::endl;
	// Print the map elements
	for (auto elem : wordMap)
		std::cout << elem.first << " :: " << elem.second << std::endl;
 
	// Create an iterator pointing to begin of map
	std::map<std::string, int>::iterator it1 = wordMap.begin();
 
	// Create an iterator pointing to begin of map
	std::map<std::string, int>::iterator it2 = wordMap.begin();
	// Increment Iterator
	it2++;
	// Increment Iterator
	it2++;
	// Itr2 is now pointing to 3rd element
 
 
	// Check if iterator is valid.
	if (it1 != wordMap.end() && it2 != wordMap.end())
	{
		// Remove the element pointed by iterator
		wordMap.erase(it1, it2);
		std::cout << "Elements Removed" << std::endl;
	}
	else
		std::cout << "Key Not Found" << std::endl;
 
 
	std::cout << "Map Entries After Deletion" << std::endl;
	// Print the map elements
	for (auto elem : wordMap)
		std::cout << elem.first << " :: " << elem.second << std::endl;
 
	return 0;
}