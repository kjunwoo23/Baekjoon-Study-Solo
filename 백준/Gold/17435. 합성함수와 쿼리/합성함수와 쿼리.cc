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

//희소 배열
int m;
int Q;
int memo[20][500001];

void fillMemo() {
	for (int logN = 1; logN <= 19; logN++) {
		for (int i = 1; i < m + 1; i++) {
			int tmp = memo[logN - 1][i];
			memo[logN][i] = memo[logN - 1][tmp];
		}
	}
}

int find(int n, int x) {
	int cur = x;

	for (int i = 19; i >= 0; i--) {
		if (n & (1 << i))
			cur = memo[i][cur];
	}
	return cur;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> m;
	for (int i = 1; i < m + 1; i++)
		cin >> memo[0][i];

	fillMemo();

	cin >> Q;

	for (int i = 0; i < Q; i++) {
		int n, x;
		cin >> n >> x;
		cout << find(n, x) << "\n";
	}

	return 0;
}