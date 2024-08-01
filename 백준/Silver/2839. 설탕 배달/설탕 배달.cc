#include <iostream>
using namespace std;

int memo[5000];

int GetNum(int n) {
	if (n == 0) return 0;
	if (memo[n] != 0) return memo[n];

	if (n < 3) { memo[n] = -1; return -1; }
	if (n % 5 == 0) { memo[n] = n / 5; return n / 5; }

	int data1 = GetNum(n - 5);
	int data2 = GetNum(n - 3);

	if (data1 == -1 && data2 == -1) { memo[n] = -1; return -1; }
	if (data1 == -1) { memo[n] = data2 + 1; return data2 + 1; }
	if (data2 == -1) { memo[n] = data1 + 1; return data1 + 1; }

	if (data1 < data2) { memo[n] = data1 + 1; return data1 + 1; }
	else { memo[n] = data2 + 1; return data2 + 1; }
}


int main() {
	int n;
	cin >> n;
	cout << GetNum(n);

	return 0;
}