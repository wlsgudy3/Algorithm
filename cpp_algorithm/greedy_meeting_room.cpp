#include <iostream>

using namespace std;

struct meeting {
	int start;
	int end;
};

int N;
meeting Meetings[10];

int solve() {
	for (int i = 0; i < N - 1; i++) { // sort
		for (int j = i + 1; j < N; j++)
			if (Meetings[i].end > Meetings[j].end) {
				meeting temp = Meetings[i];
				Meetings[i] = Meetings[j];
				Meetings[j] = temp;
			}
	}
	int last_time = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (Meetings[i].start < last_time) continue;
		last_time = Meetings[i].end;
		cnt++;
	}
	return cnt;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Meetings[i].start >> Meetings[i].end;
	}

	cout << solve() << '\n';

	return 0;
}