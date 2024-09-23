#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <climits>
#include <cmath>
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

int N;
int S;

deque<int> arr;

int searchProper(int idx) {
	int tmpIdx = idx;
	int tmpMax = arr[idx];
	for (int i = idx; i < N; i++) {
		if (i - idx <= S)
			if (arr[i] > tmpMax) {
				tmpMax = arr[i];
				tmpIdx = i;
			}
	}
	return tmpIdx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.emplace_back(tmp);
	}
	cin >> S;

	for (int idx = 0; idx < N; idx++) {
		if (S <= 0) break;
		int tmpIdx = searchProper(idx);
		if (tmpIdx != -1) {
			int tmp = arr[tmpIdx];
			arr.erase(arr.begin() + tmpIdx);
			arr.insert(arr.begin() + idx, tmp);
			S -= tmpIdx - idx;
		}
	}

	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";

	return 0;
}