#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	vector<int> v;
	pair <int, int> ret;
	int a[9] = {0};
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - a[i] - a[j] == 100)
				ret = { i, j };
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (ret.first == i || ret.second == i) continue;
		v.push_back(a[i]);
	}

	sort(v.begin(), v.end());
	for (int a : v) cout << a << '\n';

	return 0;
}