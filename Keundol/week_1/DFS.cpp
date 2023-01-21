#include <iostream>

using namespace std;

const int MAX_N = 10;
int E, N, Graph[MAX_N][MAX_N], curr, top;
int Stack[20] = { 0 };

void dfs(int node) {
	bool visited[MAX_N] = { false };
	top = -1;
	Stack[++top] = node;
	while (top != -1) {
		curr = Stack[top--];
		if (visited[curr] == false) {
			visited[curr] = true;
			cout << curr << ' ';
			for (int next = 0; next < N; next++) {
				if (!visited[next] && Graph[curr][next])
					Stack[++top] = next;
			}
		}
	}

}

int main() {
	cin >> N >> E;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Graph[i][j] = 0;
		}
	}
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		Graph[a][b] = Graph[b][a] = 1;
	}
	dfs(0);
	return 0;
}