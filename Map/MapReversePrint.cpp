#include <iostream>
#include <map>
#include <string>
#include <iterator>
 
int main() {
 
	// Creating & Initializing a map of String & Ints
	std::map<std::string, int> mapOfWordCount = {
			{ "aaa", 10 },
			{ "ddd", 11 },
			{ "bbb", 12 },
			{ "ccc", 13 }
	};
 
	// Create a map iterator and point to the end of map
	std::map<std::string, int>::reverse_iterator it = mapOfWordCount.rbegin();
 
	// Iterate over the map using Iterator till beginning.
	while (it != mapOfWordCount.rend()) {
		// Accessing KEY from element pointed by it.
		std::string word = it->first;
 
		// Accessing VALUE from element pointed by it.
		int count = it->second;
 
		std::cout << word << " :: " << count << std::endl;
 
		// Increment the Iterator to point to next entry
		it++;
	}
 
	return 0;
}