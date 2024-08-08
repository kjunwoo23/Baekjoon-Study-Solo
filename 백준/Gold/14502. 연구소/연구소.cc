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

int rooms[9][9];
int sampleRooms[9][9];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

queue<tuple<int, int>> waitList;
queue<tuple<int, int>> waitList2;
queue<tuple<int, int>> waitListOrigin;
vector<tuple<int, int>> zeroList;

int curRoomLeft;
int maxRoomLeft;

void spreadVirus() {
	while (!waitList.empty()) {
		int curX = get<0>(waitList.front());
		int curY = get<1>(waitList.front());

		waitList.pop();

		for (int i = 0; i < 4; i++) {
			if (1 <= curY + dy[i] && curY + dy[i] <= N
				&& 1 <= curX + dx[i] && curX + dx[i] <= M)
				if (sampleRooms[curY + dy[i]][curX + dx[i]] == 0) {
					waitList2.emplace(curX + dx[i], curY + dy[i]);
					sampleRooms[curY + dy[i]][curX + dx[i]] = 2;
					curRoomLeft--;
				}
		}
	}

	waitList = waitList2;
	waitList2 = queue<tuple<int, int>>();
}

int main() {
	int ans = 0;

	cin >> N >> M;

	fill(&rooms[0][0], &rooms[8][9], 1);

	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++) {
			cin >> rooms[i][j];
			if (rooms[i][j] == 0) {
				zeroList.emplace_back(i, j);
			}
			else if (rooms[i][j] == 2)
				waitListOrigin.emplace(j, i);
		}

	for (int i = 0; i < zeroList.size() - 2; i++)
		for (int j = i + 1; j < zeroList.size() - 1; j++)
			for (int k = j + 1; k < zeroList.size(); k++) {
				waitList = waitListOrigin;
				curRoomLeft = zeroList.size() - 3;
				copy(&rooms[0][0], &rooms[8][8] + 1, &sampleRooms[0][0]);
				sampleRooms[get<0>(zeroList[i])][get<1>(zeroList[i])] = 1;
				sampleRooms[get<0>(zeroList[j])][get<1>(zeroList[j])] = 1;
				sampleRooms[get<0>(zeroList[k])][get<1>(zeroList[k])] = 1;

				while (!waitList.empty())
					spreadVirus();
				maxRoomLeft = max(maxRoomLeft, curRoomLeft);
			}


	cout << maxRoomLeft;

	return 0;
}