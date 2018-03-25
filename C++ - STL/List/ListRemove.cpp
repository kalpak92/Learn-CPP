#include <iostream>
#include <list>

using namespace std;

int main() {
	// Create a list and initialize it with 7 elements
	std::list<int> listOfInts( { 2, 3, 4, 6, 4, 9, 1, 2, 8, 9, 4, 6, 2 });
    
    cout << "Original List : " ;
    //orginal list
    for (int x : listOfInts)
        cout << x << " ";
    cout << endl;
    
	// Remove all elements with value 4
	listOfInts.remove(4);
    cout << "Removing all occurences of 4 : " ; 
	// Iterate over the list using range based loop
	for (int val : listOfInts)
		std::cout << val << " ";
	std::cout << std::endl;
 
    // Remove only first occurrence of element with value 4
    listOfInts.remove_if([](const int & val) {
		if(val >= 2 && val < 5)
		return true;
		else
		return false;
	});
    
    cout << "Removing all values greater than or equal to 2 but less than 5 : "; 
	// Iterate over the list using range based loop
	for (int val : listOfInts)
		std::cout << val << " ";
	std::cout << std::endl;
	return 0;
}