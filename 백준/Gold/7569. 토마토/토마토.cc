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
int H;

int tomatoes[101][101][101];

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

queue<tuple<int, int, int>> waitList;
queue<tuple<int, int, int>> waitList2;

int day = -1;

void burningTomatoes() {
	while (!waitList.empty()) {
		int curX = get<0>(waitList.front());
		int curY = get<1>(waitList.front());
		int curZ = get<2>(waitList.front());

		waitList.pop();

		for (int i = 0; i < 6; i++) {
			if (1 <= curY + dy[i] && curY + dy[i] <= N
				&& 1 <= curX + dx[i] && curX + dx[i] <= M
				&& 1 <= curZ + dz[i] && curZ + dz[i] <= H)
				if (tomatoes[curZ + dz[i]][curY + dy[i]][curX + dx[i]] == 0) {
					waitList2.emplace(curX + dx[i], curY + dy[i], curZ + dz[i]);
					tomatoes[curZ + dz[i]][curY + dy[i]][curX + dx[i]] = 1;
				}
		}
	}

	waitList = waitList2;
	waitList2 = queue<tuple<int, int, int>>();
	day++;
}

bool testTomatoes() {
	for (int k = 1; k < H + 1; k++)
		for (int i = 1; i < N + 1; i++)
			for (int j = 1; j < M + 1; j++)
				if (tomatoes[k][i][j] == 0)
					return false;
	return true;
}


int main() {
	int ans = 0;

	cin >> M >> N >> H;

	fill(&tomatoes[0][0][0], &tomatoes[100][100][101], -1);

	for (int k = 1; k < H + 1; k++)
		for (int i = 1; i < N + 1; i++)
			for (int j = 1; j < M + 1; j++) {
				cin >> tomatoes[k][i][j];
				if (tomatoes[k][i][j] == 1)
					waitList.emplace(j, i, k);
			}

	while (!waitList.empty())
		burningTomatoes();

	if (testTomatoes())
		cout << day;
	else
		cout << -1;

	return 0;
}