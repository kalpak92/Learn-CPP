#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	unordered_map<string, int> wordMap;

	//Inserting a few element
	wordMap.insert({"First", 1});
	wordMap.insert({"Second", 2});
	wordMap.insert({"Third", 3});

	//Overwrite value of an element
	wordMap["Third"] = 8;

	//Displaying an unordered map
	for (pair<string, int> elem : wordMap)
		cout << elem.first << " :: " << elem.second << endl;

	return 0;
}