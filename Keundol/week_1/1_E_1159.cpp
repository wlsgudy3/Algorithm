#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> mp;
string str;
int num, check;
char temp;

int main() {
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> str;
		temp = str[0];
		if (mp[temp] == 0) {
			mp[temp] = 1;
		}
		else {
			mp[temp]++;
		}
	}

	for (auto a : mp) {
		if (a.second >= 5) {
			cout << a.first;
			check = 1;
		}
	}
	if (check == 0) 
		cout << "PREDAJA";
}