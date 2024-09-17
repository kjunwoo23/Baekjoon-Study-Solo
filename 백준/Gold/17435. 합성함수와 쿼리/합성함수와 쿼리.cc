#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <limits.h>
#include <vector>
#include <math.h>
#include <stack>
#include <bitset>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <sstream>
#include <cstdlib>
using namespace std;

//희소 배열
int memo[22][500001];
int m, q, n, x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m;
	for (int i = 1; i < m + 1; i++)
		cin >> memo[0][i];

	//fillMemo();
	for (int logN = 1; logN < 22; logN++) {
		for (int i = 1; i < m + 1; i++) {
			//int tmp = memo[logN - 1][i];
			memo[logN][i] = memo[logN - 1][memo[logN - 1][i]];
		}
	}

	cin >> q;

	for (int i = 1; i < q + 1; i++) {
		cin >> n >> x;

		for (int j = 0; j < 22; j++) {
			if (n & (1 << j)) x = memo[j][x];
		}
		cout << x << "\n";
	}

	return 0;
}