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

long long A, B, C;

long long multiply(long long B) {
	//if (B < 3) return (long long)pow(A, B) % C;
	if (B == 1) return A % C;
	if (B == 2) return A * A % C;

	long long tmpA, tmpB;

	long long k = multiply(B / 2) % C;

	if (B % 2 == 0) return k * k % C;
	else return k * k % C * A % C;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> A >> B >> C;

	cout << multiply(B);

	return 0;
}