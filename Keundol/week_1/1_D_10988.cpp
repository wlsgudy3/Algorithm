#include <iostream>
#include <algorithm>

using namespace std;

string str1, str2;

int main() {
	cin >> str1;
	str2 = str1;
	reverse(str2.begin(), str2.end());
	if (str1 == str2) cout << 1;
	else cout << 0;
}