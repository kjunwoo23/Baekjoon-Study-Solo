#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
#include <list>
#include <set>
using namespace std;

//multiset 이용해야 함
//lower_bound 이용한 빠른 탐색

int N, K;
priority_queue<tuple<int, int>> jewelVM;
multiset<int> C;

int main() {
	long long ans = 0;

	cin >> N >> K;

	int m, v;
	for (int i = 0; i < N; i++) {
		cin >> m >> v;
		jewelVM.emplace(v, m);
	}

	int c;
	for (int i = 0; i < K; i++) {
		cin >> c;
		C.emplace(c);
	}

	while(!jewelVM.empty()) {
		if (C.empty()) break;
		
		for (auto i = C.lower_bound(get<1>(jewelVM.top())); i != C.end(); i++) {
			if (get<1>(jewelVM.top()) <= *i) {
				ans += get<0>(jewelVM.top());
				C.erase(i);
				break;
			}
		}
		jewelVM.pop();
	}

	cout << ans;
	return 0;
}