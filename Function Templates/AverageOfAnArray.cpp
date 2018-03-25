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

int main()
{
	int array1[] = { 5, 3, 2, 1, 4 };
	cout << "Average of array1 = " << average(array1, 5) << endl;

	double array2[] = { 3.12, 3.45, 9.23, 6.34 };
    cout << "Average of array2 = " << average(array2, 4) << endl;

    return 0;

}