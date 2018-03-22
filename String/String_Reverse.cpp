#include <bits/stdc++.h>

using namespace std;

// Function to reverse a string
void reverseStr(string &str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i=0; i<n/2; i++)
       swap(str[i], str[n-i-1]);
}

int main() {
	string str = "geeksforgeeks";
    reverseStr(str);

    //Using the built-in reverse Function:
    //reverse(str.begin(),str.end());
    cout << str;
    return 0;
}
