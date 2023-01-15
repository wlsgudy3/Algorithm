#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001], psum[100001], n;

int main() {
	int max, min;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] == 1) {
			psum[i] = psum[i - 1] + 1;
		}
		else if (arr[i] == 2) {
			psum[i] = psum[i - 1] - 1;
		}
	}

	max = *max_element(psum, psum + n + 1);
	min = *min_element(psum, psum + n + 1);

	cout << max - min;
}