#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
 
void testResult(
		std::pair<std::map<std::string, int>::iterator, bool> & result) {
	// Check if Insertion was successful
	if (result.second == false) {
		// Insertion Failed
		std::cout << "Failed to add . duplicate key :: " << result.first->first
				<< std::endl;
	} else {
		// Insertion was successful
		std::cout << "Successful in Adding , key :: " << result.first->first
				<< std::endl;
	}
}
 
int main() {
 
	// Map of string and int
	std::map<std::string, int> mapOfWordCount;
 
	// Pair of Map Iterator and bool
	std::pair<std::map<std::string, int>::iterator, bool> result;
 
	// Insert Element in map
	result = mapOfWordCount.insert(std::pair<std::string, int>("first", 1));
	// Test its result
	testResult(result);
 
	// Insert Element in map
	result = mapOfWordCount.insert(std::pair<std::string, int>("second", 2));
	// Test its result
	testResult(result);
 
	// Insert Element in map
	result = mapOfWordCount.insert(std::pair<std::string, int>("third", 3));
	// Test its result
	testResult(result);
 
	// Try to add duplicate element
	result = mapOfWordCount.insert(std::pair<std::string, int>("third", 4));
	// Test its result
	testResult(result);
 
	// Create a map iterator and point to beginning of map
	std::map<std::string, int>::iterator it = mapOfWordCount.begin();
 
	std::cout << "*****************************" << std::endl;
	// Iterate over a map using std::for_each and Lambda function
	std::for_each(mapOfWordCount.begin(), mapOfWordCount.end(),
			[](std::pair<std::string, int> element) {
				// Accessing KEY from element
				std::string word = element.first;
				// Accessing VALUE from element.
				int count = element.second;
				std::cout<<word<<" :: "<<count<<std::endl;
			});
 
	return 0;
}