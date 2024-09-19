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

// 1번 방에서 출발, 모든 방 탐색
void DFS(int node) {
	visited[node] = true;

	for (int i = 0; i < edges[node].size(); i++)
		if (visited[get<0>(edges[node][i])]) continue;
		else {
			// 새로운 방 찾을 때마다 (새로운 방, 방까지의 거리) 쌍 저장
			antPath[get<0>(edges[node][i])] = tuple<int, int>(node, get<1>(edges[node][i]));
			DFS(get<0>(edges[node][i]));
		}
}

// i번째 개미의 모험
int MoveAnt(int i) {
	int curRoom = i;
	int losedPower = 0;
	while (antPower[i] - get<1>(antPath[curRoom]) >= 0) {
		if (curRoom == 1) break;
		//전에 죽은 개미가 남긴 메모가 있는지 확인
		if (get<0>(memo[i]) != 0)
			if (get<1>(memo[i]) <= antPower[i]) {
				antPower[i] -= get<1>(memo[i]);
				losedPower += get<1>(memo[i]);
				curRoom = get<0>(memo[i]);
				continue;
			}
		// 다음 방으로 이동할 때는 DFS에서 찾아둔 경로대로 이동
		antPower[i] -= get<1>(antPath[curRoom]);
		losedPower += get<1>(antPath[curRoom]);
		curRoom = get<0>(antPath[curRoom]);
	}
	// 개미가 죽을 때마다 메모를 남김 (출발한 방, 도착한 방, 총 소요 힘)
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
		//"\n"!!!!!!!!!!!!!!!
		cout << MoveAnt(i) << "\n";

	return 0;
}