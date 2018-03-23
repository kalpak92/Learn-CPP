#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> flist1;
	forward_list<int> flist2;

	//Assigning values using assign
	flist1.assign({1, 2, 3});

	//Assigning repeated values - 5 elements with the value 10
	flist2.assign(5, 10);

	cout << "The elements of the first Forward list are : ";
	for (int& a : flist1)
		cout << a << " ";
	cout << endl;

	cout << "The elements of the seconf Forward list are : ";
	for (int& b : flist2)
		cout << b << " ";
	cout << endl;

	return 0;
}