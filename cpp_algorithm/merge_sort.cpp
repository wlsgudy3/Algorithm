void mergeSort(int arr[], int size) { //반복문
	if (size == 1) return;
	
	int mid = size / 2;
	mergeSort(arr, mid);
	mergeSort(arr + mid, size - mid);

	int* buf = new int[size];
	int i = 0, j = mid, k = 0;
	while (i < mid && j < size) {
		buf[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	}
	while (i < mid) {
		buf[k++] = arr[i++];
	}
	while (j < size) {
		buf[k++] = arr[j++];
	}

	for (i = 0; i < size; i++) {
		arr[i] = buf[i];
	}
	
	delete buf;
}


// 재귀(recursive)

#include <cstring>

constexpr size_t MAX_N = 100000;

int a[MAX_N], buffer[MAX_N];

void merge(int* const begin, int* const mid, int* const end) {
	int* begin1 = begin, * end1 = mid;
	int* begin2 = mid, * end2 = end;
	int* result = buffer;
	while (begin1 != end1 && begin2 != end2) {
		*result++ = *begin1 < *begin2 ? *begin1++ : *begin2++;
	}
	while (begin1 != end1) *result++ = *begin1++;
	while (begin2 != end2) *result++ = *begin2++;
	std::memcpy(begin, buffer, sizeof(int) * (end - begin));
}

void merge_sort(int* const begin, int* const end) {
	if (end - begin <= 1) return;
	int* const mid = begin + (end - begin) / 2;
	merge_sort(begin, mid);
	merge_sort(mid, end);
	merge(begin, mid, end);
}