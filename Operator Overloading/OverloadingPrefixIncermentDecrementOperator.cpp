#include <iostream>

using namespace std;

class Digits
{
	int m_digit;
public:
	Digits(int digit) : m_digit(digit)
	{}

	Digits& operator++();
	Digits& operator--();

	friend ostream& operator<< (ostream &out, const Digits &d);
};

// Note that we return *this. The overloaded increment and decrement operators return the current implicit object 
// so multiple operators can be “chained” together.

Digits& Digits::operator++()
{
	if (m_digit == 9)
		m_digit = 0;
	else
		++m_digit;

	return *this;
}

Digits& Digits::operator--()
{
	if (m_digit == 0)
		m_digit = 9;
	else
		--m_digit;

	return *this;
}

ostream& operator<< (ostream &out, const Digits &d)
{
	out << d.m_digit;
	return out;
}

int main()
{
	Digits d1(6);
	cout << "The Digit is : " << d1 << endl;
	cout << "Prefix Increment : " << ++d1 << endl;
	cout << "Prefix Decrement : " << --d1 << endl;

	return 0;
}