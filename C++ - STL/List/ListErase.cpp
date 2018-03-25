#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

int main() {
	// Create a list and initialize it with 7 elements
	std::list<int> listOfInts( { 2, 3, 4, 6, 4, 9, 1, 2, 8, 9, 4, 6, 2, 4, 9 });

	//Display The List
	std::copy(listOfInts.begin(), listOfInts.end(),
			std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	// Iterator itList points to element next to begin
	std::list<int>::iterator itList = ++(listOfInts.begin());

	// Erasing element represented by iterator itList i.e. 3
	itList = listOfInts.erase(itList);

	//Display The List
	std::copy(listOfInts.begin(), listOfInts.end(),
			std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//Increment iterator
	itList++;

	// Erase a range of elements i.e. 6 to end
	listOfInts.erase(itList, listOfInts.end());

	//Display The List
	std::copy(listOfInts.begin(), listOfInts.end(),
			std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	return 0;
}