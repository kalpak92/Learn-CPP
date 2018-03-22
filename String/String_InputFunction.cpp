#include <bits/stdc++.h>

using namespace std;

int main() {
	string str;
	getline(cin, str);

	cout << "The String is: " << str << endl;

	str.push_back('s');
	cout <<"The string after push back operation is: " << str << endl;

	str.pop_back();
	cout <<"The string after pop back operation is: " << str << endl;
	
	return 0;
}
