#include <iostream>

using namespace std;

int n, pos;
string pattern, str, pre, suf;

int main() {
	cin >> n;
	cin >> pattern;
	pos = pattern.find('*');

	pre = pattern.substr(0, pos);
	suf = pattern.substr(pos + 1);

	for (int i = 0; i < n; i++) {
		cin >> str;
		if (pre.size() + suf.size() > str.size())
			cout << "NE\n";
		else {
			if (pre == str.substr(0, pre.size()) && suf == str.substr(str.size() - suf.size())) cout << "DA\n";
			else cout << "NE\n";
		}
	}
	return 0;
}