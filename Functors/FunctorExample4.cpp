#include <iostream>
#include <set>
#include <deque>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;
using namespace placeholders;
double Pow(double x, double y)
{
	return pow(x, y);
}

int main()
{
	set<int> myset = {3, 1, 5, 4, 2};
	deque<int> d;

	auto f = function<double (double, double)>(Pow); //regualar function to functor
	transform(myset.begin(), myset.end(),
				back_inserter(d),
				bind(f, placeholders::_1, 2));

	for(int x : d)
		cout << x << " ";
	cout<<endl;
}