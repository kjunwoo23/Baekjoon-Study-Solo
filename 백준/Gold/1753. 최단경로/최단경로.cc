#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <climits>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
#include <list>
#include <set>
#include <map>
#pragma warning(disable:4996)
using namespace std;


int V;
int E;
int K;

vector<tuple<int, int>> edges[20001];
int dist[20001] = { 0 };

priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> waitList;

void BFS(int start) {

	waitList.emplace(0, start);
	dist[start] = 0;

	while (!waitList.empty()) {
		int curDist = get<0>(waitList.top());
		int curNode = get<1>(waitList.top());
		waitList.pop();

		for (int i = 0; i < edges[curNode].size(); i++) {
			if (dist[curNode] + get<0>(edges[curNode][i]) < dist[get<1>(edges[curNode][i])]) {
				dist[get<1>(edges[curNode][i])] = dist[curNode] + get<0>(edges[curNode][i]);
				waitList.emplace(dist[get<1>(edges[curNode][i])], get<1>(edges[curNode][i]));
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	scanf("%d%d%d", &V, &E, &K);
	//cin >> V >> E >> K;

	int tmp1, tmp2, tmp3;
	for (int i = 0; i < E; i++) {
		scanf("%d%d%d", &tmp1, &tmp2, &tmp3);

		edges[tmp1].emplace_back(tmp3, tmp2);
	}

	for (int i = 1; i < V + 1; i++)
		sort(edges[i].begin(), edges[i].end());

	fill(dist, dist + 20001, INT_MAX - 11);
	BFS(K);

	for (int i = 1; i < V + 1; i++)
		if (dist[i] != INT_MAX - 11)
			printf("%d\n", dist[i]);
		else
			printf("INF\n");

	return 0;
}