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
using namespace std;


int N;
priority_queue<int> positive;
priority_queue<int, vector<int>, greater<int>> negative;


int main() {
	long long ans = 0;

	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp > 0)
			positive.emplace(tmp);
		else
			negative.emplace(tmp);
	}

	int top1, top2, top3;
	priority_queue<tuple<int, int>> tmps;

	while (!positive.empty()) {
		top1 = positive.top();
		positive.pop();
		if (positive.empty()) {
			ans += top1;
			break;
		}

		top2 = positive.top();
		positive.pop();
		if (positive.empty()) {
			if (top1 * top2 > top1 + top2)
				ans += top1 * top2;
			else
				ans += top1 + top2;
			break;
		}

		top3 = positive.top();
		positive.pop(); 
		tmps.emplace(top1 + top2 + top3, 0);
		tmps.emplace(top1 * top2 + top3, 1);
		tmps.emplace(top1 + top2 * top3, 2);
		tmps.emplace(top1 * top3 + top2, 3);

		int topCase = get<1>(tmps.top());

		switch (topCase)
		{
		case 0:
			ans += top1 + top2;
			positive.emplace(top3);
			break;
		case 1:
			ans += top1 * top2;
			positive.emplace(top3);
			break;
		case 2:
			ans += top2 * top3;
			positive.emplace(top1);
			break;
		case 3:
			ans += top1 * top3;
			positive.emplace(top2);
			break;
		}
		tmps = priority_queue<tuple<int, int>>();
	}

	while (!negative.empty()) {
		top1 = negative.top();
		negative.pop();
		if (negative.empty()) {
			ans += top1;
			break;
		}

		top2 = negative.top();
		negative.pop();
		if (negative.empty()) {
			if (top1 * top2 > top1 + top2)
				ans += top1 * top2;
			else
				ans += top1 + top2;
			break;
		}

		top3 = negative.top();
		negative.pop();
		tmps.emplace(top1 + top2 + top3, 0);
		tmps.emplace(top1 * top2 + top3, 1);
		tmps.emplace(top1 + top2 * top3, 2);
		tmps.emplace(top1 * top3 + top2, 3);

		int topCase = get<1>(tmps.top());

		switch (topCase)
		{
		case 0:
			ans += top1 + top2;
			negative.emplace(top3);
			break;
		case 1:
			ans += top1 * top2;
			negative.emplace(top3);
			break;
		case 2:
			ans += top2 * top3;
			negative.emplace(top1);
			break;
		case 3:
			ans += top1 * top3;
			negative.emplace(top2);
			break;
		}
		tmps = priority_queue<tuple<int, int>>();
	}

	cout << ans;
	return 0;
}