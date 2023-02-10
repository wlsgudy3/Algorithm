#include <stdio.h>

#define INF (987654321)

const int MAX_N = 6;

int graph[MAX_N][MAX_N] = {
	{0,2,5,1,INF,INF},
	{2,0,3,2,INF,INF},
	{5,3,0,3,1,5},
	{1,2,3,0,1,INF},
	{INF,INF,1,1,0,2},
	{INF,INF,5,INF,2,0}
};

int getMinIdx(int nodes[MAX_N], int visited[MAX_N]) {
	int min = -1;
	for (int i = 0; i < MAX_N; i++) {
		if (visited[i]) continue;
		if (min < 0 || nodes[min] > nodes[i]) min = i;
	}

	return min;
}

void dijkstra2(int arr[MAX_N][MAX_N], int start, int dist[MAX_N]) {
	int visited[MAX_N] = { 0, };
	for (int i = 0; i < MAX_N; i++) {
		dist[i] = arr[start][i];
	}

	visited[start] = 1;

	for (int i = 0; i < MAX_N; i++) {
		int n_new = getMinIdx(dist, visited);
		visited[n_new] = 1;
		for (int j = 0; j < MAX_N; j++) {
			if (visited[j]) continue;
			if (dist[j] > dist[n_new] + arr[n_new][j])
				dist[j] = dist[n_new] + arr[n_new][j];
		}
	}
}

int main() {
	int dist[MAX_N];
	int start = 0;
	dijkstra2(graph, start, dist);
	for (int i = 0; i < MAX_N; i++) {
		printf("%d->%d : %d\n", start, i, dist[i]);
	}

	printf("\n");
	return 0;
}


//우선순위 큐
#include <iostream>
#include <queue>

using namespace std;

const int INF(987654321);
const int MAX_N = 6;

int graph[MAX_N][MAX_N] = {
	{0,2,5,1,INF,INF},
	{2,0,3,2,INF,INF},
	{5,3,0,3,1,5},
	{1,2,3,0,1,INF},
	{INF,INF,1,1,0,2},
	{INF,INF,5,INF,2,0}
};

void dijkstra(int arr[MAX_N][MAX_N], int start, int dist[MAX_N]) {
	priority_queue<pair <int, int>> pq;

	for (int i = 0; i < MAX_N; i++) {
		dist[i] = INF;
	}

	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		for (int i = 0; i < MAX_N; i++) {
			int nxt_dist = cur_dist + arr[cur_node][i];

			if (nxt_dist < dist[i]) {
				dist[i] = nxt_dist;
				pq.push({ -nxt_dist, i });
			}
		}
	}
}