#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <climits>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
#include <list>
#include <set>
#include <map>

#define endl "\n"
#pragma warning(disable:4996)
using namespace std;

int N, M;
int T[501][501];

void shorten() {
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				T[i][j] = min(T[i][j], T[i][k] + T[k][j]);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> T[i][j];

	shorten();

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (T[a][b] <= c) cout << "Enjoy other party" << endl;
		else cout << "Stay here" << endl;
	}

	return 0;
}