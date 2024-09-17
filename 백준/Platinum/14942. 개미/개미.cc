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

int N;

int antPower[100001];

vector<tuple<int, int>> edges[100001];

tuple<int, int> antPath[100001];
bool visited[100001];

tuple<int, int> memo[100001];

void DFS(int node) {
	visited[node] = true;

	for (int i = 0; i < edges[node].size(); i++)
		if (visited[get<0>(edges[node][i])]) continue;
		else {
			antPath[get<0>(edges[node][i])] = tuple<int, int>(node, get<1>(edges[node][i]));
			DFS(get<0>(edges[node][i]));
		}
}

int MoveAnt(int i) {
	int curRoom = i;
	int losedPower = 0;
	while (antPower[i] - get<1>(antPath[curRoom]) >= 0) {
		if (curRoom == 1) break;
		if (get<0>(memo[i]) != 0)
			if (get<1>(memo[i]) <= antPower[i]) {
				antPower[i] -= get<1>(memo[i]);
				losedPower += get<1>(memo[i]);
				curRoom = get<0>(memo[i]);
				continue;
			}
		antPower[i] -= get<1>(antPath[curRoom]);
		losedPower += get<1>(antPath[curRoom]);
		curRoom = get<0>(antPath[curRoom]);
	}
	memo[i] = tuple<int, int>(curRoom, losedPower);
	return curRoom;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 1; i < N + 1; i++) {
		cin >> antPower[i];
	}

	int room1, room2, roomGap;
	for (int i = 0; i < N - 1; i++) {

		cin >> room1 >> room2 >> roomGap;
		edges[room1].emplace_back(room2, roomGap);
		edges[room2].emplace_back(room1, roomGap);
	}

	DFS(1);

	for (int i = 1; i < N + 1; i++)
		cout << MoveAnt(i) << "\n";

	return 0;
}