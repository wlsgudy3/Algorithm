#include <iostream>

using namespace std;

string str;
int check;

int main() {
	cin >> str;
	check = 1;
	for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[str.length() - i - 1]) {
			check = 0;
			break;
		}
	}

	cout << check;
}