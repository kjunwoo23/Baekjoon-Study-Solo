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

int n, m;
int D;
struct matStruct {
	long long mat[51][51] = { 0 };
};
matStruct defaultMat;

matStruct* sqrMat(matStruct *A, matStruct *B) {
	matStruct* result = new matStruct;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int a = 0;
			int b = 0;
			for (; a < n; a++, b++) {
				result->mat[i][j] += A->mat[i][a] * B->mat[j][b];
				result->mat[i][j] %= 1000000007;
			}
		}
	return result;
}

matStruct* multiplyMat(int D) {
	if (D == 1) return &defaultMat;
	if (D == 2) return sqrMat(&defaultMat, &defaultMat);

	matStruct *halfMat = multiplyMat(D / 2);

	if (D % 2 == 0)
		return sqrMat(halfMat, halfMat);
	else
		return sqrMat(sqrMat(halfMat, halfMat), &defaultMat);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		defaultMat.mat[a - 1][b - 1] = 1;
		defaultMat.mat[b - 1][a - 1] = 1;
	}
	cin >> D;

	matStruct *ans = multiplyMat(D);

	cout << ans->mat[0][0];
	return 0;
}