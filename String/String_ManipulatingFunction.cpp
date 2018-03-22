#include <bits/stdc++.h>

using namespace std;

int main() {
	// Initializing 1st string
    string str1 = "geeksforgeeks is for geeks";
 
    // Declaring 2nd string
    string str2 = "geeksforgeeks rocks";
 
    // Declaring character array
    char ch[80];
 
    // using copy() to copy elements into char array
    // copies "geeksforgeeks"
    str1.copy(ch,13,0);
 
    // Diplaying char array
    cout << "The new copied character array is : ";
    cout << ch << endl << endl;
 
    // Displaying strings before swapping
    cout << "The 1st string before swapping is : ";
    cout << str1 << endl;
    cout << "The 2nd string before swapping is : ";
    cout << str2 << endl;
 
    // using swap() to swap string content
    str1.swap(str2);
 
    // Displaying strings after swapping
    cout << "The 1st string after swapping is : ";
    cout << str1 << endl;
    cout << "The 2nd string after swapping is : ";
    cout << str2 << endl;

    cout << "=======================\n" << endl;

    string stra = "first string";
    string str4(stra, 6, 6);
    string str6 = str4;
    // append add the argument string at the end
    str6.append(" extension");
    //  same as str6 += " extension"
 
    // another version of appends, which appends part of other
    // string
    str4.append(str6, 0, 6);  // at 0th position 6 character
 
    cout << str6 << endl;
    cout << str4 << endl;
 
    //  find returns index where pattern is found.
    //  If pattern is not there it returns predefined
    //  constant npos whose value is -1
 
    if (str6.find(str4) != string::npos)
        cout << "str4 found in str6 at " << str6.find(str4)
             << " pos" << endl;
    else
        cout << "str4 not found in str6" << endl;
 
    //  substr(a, b) function returns a substring of b length
    //  starting from index a
    cout << str6.substr(7, 3) << endl;
 
    //  if second argument is not passed, string till end is
    // taken as substring
    cout << str6.substr(7) << endl;
 
    //  erase(a, b) deletes b character at index a
    str6.erase(7, 4);
    cout << str6 << endl;
 
    //  iterator version of erase
    str6.erase(str6.begin() + 5, str6.end() - 3);
    cout << str6 << endl;
 
    str6 = "This is a examples";
 
    //  replace(a, b, str)  replaces b character from a index by str
    str6.replace(2, 7, "ese are test");
 
    cout << str6 << endl;
	return 0;
}
