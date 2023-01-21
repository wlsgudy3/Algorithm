#include <iostream>

using namespace std;

const int MAX_N = 100;
int Graph[MAX_N][MAX_N], N, E, curr;
bool visited[MAX_N];
int Queue[20], front, rear;

void BFS(int node) {
	front = rear = -1;
	Queue[++rear] = node;
	visited[node] = true;
	while (front != rear) {
		curr = Queue[++front];
		cout << curr << ' ';
		for (int next = 0; next < N; next++) {
			if (!visited[next] && Graph[curr][next]) {
				visited[next] = true;
				Queue[++rear] = next;
			}
		}
	}
}

int main() {
	cin >> N >> E; // N은 정점의 개수, E는 간선의 개수이고 두 정점의 나열로 간선을 표시한다.

	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		Graph[a][b] = Graph[b][a] = 1;
	}
	BFS(0);
	return 0;

}