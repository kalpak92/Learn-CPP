#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int mul = 5;

	for_each(arr, arr + sizeof(arr)/sizeof(int), [&](int x){
		cout << x <<" ";
		//Can modify 'mul' inside this function because all outer scope elements has write access.
		mul = 9;
	});

	cout << endl;
	cout << "mul = " << mul << endl;

	for_each(arr, arr + sizeof(arr)/sizeof(int), [=](int x){
		cout << x <<" ";
		//Cannot modify 'mul' inside this function because all outer scope elements has read only access.
		// m = 2;  Not Allowed
		//cout << mul << endl; Allowed
	});

	cout << endl;
	cout << "mul = " << mul << endl;

	for_each(arr, arr + sizeof(arr) / sizeof(int), [](int x) {
 
        // No access to mul inside this lambda function because
        // all outer scope elements are not visible here.
        //cout << mul << " ";
        });
    cout << endl;
}