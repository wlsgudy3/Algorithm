#include <iostream>
#include <algorithm>

using namespace std;

class MaxHeap {
#define parent (i >> 1)
#define left (i << 1)
#define right (i << 1 | 1)
	
	static constexpr size_t MAX_N = 10000;

	int data[MAX_N];
	size_t size;

public:
	MaxHeap() = default;

	void push(int x) {
		data[++size] = x;
		for (int i = size; parent != 0 && data[parent] < data[i]; i >>= 1) {
			swap(data[parent], data[i]);
		}
	}

	int top() const {
		return data[1];
	}

	void pop() {
		data[1] = data[size--];
		for (size_t i = 1; left <= size;) {
			if (left == size || data[left] > data[right]) {
				if (data[i] < data[left]) {
					swap(data[left], data[i]);
					i = left;
				}
				else
					break;
			}
			else {
				if (data[i] < data[right]) {
					swap(data[i], data[right]);
					i = right;
				}
				else
					break;
			}
		}
	}

#undef parent
#undef left
#undef right
};

