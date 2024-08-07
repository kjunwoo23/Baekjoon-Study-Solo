#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
#include <list>
#include <set>
#include <map>
using namespace std;

int N;
int M, V;

vector<int> graph[1001];
bool visited[1001];

vector<int> dfs, bfs;

void DFS(int node) {
	if (visited[node]) return;
	else {
		visited[node] = true;
		dfs.emplace_back(node);
	}

	for (int i = 0; i < graph[node].size(); i++)
		DFS(graph[node][i]);
}

void BFS(int start) {
	queue<int> waitList;
	waitList.emplace(start);
	visited[start] = true;

	while (!waitList.empty()) {
		int curNode = waitList.front();
		waitList.pop();
		bfs.emplace_back(curNode);

		for (int i = 0; i < graph[curNode].size(); i++) {
			if (!visited[graph[curNode][i]]) {
				waitList.emplace(graph[curNode][i]);
				visited[graph[curNode][i]] = true;
			}
		}
	}
}


int main() {
	cin >> N >> M >> V;

	int first, second;
	for (int i = 0; i < M; i++) {
		cin >> first >> second;
		graph[first].emplace_back(second);
		graph[second].emplace_back(first);
	}
	for (int i = 0; i < N + 1; i++)
		sort(graph[i].begin(), graph[i].end());

	DFS(V);
	fill(visited, visited + N + 1, false);
	BFS(V);

	for (int i = 0; i < dfs.size(); i++)
		cout << dfs[i] << " ";
	
	cout << endl;

	for (int i = 0; i < bfs.size(); i++)
		cout << bfs[i] << " ";

	return 0;
}