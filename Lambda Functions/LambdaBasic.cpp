#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int arr[] = {1, 2, 3, 4, 5};

	for_each(arr, arr + sizeof(arr)/sizeof(int), [](int x){
		cout << x <<" ";
	});

	cout << endl;
}