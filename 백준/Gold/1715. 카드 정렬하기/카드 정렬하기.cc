#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

struct cmp {
	bool operator() (int a, int b) {
		return a > b;
	}
};

int N;

priority_queue<int, vector<int>, cmp> deck;

int main() {
	int  cnt = 0;
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		deck.emplace(tmp);
	}

	while (deck.size() != 1) {
		int tmp1 = deck.top();
		deck.pop();
		int tmp2 = deck.top();
		deck.pop();
		cnt += tmp1 + tmp2;
		deck.emplace(tmp1 + tmp2);
	}

	cout << cnt;

	return 0;
}