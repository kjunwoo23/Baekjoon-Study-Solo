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
struct matStruct {
	long long mat[8][8] = { 0, 1, 1, 1, 0, 0, 0, 0,
		1, 0, 0, 1, 0, 0, 0, 0,
		1, 0, 0, 1, 1, 1, 0, 0,
		1, 1, 1, 0, 0, 1, 0, 0,
		0, 0, 1, 0, 0, 1, 1, 0,
		0, 0, 1, 1, 1, 0, 0, 1,
		0, 0, 0, 0, 1, 0, 0, 1,
		0, 0, 0, 0, 0, 1, 1, 0 };
};
matStruct defaultMat;

matStruct sqrMat(matStruct A, matStruct B) {
	matStruct result;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			result.mat[i][j] = 0;
			int a = 0;
			int b = 0;
			for (; a < 8; a++, b++) {
				result.mat[i][j] += A.mat[i][a] * B.mat[j][b];
			}
			result.mat[i][j] %= 1000000007;
		}
	return result;
}

matStruct multiplyMat(int D) {
	if (D == 1) return defaultMat;
	if (D == 2) return sqrMat(defaultMat, defaultMat);

	matStruct halfMat = multiplyMat(D / 2);

	if (D % 2 == 0)
		return sqrMat(halfMat, halfMat);
	else
		return sqrMat(sqrMat(halfMat, halfMat), defaultMat);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> D;

	matStruct ans = multiplyMat(D);

	cout << ans.mat[1][1];
	return 0;
}