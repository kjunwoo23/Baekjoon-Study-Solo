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

int testCase;
int N;

int sticksForMin[18] = { 0, 0, 1, 7, 4, 2, 6, 8, 10, 18, 22,
						20, 28, 68, 88, 108, 188, 200};
int sticksForMax[4] = { 0, 0, 1, 7 };


void makeMin(int n) {
	string ans = "";

	while (n > 17) {
		n -= 7;
		ans += "8";
	}

	cout << sticksForMin[n];
	cout << ans;
	cout << ' ';

	return;
}

void makeMax(int n) {
	string ans = "";

	while (n > 3) {
		n -= 2;
		ans += "1";
	}

	cout << sticksForMax[n];
	cout << ans;
	cout << endl;

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> N;
		makeMin(N);
		makeMax(N);
	}

	return 0;
}