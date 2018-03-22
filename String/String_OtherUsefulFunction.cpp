#include <bits/stdc++.h>

using namespace std;

int main() {
	string str("GeeksforGeeks");
    string str1("GeeksforGeeks");
 
    // Comparing strings using compare()
    if ( str.compare(str1) == 0 )
        cout << "Strings are equal";
    else
        cout << "Strings are unequal";

    string str2("The Geeks for Geeks");
 
    // find() returns position to first
    // occurrence of substring "Geeks"
    // Prints 4
    cout << "First occurrence of \"Geeks\" starts from : ";
    cout << str2.find("Geeks") << endl;
 
    // Prints position of first occurrence of
    // any character of "reef" (Prints 2)
    cout << "First occurrence of character from \"reef\" is at : ";
    cout << str2.find_first_of("reef") << endl;
 
    // Prints position of last occurrence of
    // any character of "reef" (Prints 16)
    cout << "Last occurrence of character from \"reef\" is at : ";
    cout << str2.find_last_of("reef") << endl;
 
    // rfind() returns position to last
    // occurrence of substring "Geeks"
    // Prints 14
    cout << "Last occurrence of \"Geeks\" starts from : ";
    cout << str2.rfind("Geeks") << endl;

    string str3("Geeksfor");
 
    // Printing the original string
    cout << str3 << endl;
 
    // Inserting "for" at 5th position
    str3.insert(8,"Geeks");
 
    // Printing the modified string
    // Prints "GeeksforGeeks"
    cout << str3 << endl;

    //Clearing the string
    str3.clear();

    //Checking if string is empty. Returns a boolean value.
    if (str3.empty() ==true)	//This also works. str3.empty()==1
    	cout << "The string is Empty" << endl;
    else
    	cout <<"The string is not empty." << endl;

	return 0;
}
