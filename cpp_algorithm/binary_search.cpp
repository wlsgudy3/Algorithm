//반복문
int binarySearch(int arr[], int size, int key) {
	int low = 0; high = size - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	
	return -1;
}

//재귀호출
int binarySearch(int arr[], int low, int high, int key) {
	if (low > high) return -1;

	int mid = (low + high) / 2;

	if (arr[mid] == key)
		return mid;
	else if (arr[mid] > key)
		return binarySearch(arr, low, mid - 1, key);
	else
		return binarySearch(arr, mid + 1, high, key);
}