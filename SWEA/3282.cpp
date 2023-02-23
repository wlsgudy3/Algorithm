#include <iostream>
#include <algorithm>

using namespace std;

int T, N, K;
int V[100], C[100], W[101][1001];

int knapsack() {
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= K; j++)
			W[i][j] = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (i == 0 || j == 0)
				W[i][j] = 0;
			else if (V[i -1] <= j ) {
				W[i][j] = max(C[i - 1] + W[i - 1][j - V[i - 1]], W[i - 1][j]);
			}
			else {
				W[i][j] = W[i - 1][j];
			}
		}
	}
	return W[N][K];
}

int main() {
	cin >> T;
	int ret = 0;
	for (int tc = 0; tc < T; tc++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> V[i] >> C[i];
		}
		ret = knapsack();
		cout << "#" << tc + 1 << ' ' << ret << '\n';
	}
}