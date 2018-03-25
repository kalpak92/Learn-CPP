#include <iostream>
#include <string>

using namespace std;

template <typename T>
const T& maximum(const T &a, const T&b)
{
	return (a > b) ? a : b;
}

int main()
{
	int i = 78;
	int j = 89;
	cout << "max(i, j) = " << maximum(i, j) << endl;

	double a = 7.89;
	double b = 3.56;
	cout << "max(i, j) = " << maximum(a, b) << endl;

	string s1 = "Hello";
	string s2 = "World";
	cout << "max(s1, s2) = " << maximum(s1, s2) << endl;

	return 0;
}