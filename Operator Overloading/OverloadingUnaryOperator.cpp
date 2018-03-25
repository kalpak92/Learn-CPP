#include <iostream>

using namespace std;

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents) { m_cents = cents; }
    
    // Overload -Cents as a member function
    Cents operator-() const;
 
    int getCents() const { return m_cents; }
};

Cents Cents::operator-() const
{
	return Cents(-m_cents);
}

int main()
{
	const Cents nickle(5);
	cout << "Nickle of debt is worth " << (-nickle).getCents() << " cents." << endl;

	return 0;
}