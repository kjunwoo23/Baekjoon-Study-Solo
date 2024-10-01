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

int arr[50];
int cnt;

void makeEven() {
	for (int i = 0; i < N; i++)
		if (arr[i] % 2 == 1) {
			arr[i]--;
			cnt++;
		}
}
void divideWithTwo() {
	for (int i = 0; i < N; i++) 
		arr[i] /= 2;
	cnt++;
}

int getSum() {
	int sum = 0;

	for (int i = 0; i < N; i++)
		sum += arr[i];

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	while (true) {
		if (getSum() == 0) break;
		makeEven();
		if (getSum() == 0) break;
		divideWithTwo();
	}

	cout << cnt;

	return 0;
}