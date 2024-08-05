#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
#include <list>
#include <set>
using namespace std;


bool compare(int i, int j) {
	return j < i;
}
struct cmp{
	bool operator()(tuple<int, int> i, tuple<int, int> j) {
		if (get<0>(j) != get<0>(i))
			return get<0>(j) > get<0>(i);
		else
			return get<1>(j) > get<1>(i);
	}
};

int N, K;
priority_queue<tuple<int, int>, vector<tuple<int, int>>> jewelVM;
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