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
using namespace std;

int N;
int M;

vector<int> graph[1001];
bool visited[1001];
int totalVisited;


void BFS(int start) {
	queue<int> waitList;
	waitList.emplace(start);
	visited[start] = true;
	totalVisited++;

	while (!waitList.empty()) {
		int curNode = waitList.front();
		waitList.pop();

		for (int i = 0; i < graph[curNode].size(); i++) {
			if (!visited[graph[curNode][i]]) {
				visited[graph[curNode][i]] = true;
				totalVisited++;
				waitList.emplace(graph[curNode][i]);
			}
		}
	}
}

int main() {
	int ans = 0;

	cin >> N >> M;
	
	int first, second;
	for (int i = 0; i < M; i++) {
		cin >> first >> second;
		graph[first].emplace_back(second);
		graph[second].emplace_back(first);
	}

	int start = 1;
	while (totalVisited < N) {
		BFS(start);
		ans++;
		while (visited[start]) start++;
	}

	cout << ans;

	return 0;
}