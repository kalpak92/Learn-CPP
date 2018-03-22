#include <bits/stdc++.h>

using namespace std;

int main() {
	// various constructor of string class
 
    // initialization by raw string
    string str1("first string");
 
    // initialization by another string
    string str2(str1);
 
    // initialization by character with number of occurence
    string str3(5, '#');
 
    // initialization by part of another string
    string str4(str1, 6, 6); // from 6th index (second parameter)
                             // 6 characters (third parameter)
 
    // initialization by part of another string : iteartor version
    string str5(str2.begin(), str2.begin() + 5);
 
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
    cout << str5 << endl;	
	return 0;
}
