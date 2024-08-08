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

char arrRGB[100][100];
char arrRB[100][100];

queue<tuple<int, int>> waitList;

bool visitedRGB[100][100], visitedRB[100][100];
int visitCntRGB, visitCntRB;
int sectionRGB, sectionRB;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void BFS_RGB(int pos) {
	int x = pos % N;
	int y = pos / N;

	if (visitedRGB[y][x]) return;

	waitList.emplace(x, y);
	visitedRGB[y][x] = true;
	visitCntRGB++;

	while (!waitList.empty()) {
		int curX = get<0>(waitList.front());
		int curY = get<1>(waitList.front());
		char curColor = arrRGB[curY][curX];
		waitList.pop();

		for (int i = 0; i < 4; i++) {
			if (0 <= curX + dx[i] && curX + dx[i] <= N - 1
				&& 0 <= curY + dy[i] && curY + dy[i] <= N - 1) 
				if (!visitedRGB[curY + dy[i]][curX + dx[i]])
					if (arrRGB[curY][curX] == arrRGB[curY + dy[i]][curX + dx[i]]) {
						visitedRGB[curY + dy[i]][curX + dx[i]] = true;
						waitList.emplace(curX + dx[i], curY + dy[i]);
						visitCntRGB++;
					}
		}
	}
	sectionRGB++;
}

void BFS_RB(int pos) {
	int x = pos % N;
	int y = pos / N;

	if (visitedRB[y][x]) return;

	waitList.emplace(x, y);
	visitedRB[y][x] = true;
	visitCntRB++;

	while (!waitList.empty()) {
		int curX = get<0>(waitList.front());
		int curY = get<1>(waitList.front());
		char curColor = arrRB[curY][curX];
		waitList.pop();

		for (int i = 0; i < 4; i++) {
			if (0 <= curX + dx[i] && curX + dx[i] <= N - 1
				&& 0 <= curY + dy[i] && curY + dy[i] <= N - 1)
				if (!visitedRB[curY + dy[i]][curX + dx[i]])
					if (arrRB[curY][curX] == arrRB[curY + dy[i]][curX + dx[i]]) {
						visitedRB[curY + dy[i]][curX + dx[i]] = true;
						waitList.emplace(curX + dx[i], curY + dy[i]);
						visitCntRB++;
					}
		}
	}
	sectionRB++;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	char tmp;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
		cin >> tmp;
		arrRGB[i][j] = tmp;
		if (tmp == 'G') tmp = 'R';
		arrRB[i][j] = tmp;
	}

	int pos = 0;
	while (visitCntRGB < N * N) {
		BFS_RGB(pos);
		pos++;
	}

	pos = 0;
	while (visitCntRB < N * N) {
		BFS_RB(pos);
		pos++;
	}

	cout << sectionRGB << " " << sectionRB;

	return 0;
}