#include <iostream>
#include <string>

using namespace std;

string str;

int main() {
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (65 <= str[i] && str[i] <= 90) {
			if (str[i] + 13 > 90) str[i] = str[i] + 13 - 26;
			else str[i] = str[i] + 13;
		}
		else if (97 <= str[i] && str[i] <= 122) {
			if (str[i] + 13 > 122) str[i] = str[i] + 13 - 26;
			else str[i] = str[i] + 13;
		}
		cout << str[i];
	}
	return 0;
}