#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> dequeObj;

	dequeObj.push_back(5);
	dequeObj.push_back(6);

	dequeObj.push_front(1);
	dequeObj.push_front(3);

	cout << "The Deque till now is : " << endl;

	deque<int>::iterator it;
	for (it = dequeObj.begin(); it != dequeObj.end(); it++)
		cout << *it << '\t';

	cout << "" << endl;
}