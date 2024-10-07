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
int candy[30001];
int memo[3001];
int parent[30001];

struct kidsAndCandies {
	int kids;
	int candies;
};

kidsAndCandies groupedCandies[30001];

// 부모 찾기
int FindParent(int x) {
	if (parent[x] == x)
		return x;

	return parent[x] = FindParent(parent[x]);
}

// 이미 선택된 숫자는 바로 다음 숫자랑 부모 합치기
void UnionParent(int x, int y) {
	x = FindParent(x);
	y = FindParent(y);
	if (x != y)
		if (x > y) parent[y] = x;
		else parent[x] = y;
}

void groupFriends() {
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		//int f = FindParent(a);
		UnionParent(a, b);
	}
}

void sumCandies() {
	for (int i = 1; i <= N; i++) {
		int f = FindParent(i);
		groupedCandies[f].kids++;
		groupedCandies[f].candies += candy[i];
	}
}

// 냅색
void chooseBetterPrice() {
	for (int i = 1; i <= N; ++i)
		for (int j = K; j >= 1; --j)
			if (j - groupedCandies[i].kids > 0)
				memo[j] = max(memo[j], memo[j - groupedCandies[i].kids] + groupedCandies[i].candies);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> candy[i];
		parent[i] = i;
	}

	groupFriends();

	sumCandies();

	chooseBetterPrice();

	cout << memo[K];

	return 0;
}