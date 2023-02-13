#include <iostream>

using namespace std;

int TC, N, num;

int main() {
	cin >> TC;
	for (int i = 0; i < TC; i++) {
		cin >> N >> num;
		if ((((1 << N) - 1) & num) == ((1 << N) - 1) ) cout << "#" << i+1 << " ON\n";
		else cout << "#" << i+1 << " OFF\n";
	}
	return 0;
}