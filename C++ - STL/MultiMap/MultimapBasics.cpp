#include <iostream>
#include <map>

using namespace std;

int main()
{
	multimap<char, int> mmapOfPos = {
		{'t', 0},
		{'h', 1},
		{'i', 2},
		{'s', 3},
		{'i', 5},
		{'s', 6},
		{'i', 8},
	};

	mmapOfPos.insert(pair<char, int>('t', 9));

	//Iterating over the multimap using iterator
	
	for (multimap<char, int>::iterator it = mmapOfPos.begin(); it != mmapOfPos.end(); it++)
		cout << it->first << " :: " << it->second << endl;

	cout << " ******************************************************** " << endl;

	//Iterating over multimap using range based loop
	for (pair<char, int> elem : mmapOfPos)
		cout << elem.first << " :: " << elem.second << endl;

	return 0;
}