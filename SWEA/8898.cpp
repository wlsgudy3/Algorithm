#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int cow[500005];
int horse[500005];
int T, N, M, c1, c2;
int min_len, cnt;
int idx;

int dist(int x, int y) {
	int ret = x - y;
	if (ret < 0) return ret *= -1;
	return ret;
}

void search_dist(int hor) {

	int min_dist = 200000001;
	int temp_cnt = 0;
	for (int i = idx; i < N; i++) {
		int len = dist(hor, cow[i]);
		if (min_dist > len) {
			min_dist = len;
			idx = i;
			temp_cnt = 1;
		}
		else if (min_dist == len) {
			temp_cnt++;
		}
		else
			break;
	}
	if (min_len > min_dist) {
		min_len = min_dist;
		cnt = temp_cnt;
	}
	else if (min_len == min_dist) {
		cnt += temp_cnt;
	}
}

int main() {
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		scanf("%d %d", &N, &M);
		scanf("%d %d", &c1, &c2);
		for (int i = 0; i < N; i++) {
			scanf("%d", &cow[i]);
		}
		sort(cow, cow + N);
		for (int i = 0; i < M; i++) {
			scanf("%d", &horse[i]);
		}
		sort(horse, horse + M);
		min_len = 200000001;
		cnt = 0;
		idx = 0;
		for (int i = 0; i < M; i++) {
			search_dist(horse[i]);
		}
		int ret = min_len + dist(c1, c2);
		printf("#%d %d %d\n", TC, ret, cnt);
	}
}