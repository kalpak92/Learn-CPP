#include <iostream>

using namespace std;

template <typename T>
T average(T *array, int length)
{
	T sum = 0;
	for (int i = 0; i < length; i++)
		sum += array[i];

	sum /= length;
	return sum;
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

	friend ostream& operator<< (ostream& out, const Cents& c1)
	{
		out << "Average of the Cents is = " << c1.m_cents << " cents";
		return out;
	}

	Cents& operator+= (Cents &c1)
	{
		m_cents += c1.m_cents;
		return *this;
	}

	Cents& operator/= (int value)
	{
		m_cents /= value;
		return *this;
	}
};

int main()
{
    Cents array[] = { Cents(5), Cents(10), Cents(15), Cents(14) };
    cout << average(array, 4) << endl;
 
    return 0;
}
