#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int a, b;
int ans;

int divide(int i, int cnt) {
	if (i < a) {
		ans = -1;
		return ans;
	}
	if (i == a)
		return cnt;
	if (i % 10 == 1)
		return divide(i / 10, cnt + 1);
	else if (i % 2 == 0)
		return divide(i / 2, cnt + 1);
	else {
		ans = -1;
		return ans;
	}
}

int main() {
	cin >> a >> b;

	int tmp = divide(b, 1);

	if (ans != -1) ans = tmp;

	cout << ans;

	return 0;
}