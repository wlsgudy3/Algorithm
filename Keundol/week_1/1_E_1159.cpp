#include <iostream>

using namespace std;

string str, ret;
int n, cnt[26];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		cnt[str[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++) if (cnt[i] >= 5) ret += (i + 'a');
	if (ret.size()) cout << ret;
	else cout << "PREDAJA";
}