#include <iostream>
#include <algorithm>

using namespace std;

int T;
string a, b;
int LSC[1001][1001];


int LongestCommonSequence(int a_size, int b_size){
	for (int i = 0; i <= a_size; i++)
		for (int j = 0; j <= b_size; j++)
			LSC[i][j] = 0;
	for (int i = 0; i <= a_size; i++) {
		for (int j = 0; j <= b_size; j++) {
			if (i == 0 || j == 0)
				LSC[i][j] = 0;
			else if (a[i - 1] == b[j - 1])
				LSC[i][j] = LSC[i - 1][j - 1] + 1;
			else
				LSC[i][j] = max(LSC[i][j - 1], LSC[i - 1][j]);
		}
	}
	return LSC[a_size][b_size];
}

int main() {
	cin >> T;
	int ret = 0;
	for (int tc = 1; tc <= T; tc++) {
		cin >> a >> b;
		ret = LongestCommonSequence(a.size(), b.size());
		cout << "#" << tc << ' ' << ret << '\n';
	}
	return 0;
}