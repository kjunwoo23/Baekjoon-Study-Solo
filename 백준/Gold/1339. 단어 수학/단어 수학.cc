#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int N;

int alpha[26];

bool compare(int i, int j) {
	return j < i;
}

void GetAlpha() {
	string tmp;
	cin >> tmp;

	int size = 1;
	while (!tmp.empty()) {
		alpha[tmp.back() - 'A'] += size;
		size *= 10;
		tmp.pop_back();
	}
}

int main() {
	int ans = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
		GetAlpha();

	sort(alpha, alpha + 26, compare);

	for (int i = 0; i < 9; i++)
		ans += alpha[i] * (9 - i);

	cout << ans;
	return 0;
}