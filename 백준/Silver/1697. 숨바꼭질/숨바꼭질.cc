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
int K;
int dist[200001];


void BFS(int start) {
	queue<int> waitList;
	waitList.emplace(start);
	dist[start] = 0;

	while (!waitList.empty()) {
		int curPos = waitList.front();
		waitList.pop();

		if (curPos - 1 >= 0 && dist[curPos] + 1 < dist[curPos - 1]) {
			waitList.emplace(curPos - 1);
			dist[curPos - 1] = dist[curPos] + 1;
		}
		if (curPos + 1 <= 200000 && dist[curPos] + 1 < dist[curPos + 1]) {
			waitList.emplace(curPos + 1);
			dist[curPos + 1] = dist[curPos] + 1;
		}
		if (curPos * 2 <= 200000 && dist[curPos] + 1 < dist[curPos * 2]) {
			waitList.emplace(curPos * 2);
			dist[curPos * 2] = dist[curPos] + 1;
		}
	}
}

int main() {
	int ans = 0;

	fill(dist, dist + 200000, 200000);

	cin >> N >> K;
	
	BFS(N);

	cout << dist[K];

	return 0;
}