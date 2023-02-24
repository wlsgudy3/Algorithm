#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define parent (i >> 1)
#define left (i << 1)
#define right (i << 1 | 1)

static constexpr size_t MAX_N = 200005;
int maxHeap[MAX_N];
int minHeap[MAX_N];
size_t max_cnt;
size_t min_cnt;

void init() {
	max_cnt = 0;
	min_cnt = 0;
}

void add_max(int x) {
	maxHeap[++max_cnt] = x;
	for (size_t i = max_cnt; parent != 0 && maxHeap[parent] < maxHeap[i]; i >>= 1) {
		swap(maxHeap[parent], maxHeap[i]);
	}
}

void add_min(int x) {
	minHeap[++min_cnt] = x;
	for (size_t i = min_cnt; parent != 0 && minHeap[parent] > minHeap[i]; i >>= 1) {
		swap(minHeap[parent], minHeap[i]);
	}
}

int pop_max() {
	int top = maxHeap[1];
	maxHeap[1] = maxHeap[max_cnt--];
	for (size_t i = 1; left <= max_cnt;) {
		if (left == max_cnt || maxHeap[left] > maxHeap[right]) {
			if (maxHeap[i] < maxHeap[left]) {
				swap(maxHeap[left], maxHeap[i]);
				i = left;
			}
			else
				break;
		}
		else {
			if (maxHeap[i] < maxHeap[right]) {
				swap(maxHeap[i], maxHeap[right]);
				i = right;
			}
			else
				break;
		}
	}
	return top;
}

int pop_min() {
	int top = minHeap[1];
	minHeap[1] = minHeap[min_cnt--];
	for (size_t i = 1; left <= min_cnt;) {
		if (left == min_cnt || minHeap[left] < minHeap[right]) {
			if (minHeap[i] > minHeap[left]) {
				swap(minHeap[left], minHeap[i]);
				i = left;
			}
			else
				break;
		}
		else {
			if (minHeap[i] > minHeap[right]) {
				swap(minHeap[i], minHeap[right]);
				i = right;
			}
			else
				break;
		}
	}
	return top;
}

#undef parent
#undef left
#undef right

int T, N, first_num;

int main() {
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int ret = 0;
		init();
		cin >> N >> first_num;
		add_max(first_num);
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			if (a > maxHeap[1]) add_min(a);
			else add_max(a);
			if (b > maxHeap[1]) add_min(b);
			else add_max(b);
			if (max_cnt < min_cnt) add_max(pop_min());
			else if (max_cnt - 1 > min_cnt) add_min(pop_max());
			ret += maxHeap[1];
			if (ret >= 20171109) ret %= 20171109;
		}

		cout << "#" << TC << ' ' << ret << '\n';
	}
}
