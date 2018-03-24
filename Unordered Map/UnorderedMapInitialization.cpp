#include <iostream>
#include <unordered_map>
#include <string>
 
int main()
{
	// Initialize an unordered_map through initializer_list
	std::unordered_map<std::string, int> wordMap(
	{
		{ "First", 1 },
		{ "Second", 2 },
		{ "Third", 3 } 
	});
 
	// Iterate over an unordered_map and display elements
	for (std::pair<std::string, int> element : wordMap)
		std::cout << element.first << " :: " << element.second << std::endl;
 
	std::cout << "*******************" << std::endl;
 
	// Initialize an unordered_map through another range of elements of type std::pair
	std::unordered_map<std::string, int> wordMap_2(wordMap.begin(),
			wordMap.end());
 
	// Iterate over an unordered_map and display elements
	for (std::pair<std::string, int> element : wordMap_2)
		std::cout << element.first << " :: " << element.second << std::endl;
 
	std::cout << "*******************" << std::endl;
 
	// Initialize an unordered_map through other unordered_map
	std::unordered_map<std::string, int> wordMap_3(wordMap);
 
	// Iterate over an unordered_map and display elements
	for (std::pair<std::string, int> element : wordMap_3)
		std::cout << element.first << " :: " << element.second << std::endl;
 
	return 0;
}