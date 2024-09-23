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
#define endl "\n"
#pragma warning(disable:4996)
using namespace std;

struct Star {
	int x, y;
};

int N, M;
int L, K;
Star stars[100];

set<int> starXs, starYs;

int ans;

int countingStars(int x, int y) {
	int cnt = 0;
	
	for (int i = 0; i < K; i++) {
		if (x <= stars[i].x && stars[i].x <= x + L)
			if (y <= stars[i].y && stars[i].y <= y + L)
				cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> L >> K;

	for (int i = 0; i < K; i++) {
		cin >> stars[i].x >> stars[i].y;
		starXs.insert(stars[i].x);
		starYs.insert(stars[i].y);
	}

	for (int x : starXs)
		for (int y : starYs)
			ans = max(ans, countingStars(x, y));

	cout << K - ans;

	return 0;
}