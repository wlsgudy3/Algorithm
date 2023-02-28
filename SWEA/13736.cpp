#include <iostream>

using namespace std;

int T, A, B, K, sum;

long long power_2(int k) {
	if (k == 0) return 1;
	if (k == 1) return 2;

	if (k % 2 == 0) {
		long long ret = power_2(k / 2) % sum;
		return (ret * ret);
	}
	else {
		long long ret = power_2((k - 1) / 2) % sum;
		return (ret * ret * 2);
	}
}

int main() {
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		cin >> A >> B >> K;
		long long x, y;
		sum = A + B;
		if (A > B) {
			x = ((power_2(K) % sum) * B) % sum;
		}
		else {
			x = ((power_2(K) % sum) * A) % sum;
		}
		y = sum - x;
		if(x < y)
			cout << "#" << TC << ' ' << x << '\n';
		else
			cout << "#" << TC << ' ' << y << '\n';

	}
}