#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void add2(int i)
{
	cout << i + 2 << " ";
}

class AddValue
{
	int val;
public:
	AddValue(int j) : val(j)
	{}

	void operator() (int i)
	{
		cout << i + val << " ";
	}
};

int main()
{
	vector<int> v = {1, 2, 3, 4, 5};

	for_each(v.begin(), v.end(), add2);
	cout << endl;

	int x = 5;
	for_each(v.begin(), v.end(), AddValue(x));
	cout << endl;

}