#include <iostream>
#include <string>
#include <map>


using namespace std;

int main()
{
	map<string, int> mapOfWords;
	
	mapOfWords.insert(make_pair("earth", 1));
	mapOfWords.insert(make_pair("moon", 2));
	mapOfWords["sun"] = 3;
	mapOfWords["earth"] = 4;

	map<string, int>::iterator it = mapOfWords.begin();

	while(it != mapOfWords.end())
	{
		cout << it->first << " :: " << it->second << endl;
		it++;
	}

	//check if insertion is successfull
	if (mapOfWords.insert(make_pair("earth", 1)).second == false)
		cout << "Element with key 'earth' was not inserted as it already existed" << endl;

	//Searching element in map by Key
	if (mapOfWords.find("sun") != mapOfWords.end())
		cout << "Word 'sun' was found" << endl;

	if (mapOfWords.find("mars") == mapOfWords.end())
		cout << "Word 'mars' was not found" << endl;

	return 0;
}
