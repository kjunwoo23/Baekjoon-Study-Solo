#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int t;
int N;

int Test() {
	priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> test;
	int cnt = 0;
	cin >> N;
	int first, second;
	for (int i = 0; i < N; i++) {
		cin >> first >> second;
		test.emplace(first, second);
	}

	int eliteSecond = get<1>(test.top());
	test.pop();
	cnt++;

	while (!test.empty()) {
		if (eliteSecond > get<1>(test.top())) {
			eliteSecond = get<1>(test.top());
			cnt++;
		}
		test.pop();
	}

	return cnt;
}

int main() {
	cin >> t;

	for (int i = 0; i < t; i++)
		cout << Test() << endl;

	return 0;
}