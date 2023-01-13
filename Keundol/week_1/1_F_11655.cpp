#include <iostream>
#include <string>

using namespace std;

string str;
char low[52], upp[52];


int main() {
	getline(cin, str);

	for (int i = 0; i < 26; i++) {
		low[i] = 'a' + i;
		low[i + 26] = 'a' + i;
 		upp[i] = 'A' + i;
		upp[i + 26] = 'A' + i;
	}

	for (int i = 0; i < str.size(); i++) {
 		if ('a' <= str[i] && str[i] <= 'z') {
			str[i] = low[str[i] - 'a' + 13];
		}
		else if ('A' <= str[i] && str[i] <= 'Z') {
			str[i] = upp[str[i] - 'A' + 13];
		}
	}
	cout << str;
}