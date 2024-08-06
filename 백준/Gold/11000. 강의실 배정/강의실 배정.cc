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

multimap<int, int> classes;

int main() {
	long long ans = 0;

	cin >> N;

	int S, T;
	for (int i = 0; i < N; i++) {
		cin >> S >> T;
		classes.emplace(S, T);
	}

	while (!classes.empty()) {
		ans++;
		int finTime = 0;
		for (auto iter = classes.begin(); iter != classes.end();) {
			if (finTime <= (*iter).first) {
				finTime = (*iter).second;
				classes.erase(iter);
				iter = classes.lower_bound(finTime);
			}
			else
				iter++;
		}
	}


	cout << ans;
	return 0;
}