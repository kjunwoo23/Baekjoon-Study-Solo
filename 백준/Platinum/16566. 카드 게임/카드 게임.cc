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

int N, M, K;

vector<int> minsoo;
int parent[4000001];
int tmp;

// 부모 찾기
int FindParent(int x) {
	if (parent[x] == x)
		return x;

	return parent[x] = FindParent(parent[x]);
}

// 이미 선택된 숫자는 바롣 다음 숫자랑 부모 합치기
void UnionParent(int x, int y) {
	x = FindParent(x);
	y = FindParent(y);
	if (x != y)
		if (x > y) parent[y] = x;
		else parent[x] = y;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		minsoo.emplace_back(tmp);
		parent[i] = i;
	}
	sort(minsoo.begin(), minsoo.end());

	for (int i = 0; i < K; i++) {
		cin >> tmp;
		// 이분 탐색
		int idx = upper_bound(minsoo.begin(), minsoo.end(), tmp) - minsoo.begin();
		int f = FindParent(idx);
		cout << minsoo[f] << endl;
		UnionParent(f, f + 1);
	}

	return 0;
}