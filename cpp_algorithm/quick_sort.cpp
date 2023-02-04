
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