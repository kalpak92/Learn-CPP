#include <iostream>
#include <map>
#include <string>
 
struct Occurance
{
	int count;
 
	// Default Constructor
	// Un Comment it to compile the code
	
	Occurance()
	{
		this->count = 0;
	}
	
 
	// Parametrized constructor
	Occurance(int count)
	{
		this->count = count;
	}
};
int main() {
 
	// Map of string & int i.e. words as key & there
	// occurrence count as values
	std::map<std::string, Occurance> wordMap = {
					{ "is", Occurance(6) },
					{ "the", Occurance(5) }
				};
 
 
	// As key is not in map, so operator[] will create new entry
	// With default value of value field. Therefore, Will compile
	// only if Occurance sruct has default constructor.
	Occurance occur = wordMap["Hello"];

	for (auto elem : wordMap)
		std::cout << elem.first << " :: " << elem.second.count << std::endl;
 
	return 0;
}