#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(5);
	v.push_back(3);
	v.push_back(7);
	v.push_back(8);

	cout << "The initialized vector is : " << endl;
	for (int x : v)
		cout << x << " " ;
	cout << "" << endl;

	// Use pop_back to remove the last element.
	v.pop_back();
	cout << "Use pop.back() to remove the last element from the vector. " << endl;
	for (int x : v)
		cout << x << " " ;
	cout << "" << endl;

	// To remove the first element, use erase(). Pass the element's position as an argument.
	v.erase(v.begin());
	cout << "Use erase() to remove the first element. Also pass the element's position as an argument" << endl;
	for (int x : v)
		cout << x << " ";
	cout << "" << endl;

	//Using erase() to remove the last element.
	v.erase(v.begin() + v.size() - 1);
	cout << "Using erase to remove the last element of the vector" << endl;

	for (int x : v)
		cout << x << " ";
	cout << "" << endl;

	//Some other utility functions
	cout <<"Front Element = " <<  v.front() << endl;
	cout <<"Last Element = " << v.back() << endl;
	cout <<"Size of the vector = " <<  v.size() << endl;

	//To clean the vector, use v.clear()
	
	return 0;
}