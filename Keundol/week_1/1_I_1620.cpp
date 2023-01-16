//시간 오버, 실패

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m, num;
string temp;
string poketmon[100000];

int str_to_int(string str) {
	int len = str.size();
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += int(str[i] - '0')* pow(10, (len - i - 1));
	}
	return sum;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> poketmon[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		if ('0' < temp[0] && temp[0] <= '9') { //숫자
			num = str_to_int(temp); 
			cout << poketmon[num - 1] << '\n';
		}
		else if (65 <= temp[0] && temp[0] <= 122) {
			int j = 0;
			while (poketmon[j] != temp) {
				j++;
			}
			cout << j + 1 << '\n';
		}
	}
	return 0;
}