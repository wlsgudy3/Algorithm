#include <iostream>
#include <string.h>

using namespace std;

long long ret;
int T;
string manager;
int today[4] = { 1, 2, 4, 8 };
long long memo[10000][16];
const int MOD = 1000000007;

long long f(int d, int state);

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		ret = 0;
		cin >> manager;
		memset(memo, -1, sizeof(memo));
		for (int j = 1; j <= 15; j++) {
			ret += f(manager.size(), j) % MOD;
		}
		cout << "#" << i << " " << ret % MOD << '\n';
	}
	return 0;
}

long long f(int d, int state) {
	long long  ret = 0;
	if (d == 0) {
		if (state == 1) return memo[d][1] = 1;
		return memo[d][state] = 0;
	} // 초기값 f(0,1)
	if (((today[manager[d - 1] - 'A']) & state) == 0) {
		return memo[d][state] = 0;
	} //당일 담당자 확인
	if (memo[d][state] != -1)
		return memo[d][state];
	else {
		for (int i = 1; i <= 15; i++) {
			if ((i & state) != 0) {
				ret += f(d - 1, i) % MOD;
			}
		}
		return memo[d][state] = ret % MOD;
	}
}