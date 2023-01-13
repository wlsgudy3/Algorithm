#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str, pattern, a, b, temp;
int n, star;

int main() {
	cin >> n;
	cin >> pattern;
	for (int i = 0; i < pattern.size(); i++) {
		if (pattern[i] == '*') {
			star = i;
			break;
		}
	}
	a = pattern.substr(0, star);
	b = pattern.substr(star + 1);

	for (int i = 0; i < n; i++) {
		cin >> str;
		temp = str.substr(0, a.size());
		if (str.size() < a.size() + b.size()) {
			cout << "NE" << "\n";
			continue;
		}
		if (temp != a) { 
			cout << "NE" << "\n";
			continue;
		}
		temp = str.substr(str.size() - b.size());
		if (temp != b) {
			cout << "NE" << "\n";
			continue;
		}
		cout << "DA" << "\n";
	}
	return 0;
}