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
int L;

priority_queue<int, vector<int>, greater<int>> pos;

int main() {
	int ans = 0;

	cin >> N >> L;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		pos.emplace(tmp);
	}

	int start = 0;
	while (!pos.empty()) {
		start = pos.top();
		ans++;
		while (!pos.empty() && pos.top() < start + L)
			pos.pop();
	}

	cout << ans;

	return 0;
}