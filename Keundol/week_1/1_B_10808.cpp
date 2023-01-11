#include <iostream>

using namespace std;

int ret[30] = { 0 };
string a;

int main()
{
	cin >> a;

	for (int i = 0; i < a.length(); i++) {
		ret[a[i] - 'a'] += 1;
	}
	for (int i = 0; i < 'z' - 'a' + 1; i++) {
		cout << ret[i] << " ";
	}

	return 0;
}