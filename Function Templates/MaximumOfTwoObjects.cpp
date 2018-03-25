#include <iostream>

using namespace std;

template <typename T>
const T& maximum(const T& x, const T& y)
{
	return (x > y) ? x : y;
}

class Cents
{
	int m_cents;
public:
	Cents(int cents): m_cents(cents)
	{}

	int get_cents()
	{
		cout << m_cents << endl;
	}

	friend bool operator> (const Cents &c1, const Cents &c2)
	{
		return (c1.m_cents > c2.m_cents);
	}
};

int main()
{
	Cents nickle(5);
	Cents dime(10);

	Cents bigger = maximum(nickle, dime);
	bigger.get_cents();
	return 0;
}