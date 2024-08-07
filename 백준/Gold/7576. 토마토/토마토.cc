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

int tomatoes[1001][1001];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

queue<tuple<int, int>> waitList;
queue<tuple<int, int>> waitList2;

int day = -1;

void burningTomatoes() {
	while (!waitList.empty()) {
		int curX = get<0>(waitList.front());
		int curY = get<1>(waitList.front());

		waitList.pop();

		for (int i = 0; i < 4; i++) {
			if (1 <= curY + dy[i] && curY + dy[i] <= N
				&& 1 <= curX + dx[i] && curX + dx[i] <= M)
				if (tomatoes[curY + dy[i]][curX + dx[i]] == 0) {
					waitList2.emplace(curX + dx[i], curY + dy[i]);
					tomatoes[curY + dy[i]][curX + dx[i]] = 1;
				}
		}
	}

	waitList = waitList2;
	waitList2 = queue<tuple<int, int>>();
	day++;
}

bool testTomatoes() {
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++)
			if (tomatoes[i][j] == 0)
				return false;
	return true;
}


int main() {
	int ans = 0;

	cin >> M >> N;

	fill(&tomatoes[0][0], &tomatoes[100][101], -1);

	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++) {
			cin >> tomatoes[i][j];
			if (tomatoes[i][j] == 1)
				waitList.emplace(j, i);
		}

	while (!waitList.empty())
		burningTomatoes();

	if (testTomatoes())
		cout << day;
	else
		cout << -1;

	return 0;
}