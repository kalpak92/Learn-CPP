#include <iostream>

using namespace std;

class Cents
{
	int m_cents;
public:
	Cents(int cents) : m_cents(cents)
	{}

	int getCents() const 
	{
		return m_cents;
	}

	friend Cents operator+ (const Cents &c1, const Cents &c2)
	{
		return Cents(c1.m_cents + c2.m_cents);
	}

	friend Cents operator- (const Cents &c1, const Cents &c2)
	{
		return Cents(c1.m_cents - c2.m_cents);
	}

	friend Cents operator+ (const Cents &c1, int value)
	{
		// we can access m_cents directly because this is a friend function
		return Cents(c1.m_cents + value);
	}
	 
	friend Cents operator+ (int value, const Cents &c1)
	{
		// we can access m_cents directly because this is a friend function
		return Cents(c1.m_cents + value);
	}

};

int main()
{
	Cents c1(5);
	Cents c2(10);

	Cents cent_sum = c1 + c2;
	Cents cent_diff = c2 - c1;
	cout << "I have " << cent_sum.getCents() << " cents" << endl;
	cout << "I have " << cent_diff.getCents() << " cents." << endl;

	Cents c3 = Cents(4) + 6;
	Cents c4 = 6 + Cents(4);

	cout << "I have " << c3.getCents() << " cents." << endl;
	cout << "I have " << c4.getCents() << " cents." << endl;

	return 0;
}