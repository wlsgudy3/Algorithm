//반복문
void quickSort(int arr[], int left, int right) {
	if (left < right) {
		int p = left, i = left + 1, j = right;
		while (i <= j) {
			while (arr[i] <= arr[p]) i++;
			while (arr[j] > arr[p]) j--;

			if (i < j) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		int tmp = arr[p];
		arr[p] = arr[j];
		arr[j] = tmp;

		quickSort(arr, left, j - 1);
		quickSort(arr, j + 1, right);
	}
}

//재귀
#include <algorithm>
#include <random>

constexpr size_t MAX_N = 1e6;

int a[MAX_N];
std::mt19937 engine(std:random_devicee{}());
std::uniform_int_distribution<ptrdiff_t> generator(0, PTRDIFF_MAX);

int* partition(int* begin, int* end) {
	std::iter_swap(begin + generator(engine) % (end - begin), end - 1);
	const int pivot = *--end;
	int* i = begin;
	while (begin != end) {
		if (*begin < pivot) {
			std::iter_swap(i++, begin);
		}
		++begin;
	}
	return i;
}

void quick_sort(int* const begin, int* const end) {
	if (end - begin <= 1) return;
	int* const mid = partition(begin, end);
	quick_sort(begin, mid);
	quick_sort(mid, end);
}