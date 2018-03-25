#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	set<string> setOfNumbers;

	setOfNumbers.insert("first");
	setOfNumbers.insert("second");
	setOfNumbers.insert("third");
	setOfNumbers.insert("fourth");
	setOfNumbers.insert("first");

	cout << "Set Size : " << setOfNumbers.size() << endl;

	set<string>::iterator it;

	for (it=setOfNumbers.begin(); it!=setOfNumbers.end(); it++)
		cout << (*it) << " ";
	cout << endl;

	return 0;
}