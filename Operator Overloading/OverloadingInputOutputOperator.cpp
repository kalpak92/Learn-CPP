#include <iostream>

using namespace std;

class Point
{
	double m_x, m_y, m_z;

public:
	Point(double x=0.0, double y=0.0, double z=0.0) : m_x(x), m_y(y), m_z(z) //Dont forget to pass the default values or else create a default constructor.
	{}

	friend ostream& operator<< (ostream &out, const Point &point);
	friend istream& operator>> (istream &in, Point &point);

};

//If you try to return std::ostream by value, you’ll get a compiler error. 
//This happens because std::ostream specifically disallows being copied.
ostream& operator<< (ostream &out, const Point &point)
{
	out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";
	return out;
}

istream& operator>> (istream &in, Point &point)
{
	in >> point.m_x;
	in >> point.m_y;
	in >> point.m_z;

	return in;
}

int main()
{
	Point p1(1.0, 2.0, 3.0);
	Point p2(4.0, 5.0, 6.0);

	cout << p1 << " " << p2 << endl;

	Point p3;
	cin >> p3;
	cout << "You entered " << p3 << endl;

	return 0;
}