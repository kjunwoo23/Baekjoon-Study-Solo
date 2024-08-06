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
int M;
int originMatrix[50][50];
int curMatrix[50][50];
int destMatrix[50][50];

void flip01(int i, int j) {
	for (int ii = -1; ii < 2; ii++)
		for (int jj = -1; jj < 2; jj++)
			curMatrix[i + ii][j + jj] = 1 - curMatrix[i + ii][j + jj];
}

bool compareMatrix() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (curMatrix[i][j] != destMatrix[i][j])
				return false;
	return true;
}

int main() {
	int ans = 0;
	char tmp;

	cin >> N >> M;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			originMatrix[i][j] = tmp - '0';
			curMatrix[i][j] = originMatrix[i][j];
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			destMatrix[i][j] = tmp - '0';
		}

	if (N >= 3 && M >= 3)
		for (int i = 1; i < N - 1; i++)
			for (int j = 1; j < M - 1; j++)
				if (curMatrix[i - 1][j - 1] != destMatrix[i - 1][j - 1]) {
					flip01(i, j);
					ans++;
				}

	if (compareMatrix())
		cout << ans;
	else
		cout << -1;

	return 0;
}