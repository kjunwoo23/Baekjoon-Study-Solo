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

int D;

long long memo[8] = {1, 0, 0, 1, 0, 0, 0, 0};

void walking(int D) {
	for (int i = 1; i < D; i++) {
		long long tmp[8];
		tmp[0] = memo[1] + memo[2] + memo[3];
		tmp[1] = memo[0] + memo[3];
		tmp[2] = memo[0] + memo[3] + memo[4] + memo[5];
		tmp[3] = memo[0] + memo[1] + memo[2] + memo[5];
		tmp[4] = memo[2] + memo[5] + memo[6];
		tmp[5] = memo[2] + memo[3] + memo[4] + memo[7];
		tmp[6] = memo[4] + memo[7];
		tmp[7] = memo[5] + memo[6];
		for (int i = 0; i < 8; i++)
			memo[i] = tmp[i] % 1000000007;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> D;

	walking(D);

	cout << memo[1];

	return 0;
}