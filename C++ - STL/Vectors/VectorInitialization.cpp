#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <iterator>

using namespace std;

void example1()
{
	std::vector<int> vectorOfInt(5);

	for (int x : vectorOfInt)
		cout << x << endl;
}

void example2()
{
	std::vector<string> vectorOfString(5, "Hi");

	for (string x : vectorOfString)
		cout << x << endl;
}

void example3()
{
	string arr[] = {"First", "Second", "Third", "Fourth"};

	std::vector<string> vectorOfString(arr, arr + sizeof(arr)/sizeof(string));

	for (string x : vectorOfString)
		cout << x << endl;
}

void example4()
{
	list<string> listOfStr;
	listOfStr.push_back("first");
	listOfStr.push_back("second");
	listOfStr.push_back("third");
	listOfStr.push_back("fourth");

	std::vector<string> vectorOfString(listOfStr.begin(), listOfStr.end());

	for (string x : vectorOfString)
		cout << x << endl;
}

void example5()
{
	std::vector<string> vectorOfString;
	vectorOfString.push_back("first");
	vectorOfString.push_back("second");
	vectorOfString.push_back("third");

	vector<string> vectorCopy(vectorOfString);

	for (string x : vectorCopy)
		cout << x << endl;
}

int main()
{
	cout << "Vector Initialization with Default Values" << endl;
	example1();

	cout << "Vector Initialization with similar copy of elements" << endl;
	example2();

	cout << "Vector Initialization with an array" << endl;
	example3();

	cout << "Vector Initialization with a list" << endl;
	example4();

	cout << "Vector initialization with another vector" << endl;
	example5();

	return 0;
}