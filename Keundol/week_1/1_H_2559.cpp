#include <iostream>

using namespace std;

int n, k, arr[100001], psum[100001];

int main() {
	cin >> n >> k;
	for (int i = 1; i < n + 1; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	int max, temp;
	max = psum[k];
	for (int i = 1; i + k - 1 < n + 1; i++) {
		temp = psum[i + k - 1] - psum[i - 1];
		if (max < temp)
			max = temp;
	}
	cout << max;
    return 0;
}