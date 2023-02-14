#include <iostream>

using namespace std;

int T, ret, num, check;

void check_bit(int a) {
	int temp = 0;
	if ((1023 & ret) == 1023)
		check = 0;
	if (a > 0) {
		temp = a % 10;
		ret = ret | (1 << temp);
		check_bit(a / 10);
	}
	else return;
}

int main() {
	int j;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> num;
		ret = 0; check = 1; j = 0;
		while (check) {
			j++;
			check_bit(num * j);
		}
		cout << "#" << i + 1 << " " << num * j << '\n';
	}
	return 0;
}