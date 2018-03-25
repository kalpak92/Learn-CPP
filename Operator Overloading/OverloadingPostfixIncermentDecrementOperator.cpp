#include <iostream>

using namespace std;

class Digits
{
	int m_digit;
public:
	Digits(int digit) : m_digit(digit)
	{}

	Digits operator++(int);
	Digits operator--(int);

	friend ostream& operator<< (ostream &out, const Digits &d);
};

Digits Digits::operator++(int)
{
	//Create a temporary variable with our current digit
	Digits temp(m_digit);

	//Use prefix operator to increment this digit
	++(m_digit);

	//return temporary result
	return temp;
}

Digits Digits::operator--(int)
{
	Digits temp(m_digit);

	--(m_digit);

	return temp;
}

ostream& operator<< (ostream &out, const Digits &d)
{
	out << d.m_digit;
	return out;
}

int main()
{
	Digits d1(5);
	cout << "The Digit is : " << d1 << endl;
	cout << "Postfix Increment : " << d1++ << endl;
	cout << "Postfix Decrement : " << d1-- << endl;

	return 0;
}